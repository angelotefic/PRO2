/*
 * Created by angelotefic on 20 / 02 / 24.
 */

#include "static_list.h"
#include <string.h>


void createEmptyList(tList* L){
    L->lastPosition = LNULL;//Iguala la última posicion a LNULL indicando que no hay más posiciones válidas
}

bool isEmptyList(tList L){
    return L.lastPosition == LNULL;//Devuelve true si la última posición de la lista es LNULL, indicando que la lista está vacía
}


tPosL first(tList L){
    return 0;//Devuelve la primera posicion de la lista
}

tPosL last(tList L){
    return L.lastPosition;//Devuelve la última posición de la lista
}

tPosL next(tPosL p, tList L){
    if(p == L.lastPosition)//Comprueba si p es la última posición de la lista
        return LNULL;
    else
        return ++p;//Devuelve la siguiente posicion a p
}

tPosL previous(tPosL p, tList L){
    if(p == 0)//Comprueba si p es la primera posicion de la lista
        return LNULL;
    else
        return --p;//Devuelve la posición anterior a p
}

bool insertItem(tItemL d, tPosL p, tList* L){
    if(L -> lastPosition == MAX - 1 ){//Se comprueba si que la lista esté llena (que la ultima posicion no sea igual al tamaño del array)
        return false;
    } else {//Si no está llena
        tPosL i;//Creamos una posicion auxiliar
        L->lastPosition++;//Aumentamos en uno la ultima posicion
        if(isEmptyList(*L) || p==LNULL){//Se comprueba si la lista está vacía o si la posición p es LNULL
            L->data[L->lastPosition] = d;//Se guarda el elemento d en la última posicion de la lista
        } else {
            for (i = L->lastPosition; i >= p; i--) {//Desplaza todos los elementos una posición hacia el final de la lista
                L->data[i] = L->data[i - 1];
            }
            L->data[p] = d;//Asgina el elemento dado a la posicion solicitada
        }
        return true;
    }
}

void deleteAtPosition(tPosL p, tList* L){
    tPosL i;
    for(i = p; i < L-> lastPosition; i++){//Desplaza todos los elementos una posición hacia el inicio de la lista
        L -> data[i] = L -> data [i+1];
    }
    L -> lastPosition--;//Reduce en 1 el tamaño total de la lista
}


tItemL getItem (tPosL p, tList L){
    return L.data[p];//Devuelve el elemento de la lista que se encuentra en la posicón p
}

void updateItem (tItemL d, tPosL p, tList* L){
    L -> data[p] = d;//Actualiza el elemento de la posicion p al elemento d
}

tPosL findItem (tUserName n, tList L){
    if(isEmptyList(L)){
        return LNULL;//Si la lista está vacía devuelve la posición LNULL
    } else {
        tPosL i;
        for(i = 0; i<=L.lastPosition && strcmp(n, L.data[i].userName) != 0; i++);//Se recorre la lista en busca del primer elemento con el userName solicitado
        if(strcmp(n, L.data[i].userName) == 0) {//Se comprueba si el elemento de la posición i coincide con el userName introducido
            return i;
        }else{
            return LNULL;
        }
    }
}
