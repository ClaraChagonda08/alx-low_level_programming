#ifndef MAIN_H
#define MAIN_H
unsigned int binary_to_uint(const char *a);
void print_binary(unsigned long int l);
int get_bit(unsigned long int l, unsigned int index);
int set_bit(unsigned long int *l, unsigned int index);
int clear_bit(unsigned long int *l, unsigned int index);
unsigned int flip_bits(unsigned long int l, unsigned long int o);
int get_endianness(void);
int _putchar(char d);
#endif
