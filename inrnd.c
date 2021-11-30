//------------------------------------------------------------------------------
// inrnd.c - единица компиляции, вбирающая функции генерации случайных данных
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "extdata.h"

// rnd.c - содержит генератор случайных чисел в диапазоне от 1 до 20
int Random() {
    return rand() % 4 + 1;
}

// Случайный ввод параметров афоризма
void InRndAphorism(void* a) {
    int num = Random();
    switch (num)
    {
    case 1:
        *((char*)a) = "There are no shortcuts to any place worth going.";
        *((char*)(a + charSize)) = "Helen Keller";
    case 2:
        *((char*)a) = "Success consists of going from failure to failure without loss of enthusiasm";
        *((char*)(a + charSize)) = "Winston Churchill";
    case 3:
        *((char*)a) = "You miss 100% of the shots you don’t take";
        *((char*)(a + charSize)) = "Wayne Gretzky";
    case 4:
        *((char*)a) = "Success is the child of audacity.";
        *((char*)(a + charSize)) = "Benjamin Disraeli";
    default:
        break;
    }
}

// Случайный ввод параметров поговорки
void InRndProverb(void* p) {
    int num = Random();
    switch (num)
    {
    case 1:
        *((char*)p) = "Two wrongs don't make a right.";
        *((char*)(p + charSize)) = "Scotland";
    case 2:
        *((char*)p) = "The pen is mightier than the sword.";
        *((char*)(p + charSize)) = "UK";
    case 3:
        *((char*)p) = "Fortune favors the bold.";
        *((char*)(p + charSize)) = "France";
    case 4:
        *((char*)p) = "The pen is mightier than the sword";
        *((char*)(p + charSize)) = "Unknown";
    default:
        break;
    }
}

// Случайный ввод параметров загадки
void InRndRiddle(void* r) {
    int num = Random();
    switch (num)
    {
    case 1:
        *((char*)r) = "What do you throw out when you want to use it, but take in when you don’t want to use it";
        *((char*)(r + charSize)) = "anchor";
    case 2:
        *((char*)r) = "What do you get if you put a radio in the fridge?";
        *((char*)(r + charSize)) = " Cool music. ";
    case 3:
        *((char*)r) = "What do you serve that you can’t eat?";
        *((char*)(r + charSize)) = "Guests";
    case 4:
        *((char*)r) = "What flies when it’s born, lies when it’s alive, and runs when it’s dead?";
        *((char*)(r + charSize)) = "snowflake";
    default:
        break;
    }
}

// Случайный ввод обобщенной фигуры
int InRndWellOfWisdom(void* wow) {
    int k = rand() % 2 + 1;
    switch (k) {
    case 1:
        *((int*)wow) = APHORISM;
        InRndAphorism(wow + charSize);
        return 1;
    case 2:
        *((int*)wow) = PROVERB;
        InRndProverb(wow + charSize);
        return 1;
    case 3:
        *((int*)wow) = RIDDLE;
        InRndRiddle(wow + charSize);
        return 1;
    default:
        return 0;
    }
}

// Случайный ввод содержимого контейнера
void InRndContainer(void* c, int* len, int size) {
    void* tmp = c;
    while (*len < size) {
        if (InRndWellOfWisdom(tmp)) {
            tmp = tmp + well_of_wisdomSize;
            (*len)++;
        }
    }
}
