// UTF-8 Encoding
/**
 * @author	Jaewon Choi <jwonee1343@gmail.com>
 * @brief	문자를 변환 또는 문자로 변환하기 위한 함수들을 정의한 소스 코드
 */
#include "ch.h"
#include <stdbool.h>
#include <stdint.h>

/**
 * @brief	문자의 내용이 숫자인지 확인하는 함수 
 * @param	ch	확인할 문자
 * @return	true	문자의 내용이 숫자임\n
 * 		false	문자의 내용이 숫자가 아님
 */
bool char_isnum(char ch)
{
	return ch >= '0' && ch <= '9';
}

/**
 * @brief	문자의 내용을 숫자로 변환하는 함수
 * @param	ch		변환할 문자
 * @return	0 - 9		변환한 숫자\n
 * 		CHAR_ERR 	에러
 */
uint8_t char_tonum(char ch)
{
	return char_isnum(ch) ? (ch - '0') : CHAR_ERR;
}

/**
 * @brief	문자의 내용이 16진수인지 확인하는 함수
 * @param	ch	확인할 문자
 * @return	true	문자의 내용이 16진수임\n
 * 		false	문자의 내용이 16진수가 아님
 */
bool char_ishex(char ch)
{
	return char_isnum(ch) || 
		(ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
}

/**
 * @brief	문자를 16진수로 변환하는 함수
 * @param	ch		변환할 문자
 * @return	0x0 - 0xf	변환한 16진수 값
 * 		CHAR_ERR	에러
 */
uint8_t char_tohex(char ch)
{
	if (char_isnum(ch)) {
		return char_tonum(ch);
	} else if (ch >= 'a' && ch <= 'f') {
		return ch - 'a' + 0xa;
	} else if (ch >= 'A' && ch <= 'F') {
		return ch - 'A' + 0xa;
	}

	return CHAR_ERR;
}

/**
 * @brief	숫자를 문자로 변환하는 함수
 * @param	single_num	변환할 한 자리 숫자 (0 - 9)
 * @return	'0' - '9'	변환한 문자
 * @warning	num 이 두자릿수를 넘어가면 1의 자리수만 변환한다
 */
char num_tochar(uint8_t num)
{
	num %= 10;

	return num + '0';
}

/**
 * @brief	16진수를 문자로 변환하는 함수
 * @parma	nib	변환할 니블 (0x0 - 0xf)
 * @param	upper	true	대문자로 출력\n
 * 			false	소문자로 출력
 * @return	'0' - '9'	변환한 문자
 */
char hex_tochar(uint8_t nib, bool upper)
{
	nib &= 0xf;
	if (nib < 0xa) {
		return num_tochar(nib);
	} else {
		return nib - 0xa + (upper ? 'A' : 'a');
	} 
}
