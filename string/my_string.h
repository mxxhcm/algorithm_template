#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
 * char delim[] = " \t\f\r\v\n";
 * print_token_strtok, can't deal "foo,,,foo,bar"
 * print_token_strsep, can deal "foo,,,foo,,bar", can't deal "foo , bar ,"(contain much duplicate whitespace)
 */
void print_token_strtok(char *line, const char *delim);
void print_token_strsep(char *line, const char *delim);


/*
 *
 */
void split_strtok(char *line, const char *delim, char ***res);
void split_strsep(char *line, const char *delim, char ***res, int remove_white=0);


// remove ' '
void remove_duplicate_white(char *line);
 
#endif
