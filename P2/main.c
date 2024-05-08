/*
 * Created by angelotefic on 22 / 03 / 24.
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "types.h"
#include "user_list.h"

#define MAX_BUFFER 255


void New (tListU *U, char *userName, char *category);
/*
Objetivo: Da de alta un usuario en la lista
Entradas: La lista, el nombre del usuario y su categoría (basic || pro)
Salidas: Devuelve una lista actualizada con el nuevo usuario con su numero de reproduciones a 0
Precondición: La lista esta incializada
Poscondición: El numero de posiciones totales de la lista aumenta en uno
*/


void Delete (tListU *U, char *userName);
/*
Objetivo: Da de baja a un usuario de la lista, eliminando tambien su lista de canciones
Entradas: La lista, el nombre del usuario que se quiere eliminar
Salidas: Devuelve una lista actualizada sin el usuario solicitado
Precondición: La lista esta incializada
Poscondición: Las posiciones totales de la lista se ven reducidas en uno
*/


void Upgrade (tListU *U, char *userName);
/*
Objetivo: se buscará al usuario en la lista, se actualizará su categoría a pro
Entradas: La lista, el nombre del usuario que se quiere actualizar
Salidas: Devuelve una lista actualizada con la categoría del usuario cambiada a pro
Precondición: La lista esta incializada
*/

void Play (tListU *U, char *userName, char *songTitle, char *playTime);
/*
Objetivo: se buscará al usuario en la lista y se le añadirá el tiempo de reprodución a su cancion correspondiente
Entradas: La lista, el nombre del usuario que se escucha, la cancion y el tiempo de reproducion de esa cancion
Salidas: Devuelve la lista con el numero de reproduciones del usuario actualizadas
Precondición: La lista esta incializada
*/

void Stats (tListU U);
/*
Objetivo: se mostrará por pantalla el numero de usuarios con cada categoría, el numero de canciones reproducidas por categoría y la media
Entradas: La lista
Salidas: Devuelve una "tabla" con el numero de usuarios de cada categoría, con su numero de reproduciones y la media de reproduciones entre usuarios según su categoría
Precondición: La lista esta incializada
Poscondición: El orden de los elementos de la lista no cambia
*/

void Add (tListU *U, char *userName, char *songTitle);
/*
Objetivo: Añade una cancion a la lista de canciones de un usuario
Entradas: La lista, el nombre del usuario al que se le quiere añdair una cancion, el titulo de la cancion
Salidas: Devuelve la lista de usuarios con la lista de canciones de su respectivo usuario actualizada, con el tiempo de reproduccion de la cancion incializado a 0
Precondición: La lista esta incializada
*/


void Remove (tListU *U, char *maxPlayTime);
/*
Objetivo: Eliminan los usuarios que hayan excedido el tiempo máximo de reproducion y la lista de canciones correspondientes a cada usuario
Entradas: La lista y el numero máximo de minutos
Salidas: Devuelve la lista de usuarios sin las canciones que duran más que los minutos introducidos
Precondición: La lista esta incializada
*/

char* toStringUserCategory (tUserCategory userCategory);
/*
Objetivo: Cambiará de tipo tUserCategory a tipo string la categoría del usuario
Entradas: Un elemento del tipo tUserCategory
Salidas: Un elemento de tipo string
*/

void deleteSongList(tItemU *user);
/*
Objetivo: Eliminará la lista de canciones del usuario
Entradas: Un usuario
Salidas: El usuario con la lista de canciones vacía
Precondicion: El usuario es valido
*/


void processCommand(tListU *U, char *commandNumber, char command, char *param1, char *param2, char *param3) {

    switch (command) {
        case 'N':
            printf("********************\n%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            New(U, param1, param2);
            break;
        case 'D':
            printf("********************\n%s %c: user %s\n", commandNumber, command, param1);
            Delete(U, param1);
            break;
        case 'A':
            printf("********************\n%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            Add(U, param1, param2);
            break;
        case 'U':
            printf("********************\n%s %c: user %s\n", commandNumber, command, param1);
            Upgrade(U, param1);
            break;
        case 'P':
            printf("********************\n%s %c: user %s song %s minutes %s\n", commandNumber, command, param1, param2, param3);
            Play(U, param1, param2, param3);
            break;
        case 'S':
            printf("********************\n%s %c:\n", commandNumber, command);
            Stats(*U);
            break;
        case 'R':
            printf("********************\n%s %c: maxtime %s\n", commandNumber, command, param1);
            Remove(U, param1);
            break;
        default:
            break;
    }
}

void New (tListU *U, char *userName, char *category){
    if(findItemU(userName, *U) == NULLU){//Comprobamos que el usuario no esté en la lista
        //creamos un usuario auxiliar que añadiremos a la lista
        tItemU user;
        strcpy(user.userName, userName);
        user.totalPlayTime = 0;
        if(strcmp(category, "basic")==0)
            user.userCategory = basic;
        else
            user.userCategory = pro;
        //Inicializamos la lista de canciones del usuario auxiliar
        createEmptyListS(&user.songList);

        //comprobamos si se puede insertar el usuario en la lista
        if(insertItemU(user, U)) {//Lo insertamos en la lista ordenada
            printf("* New: user %s category %s\n", user.userName, toStringUserCategory(user.userCategory));
        } else {//Si no se puede insertar imprime el error por pantalla
            printf("+ Error: New not possible\n");
        }
    } else {
        printf("+ Error: New not possible\n");
    }
}

char* toStringUserCategory (tUserCategory userCategory){
    if(userCategory == basic){
        return "basic";
    } else {
        return "pro";
    }
}

void deleteSongList(tItemU *user){
    tListS *S = (&(*user).songList);
    if(!isEmptyListS(*S)) {//Si la lista de canciones tiene elementos
        tPosS posS = firstS(*S);
        do {
            deleteAtPositionS(posS, S);//Se van eliminando uno a uno hasta que la lista esté vacia
        } while (!isEmptyListS(*S));
    }
}

void Delete (tListU *U, char *userName){
    tPosU p = findItemU(userName, *U);//Creamos una posición auxiliar en donde guardamos la posicion del elemento
    if(p == NULLU){//Se comprueba si el usuario no está en la lista, o si la lista está vacía
        printf("+ Error: Delete not possible\n");
    } else {
        tItemU user = getItemU(p, *U);//Se crea un elemento auxiliar
        deleteSongList(&user);//Se elimina la lista de canciones del usuario
        updateItemU(user, p, U);//Se actualiza el usuario en la lista (con la lista de canciones ya vacia)

        deleteAtPositionU(p, U);//Se elimina el elemento que se encuentra en la posicion p de la lista L
        printf("* Delete: user %s category %s totalplaytime %d\n", user.userName, toStringUserCategory(user.userCategory), user.totalPlayTime);
    }
}

void Upgrade (tListU *U, char *userName){
    tPosU p = findItemU(userName, *U);//Creamos una posición auxiliar en donde guardamos la posicion del usuario
    if(p == NULLU){//Se comprueba si el usuario no está en la lista, o si la lista está vacía
        printf("+ Error: Upgrade not possible\n");
    } else {
        tItemU d = getItemU(p, *U);//Creamos un elemento auxiliar que vamos a actualizar
        if(d.userCategory == pro){
            printf("+ Error: Upgrade not possible\n");
        } else {
            d.userCategory = pro;
            updateItemU(d, p, U);//Una vez modificada la categoría lo actualizamos en la lista
            printf("* Upgrade: user %s category %s\n", d.userName, toStringUserCategory(d.userCategory));
        }
    }
}

void Add (tListU *U, char *userName, char *songTitle){
    tPosU p = findItemU(userName, *U);
    if(p != NULLU){//Comprobamos que el elemento no esté en la lista o si la lista está vacía
        tItemU user = getItemU(p, *U);
        tListS *S = (&user.songList);//Se crea un puntero que apunta a la lista de canciones del usuario
        tPosS posS = findItemS(songTitle, *S);

        if(posS == NULLS){//Se comprueba si la cancion existe en la lista o si la lista de canciones está vacía
            tItemS song;
            strcpy(song.songTitle, songTitle);
            song.playTime = 0;
            if(insertItemS(song, NULLS, S)){//Se inserta y se comprueba si se inserta correctamente
                updateItemU(user, p, U);//Se actualiza el usuario con la nueva canción en su lista
                printf("* Add: user %s adds song %s \n", user.userName, song.songTitle);
            } else {
                printf("+ Error: Add not possible\n");
            }
        } else {
            printf("+ Error: Add not possible\n");
        }
    } else {
        printf("+ Error: Add not possible\n");
    }
}

void Play (tListU *U, char *userName, char *songTitle, char *playTime){
    tPosU p = findItemU(userName, *U);//Creamos una posición auxiliar en donde guardamos la posicion del usuario
    if(p == NULLU){//Se comprueba si el elemento no está en la lista, o si la lista está vacía
        printf("+ Error: Play not possible\n");
    } else {
        tItemU user = getItemU(p, *U);
        tListS *S = &(user.songList);//Se crea un puntero que apunta a la lista de canciones del usuario
        tPosS posS = findItemS(songTitle, *S);

        if(posS != NULLS){
            tItemS song = getItemS(posS, *S);
            tPlayTime min = atoi(playTime);//Se crea una variable donde se almacena el tiempo de escucha de la canción
            //Se incrementa el tiempo de escucha del usuario y de la cancion
            song.playTime +=  min;
            user.totalPlayTime += min;

            updateItemS(song, posS, S);
            updateItemU(user, p, U);
            printf("* Play: user %s plays song %s playtime %d totalplaytime %d\n", user.userName, song.songTitle, song.playTime, user.totalPlayTime);
        } else {
            printf("+ Error: Play not possible\n");
        }
    }
}

void Stats (tListU U){
    if(isEmptyListU(U)){
        printf("+ Error: Stats not possible\n");
    } else {

        tPosU p = firstU(U); // Creamos una posición auxiliar y la inicializamos a la primera posición de la lista de usuarios
        tItemU user; //Creamos un usuario auxiliar
        tListS S; //Creamos una variable auxiliar para almacenar la lista de canciones de cada usuario

        //Creamos e inicializamos a 0 los contadores que vamos a emplear
        int pCount = 0, bCount = 0, pPlay = 0, bPlay = 0;
        float pAverage, bAverage; // Creamos las variables donde vamos a almacenar las medias

        do {
            user = getItemU(p, U); // Obtiene al usuario actual de la lista
            S = user.songList;
            printf("User %s category %s totalplaytime %d\n", user.userName, toStringUserCategory(user.userCategory), user.totalPlayTime);
            if(isEmptyListS(S)){
                printf("No songs\n");
            } else{
                tItemS song;
                for(tPosS i = firstS(S); i != NULLS; i = nextS(i, S)){//Se recorre la lista de canciones para imprimir por pantalla que canciones tiene cada usuario
                    song = getItemS(i, S);
                    printf("Song %s playtime %d\n", song.songTitle, song.playTime);
                }
            }
            if(user.userCategory == basic){//Dependiendo de su categoría aumentamos los valores de los contadores de basic o de pro
                bCount++;
                bPlay += user.totalPlayTime;
            } else {
                pCount++;
                pPlay += user.totalPlayTime;
            }
            p = nextU(p, U); // Avanza a la siguiente posicion de la lista
            printf("\n");
        } while (p!=NULLU); // Continua hasta que llegue al final de la lista

        // Calculamos las medias:
        // Si el numero de usuarios es 0 se almacena un 0
        pAverage = (pCount != 0) ?  (float )pPlay/(float)pCount : 0;
        bAverage = (bCount != 0) ?  (float )bPlay/(float)bCount : 0;

        printf("Category  Users  TimePlay  Average\n"
               "Basic     %5d %9d %8.2f\n"
               "Pro       %5d %9d %8.2f\n", bCount, bPlay, bAverage, pCount, pPlay, pAverage);
    }
}

void Remove (tListU *U, char *maxPlayTime){
    if(isEmptyListU(*U)){//Se comprueba si el elemento no está en la lista, o si la lista está vacía
        printf("+ Error: Remove not possible\n");
    } else {
        tItemU user;
        int c = 0;//Se inicializa un contador que contará el numero de usuarios que se eliminan
        for(tPosU p = firstU(*U); p != NULLU; p = nextU(p, *U)){
            user = getItemU(p, *U);
            if(user.totalPlayTime > atoi(maxPlayTime) && user.userCategory==basic){//Se comprueba si el tiempo de reproduccion del usuario actual es mayor al maximo y si la categoría es basic
                deleteSongList(&user);//Se elimina la lista de canciones del usuario
                updateItemU(user, p, U);//Se actualiza el usuario en la lista (con la lista de canciones ya vacia)
                deleteAtPositionU(p, U);//Se elimina el elemento que se encuentra en la posicion p de la lista L
                c++;
                printf("Removing user %s totalplaytime %d\n", user.userName, user.totalPlayTime);
            }
        }
        if(c==0){//Si no se elimina ningun usuario imprime un error
            printf("+ Error: Remove not possible\n");
        }

    }
}

void readTasks(tListU *U, char *filename) {

    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);

            processCommand(U, commandNumber, command[0], param1, param2, param3);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    //Creamos e inicializamos la lista de usuarios
    tListU U;
    createEmptyListU(&U);

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(&U, file_name);

    return 0;
}
