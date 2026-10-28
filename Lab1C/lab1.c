
#include <stdio.h>
#include <stdlib.h>
#include "array.h"

// Создание массива и чтение данных из файла
Array *array_create_and_read(FILE *input)
{
    int n;

    // Чтение размера массива
    if (fscanf(input, "%d", &n) != 1 || n < 0)
        return NULL;

    // Создание массива
    Array *arr = array_create((size_t)n, NULL);

    if (arr == NULL)
        return NULL;

    // Заполнение массива числами из файла
    for (int i = 0; i < n; ++i)
    {
        int x;

        if (fscanf(input, "%d", &x) != 1)
        {
            array_delete(arr);
            return NULL;
        }

        array_set(arr, (size_t)i, (Data)x);
    }

    return arr;
}

// Вывод элементов массива
void print_array(const Array *arr)
{
    for (size_t i = 0; i < array_size(arr); ++i)
    {
        if (i > 0)
            printf(" ");

        printf("%d", (int)array_get(arr, i));
    }

    printf("\n");
}

// Обработка первого массива
void task1(Array *arr)
{
    print_array(arr);
}

// Обработка второго массива
void task2(Array *arr)
{
    print_array(arr);
}

int main(int argc, char **argv)
{
    // Проверка аргументов командной строки
    if (argc != 2)
    {
        fprintf(stderr, "Укажите входной файл\n");
        return 1;
    }

    // Открытие файла
    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        fprintf(stderr, "Не удалось открыть файл\n");
        return 1;
    }

    // Чтение и обработка первого массива
    Array *arr = array_create_and_read(input);

    if (arr == NULL)
    {
        fclose(input);
        fprintf(stderr, "Ошибка чтения первого массива\n");
        return 1;
    }

    task1(arr);
    array_delete(arr);

    // Чтение и обработка второго массива
    arr = array_create_and_read(input);

    if (arr == NULL)
    {
        fclose(input);
        fprintf(stderr, "Ошибка чтения второго массива\n");
        return 1;
    }

    task2(arr);
    array_delete(arr);

    // Закрытие файла
    fclose(input);

    return 0;
}
