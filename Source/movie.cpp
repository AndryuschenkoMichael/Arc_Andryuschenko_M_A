//
// Реализация функционала базового класса movie
//


#include <cstring>
#include "Headers/movie.h"
#include "Headers/documentary.h"
#include "Headers/gaming.h"
#include "Headers/cartoon.h"
#include "Headers/rnd.h"

// Конструктор.
movie::movie(const char *name, const int year) {
    strcpy(this->name, name);
    this->year = year;
}

// Getter поля name.
char *movie::GetName() {
    return name;
}

// Getter поля name.
void movie::SetName(char *n) {
    strcpy(name, n);
}

// Getter поля year.
int movie::GetYear() {
    return year;
}

// Setter поля year.
void movie::SetYear(int year) {
    this->year = year;
}

// Ввод фильмов из файла.
movie *movie::InMovie(FILE *ifst) {
    int in_k;
    if (fscanf(ifst, "%d", &in_k) == EOF)
        return nullptr;

    switch (in_k) {
        case 1:
            return documentary::InDocumentary(ifst);
        case 2:
            return gaming::InGaming(ifst);
        case 3:
            return cartoon::InCartoon(ifst);
        default:
            return nullptr;
    }
}

// Рандомный ввод фильмов.
movie *movie::InRndMovie() {
    int in_k = rnd::RandomRange(0, 3);
    switch (in_k) {
        case 1:
            return documentary::InRndDocumentary();
        case 2:
            return gaming::InRndGaming();
        case 3:
            return cartoon::InRndCartoon();
        default:
            return nullptr;
    }
}

// Вывод фильмов в файл.
void movie::OutMovie(FILE *ofst) {
    fprintf(ofst, " Name = %s. Year = %d. Task result: %f\n", name, year, CalculateQuotient());
}

// Функция из ТЗ.
double movie::CalculateQuotient() {
    return (double) year / (double) strlen(name);
}
