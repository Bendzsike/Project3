//
// Created by Benjamin on 2021. 03. 11..
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#ifndef LABOR2_ARRAY_H
#define LABOR2_ARRAY_H

typedef struct{
    int size;
    int *elements;
}intArray;

//tömb létrehozása
//calloc vagy malloc használata
void createArray(intArray *array);
//tömb tartalmának beolvasása állományból
void readArray(const char *fileName, intArray* array);
//tömb tartalmának véletlenszámokkal való feltöltése
void fillArray(intArray* array, int first, int last);
//tömb tartalmának kiiratása a képernyőre
void printArray(intArray array);
//tömb tartalmának kiiratása állományba
void printArrayToFile(const char* fileName, intArray array);
//tömb rendezése tetszőleges algoritmussal
void sortArray(intArray* array);
//egy adott elem keresése lineáris vagy bináris kereséssel
//a függvény pozíciót térítsen vissza, ha nincs benne az keresett elem, akkor -1 et
int findElement(intArray array, int element);
//töröl egy adott értéket a tömbből (összes előfordulását)
//csökkenti a tömb hosszát
void deleteElement(intArray* array, int element);
//visszatéríti a tömb legkisebb elemét
int minimum(intArray array);
//visszatéríti a tömb legnagyobb elemét
int maximum(intArray array);
//átmásolja az egyik tömb tartalmát egy másik tömbbe
//csak akkor engedélyezett a másolás, amennyiben a másolandó
//tömb hossza <= mint annak a tömbnek a hossza, ahova másolunk
void copy(intArray *array1, intArray array2);
//lineáris keresés
int linearSearch(intArray array, int element);
//bináris keresés
int binarySearch(intArray array, int element);

#endif //LABOR2_ARRAY_H
