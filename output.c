//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

// Вычисление частного от деления количества знаков препинания в строке на ee длину
double Quotient(void *a);
// Вывод параметров афоризма в файл
void OutAphorism(void *a, FILE *ofst) {
    fprintf(ofst, "Aphorism: %s\n Author: %s\n Quotient = %g\n",
            ((char*)a), ((char*)(a+charSize)), Quotient(a));
}

// Вычисление частного от деления количества знаков препинания в строке на ee длину
double Quotient(void *p);

// Вывод параметров поговорки в файл
void OutProverb(void *p, FILE *ofst) {
    fprintf(ofst, "Proverb: %s\n Country: %s\n Quotient = %g\n",
           ((char*)p), ((char*)(p+charSize)), Quotient(p));
}

// Вычисление частного от деления количества знаков препинания в строке на ee длину
double Quotient(void* r);

// Вывод параметров загадки в файл
void OutRiddle(void* r, FILE* ofst) {
    fprintf(ofst, "Riddle: %s\n Answer: %s\n Quotient = %g\n",
        ((char*)r), ((char*)(r + charSize)), Quotient(r));
}

// Вывод параметров текущей фразы в поток
void OutWellOfWisdom(void *s, FILE *ofst) {
    int k = *((int*)s);
    if(k == APHORISM) {
        OutAphorism(s + charSize, ofst);
    }
    else if(k == PROVERB) {
        OutProverb(s + charSize, ofst);
    }
    else if (k == RIDDLE) {
        OutRiddle(s + charSize, ofst);
    }
    else {
        fprintf(ofst, "Incorrect phrase!\n");
    }
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container is store %d phrases.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        OutWellOfWisdom(tmp, ofst);
        tmp = tmp + well_of_wisdomSize;
    }
}
