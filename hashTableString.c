//
// Created by Noémie on 11/05/2020.
//

#include "hashTableString.h"

// Creates a hashtable of size "buckets", initializes each position to -1 and items to 0
struct HashTable* createEmptyHashTable(int buckets){
    struct HashTable *ht = malloc(sizeof(struct HashTable));
    if(ht!=NULL) {
        ht->items = 0;
        ht->buckets=buckets;
        ht->table= malloc((buckets)*sizeof(char*));
        if(ht->table!=NULL) {
            for (int i = 0; i < buckets; i++) {
                ht->table[i] = malloc((51) * sizeof(char));
                ht->table[i]=NULL;
            }
        }
    }
    return ht;
}

// Returns True if no items are in the table, False otherwise
bool isHashTableEmpty(struct HashTable* ht){
    if(ht!=NULL&&hashTableElements(ht)>0){
        return false;
    }
    return true;
}

// Returns the number of items present in the table
int hashTableElements(struct HashTable* ht){
    if(ht!=NULL){
        return ht->items;
    }
    return -1;
}

// Returns the hash of "value"
int hash_function(struct HashTable* ht, char* value){
    int size=strlen(value);
    int hash_val=0;
    for(int i=0;i<size;i++){
        hash_val=hash_val+value[i];
    }
    return abs(hash_val)%ht->buckets;
}

// If no collision, inserts "value" in the table and returns True, otherwise False
bool insert(struct HashTable* ht, char* value){
    int i=hash_function(ht,value);
    if(ht->table[i]==NULL){
        ht->table[i]=value;
        ht->items=ht->items+1;
        return true;
    }
    return false;
}

// Returns True if "value" exists in the table and False otherwise
bool exists(struct HashTable* ht, char* value){
    int hashIndex=hash_function(ht, value);
    if(ht->table[hashIndex]==value) {
        return true;
    }
    return false;
}

// Shows the whole content of the table and its number of items
void printHashTable(struct HashTable* ht){
    if(ht!=NULL) {
        /*for (int i = 0; i <=(ht->buckets);i++) {
            if (ht->table[i] != NULL) {
                printf("%s\n", ht->table[i]);
            }
        }*/
        for(int i=0; i<ht->buckets; i++){
            char* val =0;
            if(ht->table != 0) val = ht->table[i];

            if(val == NULL) printf("%d - NOT SET\n", i);
            else printf("%d - %s\n", i, val);
        }
    }
}

// If present, deletes the item "value" in the table
void deleteItem(struct HashTable* ht, char* value){
    if(ht!=NULL) {
        if(exists(ht, value)){
            int indice=hash_function(ht,value);
            ht->table[indice]=NULL;
            ht->items=ht->items-1;
        }
    }
}

// Deletes the whole content of the table
void deleteHashTable(struct HashTable* ht){
    for(int i=0;i<ht->buckets;i++){
        ht->table[i]=NULL;
    }
    ht->items=0;
    free(ht->table);
    free(ht);
}