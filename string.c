// UTF-8 encoding
/**
 * @brief	문자열을 처리하기 위한 간단한 함수들을 구현
 * @author	Jaewon Choi <jwonee1343@gmail.com>
 */
#include "string.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief	문자열의 길이를 구하는 함수
 * @param	s	문자열 주소
 * @return	문자열 길이
 */
uint32_t string_length(const char *s)
{
	uint32_t len = 0;

	for (len = 0; s[len]; len++) {
		;
	}

	return len;
}

/**
 * @brief	두 문자열의 내용이 같은 지 비교하는 함수
 * @param	s1	문자열 1
 * @param	s1	문자열 2
 * @return	true = 같음, false = 다름
 */
bool string_equal(const char *s1, const char *s2)
{
	uint32_t i = 0;

	for (i = 0; s1[i] && s2[i]; i++) {
		if (s1[i] != s2[i]) {
			return false;
		}
	}

	return s1[i] == s2[i];
}

/**
 * @brief	문자열을 복사한다
 * @param	from	복사할 문자열
 * @param	to	저장할 문자열
 * return	복사한 문자열 길이
 */
uint32_t string_copy(const char *from, char to[])
{
	uint32_t len = 0;

	for (len = 0; from[len]; len++) {
		to[len] = from[len];
	}
	to[len] = '\0';

	return len;
}

/**
 * @brief	문자열을 두 개로 나눈다 
 * @param	s	문자열 주소
 * @delim	delim	구분 문자
 * @return	나눠진 문자열의 주소. NULL = delim을 찾지 못함
 */
char *string_split(char s[], char delim)
{
	while (*s && *s != delim) {
		s++;
	}

	if (*s) {
		*s = '\0';
		return s + 1;
	} else {
		return NULL;
	}
}

/**
 * @brief	문자열을 부호 없는 정수로 변환한다
 * @param	s	변환할 문자열
 * @return	정수 값
 */
uint32_t string_to_uint(const char *s)
{
	uint32_t i = 0;

	while (*s) {
		i *= 10;
		i += *s - '0';
		s++;
	}

	return i;
}

/**
 * @brief	문자열을 정수로 변환한다
 * @param	변환할 문자열
 * @return	정수 값
 */
int64_t string_to_int(const char *s)
{
	return *s != '-' ? string_to_uint(s) : -string_to_uint(s + 1);
}

