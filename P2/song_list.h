/*
 * Created by angelotefic on 22 / 03 / 24.
 */

#ifndef SONG_LIST_H
#define SONG_LIST_H

#include "types.h"

#define NULLS -1
#define MAX 25

typedef int tPosS;

typedef tSong tItemS;

typedef struct tListS{
    tPosS lastPosition;
    tItemS data[MAX];
} tListS;


void createEmptyListS(tListS* S);
/*
 Objetivo: Crear una lista vacía
 Entradas: Una puntero a una lista
 Salidas: Devuelve una lista inicializada
 Poscondición: La lista inicializada no contiene elementos
 */

bool isEmptyListS(tListS S);
/*
 Objetivo: Comprueba si la lista está vacía
 Entradas: Una lista
 Salidas: Elemento booleano indicando si la lista está vacía o no, true si está vacía false si no lo está
 */

tPosS firstS(tListS S);
/*
 Objetivo: Devuelve la primera posicion de una lista
 Entradas: Una lista
 Salidas: Primera posicion de la lista
 Precondición: La lista no está vacía
 */

tPosS lastS(tListS S);
/*
 Objetivo: Devuelve la última posición de una lista
 Entradas: Una lista
 Salidas: Última posición de la lista
 Precondición: La lista no está vacía
 */

tPosS nextS(tPosS p, tListS S);
/*
 Objetivo: Devuelve la posición posterior a una dada
 Entradas: Una lista y una posición
 Salidas: Devuelve la posición siguiente a la dada
 Precondición: La posición dada es válida
 */

tPosS previousS(tPosS p, tListS S);
/*
 Objetivo: Devuelve la posición anterior a una dada
 Entradas: Una lista y una posición
 Salidas: Devuelve la posición previa a la dada
 Precondición: La posición dada es válida
 */

bool insertItemS(tItemS d, tPosS p, tListS* S);
/*
 Objetivo: Añade un elemento a una lista en la posición dada
 Entradas: Una lista, una posición y un elemento
 Salidas: Devuelve la lista modificada con el nuevo elemento añadido
 Precondición: La posición dada es válida o tambien puede ser nula
 Poscondición: Las posiciones de los elementos posteriores podrían verse modificadas
 */

void deleteAtPositionS(tPosS p, tListS* S);
/*
 Objetivo: Elimina el elemento que se encuentra en la posicion introducida en una lista
 Entradas: Una lista y una posición
 Salidas: Devuelve la lista modificada con el elemento eliminado
 Precondición: La posición dada es válida
 Poscondición: La posicion de los elementos pueden variar
 */

tItemS getItemS (tPosS p, tListS S);
/*
 Objetivo: Devuelve el elemento que se encuentra en la posición dada
 Entradas: La posicion del elemento que se quiere devolver y la lista
 Salidas: Devuelve un elemento
 Precondición: La posición dada es válida
 */

void updateItemS (tItemS d, tPosS p, tListS* S);
/*
 Objetivo: Actualiza el elemento que se encuentra en la posicion indicada de la lista
 Entradas: El elemento actualizado, la posicion del elemento a cambiar, la lista
 Salidas: Devuelve la lista ya actualizada
 Precondición: La posición dada es válida
 Poscondición: El orden de los elementos de la lista no cambia
 */

tPosS findItemS (tSongTitle n, tListS S);
/*
 Objetivo: Encuentra la posición del primer elemento de la lista correspondiente al tSongTitle introducido
 Entradas: Una lista y el nombre de una cancion
 Salidas: Devuelve la posicion del elemento correspondiente al introducido, en el caso de que dicho elemento no se encuentre en la lista devuelve NULLS
 */



#endif
