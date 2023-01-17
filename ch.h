// UTF-8 Encoding
/**
 * @author	Jaewon Choi <jwonee1343@gmail.com>
 * @brief	문자를 변환 또는 문자로 변환하기 위한 함수들을 선언
 */
#ifndef __CH_H
#define __CH_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

#define CHAR_ERR UINT8_MAX 

bool	char_isnum(char ch);
uint8_t	char_tonum(char ch);
bool	char_ishex(char ch);
uint8_t	char_tohex(char ch);
char	num_tochar(uint8_t num);
char	hex_tochar(uint8_t nib, bool upper);

#ifdef __cplusplus
}
#endif 

#endif // __CH_H
