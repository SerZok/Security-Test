// CWE-590: Free of memory not on heap
#include "invalid_free.h"
#include <cstring>
#include <iostream>

void free_stack_memory()
{
    char stack_buffer[128];
    strcpy(stack_buffer, "test data");

    // Уязвимость: попытка освободить стековую память
    free(stack_buffer); // ПЛОХО: stack_buffer не выделена через malloc/new
}

void free_global_memory()
{
    static char global_buffer[256];
    strcpy(global_buffer, "global data");

    // Уязвимость: попытка освободить глобальную память
    free(global_buffer); // ПЛОХО: global_buffer не выделена через malloc/new
}

void double_free_example()
{
    char *heap_buffer = new char[64];
    strcpy(heap_buffer, "heap data");

    delete[] heap_buffer;

    // Уязвимость: двойное освобождение
    delete[] heap_buffer; // ПЛОХО: heap_buffer уже освобождена
}

void use_after_free_advanced()
{
    char *ptr1 = new char[32];
    char *ptr2 = ptr1;

    delete[] ptr1;

    // Уязвимость: доступ через алиасинговый указатель
    strcpy(ptr2, "use after free via alias"); // ПЛОХО: ptr2 указывает на освобождённую память
}

void invalid_free_test()
{
    free_stack_memory();
    free_global_memory();
    double_free_example();
    use_after_free_advanced();
}
