#ifndef MAIN_HEADER
#define MAIN_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <string.h>

/*Macros*/
#define MAX_COMMAND_LEN 100
#define INITIAL_BUFFER_SIZE 120

/*getenv*/
extern char **environ;
char *_getenv(const char *name);

/*getline*/
ssize_t _getline(char **lineptr, size_t *n, int fd);
bool _resize_buffer(char **buf, size_t *n, size_t *buff_size);
ssize_t _read_file(int fd, char *buf, size_t buff_size);

/*shell.c*/
void read_input(char **line_read, size_t *n);
char *find_command(char **args, char *path_env);
void execute_command(char *command_path, char **args, char **env);
void tokenize(char *str, char **args, int max_args, char *delimiters);
void p_error(char *argv, char *args);

/*Memory*/
void _free(char **lineptr);
void *_realloc(void *ptr, size_t size);

/*strings*/
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /*MAIN_HEADER*/
