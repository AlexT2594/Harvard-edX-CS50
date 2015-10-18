/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>

#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
    char word[LENGTH + 1];
    struct node* next;
}node;

node* hashtable[27] = {NULL};

int hash(const char* word){
    int hash = 26;
    if(isalpha(word[0])){
        hash = tolower(word[0]) - 65;
    }
    return hash;
}

unsigned int Size = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int l = hash(word);
    if(hashtable[l] == NULL){
        return false;
    }
    char w[46];
    int i;
    int n = strlen(word);
    for(i = 0;i<n;i++){
        w[i] = tolower(word[i]);
    }
    w[n] = '\0';
    node* aux = hashtable[l];
    while(aux!=NULL){
        if(strcmp(aux->word,w) == 0){
            return true;
        }
        aux = aux->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* file = fopen(dictionary,"r");
    
    char word[46];
    int l;
    while(fscanf(file,"%s",word)!=EOF){
        Size++;
        l = hash(word);
        if(hashtable[l] == NULL ){
            hashtable[l] = (node*)malloc(sizeof(node));
            strcpy(hashtable[l]->word,word);
            hashtable[l] -> next = NULL;
        }else{
            node* aux = (node*)malloc(sizeof(node));
            strcpy(aux->word,word);
            aux -> next = hashtable[l];
            hashtable[l] = aux;
        }
    }
    fclose(file);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if(Size == 0){
        return 0;
    }
    return Size;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for(int i = 0;i<27;i++){
        while(hashtable[i]!=NULL){
            node* temp = hashtable[i];
            hashtable[i] = hashtable[i]->next;
            free(temp);
        }
    }
    return true; 
}
