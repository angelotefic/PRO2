/*
 * Created by angelotefic on 22 / 03 / 24.
 */


#include <malloc.h>
#include <string.h>
#include "user_list.h"
#include "song_list.h"

void createEmptyListU(tListU *U){
    *U = NULLU;//Iguala el puntero L a NULLU indicando que no hay más posiciones válidas
}

bool isEmptyListU(tListU U){
    return U == NULLU;//Devuelve true si la última posición de la lista es NULLU, indicando que la lista está vacía
}

bool createNodeU (tPosU *p){//Esta funcion comprueba si hay espacio en la memoria para crear otro nodo, de ser verdadero, devuelve true
    *p = malloc(sizeof(struct tNode));
    return *p != NULLU;
}

tPosU firstU(tListU U){
    return U;//Devuelve la primera posicion de la lista
}

tPosU lastU(tListU U){
    tPosU i;
    for (i = U; i->next != NULLU ; i = i->next);//Recorre la lista hasta llegar hasta el último elemento
    return i;
}

tPosU nextU(tPosU p, tListU U){
    return p->next;//Devuelve la siguiente posicion a p
}

tPosU previousU(tPosU p, tListU U){
    tPosU i;
    if(p == U){
        return NULLU;
    } else {
        for(i = U; i -> next != p; i = i->next);//Recorre la lista hasta llegar a la posición anterior a p
        return i;
    }
}

bool insertItemU(tItemU d, tListU *U) {
    tPosU q, i;
    if(!createNodeU(&q)){//Comprobamos si se puede crear un nuevo nodo
        return false;
    } else {
        q -> data = d;//Asignamos los valores dados a un nuevo nodo auxiliar
        q -> next = NULLU;

        if(isEmptyListU(*U)){
            *U = q;//Si las lista está vacia lo añade a la primera posicion

        } else if(strcmp(q->data.userName, (*U)->data.userName) < 0){//Si se quiere insertar en el primer elemento de la lista
            q -> next = *U;
            *U = q;
        }else {
            for (i = *U; i->next != NULLU && strcmp(q->data.userName, i->next->data.userName) > 0; i = i->next);//Se recorre la lista en busca del primer elemento con el userName solicitado
            q -> next = i -> next;
            i-> next = q;
        }
        return true;
    }
}

tItemU getItemU (tPosU p, tListU U){
    return p->data;//Devuelve el elemento de la lista que se encuentra en la posicón p
}

void updateItemU (tItemU d, tPosU p, tListU *U){
    p -> data = d;//Actualiza el elemento de la posicion p al elemento d
}

void deleteAtPositionU(tPosU p, tListU* U){
    tPosU q, i;
    if(p == *U){//Si se quiere eliminar el primer elemento
        *U = p->next;
    } else if(p == NULLU){//Si se quiere eliminar el último elemento
        for (i = *U; i->next != NULLU ; i = i->next);//Recorre la lista hasta llegar a la penúltima posicion
        i -> next = NULLU;
    }   else {
        q = p->next;//Empleamos una posicón auxiliar donde guardaremos el elemento siguiente a p
        for (i = *U; i->next != p ; i = i->next);//Recorremos la lista hasta el elemento anterior a p
        i->next = q;//Igualamos el elemento anterior a p a q
    }
    free(p);//Liberamos p
}

tPosU findItemU (tUserName n, tListU L) {
    if (isEmptyListU(L)) {
        return NULLU;//Si la lista está vacia devuelve la posicion NULLU
    } else {
        tPosU i;
        for (i = L; i->next != NULLU && strcmp(n, i->data.userName) > 0; i = i->next);//Se recorre la lista en busca del primer elemento con el userName solicitado
        if(strcmp(n, i->data.userName) == 0) {//Se comprueba si el elemento de la posición i coincide con el userName introducido
            return i;
        } else {
            return NULLU;
        }
    }
}




