//
// Created by Andryuschenko Michail on 2021.
//
//------------------------------------------------------------------------------
// container.c - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include "container.h"
#include <stdlib.h>

//------------------------------------------------------------------------------
// Инициализация контейнера
void InitContainer(struct container *c) {
    c->len = 0;
}

// Очистка контейнера от элементов (освобождение памяти)
void ClearContainer(struct container *c) {
    for (int i = 0; i < c->len; i++) {
        free(c->cont[i]);
    }

    c->len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void InContainer(struct container *c, FILE *ifst) {
    struct movie *newPlant;
    while ((newPlant = InMovie(ifst)) != ((void *) 0)) {
        c->cont[c->len] = newPlant;
        c->len++;
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRndContainer(struct container *c, int size) {
    while (c->len < size) {
        if ((c->cont[c->len] = InRndMovie()) != ((void *) 0)) {
            c->len++;
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void OutContainer(struct container *c, FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", c->len);
    for (int i = 0; i < c->len; i++) {
        fprintf(ofst, "%d: ", i);
        OutMovie(c->cont[i], ofst);
    }
}

// Heap sort
void HeapSortContainer(struct container *c) {
    for (int i = (int)c->len / 2 - 1; i >= 0; --i)
        MakeHeap(c, i, c->len);

    for (int i = c->len - 1; i >= 0; --i) {
        struct movie *k = c->cont[0];
        c->cont[0] = c->cont[i];
        c->cont[i] = k;

        MakeHeap(c, 0, i);
    }

}

// Создание кучи
void MakeHeap(struct container *c, int head, int count) {
    int largest = head;

    int left = 2 * head + 1;
    int right = 2 * head + 2;

    if (left < count && CalculateQuotient(c->cont[left]) < CalculateQuotient(c->cont[largest]))
        largest = left;

    if (right < count && CalculateQuotient(c->cont[right]) < CalculateQuotient(c->cont[largest]))
        largest = right;

    if (largest != head) {
        struct movie *k = c->cont[head];
        c->cont[head] = c->cont[largest];
        c->cont[largest] = k;

        MakeHeap(c, largest, count);
    }
}
