//
// Created by Noémie on 11/05/2020.
//

#ifndef TP15_1_HASHTABLESTRING_H
#define TP15_1_HASHTABLESTRING_H


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


struct HashTable {
    int items; // number of elements in the table
    int buckets; // table size
    char** table; // the array
};

// Creates a hashtable of size "buckets", initializes each position to NULL and items to 0
struct HashTable* createEmptyHashTable(int buckets);


// Returns True if no items are in the table, False otherwise
bool isHashTableEmpty(struct HashTable* ht);

// Returns the number of items present in the table
int hashTableElements(struct HashTable* ht);

// Returns the hash of "value"
int hash_function(struct HashTable* ht, char* value);

// If no collision, inserts "value" in the table and returns True, otherwise False
bool insert(struct HashTable* ht, char* value);

// Returns True if "value" exists in the table and False otherwise
bool exists(struct HashTable* ht, char* value);

// Shows the whole content of the table and its number of items
void printHashTable(struct HashTable* ht);

// If present, deletes the item "value" in the table
void deleteItem(struct HashTable* ht, char* value);

// Deletes the whole content of the table
void deleteHashTable(struct HashTable* ht);

#endif //TP15_1_HASHTABLESTRING_H
