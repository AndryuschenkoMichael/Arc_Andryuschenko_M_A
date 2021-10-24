//
// Реализация функционала класса container.
//


#include "Headers/container.h"
#include "Headers/movie.h"

// Конструктор.
container::container() {
    cont = new movie *[max_len];
}

// Деструктор.
container::~container() {
    for (int i = 0; i < len; ++i) {
        delete (cont[i]);
    }
    delete[] cont;
}

// Ввод данных растений из файла
void container::InContainer(FILE *ifst) {
    movie *newPlant;
    while ((newPlant = movie::InMovie(ifst)) != nullptr) {
        cont[len] = newPlant;
        len++;
    }
}

// Рандомной заполнение контейнера.
void container::InRndContainer(int size) {
    while (len < size) {
        if ((cont[len] = movie::InRndMovie()) != nullptr) {
            len++;
        }
    }
}

// Вывод двнных контейнера.
void container::OutContainer(FILE *ofst) {
    fprintf(ofst, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        cont[i]->OutMovie(ofst);
    }
}

// Heap sort.
void container::HeapSortContainer() {
    for (int i = len / 2 - 1; i >= 0; i--) {
        heapify(cont, len, i);
    }

    for (int i = len - 1; i >= 0; i--) {
        movie *temp = cont[0];
        cont[0] = cont[i];
        cont[i] = temp;
        heapify(cont, i, 0);
    }
}

void container::heapify(movie **cont, int len, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < len && cont[left]->CalculateQuotient() < cont[smallest]->CalculateQuotient())
        smallest = left;

    if (right < len && cont[right]->CalculateQuotient() < cont[smallest]->CalculateQuotient())
        smallest = right;

    if (smallest != i) {
        movie *temp = cont[smallest];
        cont[smallest] = cont[i];
        cont[i] = temp;
        heapify(cont, len, smallest);
    }
}