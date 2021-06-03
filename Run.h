#ifndef PROJECT_3_RUN_H
#define PROJECT_3_RUN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binarySearchTree.h"
#include "DynamicList.h"
#include "Heap.h"
#include "IntArray.h"
#include "hashTable.h"

#define N 200000000

double table[3][5];
int elements[N];

void generateElements();
void BSTtime();
void DLtime();
void HTtime();
void Htime();
void IAtime();

#endif //PROJECT_3_RUN_H