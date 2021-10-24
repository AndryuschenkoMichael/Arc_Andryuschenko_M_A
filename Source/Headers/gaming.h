//
// Описание функционала класса gaming.
//

#ifndef TASK_2__GAMING_H_
#define TASK_2__GAMING_H_

#include <cstdio>
#include "movie.h"

//Наследование от класса movie.
class gaming : public movie {
        private:
        char director[max_name_len]; // режисер.
        public:
        // Конструктор.
        gaming(const char *name, int year, const char *director);

        // Ввод параметров игрового фильма из файла(пришлось сделать static)
        static gaming *InGaming(FILE *ifst);

        // Рандомный ввод параметров игрового фильма(пришлось сделать static)
        static gaming *InRndGaming();

        // Вывод параметров игрового фильма в файл
        void OutMovie(FILE *ofst) override;
};

#endif //TASK_2__GAMING_H_
