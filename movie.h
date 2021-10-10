//
// Created by Andryuschenko Michail on 2021.
//

#ifndef ARC_Andryuschenko_MOVIE_H
#define ARC_Andryuschenko_MOVIE_H

//------------------------------------------------------------------------------
// movie.h - содержит описание обобщающего фильма,
//------------------------------------------------------------------------------

#include <stdio.h>
#include "cartoon.h"
#include "gaming.h"
#include "documentary.h"

//------------------------------------------------------------------------------
// структура, обобщающая все фильмы
struct movie {
    enum { max_name_len = 256 }; // максимальная длина имени

    enum KEY {DOCUMENTARY, GAMING, CARTOON} k; // ключ
    char name[max_name_len];
    int date;

    // используемые альтернативы
    union { // используем простейшую реализацию
        struct documentary t;
        struct gaming s;
        struct cartoon f;
    };
};

// Ввод обобщенного фильма
struct movie *InMovie(FILE *ifst);

// Случайный ввод обобщенного фильма
struct movie *InRndMovie();

// Вывод обобщенного фильма
void OutMovie(struct movie *a, FILE *ofst);

// Вычисление от деления года выхода фильма на количество символов в названии
double CalculateQuotient(struct movie *p);

#endif //ARC_Andryuschenko_MOVIE_H
