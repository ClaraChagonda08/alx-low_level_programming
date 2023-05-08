#ifndef MAIN_H
#define MAIN_N

#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

ssize_t read_textfile(const char *fname, size_t letrs);
int create_file(const char *fname, char *content);
int append_text_to_file(const char *fname, char *content);

/**
 * ELF header functions
*/
void check_elf(unsigned char *identf);
void magi(unsigned char *identf);
void pclass(unsigned char *identf);
void pdata(unsigned char *identf);
void pversion(unsigned char *identf);
void pab(unsigned char *identf);
void posa(unsigned char *identf);
void ptype(unsigned int e_type, unsigned char *identf);
void pentry(unsigned long int ntry, unsigned char *identf);
void closef(int elf);
#endif
