#include "hashTable.h"

int hashFunction(int key){
    return (key % capacity);
}

int checkPrime(int n){
    if (n == 1 || n == 0){
        return 0;
    }
    for (int i = 2; i < n / 2; i++){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int getPrime(int n){
    if (n % 2 == 0){
        n++;
    }
    while (!checkPrime(n)){
        n += 2;
    }
    return n;
}

void create(){
    capacity = getPrime(capacity);
    array = (struct set *)malloc(capacity * sizeof(struct set));
    for (int i = 0; i < capacity; i++){
        array[i].key = 0;
        array[i].data = 0;
    }
}

void freeHashTable(){
    free(array);
    capacity = 0;
    size = 0;
}

void insert(int key, int data){
    int index = hashFunction(key);
    if (array[index].data == 0){
        array[index].key = key;
        array[index].data = data;
        size++;
        printf("\n Key (%d) has been inserted \n", key);
    }else if (array[index].key == key){
        array[index].data = data;
    }else{
        printf("\n Collision occured  \n");
    }
}

void delete(int key){
    int index = hashFunction(key);
    if (array[index].data == 0){
        printf("\n This key does not exist \n");
    }else{
        array[index].key = 0;
        array[index].data = 0;
        size--;
        printf("\n Key (%d) has been removed \n", key);
    }
}

void search(int k){
    int j, i = 0;
    do{
        j = (k+i) % sizeOfHashtable();
        if (array[j].key == k) {
            printf("\nKey found on index: %d\n",j);
            return;
        }else i++;
    }
    while ((array[j].key != -1) && (i != sizeOfHashtable()));
    printf("\nKey not found!\n");
}

void display(){
    for (int i = 0; i < capacity; i++){
        if (array[i].data == 0){
            printf("\n array[%d]: / ", i);
        }else{
            printf("\n array[%d]: %d \t",  i, array[i].data);
        }
    }
    printf("\n");
}

int sizeOfHashtable(){
    return size;
}