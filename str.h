#ifndef __STR_H
#define __STR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

uint32_t	str_len(const char *s);
bool		str_equal(const char *s1, const char *s2);
uint32_t 	str_copy(const char *from, char to[]);
char *		str_split(char *s, char delim);
bool 		str_is_int(const char *s);
int64_t		str_to_int(const char *s);

#ifdef __cplusplus
}
#endif

#endif // __STR_H
