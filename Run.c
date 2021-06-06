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
    printf("Int Array: ");
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
    printf("\n");
}

void DLtime(){ //bendzsi
    int searchable[3] = {1,2,3};

    DynamicList *list = createDL();
    fillList(&list, elements, N);
    printf("Dynamic List: ");
    for (int i = 0; i < 3; ++i) {
        clock_t start, end;
        double elapsed;
        start = clock();

        searchInList(list,searchable[i]);

        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        table[i][0] = elapsed;
        printf(" %lf ",table[i][1]);
    }
    printf("\n");
}

void HTtime(){ //imola
    int searchable[3] = {1,2,3};

    capacity=N;
    createHT();


    for(int i=0;i<N;i++){
        //insertHT(key[i],elements[i]); mi kell legyen a key?
        //Maga a hashtable.
    }
    printf("Hash Table: ");
    for (int i = 0; i < 3; ++i) {
        clock_t start, end;
        double elapsed;
        start = clock();

        //search(key); es itt?
        //Ez a keresés nem jó. Át kell adni először is a hashtable-t, majd a keresett elemet.

        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        table[i][2] = elapsed;
        printf(" %lf ",table[i][2]);
    }
    printf("\n");
}

void Htime(){ //imola
    int searchable[3] = {1,2,3};

    HEAP heap;
    createH(&heap);

    for(int i=0;i<N;i++){
        Insert(&heap,elements[i]);
    }
    printf("Heap: ");
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
    printf("\n");
}

void BSTtime(){ //bendzsi
    int searchable[3] = {1,2,3};

    Node *BinTree = NULL;
    fillingUp(&BinTree, elements, N);
    printf("Binary Search Tree: ");
    for (int i = 0; i < 3; ++i) {
        clock_t start, end;
        double elapsed;
        start = clock();

        searchNode(BinTree, searchable[i]);

        end = clock();
        elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
        table[i][0] = elapsed;
        printf(" %lf ",table[i][4]);
    }
    printf("\n");
}