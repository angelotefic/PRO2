/*
 * Created by angelotefic on 22 / 03 / 24.
 */


#include "song_list.h"


#include <string.h>


void createEmptyListS(tListS* S){
    S->lastPosition = NULLS;//Iguala la última posicion a NULLS indicando que no hay más posiciones válidas
}

bool isEmptyListS(tListS S){
    return S.lastPosition == NULLS;//Devuelve true si la última posición de la lista es NULLS, indicando que la lista está vacía
}

tPosS firstS(tListS S){
    return 0;//Devuelve la primera posicion de la lista
}

tPosS lastS(tListS S){
    return S.lastPosition;//Devuelve la última posición de la lista
}

tPosS nextS(tPosS p, tListS S){
    if(p == S.lastPosition)//Comprueba si p es la última posición de la lista
        return NULLS;
    else
        return ++p;//Devuelve la siguiente posicion a p
}

tPosS previousS(tPosS p, tListS S){
    if(p == 0)//Comprueba si p es la primera posicion de la lista
        return NULLS;
    else
        return --p;//Devuelve la posición anterior a p
}

bool insertItemS(tItemS d, tPosS p, tListS* S){
    if(S -> lastPosition == MAX - 1 ){//Se comprueba si que la lista esté llena
        return false;
    } else {//Si no está llena
        tPosS i;//Creamos una posicion auxiliar
        S->lastPosition++;//Aumentamos en uno la ultima posicion
        if(isEmptyListS(*S) || p==NULLS){//Se comprueba si la lista está vacía o si la posición p es NULLS
            S->data[S->lastPosition] = d;//Se guarda el elemento d en la última posicion de la lista
        } else {
            for (i = S->lastPosition; i >= p; i--) {//Desplaza todos los elementos una posición hacia el final de la lista
                S->data[i] = S->data[i - 1];
            }
            S->data[p] = d;//Asgina el elemento dado a la posicion solicitada
        }
        return true;
    }
}

void deleteAtPositionS(tPosS p, tListS* S){
    tPosS i;
    for(i = p; i < S-> lastPosition; i++){//Desplaza todos los elementos una posición hacia el inicio de la lista
        S -> data[i] = S -> data [i+1];
    }
    S -> lastPosition--;//Reduce en 1 el tamaño total de la lista
}


tItemS getItemS (tPosS p, tListS S){
    return S.data[p];//Devuelve el elemento de la lista que se encuentra en la posicón p
}

void updateItemS (tItemS d, tPosS p, tListS* S){
    S -> data[p] = d;//Actualiza el elemento de la posicion p al elemento d
}

tPosS findItemS (tSongTitle n, tListS S){
    if(isEmptyListS(S)){
        return NULLS;//Si la lista está vacía devuelve la posición NULLS
    } else {
        tPosS i;
        for(i = 0; i<=S.lastPosition && strcmp(n, S.data[i].songTitle) != 0; i++);//Se recorre la lista en busca del primer elemento con el songTitle solicitado
        if(strcmp(n, S.data[i].songTitle) == 0) {//Se comprueba si el elemento de la posición i coincide con el songTitle introducido
            return i;
        }else{
            return NULLS;
        }
    }
}
