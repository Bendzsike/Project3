//
// Created by Benjamin on 2021. 03. 11..
//

#include "IntArray.h"

void createArray(intArray *array) {
    (*array).elements = (int*)calloc((*array).size, sizeof(int));
}

void readArray(const char *fileName, intArray* array) {
    FILE *input = fopen(fileName, "rt");
    if(!input){
        printf("Error opening file!\n");
        exit(1);
    }
    fscanf(input, "%d", &(*array).size);
    createArray(&(*array));
    for(int i = 0; i < (*array).size; ++i) {
        fscanf(input, "%d", &(*array).elements[i]);
    }
    fclose(input);
}
void fillArray(intArray* array, int first, int last) {
    srand(time(NULL));
    for(int i = 0; i < (*array).size; ++i) {
        (*array).elements[i] = rand() % last + first;
    }
}

void printArray(intArray array) {
    for(int i = 0; i < array.size; ++i) {
        printf("%d ", array.elements[i]);
    }
    printf("\n");
}

void printArrayToFile(const char* fileName, intArray array) {
    FILE *output = fopen(fileName, "wt");
    for(int i = 0; i < array.size; ++i) {
        fprintf(output, "%d ", array.elements[i]);
    }
    fprintf(output, "\n");
}

int compare(const void *a, const void *b) {
    const int *first = (int *)a;
    const int *second = (int *)b;

    return(*first - *second);
}

void sortArray(intArray* array) {
    qsort((*array).elements, (*array).size, sizeof(int), compare);
}

int trueBinarySearch(intArray array, int left, int right, int element) {
    if(right >= left) {
        int middle = left + (right - left) / 2;
        if(array.elements[middle] == element) {
            return middle;
        }

        if(array.elements[middle] > element) {
            return trueBinarySearch(array, left, middle - 1, element);
        }
        return trueBinarySearch(array, middle + 1, right, element);
    }

    return -1;
}

int findElement(intArray array, int element) {
    trueBinarySearch(array, 0, array.size - 1, element);
}

void deleteElement(intArray* array, int element) {
    for(int i = 0; i < (*array).size; ++i) {
        if((*array).elements[i] == element) {
            (*array).elements[i] = (*array).elements[(*array).size - 1];
            --(*array).size;
        }
    }
}

int minimum(intArray array) {
    int minimum = array.elements[0];
    for(int i = 0; i < array.size; ++i) {
        if(minimum > array.elements[i]) {
            minimum = array.elements[i];
        }
    }
    return minimum;
}

int maximum(intArray array) {
    int maximum = array.elements[0];
    for(int i = 0; i < array.size; ++i) {
        if(maximum < array.elements[i]) {
            maximum = array.elements[i];
        }
    }
    return maximum;
}

void copy(intArray *array1, intArray array2) {
    if(array2.size > (*array1).size) {
        printf("Second array is bigger than first array!\n");
        exit(2);
    }

    for(int i = 0; i < array2.size; ++i) {
        (*array1).elements[i] = array2.elements[i];
    }
    (*array1).size = array2.size;
}

int linearSearch(intArray array, int element) {
    for(int i = 0; i < array.size; ++i) {
        if(array.elements[i] == element) {
            return i;
        }
    }
    return -1;
}

int binarySearch(intArray array, int element) {
    trueBinarySearch(array, 0, array.size - 1, element);
}