//
// Реализация функционала класса documentary.
//

#include "Headers/documentary.h"
#include "Headers/rnd.h"

// Констурктор.
documentary::documentary(const char *name, int year, long long time) : movie(name, year),
                                                                       time(time) {}

// Ввод окументального фильма из файла.
documentary *documentary::InDocumentary(FILE *ifst) {
    char name[256];
    int year;
    if (fscanf(ifst, "%s %d", name, &year) == EOF)
        return nullptr;

    long long in_time;
    if (fscanf(ifst, "%lld", &in_time) == EOF)
        return nullptr;

    long long ans_time;
    if (in_time > 0) {
        ans_time = in_time;
    } else {
        return nullptr;
    }

    return new documentary(name, year, ans_time);
}

// Рандомный ввод документального фильма.
documentary *documentary::InRndDocumentary() {
    long long time = rnd::RandomRange(0, 100000);
    char name[256];
    rnd::RandomString(name, 11);
    int year = rnd::RandomRange(1900, 2021);
    return new documentary(name, year, time);
}

// Вывод документального фильма в файл.
void documentary::OutMovie(FILE *ofst) {
    fprintf(ofst, "It is Documentary: Time = %lld. Name = %s. Year = %d. Task result: %f\n", time,
            name, year,
            CalculateQuotient());
}
