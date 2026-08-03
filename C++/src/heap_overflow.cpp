#include "heap_overflow.h"
#include <cstring>
#include <iostream>

void heap_buffer_overflow()
{
    char *heap_buffer = new char[32];

    strcpy(heap_buffer, "This string is much longer than 32 characters and will overflow the heap buffer");

    std::cout << "Heap buffer: " << heap_buffer << std::endl;

    delete[] heap_buffer;
}

void heap_overflow_with_format(const char *input)
{
    char *buffer = new char[64];

    sprintf(buffer, "User input: %s", input);

    std::cout << buffer << std::endl;

    delete[] buffer;
}

void heap_overflow_with_snprintf_fix()
{
    char *buffer = new char[64];
    const char *input = "This is a very long string that should be safely truncated";

    snprintf(buffer, 64, "User input: %s", input);

    std::cout << buffer << std::endl;

    delete[] buffer;
}

void heap_overflow_tests()
{
    heap_buffer_overflow();

    const char *long_input = "This is a very long input string that will overflow the 64-byte buffer allocated on the heap";
    heap_overflow_with_format(long_input);

    heap_overflow_with_snprintf_fix();
}
