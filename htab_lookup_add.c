#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "htab.h"

htab_listitem_t* htab_lookup_add(htab_t* t, const char* key) {
	if(t == NULL || key == NULL)
		return NULL;

	unsigned int ai = hash_function(key, t->arr_size);
	htab_listitem_t* iter = t->array[ai];
	htab_listitem_t* prev_item = NULL;
	while(iter != NULL) {
		if(strcmp(iter->key, key) == 0) {
			iter->data++;
			return iter;
		}

		prev_item = iter;	
		iter = iter->next;
	}
	// item is not in the table - put it in the table
	htab_listitem_t* new_item = (htab_listitem_t*)malloc(sizeof(htab_listitem_t));
	if(new_item == NULL) 
		return NULL;
	new_item->key = (char*)malloc(sizeof(key) + 1);
	if(new_item->key == NULL) {
		free(new_item);
		return NULL;
	}
	strcpy(new_item->key, key);
	new_item->data = 1;
	new_item->next = NULL;
	if(prev_item == NULL) 
		t->array[ai] = new_item;
	else
		prev_item->next = new_item;
	t->n++;

	return new_item;
}
	
