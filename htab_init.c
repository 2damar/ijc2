#include <stdlib.h>
#include "htab.h"

htab_t* htab_init(size_t size) {
	if(size == 0)
		return NULL;

	htab_t *ht = (htab_t*)malloc(sizeof(htab_t) + size*sizeof(htab_listitem_t*));
	if(ht == NULL) 
		return NULL;

	ht->arr_size = size;
	ht->n = 0;
	for(unsigned int i = 0; i < ht->arr_size; i++)
		ht->array[i] = NULL;

	return ht;
}
