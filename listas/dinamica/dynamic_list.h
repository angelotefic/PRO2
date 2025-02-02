/*
 * Created by angelotefic on 02 / 02 / 25.
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include <stdbool.h>
#include <stdlib.h>

#define LNULL NULL

typedef int tItemL;

typedef struct tNode {
    tItemL data;
    struct tNode *next;
} tNode;

typedef tNode* tPosL;
typedef tPosL tList;

void createEmptyList(tList *L);
bool isEmptyList(tList L);
bool createNode(tPosL *p);
bool insertItem(tItemL d, tPosL p, tList *L);
void updateItem(tItemL d, tPosL p, tList *L);
tPosL findItem(tItemL d, tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p, tList L);
void deleteAtPosition(tPosL p, tList *L);

#endif // DYNAMIC_LIST_H
