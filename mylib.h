#ifndef MYLIB_H
#define MYLIB_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
void sort_pointer_array(int **array, int n);
void sort_array(int *array, int n);

int cmp_pointer_array(const void *a, const void *b);
int cmp_array(const void *a, const void *b);

void print_array(const int *array, const int n);
void print_pointer_array(const int **array, const int n, const int *size);

void creat_int_pointer(int **ppi, const int n);
void creat_char_pointer(char **ppc, const int n);
void creat_char_pointer_array(char ***ppca, const int n, const int *l);
void creat_char_pointer_array_without_allocation(char ***ppca, const int n);

//




void print_token_strtok(char *line, const char *delim);
void print_token_strsep(char *line, const char *delim);


int split_strtok(char ***res, int **lens, char *line, const char *delim, int remove_white_flag);
int split_strsep(char ***res, int **lens, char *line, const char *delim, int remove_white_flag);



void remove_white(char *line);
 
#endif
