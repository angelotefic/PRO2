#ifndef LISTA_DINAMICA_H 
#define LISTA_DINAMICA_H 

#include <stdbool.h> 
#define LNULL NULL 

typedef int tItemL; 

typedef tNode *tPosL; 

typedef struct tNode { 
tItemL data; 
tPosL next; 
} tNode; 

typedef tPosL tList; 

void createEmptyList(tList *L); 
bool isEmptyList(tList L); 
bool createNode(tPosL *p); 
bool insertItem(tItemL d, tPosL p, tList *L); 
void updateItem(tItemL d, tPosL p, tList *L); 
tPosL findItem(tItemL d, tList L); 
tItemL getItem(tPosL p, tList L); 
tPosL first(tList L); 
tPosL last(tList L); 
tPosL previous(tPosL p, tList L); 
tPosL next(tPosL p, tList L); 
void deleteAtPosition(tPosL p, tList *L); 

#endif //LISTA_DINAMICA_H
