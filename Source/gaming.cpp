//
// Реализация функционала класса gaming.
//

#include "Headers/gaming.h"
#include "Headers/documentary.h"
#include "Headers/cartoon.h"
#include "Headers/rnd.h"
#include <cstring>

// Конструктор.
gaming::gaming(const char *name, int year, const char *director) : movie(name, year) {
    strcpy(this->director, director);
}

// Ввод игрового фильма из файла.
gaming *gaming::InGaming(FILE *ifst) {
    char name[256];
    int year;

    if (fscanf(ifst, "%s %d", name, &year) == EOF)
        return nullptr;

    char director[256];
    if (fscanf(ifst, "%s", director) == EOF)
        return nullptr;

    return new gaming(name, year, director);
}

// Рандомный ввод игрового фильма.
gaming *gaming::InRndGaming() {
    int year = rnd::RandomRange(1900, 2021);
    char name[256];
    char director[256];
    rnd::RandomString(name, 11);
    rnd::RandomString(director, 11);
    return new gaming(name, year, director);
}

// Вывод игрового фильма в файл.
void gaming::OutMovie(FILE *ofst) {
    fprintf(ofst,
            "It is Gaming: Director = %s. Name = %s. Year = %d. Task result: %f\n",
            director,
            name,
            year,
            CalculateQuotient());
}

