/*
 * Created by angelotefic on 20 / 02 / 24.
 */


#include "dynamic_list.h"
#include <stdlib.h>
#include <string.h>

void createEmptyList(tList *L){
    *L = LNULL;//Iguala el puntero L a LNULL indicando que no hay más posiciones válidas
}

bool isEmptyList(tList L){
    return L == LNULL;//Devuelve true si la última posición de la lista es LNULL, indicando que la lista está vacía
}

bool createNode (tPosL *p){//Esta funcion comprueba si hay espacio en la memoria para crear otro nodo, de ser verdadero, devuelve true
    *p = malloc(sizeof(struct tNode));
    return *p != LNULL;
}

tPosL first(tList L){
    return L;//Devuelve la primera posicion de la lista
}

tPosL last(tList L){
    tPosL i;
    for (i = L; i->next != LNULL ; i = i->next);//Recorre la lista hasta llegar hasta el último elemento
    return i;
}

tPosL next(tPosL p, tList L){
    return p->next;//Devuelve la siguiente posicion a p
}

tPosL previous(tPosL p, tList L){
    tPosL i;
    if(p == L){
        return LNULL;
    } else {
        for(i = L; i -> next != p; i = i->next);//Recorre la lista hasta llegar a la posición anterior a p
        return i;
    }
}

bool insertItem(tItemL d, tPosL p, tList *L){
    tPosL q, i;
    if(!createNode(&q)){//Comprobamos si se puede crear un nuevo nodo
        return false;
    } else {
        q -> data = d;//Asignamos los valores dados a un nuevo nodo auxiliar
        q -> next = LNULL;

        if(isEmptyList(*L)){
            *L = q;//Si las lista está vacia lo añade a la primera posicion

        } else if(p==LNULL){
            for (i = *L; i -> next != LNULL ; i = i->next);//Recorre la lista hasta llegar al ultimo elemento
            i -> next = q;

        } else if(p==*L){//Si se quiere insertar en el primer elemento de la lista
            q -> next = *L;
            *L = q;

        }  else {
            for (i = *L; i->next != p ; i = i->next);//Recorre la lista hasta llegar a la posicion anterior a p
            q -> next = p;
            i -> next = q;
        }
        return true;
    }
}

tItemL getItem (tPosL p, tList L){
    return p->data;//Devuelve el elemento de la lista que se encuentra en la posicón p
}

void updateItem (tItemL d, tPosL p, tList *L){
    p -> data = d;//Actualiza el elemento de la posicion p al elemento d
}

void deleteAtPosition(tPosL p, tList * L){
    tPosL q, i;
    if(p == *L){//Si se quiere eliminar el primer elemento
        *L = p->next;
    } else if(p == LNULL){//Si se quiere eliminar el último elemento
        for (i = *L; i->next != LNULL ; i = i->next);//Recorre la lista hasta llegar a la penúltima posicion
        i -> next = LNULL;
    }   else {
        q = p->next;//Empleamos una posicón auxiliar donde guardaremos el elemento siguiente a p
        for (i = *L; i->next != p ; i = i->next);//Recorremos la lista hasta el elemento anterior a p
        i->next = q;//Igualamos el elemento anterior a p a q
    }
    free(p);//Liberamos p
}

tPosL findItem (tUserName n, tList L) {
    if (isEmptyList(L)) {
        return LNULL;//Si la lista está vacia devuelve la posicion LNULL
    } else {
        tPosL i;
        for (i = L; i->next != LNULL && strcmp(n, i->data.userName) != 0; i = i->next);//Se recorre la lista en busca del primer elemento con el userName solicitado
        if(strcmp(n, i->data.userName) == 0) {//Se comprueba si el elemento de la posición i coincide con el userName introducido
            return i;
        } else {
            return LNULL;
        }
    }
}




