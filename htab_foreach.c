#include <stdio.h>
#include "htab.h"

void htab_foreach(htab_t* t, void (*function)(const char*, unsigned int)) {
	if(t == NULL || function == NULL)
		return;

	for(size_t i = 0; i < t->arr_size; i++) {
		htab_listitem_t* iter = t->array[i];
		while(iter != NULL) {
		//	printf("%s: %u\n", iter->key, iter->data);
			function(iter->key, iter->data);
			iter = iter->next;
		}
	}
}
