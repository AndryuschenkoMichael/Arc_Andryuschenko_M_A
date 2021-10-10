//
// Created by Andryuschenko Michail on 2021.
//
//------------------------------------------------------------------------------
// documentary.c - содержит функции обработки документального фильма.
//-------------------------------------------------------------------------------
#include "documentary.h"
#include <string.h>
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров документального фильма из потока
int InDocumentary(struct documentary *t, FILE *ifst) {
    long long time;
    if (fscanf(ifst, "%lld", &time) == EOF)
        return EOF;

    if (time > 0) {
        t->time = time;
    } else {
        return 0;
    }
    return 1;
}

// Случайный ввод параметров документального фильма
void InRndDocumentary(struct documentary *t) {
    t->time = RandomRange(0, 100000000000);
}

//------------------------------------------------------------------------------
// Вывод параметров документального фильма в поток
void OutDocumentary(struct documentary *t, FILE *ofst) {
    fprintf(ofst, "It is Documentary: time = %lld.", t->time);
}

