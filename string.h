#ifndef __STRING_H
#define __STRING_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

uint32_t	string_length(const char *s);
bool		string_equal(const char *s1, const char *s2);
uint32_t	string_copy(const char *from, char to[]);
char *		string_split(char s[], char delim);
uint32_t	string_to_uint(const char *s);
int64_t 	string_to_int(const char *s);

#ifdef __cplusplus
}
#endif

#endif // __STRING_H
