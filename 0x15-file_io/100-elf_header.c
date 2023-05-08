#include "main.h"


/**
 * Author Clara
 * .
 */
void check(unsigned char *identf)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (identf[i] != 127 &&
		    identf[i] != 'E' &&
		    identf[i] != 'L' &&
		    identf[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}


void magi(unsigned char *identf)
{
	int x;

	printf("  Magic:   ");

	for (x = 0; x < EI_NIDENT; x++)
	{
		printf("%02x", identf[x]);

		if (x == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}


void pclass(unsigned char *identf)
{
	printf("  Class:                             ");

	switch (identf[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", identf[EI_CLASS]);
	}
}


void pdata(unsigned char *identf)
{
	printf("  Data:                              ");

	switch (identf[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", identf[EI_CLASS]);
	}
}


void pversion(unsigned char *identf)
{
	printf("  Version:                           %d",
	       identf[EI_VERSION]);

	switch (identf[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}


void posa(unsigned char *identf)
{
	printf("  OSA:                            ");

	switch (identf[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", identf[EI_OSABI]);
	}
}


void pab(unsigned char *identf)
{
	printf("  ABI Version:                       %d\n",
	       identf[EI_ABIVERSION]);
}


void ptype(unsigned int e_type, unsigned char *identf)
{
	if (identf[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}


void pentry(unsigned long int ntry, unsigned char *identf)
{
	printf("  Entry point address:               ");

	if (identf[EI_DATA] == ELFDATA2MSB)
	{
		ntry = ((ntry << 8) & 0xFF00FF00) |
			  ((ntry >> 8) & 0xFF00FF);
		ntry = (ntry << 16) | (ntry >> 16);
	}

	if (identf[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)ntry);

	else
		printf("%#lx\n", ntry);
}


void closef(int elf)
{
	if (close(elf) == -1)
	{
		printf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int d, s;

	d = open(argv[1], O_RDONLY);
	if (d == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closef(d);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	s = read(d, header, sizeof(Elf64_Ehdr));
	if (s == -1)
	{
		free(header);
		closef(d);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check(header->identf);
	printf("ELF Header:\n");
	magi(header->identf);
	pclass(header->identf);
	pdata(header->identf);
	pversion(header->identf);
	posa(header->identf);
	pab(header->identf);
	ptype(header->e_type, header->identf);
	pentry(header->e_entry, header->identf);

	free(header);
	closef(d);
	return (0);
}


