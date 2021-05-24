//
// Created by Imola on 5/24/2021.
//

#include "Heap.h"

void Create(HEAP *heap){
    (*heap).size = 0;
    (*heap).elements = (int*)malloc(0*sizeof(int));
    if((*heap).elements==NULL){
        printf("Couldn't allocate memory.\n");
        exit(-1);
    }
}

void Insert(HEAP *heap, int key){
    if(heap==NULL){
        Create(&heap);
    }
    (*heap).size++;
    (*heap).elements = (int*)realloc((*heap).elements, (*heap).size*sizeof(int));
    if((*heap).elements==NULL){
        printf("Couldn't allocate memory.\n");
        exit(-1);
    }
    (*heap).elements[(*heap).size-1] = key;
    Lift(heap, (*heap).size - 1);
}

void Lift(HEAP *heap, int i){
    while(i >= 0 && (*heap).elements[i/2] < (*heap).elements[i]){
        Swap(&((*heap).elements[i / 2]), &(*heap).elements[i]);
        i/=2;
    }
}

void Swap(int *a, int *b){
    int aux;
    aux = (*a);
    (*a) = (*b);
    (*b) = aux;
}

int Top(HEAP heap){
    return heap.elements[0];
}

void PrintHeap(HEAP heap){
    for (int i = 0; i < heap.size; ++i) {
        printf("%d ", heap.elements[i]);
    }
}

void Sullyesztes(HEAP *heap, int i){
    int j;
    while(2*i<(*heap).size){
        j = 2*i;
        if(j<(*heap).size-1 && (*heap).elements[j]<(*heap).elements[j+1]){
            j += 1;
        }
        if((*heap).elements[j]<=(*heap).elements[i]){
            break;
        }
        Swap(&(*heap).elements[i], &(*heap).elements[j]);
        i = j;
    }
}

void Delete(HEAP *heap){
    printf("\nlegfelso: %d\n", Top(*heap));
    Swap(&(*heap).elements[0], &(*heap).elements[(*heap).size - 1]);
    --(*heap).size;
    (*heap).elements = (int*)realloc((*heap).elements, sizeof(int)*(*heap).size);
    Sullyesztes(heap, 0);
}

void IncreaseDataAtIndex(HEAP* mH, int index, int value){
    if ( index >= 0 && index < (*mH).size ) {
        (*mH).elements[index] = value;
        if ( (*mH).elements[index/2] < value ) {
            Lift(mH, index);
        } else Sullyesztes(mH, index);
    }
}

void MergeHeaps(HEAP* h1, HEAP* h2){
    for (int i = 0; i < (*h2).size; ++i) {
        Insert(h1, (*h2).elements[i]);
    }

    (*h2).size = 0;
    free((*h2).elements);
}
