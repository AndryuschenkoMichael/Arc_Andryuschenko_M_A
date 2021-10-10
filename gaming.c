//
// Created by Andryuschenko Michail on 2021.
//
//------------------------------------------------------------------------------
// gaming.c - содержит процедуру ввода параметров
// для уже созданного игрового фильма
//------------------------------------------------------------------------------

#include <string.h>
#include "rnd.h"
#include "gaming.h"


//------------------------------------------------------------------------------
// Ввод параметров игрового фильма из файла
int InGaming(struct gaming *s, FILE *ifst) {
    if (fscanf(ifst, "%s", s->director) == EOF)
        return EOF;

    return 1;
}

// Случайный ввод параметров игрового фильма
void InRndGaming(struct gaming *s) {
    RandomString(s->director, max_name_len_director);
}

//------------------------------------------------------------------------------
// Вывод параметров игрового фильма в форматируемый поток
void OutGaming(struct gaming *s, FILE *ofst) {
    fprintf(ofst, "It is Gaming: director name = %s.", s->director);
}
