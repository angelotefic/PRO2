/*
 * Created by angelotefic on 02 / 02 / 25.
 */

#include "static_list.h"
#include <string.h>

bool isEmptyList(tList L) {
    return L.lastPosition == LNULL;
}

void createEmptyList(tList *L) {
    L->lastPosition = LNULL;
}

bool insertItem(tItemL d, tPosL p, tList *L) {
    tPosL i;

    if(L->lastPosition == MAX - 1) { // Comprueba si la lista está llena
        return false;
    } else {
        L->lastPosition++; // El tamaño de la lista aumenta en 1
        if(p == LNULL) { // Si se quiere insertar en la última posición
            L->data[L->lastPosition] = d;
        } else { 
            for(i = L->lastPosition; i > p; i--) {
                L->data[i] = L->data[i - 1];
            }
            L->data[p] = d;
        }
        return true;
    }
}

void updateItem(tItemL d, tPosL p, tList *L) {
    L->data[p] = d;
}

tPosL findItem(tItemL d, tList L) {
    tPosL p;
    if(isEmptyList(L)) {
        return LNULL;
    } else {
        for(p = 0; (p < L.lastPosition) && (L.data[p] != d); p++);
        if(L.data[p] == d) {
            return p;
        } else {
            return LNULL;
        }
    }
}

tItemL getItem(tPosL p, tList L) {
    return L.data[p];
}

tPosL first(tList L) {
    return 0; // Como una lista estática es un array, la primera posición será 0
}

tPosL last(tList L) {
    return L.lastPosition;
}

tPosL previous(tPosL p, tList L) {
    return --p;
}

tPosL next(tPosL p, tList L) {
    if (p == L.lastPosition) {
        return LNULL;
    } else {
        return ++p;
    }
}

void deleteAtPosition(tPosL p, tList* L){
    tPosL i;
    // Desplaza todos los elementos una posición hacia el inicio de la lista
    for(i = p; i < L-> lastPosition; i++){ 
        L -> data[i] = L -> data [i+1];
    }
    L -> lastPosition--;//Reduce en 1 el tamaño total de la lista
}

