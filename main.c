#include <stdio.h>

int hi(char* script) {
	printf("🤢 %s\n", script);
	printf("🤢 %s\n", "a string literal");
	char *x = "a string variable";
	printf("🤢 %s\n", x);
	return 14;
}