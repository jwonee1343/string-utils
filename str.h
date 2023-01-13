// UTF-8 encoding
/**
 * @brief	문자열을 처리하기 위한 간단한 함수들 선언
 * @author	Jaewon Choi <jwonee1343@gmail.com>
 */
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
uint32_t	int_to_str(int64_t num, char s[]);

#ifdef __cplusplus
}
#endif

#endif // __STR_H
