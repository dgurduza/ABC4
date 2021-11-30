#ifndef __data__
#define __data__

//------------------------------------------------------------------------------
// data.h - Описание данных бестиповой программы
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант
//------------------------------------------------------------------------------

// Константа, определяющая размер целого числа
int const charSize = sizeof(char);
// Константа, задающая размер для афоризма
int const aphorismSize = 256 * sizeof(char*);
// Константа, задающая размер для поговорки
int const proverbSize = 256 * sizeof(char*);
// Константа, задающая размер для загадки
int const riddleSize = 256 * sizeof(char*);
// Константа, задающая размер для фраз
int const well_of_wisdomSize = sizeof(char*) + (aphorismSize >= proverbSize ? (aphorismSize >= riddleSize ? aphorismSize : riddleSize)
    : (proverbSize >= riddleSize ? aphorismSize : riddleSize));
// Константа, определяющая размерность массива фраз
int const maxSize = 10000 * well_of_wisdomSize;
// Константа, задающая признак афоризма
int const APHORISM = 1;
// Константа, задающая признак пословицы
int const PROVERB = 2;
// Константа, задающая признак загадки
int const RIDDLE = 3;

//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst);
// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size);
// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst);
// Удаление фраз с частным меньшим чем среднее значение частного контейнера
extern double ArithmeticMeanOfQuotients(void *c, int len);

#endif
