/*
 * Created by angelotefic on 02 / 02 / 25.
 */


#include "dynamic_list.h"
#include <stdlib.h>
#include <string.h>


void createEmptyList(tList *L) { 
    *L = LNULL; 
} 
 
bool isEmptyList(tList L) { 
    return (L == LNULL); 
} 
 
bool createNode(tPosL *p) { 
    *p = malloc(sizeof(tNode)); 
    return *p != LNULL; 
} 
 
tPosL findItem(tItemL d, tList L) { 
    tPosL p; 
    for(p = L; (p != LNULL) && (p->data != d); p = p->next); 
    // Se comprueba que el contenido de la posición p es el buscado 
    if (p -> data == d) { 
        return p; 
    } else { 
        return LNULL; 
    } 
} 
 
tItemL getItem(tPosL p, tList L) { 
    return p->data; 
} 
 
void updateItem(tItemL d, tPosL p, tList *L) { 
    p->data = d; 
} 
 
 
bool insertItem(tItemL d, tPosL p, tList *L) { 
    tPosL q, r; 
    if(!createNode(&q)) { 
        return false; 
    } else { 
        q->data = d; 
        q->next = LNULL; 
        if (isEmptyList(*L)) { // CASO 1: LISTA VACIA 
            *L = q; 
        } else if(p == LNULL) { // CASO 2: ULTIMA POSICION DE LA LISTA 
            // Recorremos el bucle hasta la última posición  
            for(r = *L; r -> next != LNULL; r = r->next);  
            r -> next = q; 
        } else if(p == *L) { // CASO 3: PRIMERA POSICION DE LA LISTA 
            q -> next = p; 
            *L = q; 
        } else { // CASO 4: DENTRO DE LA LISTA 
            q->data = p->data; 
            p->data = d; 
            q->next = p->next; 
            p->next = q; 
        } 
        return true; 
    } 
} 
 
tPosL first(tList L) { 
    return L; // L apunta al primer elemento de la lista 
} 
 
 
tPosL next(tPosL p, tList L) { 
    return p->next; 
} 
 
tPosL last(tList L) { 
    tPosL p; 
    // Recorre la lista hasta la última posición 
    for(p = L; p->next != LNULL; p = p->next);  
    return p; 
} 
 
tPosL previous(tPosL p, tList L) { 
    tPosL q; 
    if(p == L) { 
        return LNULL; 
    } else { 
        for(q = L; q->next != p; q = q->next); 
        return q; 
    } 
} 
 
void deleteAtPosition(tPosL p, tList *L) { 
    tPosL q; 
    if(p == *L) { // Se elimina el primer elemento de la lista 
        *L = (*L)->next; 
    } else if (p->next == LNULL) { // Se elimina el elemento de la última posición 
        for(q = *L; q-> next-> next != LNULL; q = q->next); 
        q->next = LNULL; 
    } else {  
        q = p->next; 
        p->data = q->data; 
        p->next = q->next; 
        p = q; 
    } 
    free(p); 
} 
