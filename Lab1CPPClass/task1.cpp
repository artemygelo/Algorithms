#include <iostream>
#include <fstream>
#include "array.h"

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Укажите входной файл\n";
        return 1;
    }

    std::ifstream file(argv[1]);

    if (!file) {
        std::cerr << "Не удалось открыть файл\n";
        return 1;
    }

    int n;
    if (!(file >> n) || n < 0) {
        std::cerr << "Некорректный размер массива\n";
        return 1;
    }

    Array a(n);

    for (int i = 0; i < n; ++i) {
        int value;

        if (!(file >> value)) {
            std::cerr << "Не удалось прочитать элемент\n";
            return 1;
        }

        a.set(i, value);
    }

    int count = 0;

    for (int i = 0; i < n; ++i) {
        for (int divisor = 2; divisor <= 9; ++divisor) {
            if (a.get(i) % divisor == 0) {
                ++count;
                break;
            }
        }
    }

    std::cout << count << '\n';
    return 0;
}