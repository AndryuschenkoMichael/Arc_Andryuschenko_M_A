//
// Описание класса container.
//

#ifndef TASK_2__CONTAINER_H_
#define TASK_2__CONTAINER_H_

#include <cstdio>
#include "movie.h"

class container {
        private:
        enum {
            max_len = 100000
        }; // максимальная длина
        int len = 0; // текущая длина
        movie **cont; // контейнер с фильмами.
        public:
        // Конструктор.
        container();

        // Деструктор.
        ~container();

        // Ввод содержимого контейнера из указанного потока.
        void InContainer(FILE *ifst);

        // Случайный ввод содержимого контейнера.
        void InRndContainer(int size);

        // Вывод содержимого контейнера в указанный поток.
        void OutContainer(FILE *ofst);

        // Heap sort.
        void HeapSortContainer();

        private:
        void heapify(movie**, int, int);
};

#endif //TASK_2__CONTAINER_H_
