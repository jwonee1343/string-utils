#include <stdio.h>
#include <stdint.h>
#include "str.h"

int main(int argc, char *argv[])
{
	char buff[0xff] = "";
	char temp[0xff] = "";
	char *s = NULL;
	char delim = '\0';

	for (;;) {
		printf("str: ");
		scanf("%s", buff);
		printf("str_len() -> %u\n", str_len(buff));
		printf("str_is_int() -> %s\n", str_is_int(buff) ? "true" : "false");
		printf("str_to_int() -> %lld\n", str_to_int(buff));
		
		printf("compare: ");
		scanf("%s", temp);
		printf("str_equal() -> %s\n", str_equal(buff, temp) ? "true" : "false");

		printf("str_copy() -> len = %u, s = %s\n", str_copy(buff, temp), temp);
		printf("delim: ");
		scanf("%c", &delim);
		scanf("%c", &delim);
		for (s = str_split(buff, delim); s && *s; s = str_split(s, delim)) {
			printf("str_split() -> %s\n", s);
		}
	}

	return 0;
}
