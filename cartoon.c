//
// Created by Andryuschenko Michail on 2021.
//
//------------------------------------------------------------------------------
// cartoon.c - содержит процедуру ввода параметров
// для уже созданного мультика
//------------------------------------------------------------------------------

#include "cartoon.h"
#include <string.h>
#include "rnd.h"

//------------------------------------------------------------------------------
// Ввод параметров мультика из файла
int InCartoon(struct cartoon *f, FILE *ifst) {
    char cartoonType[11];
    if (fscanf(ifst, "%s", cartoonType) == EOF)
        return EOF;

    if (strcmp(cartoonType, "DRAWN") == 0) {
        f->type = DRAWN;
    } else if (strcmp(cartoonType, "PUPPET") == 0) {
        f->type = PUPPET;
    } else if (strcmp(cartoonType, "PLASTICINE") == 0) {
        f->type = PLASTICINE;
    } else {
        return 0;
    }

    return 1;
}

// Случайный ввод параметров мультика
void InRndCartoon(struct cartoon *f) {
    int random = RandomRange(0, 2);

    // Случайный тип мультика
    f->type = random;
}

//------------------------------------------------------------------------------
// Вывод параметров мультика в форматируемый поток
void OutCartoon(struct cartoon *f, FILE *ofst) {
    char* cartoonType;
    if (f->type == DRAWN) {
        cartoonType = "DRAWN";
    } else if (f->type == PUPPET) {
        cartoonType = "PUPPET";
    } else if (f->type == PLASTICINE) {
        cartoonType = "PLASTICINE";
    } else {
        cartoonType = "WRONG_TYPE";
    }

    fprintf(ofst, "It is Cartoon: type = %s.", cartoonType);
}