//
// Описание класса cartoon.
//

#ifndef TASK_2__CARTOON_H_
#define TASK_2__CARTOON_H_

#include <cstdio>
#include "movie.h"

// Наследование от класса movie.
class cartoon : public movie {
        private:
        enum CARTOON_TYPE {
            DRAWN, PUPPET, PLASTICINE
        } type; // Тип мультика.
        public:
        // Конструктор.
        cartoon(const char *name, int year, CARTOON_TYPE ft);

        // Ввод параметров мультика из потока(пришлось сделать static)
        static cartoon *InCartoon(FILE *ifst);

        // Случайный ввод параметров мультика(пришлось сделать static)
        static cartoon *InRndCartoon();

        // Вывод параметров мультика в форматируемый поток (реализация виртуальной функции класса movie)
        void OutMovie(FILE *ofst) override;
};

#endif //TASK_2__CARTOON_H_
