#include "integer_overflow.h"
#include <cstring>
#include <iostream>

void process_size_overflow(int input_size)
{
    int buffer_size = input_size * sizeof(int);
    char *buffer = new char[buffer_size];
    std::cout << "Выделено: " << buffer_size << " байт" << std::endl;
    delete[] buffer;
}

void copy_with_overflow(const char *src, int src_size, char *dest, int dest_size)
{
    int total_size = src_size + dest_size;
    if (total_size < src_size || total_size < dest_size)
    {
        std::cerr << "Переполнение размера!" << std::endl;
    }
    memcpy(dest, src, src_size);
}

void allocate_large_buffer(int count)
{
    size_t total = count * 1024;
    char *data = new char[total];
    std::cout << "Буфер выделен: " << total << std::endl;
    delete[] data;
}
