#include "Run.h"

void generateElements(){
    srand(time(NULL));
    elements[0] = 1;
    for (int i = 1; i < N-1; ++i) {
        int random = rand()%99+1;
        if (random == 3){
            --i;
            continue;
        }
        elements[i] = random;
    }
    elements[N-1] = 3;
}

void IAtime(){
    int searchable[3] = {1,2,3};

    intArray intArray1;
    intArray1.size = N;
    createArray(&intArray1);
    fillArray(&intArray1,elements);

    for (int i = 0; i < 3; ++i) {
        clock_t start, end;
        double elapsed;
        start = clock();

        linearSearch(intArray1,searchable[i]);

        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        table[i][0] = elapsed;
        printf(" %lf ",table[i][0]);
    }
}

void DLtime(){ //bendzsi

}

void HTtime(){ //imola
    int searchable[3] = {1,2,3};

    capacity=N;
    createHT();


    for(int i=0;i<N;i++){
        //insertHT(key[i],elements[i]); mi kell legyen a key?
    }

    for (int i = 0; i < 3; ++i) {
        clock_t start, end;
        double elapsed;
        start = clock();

        //search(key); es itt?

        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        table[i][2] = elapsed;
        printf(" %lf ",table[i][2]);
    }
}

void Htime(){ //imola
    int searchable[3] = {1,2,3};

    HEAP heap;
    createH(&heap);

    for(int i=0;i<N;i++){
        Insert(&heap,elements[i]);
    }

    for (int i = 0; i < 3; ++i) {
        clock_t start, end;
        double elapsed;
        start = clock();

        FindH(heap, searchable[i]);

        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        table[i][3] = elapsed;
        printf(" %lf ", table[i][3]);
    }
}

void BSTtime(){ //bendzsi

}