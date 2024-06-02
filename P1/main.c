/*
 * Created by angelotefic on 20 / 02 / 24.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif


void New (tList *L, char *userName, char *category);
/*
Objetivo: Da de alta un usuario en la lista
Entradas: La lista, el nombre del usuario y su categoría (basic || pro)
Salidas: Devuelve una lista actualizada con el nuevo usuario con su numero de reproduciones a 0
Precondición: La lista esta incializada
Poscondición: El numero de posiciones totales de la lista aumenta en uno
*/

void Delete (tList *L, char *userName);
/*
Objetivo: Da de baja a un usuario de la lista
Entradas: La lista, el nombre del usuario que se quiere eliminar
Salidas: Devuelve una lista actualizada sin el usuario solicitado
Precondición: La lista esta incializada
Poscondición: Las posiciones totales de la lista se ven reducidas en uno
*/

void Upgrade (tList *L, char *userName);
/*
Objetivo: se buscará al usuario en la lista, se actualizará su categoría a pro
Entradas: La lista, el nombre del usuario que se quiere actualizar
Salidas: Devuelve una lista actualizada con la categoría del usuario cambiada a pro
Precondición: La lista esta incializada
*/

void Play (tList *L, char *userName, char *songTitle);
/*
Objetivo: se buscará al usuario en la lista y se le añadirá una reprodución
Entradas: La lista, el nombre del usuario que se escucha
Salidas: Devuelve la lista con el numero de reproduciones del usuario actualizadas
Precondición: La lista esta incializada
*/

void Stats (tList *L);
/*
Objetivo: se mostrará por pantalla el numero de usuarios con cada categoría, el numero de canciones reproducidas por categoría y la media
Entradas: La lista
Salidas: Devuelve una "tabla" con el numero de usuarios de cada categoría, con su numero de reproduciones y la media de reproduciones entre usuarios según su categoría
Precondición: La lista esta incializada
Poscondición: El orden de los elementos de la lista no cambia
*/

char* toStringUserCategory (tUserCategory userCategory);
/*
Objetivo: Cambiará de tipo tUserCategory a tipo string la categoría del usuario
Entradas: Un elemento del tipo tUserCategory
Salidas: Un elemento de tipo string
*/

void processCommand(tList *L, char *commandNumber, char command, char *param1, char *param2) {

    switch (command) {
        case 'N':
            printf("********************\n%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            New(L, param1, param2);
            break;
        case 'D':
            printf("********************\n%s %c: user %s\n", commandNumber, command, param1);
            Delete (L, param1);
            break;
        case 'U':
            printf("********************\n%s %c: user %s\n", commandNumber, command, param1);
            Upgrade(L, param1);
            break;
        case 'P':
            printf("********************\n%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            Play(L, param1, param2);
            break;
        case 'S':
            printf("********************\n%s %c:\n", commandNumber, command);
            Stats(L);
            break;
        default:
            break;
    }
}

void New (tList *L, char *userName, char *category){
    if(findItem(userName, *L) == LNULL){//Comprobamos que el elemento no esté en la lista
        //creamos un dato auxiliar que añadiremos a la lista
        tItemL d;
        strcpy(d.userName, userName);
        d.numPlay = 0;
        if(strcmp(category, "basic")==0)
            d.userCategory = basic;
        else
            d.userCategory = pro;

        //comprobamos si se puede insertar el elemento en la lista
        if(insertItem(d, LNULL, L)) {//Lo insertamos al final de la lista
            printf("* New: user %s category %s\n", d.userName, toStringUserCategory(d.userCategory));
        } else {//Si no se puede insertar imprime el error por pantalla
            printf("+ Error: New not possible\n");
        }
    } else {
        printf("+ Error: New not possible\n");
    }

}

void Delete (tList *L, char *userName){
    tPosL p = findItem(userName, *L);//Creamos una posición auxiliar en donde guardamos la posicion del elemento
    if(p == LNULL){//Se comprueba si el elemento no está en la lista, o si la lista está vacía
        printf("+ Error: Delete not possible\n");
    } else {
        tItemL d = getItem(p, *L);//Se crea un elemento auxiliar
        deleteAtPosition(p, L);//Se elimina el elemento que se encuentra en la posicion p de la lista L
        printf("* Delete: user %s category %s numplays %d\n", d.userName, toStringUserCategory(d.userCategory), d.numPlay);
    }
}

void Upgrade (tList *L, char *userName){
    tPosL p = findItem(userName, *L);//Creamos una posición auxiliar en donde guardamos la posicion del elemento
    if(p == LNULL){//Se comprueba si el elemento no está en la lista, o si la lista está vacía
        printf("+ Error: Upgrade not possible\n");
    } else {
        tItemL d = getItem(p, *L);//Creamos un elemento auxiliar que vamos a actualizar
        if(d.userCategory == pro){
            printf("+ Error: Upgrade not possible\n");
        } else {
            d.userCategory = pro;
            updateItem(d, p, L);//Una vez modificada la categoría lo actualizamos en la lista
            printf("* Upgrade: user %s category %s\n", d.userName, toStringUserCategory(d.userCategory));
        }
    }
}

void Play (tList *L, char *userName, char *songTitle){
    tPosL p = findItem(userName, *L);//Creamos una posición auxiliar en donde guardamos la posicion del elemento
    if(p == LNULL){//Se comprueba si el elemento no está en la lista, o si la lista está vacía
        printf("+ Error: Play not possible\n");
    } else {
        tItemL d = getItem(p, *L);//Creamos un elemento auxiliar
        tSongTitle song;
        strcpy(song, songTitle);
        d.numPlay++;//Incrementamos el numero de reproduciones
        updateItem(d, p, L);//Actualizamos el elemento en la lista
        printf("* Play: user %s plays song %s numplays %d\n", d.userName, song, d.numPlay);
    }
}

char* toStringUserCategory (tUserCategory userCategory){
    if(userCategory == basic){
        return "basic";
    } else {
        return "pro";
    }
}

void Stats (tList *L){
    if(isEmptyList(*L)){
        printf("+ Error: Stats not possible\n");
    } else {

        tPosL p = first(*L);//Creamos una posición auxiliar y la incializamos a la primera posicion de la lista
        tItemL d;//Creamos un elemento auxiliar

        //Creamos los contadores que vamos a emplear y los incializamos a 0
        //Contadores de la categoría pro: pCount (cuenta usuarios), pPlay (cuenta el numero de reproduciones), pAverage (calcula la media)
        //Contadores de la categoría basic: bCount (cuenta usuarios), bPlay (cuenta el numero de reproduciones), bAverage (calcula la media)
        int pCount = 0, bCount = 0, pPlay = 0, bPlay = 0;
        float pAverage, bAverage;//Creamos las variables donde vamos a almacenar las medias

        do {
            d = getItem(p, *L);//Obtiene el elemento actual de la lista

            printf("User %s category %s numplays %d\n", d.userName, toStringUserCategory(d.userCategory), d.numPlay);
            if(d.userCategory == basic){//Dependiendo de su categoría aumentamos los valores de basic o de pro
                bCount++;
                bPlay += d.numPlay;
            } else {
                pCount++;
                pPlay += d.numPlay;
            }
            p = next(p, *L);//Avanza a la siguiente posicion de la lista
        } while (p!=LNULL);//Continua hasta que llegue al final de la lista

        //Calculamos las medias:
        //Si el numero de usuarios es 0 devuelve 0
        pAverage = (pCount != 0) ?  (float )pPlay/(float)pCount : 0;
        bAverage = (bCount != 0) ?  (float )bPlay/(float)bCount : 0;


        printf("Category  Users  Plays  Average\n"
               "Basic     %5d %6d %8.2f\n"
               "Pro       %5d %6d %8.2f\n", bCount, bPlay, bAverage, pCount, pPlay, pAverage);
    }
}

void readTasks(tList *L, char *filename) {//Le pasamos la lista, ya creada e incializada en el main, por referencia
    FILE *f = NULL;

    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(L, commandNumber, command[0], param1, param2);//Le pasamos la lista por referencia al processCommand
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    //Creamos una lista y la inicializamos
    tList L;
    createEmptyList(&L);


    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(&L, file_name);//Pasamos la lista por referencia al readTasks

    return 0;
}




