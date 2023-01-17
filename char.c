#include "char.h"
#include <stdbool.h>
#include <stdint.h>

bool char_isnum(char ch)
{
	return ch >= '0' && ch <= '9';
}

uint8_t char_tonum(char ch)
{
	return char_isnum(ch) ? (ch - '0') : CHAR_ERR;
}

bool char_ishex(char ch)
{
	return char_isnum(ch) || 
		(ch >= 'a' && ch <= 'f') || (ch >= 'A' && ch <= 'F');
}

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

char num_tochar(uint8_t num)
{
	num %= 10;

	return num + '0';
}

char hex_tochar(uint8_t nib, bool upper)
{
	nib &= 0xf;
	if (nib < 0xa) {
		return num_tochar(nib);
	} else {
		return nib - 0xa + (upper ? 'A' : 'a');
	} 
}
