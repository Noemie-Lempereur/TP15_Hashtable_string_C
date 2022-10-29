#include "hashTableString.h"
int main() {
    struct HashTable *ht =createEmptyHashTable(250);
    /*printf("%d",hash_function(ht,"carnivore"));
    printf("%s",ht->table[hash_function(ht,"carnivore")]);
    insert(ht,"carnivore");
    printf("%s",ht->table[hash_function(ht,"carnivore")]);
    printHashTable(ht);*/
    /*FILE* file = fopen("word.txt", "r");
    if(file == NULL) {
        return 0;
    }
    char name[500];
    int erreur=0;
    bool a=true;
    while(! feof(file)){
        fgets(name,499,file);
        name[strlen(name)-1]='\0';
        a=insert(ht,name);
        if(a==false){
            erreur++;
        }
    }
    printf("%d",erreur);
    printHashTable(ht);
    fclose(file);
    return 0;*/
    bool test;
    struct HashTableInt* map2 = createEmptyHashTable(100);

    FILE* fp = fopen("word.txt", "r");

    char* str= malloc(50*sizeof(char));
    bool test1=true;
    int count1 = 0;
    while(!feof(fp)){

        char* ch=fgetc(fp);

        if(ch == -1 ||ch ==13 || ch == 10){
            test= true;
            if(strlen(str)>0) test = insert(map2, str);
            if(test == false) count1++;
            str = malloc(50*sizeof(char));
        }else {
            str[strlen(str)] = ch;
        }
    }
    free(str);
    printHashTable(map2);
    printf("Il y a eu %d collision.", count1);

    deleteHashTable(map2);
    return 0;
}
