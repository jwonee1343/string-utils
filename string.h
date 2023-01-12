
#ifndef __STR_H
#define __STR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

uint32_t	string_length(const char *string);
bool		string_equal(const char *string1, const char *string2);
uint32_t	string_copy(const char *from, char to[]);
char *		string_split(char string[], char delimiter);
int64_t 	string_to_int(const char *string);

int64_t str_to_int(const char *s);
uint32_t int_to_str(int64_t i, char s[]);

#ifdef __cplusplus
}
#endif

#endif // __STR_H
