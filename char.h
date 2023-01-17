#ifndef __CHAR_H
#define __CHAR_H

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

#endif // __CHAR_H
