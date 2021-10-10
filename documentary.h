//
// Created by Andryuschenko Michail on 2021.
//
//------------------------------------------------------------------------------
// documentary.h - содержит описание документального фильма.
//------------------------------------------------------------------------------

#ifndef ARC_Andryuschenko_DOCUMENTARY_H
#define ARC_Andryuschenko_DOCUMENTARY_H

#include <stdio.h>
#include <stdbool.h>

struct documentary{
    long long time; // длительность фильма
};

// Ввод параметров дерева из файла
int InDocumentary(struct documentary *t, FILE *ifst);

// Случайный ввод параметров дерева
void InRndDocumentary(struct documentary *t);

// Вывод параметров дерева в форматируемый поток
void OutDocumentary(struct documentary *t, FILE *ofst);

#endif //ARC_Andryuschenko_DOCUMENTARY_H
