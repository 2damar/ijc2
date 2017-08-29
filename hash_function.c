#include "htab.h"

unsigned int hash_function(const char* str, size_t htab_size) {
	unsigned int h = 0;
	const unsigned char* p;
	for(p = (const unsigned char*)str; *p != '\0'; p++)
		h = 65599*h + *p;

	return (h % htab_size);
}
