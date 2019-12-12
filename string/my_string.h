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
 * res是返回的指针数组
 * lens是返回的指针数组每个元素的大小
 *
 * line是输入参数
 * delim是输入分隔符
 * remove_white选择是否先去掉空格
 *
 *
 * split_strsep会认为连续的分隔符之间是空白。
 * split_strtok会删除连续的分隔符，
 *
 */
int split_strtok(char ***res, int **lens, char *line, const char *delim, int remove_white_flag);
int split_strsep(char ***res, int **lens, char *line, const char *delim, int remove_white_flag);


// remove ' '
void remove_white(char *line);
 
#endif
