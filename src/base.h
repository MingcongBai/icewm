#ifndef __BASE_H
#define __BASE_H

#ifdef NEED_BOOL
enum bool_t { false = 0, true = 1 };
typedef int bool;
#endif

char *newstr(const char *str);
char *newstr(const char *str, int len);
char *strJoin(const char *str, ...);

void die(int exitcode, const char *msg, ...);
void warn(const char *msg, ...);

// !!! remove this
void *MALLOC(unsigned int len);
void *REALLOC(void *p, unsigned int new_len);
void FREE(void *p);

#define ACOUNT(x) (sizeof(x)/sizeof(x[0]))

extern "C" {
#ifdef __EMX__
char* __XOS2RedirRoot(const char*);
#define REDIR_ROOT(path) __XOS2RedirRoot(path)
#else
#define REDIR_ROOT(path) (path)
#endif
}

//!!! clean these up
#define KEY_MODMASK(x) ((x) & (app->KeyMask))
#define BUTTON_MASK(x) ((x) & (app->ButtonMask))
#define BUTTON_MODMASK(x) ((x) & (app->ButtonKeyMask))
#define IS_BUTTON(s,b) (BUTTON_MODMASK(s) == (b))

#define ISMASK(w,e,n) (((w) & ~(n)) == (e))
#define HASMASK(w,e,n) ((((w) & ~(n)) & (e)) == (e))

#define ISLOWER(c) ((c) >= 'a' && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? (c) - 'a' + 'A' : (c))

#include "debug.h"

#endif
