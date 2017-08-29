/**
 * Collection of functions for hash table
 */
#ifndef HTAB_H
#define HTAB_H
#include <stddef.h>
#include <stdbool.h>

typedef struct htab_listitem htab_listitem_t;

/**
 * Item of the hash table
 */ 
struct htab_listitem {
	char* key;	
	unsigned int data;
	htab_listitem_t* next;
};

/**
 * Hash table
 */
typedef struct htab {
	size_t arr_size;   /**< size of the array of the pointers **/
	size_t n; 			 /**< number of items in hash table **/
	htab_listitem_t* array[]; /**< array of pointers items **/
} htab_t;

/**
 * Creates and initializes hash table
 * In case of failure returns NULL
 * @param size size of the hash table array
 * @return created hash table
 */
htab_t* htab_init(size_t size);

/**
 * Creates new hash table and fills it with the items from given hash table.
 * Original hash table is cleared of all items.
 * In case of failure returns NULL, and doesn't change the original hash table
 * @param newsize size of the new hash table
 * @param t2 hash table to be moved and cleared
 * @return new hash table
 */
htab_t* htab_move(size_t newsize, htab_t* t2);

/**
 * Returns number of items in the  hash table
 * If t is NULL returns 0
 * @param t hash table in question
 * @return number of items in hash table
 */
size_t htab_size(htab_t* t);

/**
 * Returns size of the array of the hash table
 * If t is NULL returns 0
 * @param t hash table
 * @return size of the array of the hash table
 */
size_t htab_bucket_count(htab_t* t);

/**
 * Searches for item in hash table and if its
 * found than increases the data by 1, if not than creates new item
 * In case of failure returns NULL 
 * @param t hash table
 * @param key item which is searched for
 * @return founded item in the table
 */
htab_listitem_t* htab_lookup_add(htab_t* t, const char* key);

/** 
 * Searches for item in hash table and returns it.
 * If item is not in the table returns NULL.
 *
 * @param t hash table
 * @param key item to be found
 * @return item from the hash table
 */
htab_listitem_t* htab_find(htab_t* t, const char* key);

/**
 * Calls function for every item in hash table.
 * Doesn't change the content of the hash table.
 * @param t hash table
 * @param function pointer to function which takes 2 parameters
 */
void htab_foreach(htab_t* t, void (*function)(const char* key, unsigned int value));

/**
 * Removes item frmo the hash table.
 * If item was found and removed returns true, othrewise returns false
 * @param t hash table
 * @param key key of the item
 */
bool htab_remove(htab_t* t, const char* key);

/**
 * Removes all the items from the hash table. Keeps the hash table empty.
 * @param t hash table to be cleared
 **/
void htab_clear(htab_t* t);

/**
 * Removes all the items from the hash table and then removes 
 * hash table itself
 * @param hash table to be erased
 */
void htab_free(htab_t* t);

/**
 * Returns and index into the array of the hash table.
 * @param key key of the item
 * @param htab_size size of the array of the hash table
 */
unsigned int hash_function(const char* key, size_t htab_size);

#endif
