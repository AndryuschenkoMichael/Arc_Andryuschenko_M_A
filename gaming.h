//
// Created by Andryuschenko Michail on 2021.
//
//------------------------------------------------------------------------------
// gaming.h - содержит описание игрового фильма и его интерфейса
//------------------------------------------------------------------------------

#ifndef ARC_Andryuschenko_GAMING_H
#define ARC_Andryuschenko_GAMING_H

#include <stdio.h>

// Игровой фильм
struct gaming {
    enum { max_name_len_director = 256 }; // максимальная длина имени автора

    char director[max_name_len_director] // имя автора.
};

// Ввод параметров игрового фильма из файла
int InGaming(struct gaming *s, FILE *ifst);

// Случайный ввод параметров игрового фильма
void InRndGaming(struct gaming *s);

// Вывод параметров игрового фильма в форматируемый поток
void OutGaming(struct gaming *s, FILE *ofst);

#endif //ARC_Andryuschenko_GAMING_H
