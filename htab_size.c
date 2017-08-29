#include "htab.h"

size_t htab_size(htab_t* t) {
	if(t == NULL)
		return 0;
	return t->n;
}
