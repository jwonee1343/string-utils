// UTF-8 encoding
/**
 * @brief	문자열을 처리하기 위한 간단한 함수들을 구현함
 * @author	Jaewon Choi <jwonee1343@gmail.com>
 */
#include "string.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief	문자열의 길이를 구한다
 * @param	string		문자열의 주소
 * @return	문자열의 길이
 */
uint32_t string_length(const char *string)
{
	uint32_t length = 0;

	for (length = 0; string[length]; length++) {
		;
	}

	return length;
}

/**
 * @brief	두 문자열이 같은 내용을 가지는 지 확인한다
 * @param	string1		비교할 문자열의 주소 1
 * @param	string2		비교할 문자열의 주소 2
 * @return	true = 두 문자열이 같음, false = 다름
 */
bool string_equal(const char *string1, const char *string2)
{
	uint32_t i = 0;

	for (i = 0; string1[i] && string2[i]; i++) {
		if (string1[i] != string2[i]) {
			return false;
		}
	}

	return string1[i] == string2[i];
}

/**
 * @brief	문자열의 내용을 다른 메모리로 복사한다
 * @param	from		복사할 문자열의 주소
 * @param	to		저장할 문자열의 주소
 * @return	복사한 문자열의 길이
 * @warning	반드시 from의 문자열 길이가 to의 최대 크기 보다 작아야 함!
 */
uint32_t string_copy(const char *from, char to[])
{
	uint32_t length = 0;

	for (length = 0; from[length]; length++) {
		to[length] = from[length];
	}
	to[length] = '\0';

	return length;
}

/**
 * @brief	문자열을 잘라서 두 개로 나눈다
 * @param	string		잘라낼 문자열의 주소
 * @param	delimiter	구분 문자
 * @return	잘라낸 문자열 주소, NULL = 구분 문자를 찾지 못함
 */
char *string_split(char string[], char delimiter)
{
	char *s = string;

	while (*s) {
		if (*s == delimiter) {
			*s = '\0';
			return s + 1;
		}
		s++;
	}

	return NULL;
}

/**
 * @brief	문자열을 정수로 변환한다
 * @param	string		변환할 문자열의 주소
 * @return	정수 값
 * @warning	문자열 내용이 반드시 정수라는 신뢰성이 확보된 상태에서 사용할 것!
 */
int64_t string_to_int(const char *string)
{
	const char *s = string;
	int64_t number = 0;
	bool negative = false;

	if (*s == '-') {
		negative = true;
		s++;
	}

	while (*s) {
		if (*s < '0' || '9' < *s) {
			return 0; // Invalid format 
		}

		number *= 10;
		number += *s - '0';
		s++;
	}

	/*
	 * 문자열이 "-" 인 경우, 반복문을 거치지 않으므로 
	 * 반환 값은 0이다
	 */
	return negative ? -number : number;
}

uint32_t int_to_string(int64_t number, char string[])
{
	uint32_t length = 0;
	uint32_t temp = 0;
	uint8_t count = 0;

	if (i < 0) {
		string[length++] = '-';
		temp = number * -1;
	} else {
		temp = number;
	}

	n = number > 0 ? number : -number;
	do {
		count++;
		n /= 10;
	} while (n > 0);

	length += count;
	string[length--] = '\0';

	n = number > 0 ? number : -number;
	do {
		string[length]
		n /= 10;
	} while (n > 0);


	string[length] = '\0';


	for (count = 1; temp / 10 > 0; count++) {
		temp /= 10;
	}

	length += count;
	for (temp = 0; temp < count; temp++) {
		string[length - temp]
	}

	temp = count;
	while (temp--) {
		string[length + temp] = number % 10 + '0';
		number /= 10;
	}

	length += count;
	string[length] = '\0';

	return length;
}
