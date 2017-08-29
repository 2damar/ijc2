#include <stdlib.h>
#include <string.h>
#include "htab.h"

bool htab_remove(htab_t* t, const char* key) {
	if(t == NULL || key == NULL)
		return false;
	
	unsigned int index = hash_function(key, t->arr_size);
	htab_listitem_t* iter = t->array[index];
	htab_listitem_t* prev_item = NULL;
	while(iter != NULL && strcmp(iter->key, key) != 0) {
		prev_item = iter;
		iter = iter->next;
	}
	
	// item is not in the table
	if(iter == NULL)
		return false;

	//fix pointers before removing item
	if(prev_item == NULL) 
		t->array[index] = NULL;
	else 
		prev_item->next = iter->next;
		
	//remove item
	free(iter->key);
	free(iter);
	t->n--;

	return true;
}
		

	
	
	
