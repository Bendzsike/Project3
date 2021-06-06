//
// Created by Benjamin on 2021. 04. 23..
//

#ifndef LABOR_7_DYNAMICLIST_H
#define LABOR_7_DYNAMICLIST_H
#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicList{
    int info;
    struct DynamicList* next;
}DynamicList;

DynamicList* createDL();
void fillList(DynamicList**, int*, int);
void insertSorted(DynamicList**, int);
void addFirst(DynamicList**, int);
void addLast(DynamicList**, int);
int searchInList(DynamicList*, int);
void deleteFirst(DynamicList**);
void deleteLast(DynamicList**);
void deleteValue(DynamicList**, int);
void deleteAll(DynamicList**);
void freeNode(DynamicList**);
void printList(DynamicList*);

#endif //LABOR_7_DYNAMICLIST_H
