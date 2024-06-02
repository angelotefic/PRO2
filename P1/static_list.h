/*
 * Created by angelotefic on 20 / 02 / 24.
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"

#define LNULL -1
#define MAX 25

typedef int tPosL;

typedef struct tList{
    tPosL lastPosition;
    tItemL data[MAX];

} tList;

void createEmptyList(tList* L);
/*
 Objetivo: Crear una lista vacía
 Entradas: Una puntero a una lista
 Salidas: Devuelve una lista inicializada
 Poscondición: La lista inicializada no contiene elementos
 */

bool isEmptyList(tList L);
/*
 Objetivo: Comprueba si la lista está vacía
 Entradas: Una lista
 Salidas: Elemento booleano inidcando si la lista está vacía o no, true si está vacía false si no lo está
 */

tPosL first(tList L);
/*
 Objetivo: Devuelve la primera posicion de una lista
 Entradas: Una lista
 Salidas: Primera posicion de la lista
 Precondición: La lista no está vacía
 */

tPosL last(tList L);
/*
 Objetivo: Devuelve la última posición de una lista
 Entradas: Una lista
 Salidas: Última posición de la lista
 Precondición: La lista no está vacía
 */

tPosL next(tPosL p, tList L);
/*
 Objetivo: Devuelve la posición posterior a una dada
 Entradas: Una lista y una posición
 Salidas: Devuelve la posición siguiente a la dada
 Precondición: La posición dada es válida
 */

tPosL previous(tPosL p, tList L);
/*
 Objetivo: Devuelve la posición anterior a una dada
 Entradas: Una lista y una posición
 Salidas: Devuelve la posición previa a la dada
 Precondición: La posición dada es válida
 */

bool insertItem(tItemL d, tPosL p, tList* L);
/*
 Objetivo: Añade un elemento a una lista en la posición anterior a la dada
 Entradas: Una lista, una posición y un elemento
 Salidas: Devuelve la lista modificada con el nuevo elemento añadido
 Precondición: La posición dada es válida o tambien puede ser nula
 Poscondición: Las posiciones de los elementos posteriores podrían verse modificadas
 */

void deleteAtPosition(tPosL p, tList* L);
/*
 Objetivo: Elimina el elemento que se encuentra en la posicion introducida en una lista
 Entradas: Una lista y una posición
 Salidas: Devuelve la lista modificada con el elemento eliminado
 Precondición: La posición dada es válida
 Poscondición: La posicion de los elementos pueden variar
 */

tItemL getItem (tPosL p, tList L);
/*
 Objetivo: Devuelve el elemento que se encuentra en la posición dada
 Entradas: La posicion del elemento que se quiere devolver y la lista
 Salidas: Devuelve un elemento
 Precondición: La posición dada es válida
 */

void updateItem (tItemL d, tPosL p, tList* L);
/*
 Objetivo: Actualiza el elemento que se encuentra en la posicion indicada de la lista
 Entradas: El elemento actualizado, la posicion del elemento a cambiar, la lista
 Salidas: Devuelve la lista ya actualizada
 Precondición: La posición dada es válida
 Poscondición: El orden de los elementos de la lista no cambia
 */

tPosL findItem (tUserName n, tList L);
/*
 Objetivo: Encuentra la posición del primer elemento de la lista correspondiente al tUserName introducido
 Entradas: Una lista y un nombre de usuario
 Salidas: Devuelve la posicion del elemento correspondiente al introducido, en el caso de que dicho elemento no se encuentre en la lista devuelve LNULL
 */

#endif
