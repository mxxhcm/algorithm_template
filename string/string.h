

// 1.字符串长度
size_t strlen(char const *string);

// 2.字符串拼接
char *strcat(char *dest, const char *src);
char *strncat(char *des, const char *src, size_t n);

// 3.字符串复制
char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);

// 4.字符串比较
int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t len);


// 5.查找一个字符
char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);

// 6.查找字符集中的任何一个字符
char *strpbrk(const char *str, const char *group);

// 7.查找子字符串
char *strstr(const char *s1, const char *s2);

// 8.查找字符串前缀
size_t strspn(const char *s, const char *accept);
size_t strcspn(const char *s, cosnt char *reject);


// 9.查找某个分隔符（和查找一个字符的区别？）
char *strtok(char *str, const char *delim);

// 10. 从字符串中提取token，将找到的第一个分隔符重置为'\0'，
char *strsep(char **stringp, const char *delim);

/*
 * 字符串以NULL字节结尾，所以字符串内部不能包含任何NULL字符，但是非字符串内部包含NULL字符很常见。mem开头的函数遇到NULL字节不会停止。
 *
 * memcpy从src的起始位置复制length个字节到dst的内存起始位置。可以用这种方法复制任何类型的数组，不仅仅限于字符串。
 * 比如复制两个整数数组，但是需要用sizeof(int)乘上int的数量得到复制的字节长度。
 *
 * memcpy和memmove，当memcpy遇到重叠字符串，结果未定义。而memmove可以解决重叠字符串问题，但是要比memcpy慢。
 */
void *memset(void *s, int c, size_t, n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *des, const void *src, size_t n);
void *memchr(const void *s, int c, size_t);
int  memcmp(const void *s1, const void *s1, size_t n);


