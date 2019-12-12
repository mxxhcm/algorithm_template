#ifndef SPLIT_H
#define SPLIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *
 * char delim[] = " \t\f\r\v\n";
 *
 */
void print_token(char *line, const char *delim);
void print_token_strsep(char *line, const char *delim);

/*
 *
 *
 *
 */
void split_strtok(char *line, const char *delim, char ***res);

/*
 *
 *
 *
 */
void split_strsep(char *line, const char *delim, char ***res);

 
#endif
