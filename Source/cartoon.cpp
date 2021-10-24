//
// Реализация функционала класса cartoon.
//

#include <cstring>
#include "Headers/cartoon.h"
#include "Headers/rnd.h"

// Конструктор.
cartoon::cartoon(const char *name, int year, cartoon::CARTOON_TYPE ft) : movie(name, year),
                                                                         type(ft) {}

// Ввод мультика из файла.
cartoon *cartoon::InCartoon(FILE *ifst) {
    char name[256];
    int year;

    if (fscanf(ifst, "%s %d", name, &year) == EOF)
        return nullptr;

    char cartoonType[11];

    if (fscanf(ifst, "%s", cartoonType) == EOF)
        return nullptr;

    CARTOON_TYPE ftype;

    if (strcmp(cartoonType, "DRAWN") == 0) {
        ftype = DRAWN;
    } else if (strcmp(cartoonType, "PUPPET") == 0) {
        ftype = PUPPET;
    } else if (strcmp(cartoonType, "PLASTICINE") == 0) {
        ftype = PLASTICINE;
    } else {
        return nullptr;
    }

    return new cartoon(name, year, ftype);
}

// Рандомный ввод мультика.
cartoon *cartoon::InRndCartoon() {
    CARTOON_TYPE ft;
    int random = rnd::RandomRange(0, 2);
    // Случайный тип мультика.
    ft = static_cast<CARTOON_TYPE>(random);
    char name[256];
    rnd::RandomString(name, 11);
    int year = rnd::RandomRange(1900, 2021);

    return new cartoon(name, year, ft);
}

// Вывод мультика.
void cartoon::OutMovie(FILE *ofst) {
    char *cartoonType;

    if (type == DRAWN) {
        cartoonType = "DRAWN";
    } else if (type == PUPPET) {
        cartoonType = "PUPPET";
    } else if (type == PLASTICINE) {
        cartoonType = "PLASTICINE";
    } else {
        cartoonType = "WRONG_TYPE";
    }

    fprintf(ofst, "It is Cartoon: type = %s. Name = %s. Year = %d. Task result: %f\n", cartoonType,
            name, year, CalculateQuotient());
}
