#ifndef INC_12_HASHTABLE_H
#define INC_12_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

struct set{
    int key;
    int data;
};
struct set *array;
int capacity;
int size;

int hashFunction(int );
int checkPrime(int );
int getPrime(int );
void create();
void insert(int , int );
void delete(int );
void search(int );
void display();
int sizeOfHashtable();
void freeHashTable();


#endif //INC_12_HASHTABLE_H