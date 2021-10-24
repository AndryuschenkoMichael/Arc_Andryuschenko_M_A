//
// Описание класса documentary.
//

#ifndef TASK_2__DOCUMENTARY_H_
#define TASK_2__DOCUMENTARY_H_

#include <cstdio>
#include "movie.h"

// Наследование от класса movie.
class documentary : public movie {
        private:
        long long time; // продолжительность фильма.
        public:
        // Конструктор.
        documentary(const char *name, int year, long long time);

        // Ввод параметров документального фильма из файла(пришлось сделать static)
        static documentary *InDocumentary(FILE *ifst);

        // Рандомный ввод параметров документального фильма(пришлось сделать static)
        static documentary *InRndDocumentary();

        // Вывод параметров документального фильма в файл.
        void OutMovie(FILE *ofst) override;
};

#endif //TASK_2__DOCUMENTARY_H_
