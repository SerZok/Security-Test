// CWE-787: Out-of-bounds write - запись за пределами буфера
#include "out_of_bounds.h"
#include <cstring>
#include <iostream>

void write_past_buffer()
{
    char buffer[32];
    strcpy(buffer, "This string is definitely longer than 32 characters"); // ПЛОХО: переполнение

    std::cout << "Buffer: " << buffer << std::endl;
}

void array_index_out_of_bounds()
{
    int numbers[10];

    for (int i = 0; i <= 10; i++) // ПЛОХО: i == 10 выходит за пределы [0, 9]
    {
        numbers[i] = i * 2;
    }
}

void pointer_arithmetic_out_of_bounds(int *array, int size)
{
    int *ptr = array;

    // Уязвимость: указатель сдвигается за пределы массива
    ptr += size + 5; // ПЛОХО: ptr указывает за пределами array + size
    *ptr = 42;
}

void write_via_null_terminated_string()
{
    char src[] = "source data with null inside\0and more";
    char dest[20];

    // Уязвимость: strlen не учитывает null-байты внутри строки
    size_t len = strlen(src);
    if (len < sizeof(dest))
    {
        memcpy(dest, src, len);
    }
    // ПЛОХО: len может быть меньше ожидаемого из-за null-байта
}

void buffer_boundary_test()
{
    write_past_buffer();
    array_index_out_of_bounds();

    int test_array[10] = {0};
    pointer_arithmetic_out_of_bounds(test_array, 10);
    write_via_null_terminated_string();
}
