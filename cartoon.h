//
// Created by Andryuschenko Michail on 2021.
//
//------------------------------------------------------------------------------
// cartoon.h - содержит описание мультика и его интерфейса
//------------------------------------------------------------------------------

#ifndef ARC_Andryuschenko_CARTOON_H
#define ARC_Andryuschenko_CARTOON_H

#include <stdio.h>

// Тип мультика
struct cartoon {
    enum CARTOON_TYPE {DRAWN, PUPPET, PLASTICINE} type; // тип мультика
};

// Ввод параметров мультика из потока
int InCartoon(struct cartoon *f, FILE *ifst);

// Случайный ввод параметров мультика
void InRndCartoon(struct cartoon *f);

// Вывод параметров мультика в форматируемый поток
void OutCartoon(struct cartoon *f, FILE *ofst);

#endif //ARC_Andryuschenko_CARTOON_H
