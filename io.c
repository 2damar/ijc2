#include <stdio.h>
#include <ctype.h>
#include "io.h"

int get_word(char* s, int max, FILE* f) {
	int i = 0;
	int c;
	while((c = fgetc(f)) != EOF && !isspace(c) && i < max)
		s[i++] = c;
	s[i] = '\0';
	if(c == EOF)
		return c;
	if(!isspace(c))
		fprintf(stderr, "Word has more than %d chars", max - 1);
	
	return i;
}
