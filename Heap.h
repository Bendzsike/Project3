//
// Created by Imola on 5/24/2021.
//

#ifndef PROJECT_3_HEAP_H
#define PROJECT_3_HEAP_H
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int size, *elements;
}HEAP;

void createH(HEAP *heap);
void Insert(HEAP *heap, int key);
void Lift(HEAP *heap, int i);
void Sink(HEAP *heap, int i);
void Swap(int *a, int *b);
int Top(HEAP heap);
void PrintHeap(HEAP heap);
void Delete(HEAP *heap);
void IncreaseDataAtIndex(HEAP* mH, int index, int value);
void MergeHeaps(HEAP* h1, HEAP* h2);

#endif //PROJECT_3_HEAP_H
