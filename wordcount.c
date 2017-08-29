#include <stdio.h>
#include "io.h"
#include "htab.h"

#define HTAB_SIZE 12289

void print_item(const char* key, unsigned int value) {
	printf("%s: %u\n", key, value);
}
		

int main(void) {
	int c; 
	char s[128] = {0};
	htab_t* ht = htab_init(HTAB_SIZE);
	while((c=get_word(s, 128, stdin)) != EOF) 
		htab_lookup_add(ht, s);

	htab_foreach(ht, print_item);
	htab_free(ht);

	return 0;
}

		
		
		
	
