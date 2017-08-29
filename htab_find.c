#include <string.h>
#include "htab.h"

htab_listitem_t* htab_find(htab_t* t, const char* key) {
	if(t == NULL || key == NULL)
		return NULL;

	unsigned int ai = hash_function(key, t->arr_size);
	htab_listitem_t* iter = t->array[ai];
	while((iter != NULL) && (strcmp(iter->key, key) != 0)) 
		iter = iter->next;

	return iter; 
}
	
