//
// Created by Andryuschenko Michail on 2021.
//

#ifndef ARC_Andryuschenko_CONTAINER_H
#define ARC_Andryuschenko_CONTAINER_H

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "movie.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    enum { max_len = 100000 }; // максимальная длина
    int len; // текущая длина
    struct movie *cont[max_len];
};

// Инициализация контейнера
void InitContainer(struct container *c);

// Очистка контейнера от элементов (освобождение памяти)
void ClearContainer(struct container *c);

// Ввод содержимого контейнера из указанного потока
void InContainer(struct container *c, FILE *ifst);

// Случайный ввод содержимого контейнера
void InRndContainer(struct container *c, int size);

// Вывод содержимого контейнера в указанный поток
void OutContainer(struct container *c, FILE *ofst);

// Сортировка кучей по убыванию
void HeapSortContainer(struct container *c);

void MakeHeap(struct container *c, int head, int count);

#endif //ARC_Andryuschenko_CONTAINER_H
