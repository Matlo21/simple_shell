#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/* PATH Shell Functions */

/* Program Flow */
int prompt(void);
char *_read(void);
char *_fullpathbuffer(char **av, char *PATH, char *copy);
int checkbuiltins(char **av, char *buffer, int exitstatus);
int _forkprocess(char **av, char *buffer, char *fullpathbuffer);

/* String Helper Functions */
char *_strdup(char *str);
int _splitstring(char *str);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);

/*Tokenize & PATH Helper Functions*/
char **tokenize(char *buffer);
int _splitPATH(char *str);
int _PATHstrcmp(const char *s1, const char *s2);
char *_concat(char *tmp, char **av, char *tok);

/* Built-ins*/
void env_builtin(void);
void quiter(char **cmd, char *b);
int is_builtin(char **cmd, char *b);
void prompt_printer(void);
void sighandle(int n);

/*Other Helper Funcs*/
char *_getenv(const char *name);
int _env(void);
void _puts(char *str);
int _putchar(char c);
char *_memset(char *s, char b, unsigned int n);

/**
 * struct builtins - Handles builtins
 * @env: First member
 * @exit: Second member
 * Description: builtin commands
 */
struct builtins
{
	char *env;
	char *exit;

} builtins;

/**
 * struct info - Status info struct
 * @final_exit: First member
 * @ln_count: Second member
 * Description: Used in error handling
 */
struct info
{
	int final_exit;
	int ln_count;
} info;

/**
 * struct flags - Holds flag 
 * @interactive: First member
 * Description: handles boolean switches
 */
struct flags
{
		bool interactive;
} flags;

#endif /* _SHELL_H_ */
