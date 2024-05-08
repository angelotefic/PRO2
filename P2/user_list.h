/*
 * Created by angelotefic on 22 / 03 / 24.
 */

#ifndef USER_LIST_H
#define USER_LIST_H

#include "types.h"
#include "song_list.h"

#define NULLU NULL

typedef struct tNode* tPosU;

typedef struct tItemU {
    tUserName userName;
    tPlayTime totalPlayTime;
    tUserCategory userCategory;
    tListS songList;
} tItemU;

typedef struct tNode{
    tItemU data;
    tPosU next;
} tNode;

typedef tPosU tListU;


void createEmptyListU(tListU* U);
/*
 Objetivo: Crear una lista vacía
 Entradas: Un puntero a una lista
 Salidas: Devuelve una lista inicializada
 Poscondición: La lista inicializada no contiene elementos
 */

bool isEmptyListU(tListU U);
/*
 Objetivo: Comprueba si la lista está vacía
 Entradas: Una lista
 Salidas: Elemento booleano inidcando si la lista está vacía o no, true si está vacía false si no lo está
 */

tPosU firstU(tListU U);
/*
 Objetivo: Devuelve la primera posicion de una lista
 Entradas: Una lista
 Salidas: Primera posicion de la lista
 Precondición: La lista no está vacía
 */

tPosU lastU(tListU U);
/*
 Objetivo: Devuelve la última posición de una lista
 Entradas: Una lista
 Salidas: Última posición de la lista
 Precondición: La lista no está vacía
 */

tPosU nextU(tPosU p, tListU U);
/*
 Objetivo: Devuelve la posición posterior a una dada
 Entradas: Una lista y una posición
 Salidas: Devuelve la posición siguiente a la dada
 Precondición: La posición dada es válida
 */

tPosU previousU(tPosU p, tListU U);
/*
 Objetivo: Devuelve la posición anterior a una dada
 Entradas: Una lista y una posición
 Salidas: Devuelve la posición previa a la dada
 Precondición: La posición dada es válida
 */

bool insertItemU(tItemU d, tListU *U);
/*
 Objetivo: Añade un elemento a una lista ordenada, en su posición correspondiente
 Entradas: Una lista y un elemento
 Salidas: Devuelve la lista modificada con el nuevo elemento añadido
 Poscondición: Las posiciones de los elementos pueden variar
 */

void deleteAtPositionU(tPosU p, tListU *U);
/*
 Objetivo: Elimina el elemento que se encuentra en la posicion introducida en una lista
 Entradas: Una lista y una posición
 Salidas: Devuelve la lista modificada con el elemento eliminado
 Precondición: La posición dada es válida
 Poscondición: Las posiciones de los elementos posteriores al eleminado pueden verse modificadas
 */

tItemU getItemU(tPosU p, tListU U);
/*
 Objetivo: Devuelve el elemento que se encuentra en la posición dada
 Entradas: La posicion del elemento que se quiere devolver y la lista
 Salidas: Devuelve un elemento
 Precondición: La posición dada es válida
 */

void updateItemU (tItemU d, tPosU p, tListU *U);
/*
 Objetivo: Actualiza el elemento que se encuentra en la posicion indicada de la lista
 Entradas: El elemento actualizado, la posicion del elemento a cambiar, la lista
 Salidas: Devuelve la lista ya actualizada
 Precondición: La posición dada es válida
 Poscondición: El orden de los elementos de la lista no cambia
 */

tPosU findItemU (tUserName n, tListU U);
/*
 Objetivo: Encuentra la posición del primer elemento de la lista correspondiente al tUserName introducido
 Entradas: Una lista y un nombre de usuario
 Salidas: Devuelve la posicion del elemento correspondiente al introducido, en el caso de que dicho elemento no se encuentre en la lista devuelve NULLU
 */


#endif
