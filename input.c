//------------------------------------------------------------------------------
// input.c - единица компиляции, вбирающая в себя все функции ввода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

// Ввод параметров афоризма из файла
void InAphorism(void *a, FILE *ifst) {
    fscanf(ifst, "%s%s", (char*)a, (char*)(a + charSize));
}

// Ввод параметров поговорки из файла
void InProverb(void *p, FILE *ifst) {
    fscanf(ifst, "%s%s", (char*)p, (char*)(p + charSize));
}

// Ввод параметров загадки из файла
void InRiddle(void* r, FILE* ifst) {
    fscanf(ifst, "%s%s", (char*)r, (char*)(r + charSize));
}

// Ввод параметров обобщенной фразы из файла
int InWellOfWisdom(void *wow, FILE *ifst) {
    int k;
    fscanf(ifst, "%d", &k);
    switch(k) {
        case 1:
            *((int*)wow) = APHORISM;
            InAphorism(wow + charSize, ifst);
            return 1;
        case 2:
            *((int*)wow) = PROVERB;
            InProverb(wow + charSize, ifst);
            return 1;
        case 3:
            *((int*)wow) = RIDDLE;
            InRiddle(wow + charSize, ifst);
            return 1;
        default:
            return 0;
    }
}

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst) {
    void *tmp = c;
    while(!feof(ifst)) {
        if(InWellOfWisdom(tmp, ifst)) {
            tmp = tmp + well_of_wisdomSize;
            (*len)++;
        }
    }
}
