// CWE-476: Null pointer dereference - разыменование нулевого указателя
#include "null_pointer.h"
#include <iostream>

void dereference_null_pointer()
{
    int *ptr = nullptr;

    // Уязвимость: разыменование null-указателя
    *ptr = 42; // ПЛОХО: разыменование nullptr
}

void null_pointer_string()
{
    char *str = nullptr;

    // Уязвимость: передача null-указателя в strlen
    size_t len = strlen(str); // ПЛОХО: str == nullptr
    std::cout << "Length: " << len << std::endl;
}

void null_pointer_member_access()
{
    struct Data
    {
        int value;
        char *buffer;
    };

    Data *data = nullptr;

    // Уязвимость: доступ к члену через null-указатель
    data->value = 100; // ПЛОХО: data == nullptr
}

void null_check_missing(int *ptr)
{
    // Уязвимость: отсутствует проверка на null
    int value = *ptr; // ПЛОХО: ptr может быть nullptr
    std::cout << "Value: " << value << std::endl;
}

void null_pointer_tests()
{
    dereference_null_pointer();
    null_pointer_string();
    null_pointer_member_access();

    int *null_ptr = nullptr;
    null_check_missing(null_ptr);
}
