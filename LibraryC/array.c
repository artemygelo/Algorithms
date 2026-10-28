
#include <stdint.h>
#include <stdlib.h>
#include "array.h"

// Структура динамического массива
struct Array
{
    size_t size;
    FFree *free_item;
    Data elements[];
};

// Создание массива заданного размера
Array *array_create(size_t size, FFree f)
{
    // Проверка размера перед выделением памяти
    if (size > (SIZE_MAX - sizeof(Array)) / sizeof(Data))
        return NULL;

    // Выделение памяти и заполнение нулями
    Array *arr = (Array *)calloc(
        1, sizeof(Array) + size * sizeof(Data)
    );

    if (arr == NULL)
        return NULL;

    // Сохранение размера и функции освобождения памяти
    arr->size = size;
    arr->free_item = f;

    return arr;
}

// Удаление массива и освобождение памяти
void array_delete(Array *arr)
{
    if (arr == NULL)
        return;

    // Освобождение памяти пользовательских элементов
    if (arr->free_item != NULL)
    {
        for (size_t i = 0; i < arr->size; ++i)
        {
            if (arr->elements[i] != 0)
                arr->free_item((void *)arr->elements[i]);
        }
    }

    // Освобождение памяти массива
    free(arr);
}

// Получение элемента массива по индексу
Data array_get(const Array *arr, size_t index)
{
    if (arr == NULL || index >= arr->size)
        return (Data)0;

    return arr->elements[index];
}

// Запись значения в элемент массива
void array_set(Array *arr, size_t index, Data value)
{
    if (arr == NULL || index >= arr->size)
        return;

    // Освобождение старого элемента при замене
    Data old = arr->elements[index];

    if (arr->free_item != NULL && old != 0 && old != value)
        arr->free_item((void *)old);

    arr->elements[index] = value;
}

// Получение размера массива
size_t array_size(const Array *arr)
{
    return arr == NULL ? 0 : arr->size;
}
