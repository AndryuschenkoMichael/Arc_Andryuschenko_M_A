//
// Описание класса rnd.
//

#ifndef TASK_2__RND_H_
#define TASK_2__RND_H_

#include <cstdlib>

class rnd {
        public:
        // Случайное число из диапазона.
        static int RandomRange(int min, int max) {
            return rand() % (max - min + 1) + min;
        }

        // Функция генерирующая случайную строку указанного размера.
        static char *RandomString(char *str, size_t size);
};

#endif //TASK_2__RND_H_
