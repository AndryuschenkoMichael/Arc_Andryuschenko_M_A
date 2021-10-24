//
// Описание базового класса movie.
//

#ifndef TASK_2__MOVIE_H_
#define TASK_2__MOVIE_H_

#include <cstdio>

class movie {
        protected:
        enum {
            max_name_len = 256
        }; // Максимальная длина названия.

        char name[max_name_len]; // Название фильма.
        int year;

        public:
        // Конструктор.
        movie(const char *name, const int year);

        // Getter поля name.
        char *GetName();

        // Setter поля name.
        void SetName(char *n);

        // Getter поля year.
        int GetYear();

        // Setter поля year.
        void SetYear(int year);

        // Ввод растения из файла.
        static movie *InMovie(FILE *ifst);

        // Рандомный ввод растения.
        static movie *InRndMovie();

        // Вывод растения вв файл.
        virtual void OutMovie(FILE *ofst);

        // Вычисление частного от деления года выхода на общую длину названия. (действительное число)
        double CalculateQuotient();
};

#endif //TASK_2__MOVIE_H_
