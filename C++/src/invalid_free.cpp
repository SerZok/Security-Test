#include "invalid_free.h"
#include <cstring>
#include <iostream>

void free_stack_memory()
{
    char stack_buffer[128];
    strcpy(stack_buffer, "test data");

    free(stack_buffer);
}

void double_free_example()
{
    char *heap_buffer = new char[64];
    strcpy(heap_buffer, "heap data");

    delete[] heap_buffer;

    delete[] heap_buffer;
}

void use_after_free_advanced()
{
    char *ptr1 = new char[32];
    char *ptr2 = ptr1;

    delete[] ptr1;

    strcpy(ptr2, "use after free via alias");
}

void invalid_free_test()
{
    free_stack_memory();
    double_free_example();
    use_after_free_advanced();
}
