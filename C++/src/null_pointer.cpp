#include "null_pointer.h"
#include <iostream>
#include <cstring>

void dereference_null_pointer()
{
    int *ptr = nullptr;

    *ptr = 42;
}

void null_pointer_string()
{
    char *str = nullptr;

    size_t len = strlen(str);
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

    data->value = 100;
}

void null_check_missing(int *ptr)
{
    int value = *ptr;
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
