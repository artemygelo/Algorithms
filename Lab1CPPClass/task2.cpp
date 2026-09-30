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

    long long minimum = -1;

    for (int i = 0; i < n; ++i) {
        int first = a.get(i);

        if (first % 2 != 0)
            continue;

        for (int j = i + 1; j < n; ++j) {
            int second = a.get(j);

            if (second % 2 != 0)
                continue;

            long long difference =
                static_cast<long long>(first) - second;

            if (difference < 0)
                difference = -difference;

            if (minimum == -1 || difference < minimum)
                minimum = difference;
        }
    }

    if (minimum == -1)
        std::cout << "Недостаточно чётных элементов\n";
    else
        std::cout << minimum << '\n';

    return 0;
}