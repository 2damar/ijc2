#include <stdlib.h>
#include "htab.h"

void htab_clear(htab_t* t) {
	if(t == NULL)
		return;
	
	for(size_t i = 0; i < t->arr_size; i++) {
		htab_listitem_t* it = t->array[i];
		htab_listitem_t* remove_it;
		while(it != NULL) {
			remove_it = it;
			it = it->next;
			free(remove_it->key);
			free(remove_it);
			t->n--;
		}
		t->array[i] = NULL;
	}
}
			
			
