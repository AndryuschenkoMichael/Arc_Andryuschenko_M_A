//
// Created by Andryuschenko Michail on 2021.
//

#include "movie.h"
#include "rnd.h"
#include <stdlib.h>
#include <string.h>

//------------------------------------------------------------------------------
// Ввод параметров обобщенного растения из файла

struct movie *InMovie(FILE *ifst) {
    struct movie *p;
    int k;
    if (fscanf(ifst, "%d", &k) == EOF)
        return ((void *) 0);

    char name[256];
    if (fscanf(ifst, "%s", name) == EOF)
        return ((void *) 0);

    int date;
    if (fscanf(ifst, "%d", &date) == EOF)
        return ((void *) 0);

    switch (k) {
        case 1:p = (struct movie *) malloc(sizeof(struct movie));
            p->k = DOCUMENTARY;
            strcpy(p->name, name);
            p->date = date;
            if (InDocumentary(&p->t, ifst) == EOF) {
                free(p);
                return ((void *) 0);
            }
            return p;
        case 2:p = (struct movie *) malloc(sizeof(struct movie));
            p->k = GAMING;
            strcpy(p->name, name);
            p->date = date;
            if (InGaming(&p->s, ifst) == EOF) {
                free(p);
                return ((void *) 0);
            }
            return p;
        case 3:p = (struct movie *) malloc(sizeof(struct movie));
            p->k = CARTOON;
            strcpy(p->name, name);
            p->date = date;
            if (InCartoon(&p->f, ifst) == EOF) {
                free(p);
                return ((void *) 0);
            }
            return p;
        default:return ((void *) 0);
    }
}

// Случайный ввод обобщенного фильма
struct movie *InRndMovie() {
    const int NAME_LENGTH = 11;

    struct movie *p;
    int k = RandomRange(1, 3);
    switch (k) {
        case 1:p = (struct movie *) malloc(sizeof(struct movie));
            p->k = DOCUMENTARY;
            RandomString(p->name, NAME_LENGTH);
            p->date = RandomRange(1500, 3000);
            InRndDocumentary(&p->t);
            return p;
        case 2:p = (struct movie *) malloc(sizeof(struct movie));
            p->k = GAMING;
            RandomString(p->name, NAME_LENGTH);
            p->date = RandomRange(1500, 3000);
            InRndGaming(&p->s);
            return p;
        case 3:p = (struct movie *) malloc(sizeof(struct movie));
            p->k = CARTOON;
            RandomString(p->name, NAME_LENGTH);
            p->date = RandomRange(1500, 3000);
            InRndCartoon(&p->f);
            return p;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущего фильма в поток
void OutMovie(struct movie *p, FILE *ofst) {
    switch (p->k) {
        case DOCUMENTARY:OutDocumentary(&p->t, ofst);
            break;
        case GAMING:OutGaming(&p->s, ofst);
            break;
        case CARTOON:OutCartoon(&p->f, ofst);
            break;
        default:fprintf(ofst, "Incorrect movie!\n");
            return;
    }

    fprintf(ofst, " Name = %s. Date = %d. Task result: %f\n", p->name, p->date, CalculateQuotient(p));
}

//------------------------------------------------------------------------------
// Реализация общей функции
double CalculateQuotient(struct movie *p) {
    return (double)(p->date) / (double)strlen(p->name);
}
