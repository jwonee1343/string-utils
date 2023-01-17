#include <stdio.h>
#include <stdint.h>
#include "char.h"

int main(int argc, char *argv[])
{
	uint8_t ch = 0;

	for (ch = 0; ch < 0xFF; ch++) {
		printf("%c ", ch);
		printf("char_isnum = %c, ", char_isnum(ch) ? 'O' : 'X');
		printf("char_tonum = %d, ", (int)char_tonum(ch));
		printf("char_ishex = %c, ", char_ishex(ch) ? 'O' : 'X');
		printf("char_tohex = %1x\n", (int)char_tohex(ch));
	}

	uint8_t byte = 0;

	for (byte = 0; byte < 0xFF; byte++) {
		printf("%d(%02x) ", (int)byte, (int)byte);
		printf("num_tochar = %c, ", num_tochar(byte));
		printf("hex_tochar = %c(%c)\n", 
				hex_tochar(byte, true), hex_tochar(byte, false));
	}

	return 0;
}
