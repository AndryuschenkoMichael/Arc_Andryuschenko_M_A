//
// Реализация функционала класса rnd.
//

#include "Headers/rnd.h"
#include <cstring>

// Функция генерирующая случайную строку указанного размера.
char *rnd::RandomString(char *str, size_t size) {
    const char *charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (size) {
        --size;
        for (size_t n = 0; n < size; n++) {
            int key = RandomRange(0, strlen(charset) - 1);
            str[n] = charset[key];
        }
        str[size] = '\0';
    }
    return str;
}
