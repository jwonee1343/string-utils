// UTF-8 encoding
/**
 * @brief	문자열을 처리하기 위한 간단한 함수들을 구현함
 * @author	Jaewon Choi <jwonee1343@gmail.com>
 */
#include "str.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief	문자열의 길이를 구하는 함수
 * @param	s	문자열
 * @return	문자열의 길이
 */
uint32_t str_len(const char *s)
{
	uint32_t len = 0;

	for (len = 0; s[len]; len++) {
		;
	}

	return len;
}

/**
 * @brief	두 문자열의 내용이 같은 지 비교하는 함수
 * @param	s1	문자열1
 * @param	s2	문자열2
 * @return	true = 같음, false = 다름
 */
bool str_equal(const char *s1, const char *s2)
{
	while (*s1 && *s2) {
		if (*s1 != *s2 ) {
			return false;
		}

		s1++;
		s2++;
	}

	return *s1 == *s2;
}

/**
 * @brief	문자열을 복사하는 함수
 * @param	from	복사할 문자열
 * @param	to	저장할 위치
 * return	복사한 문자열의 길이
 */
uint32_t str_copy(const char *from, char to[])
{
	uint32_t len = 0;

	for (len = 0; from[len]; len++) {
		to[len] = from[len];
	}
	to[len] = '\0';

	return len;
}

/**
 * @brief	문자열을 두 개로 나누는 함수
 * @param	s	문자열
 * @param	delim	구분 문자
 * @return	나눠진 문자열의 위치. NULL = delim을 찾지 못함
 */
char *str_split(char *s, char delim)
{
	while (*s) {
		if (*s == delim) {
			*s = '\0';
			return s + 1;
		}
		s++;
	}

	return NULL;
}

/**
 * @brief	문자열의 내용이 정수인지 확인하는 함수
 * @param	s	문자열
 * @return	true = 문자열의 내용이 정수임. false = 정수가 아님
 */
bool str_is_int(const char *s)
{
	if (*s == '-') {
		s++;
	}

	do {
		if (*s < '0' || '9' < *s) {
			return false;
		}
		s++;
	} while (*s);

	return true;
}

/**
 * @brief	문자열의 내용을 정수로 변환하는 함수
 * @param	s	문자열
 * @return	정수 값
 * @warning	호출 전에 문자열이 내용이 정수인지 확인필요
 */
int64_t str_to_int(const char *s)
{
	int64_t num = 0;
	bool ne = false;

	if (*s == '-') {
		ne = true;
		s++;
	}

	while ('0' <= *s && *s <= '9') {
		num *= 10;
		num += *s - '0';
		s++;
	}

	return ne ? -num : num;
}

uint32_t int_to_str(int64_t num, char s[])
{
	uint32_t len = 0;
	int64_t div = 1;

	if (num < 0) {
		s[len++] = '-';
		num *= -1;
	}
 
	while (num / div > 9) {
		div *= 10;
	}

	while (div > 0) {
		s[len++] = num / div + '0';
		num %= div;
		div /= 10;
	}
	s[len] = '\0';

	return len;
}


/**
 * @brief	문자열의 내용이 16진수인지 확인하는 함수
 * @param	s	문자열
 * @return	true = 문자열 내용이 16진수임. false = 16진수가 아님
 */
bool str_is_hex(const char *s)
{
	while (*s) {
		if (!(*s >= '0' && *s <= '9') ||
			! (*s >= 'a' && *s <= 'f') ||
			! (*s >= 'A' && *s <= 'F')) {
			return false;
		}
		s++;
	}

	return true;
}

/**
 * @brief	문자를 16진수 부호 없는 정수로 변환하는 함수
 * @param	ch	문자
 * @return	변환한 부호없는 정수
 */
static inline uint8_t char_to_hex(char ch)
{
	if (ch >= '0' && ch <= '9') {
		return (ch - '0') & 0xf;
	} else if (ch >= 'a' && ch <= 'f') {
		return (ch - 'a' + 0xa) & 0xf;
	} else if (ch >= 'A' && ch <= 'F') {
		return (ch - 'A' + 0xa) & 0xf;
	} else {
		return 0;
	}
}

/**
 * @brief	문자열의 내용을 16진수 부호 없는 정수로 변환하는 함수
 * @param	s	문자열
 * @return	변환한 부호없는 정수
 */
uint32_t str_to_hex(const char *s, uint8_t bytes[])
{
	uint32_t len = 0;

	for (len = 0; s[len]; len++) {
		bytes[len / 2] <<= 4;
		bytes[len / 2] = char_to_hex(s[len]);
	}

	return len;
}
