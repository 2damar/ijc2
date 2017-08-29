#include <stdlib.h>
#include "htab.h"

htab_t* htab_move(size_t newsize, htab_t* t2) {
	if(t2 == NULL || newsize == 0)
		return NULL;
	htab_t* new_htab = htab_init(newsize);
	if(new_htab == NULL)
		return NULL;

	for(size_t i = 0; i < t2->arr_size; i++) {
		htab_listitem_t* t2_it = t2->array[i];
		htab_listitem_t* new_htab_it;
		while(t2_it != NULL) {
			new_htab_it = htab_lookup_add(new_htab, t2_it->key);
			if(new_htab_it == NULL) {
				htab_free(new_htab);
				return NULL;
			}
			new_htab_it->data = t2_it->data;
		}
	}

	htab_clear(t2);
	return new_htab;
}
			
			
