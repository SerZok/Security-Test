#include "integer_underflow.h"
#include <iostream>

void signed_underflow()
{
    int value = -100;

    for (int i = 0; i < 10; i++)
    {
        value -= 50;
    }

    std::cout << "Value: " << value << std::endl;
}

void unsigned_wrapping_underflow()
{
    unsigned int small = 0;
    unsigned int large = 100;

    unsigned int diff = small - large;
    std::cout << "Difference: " << diff << std::endl;
}

void pointer_underflow()
{
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    int *ptr = &array[5];
    ptr -= 10;

    std::cout << "Value: " << *ptr << std::endl;
}

void underflow_compare()
{
    unsigned int a = 0;
    unsigned int b = 10;

    if (a - b < 5)
    {
        std::cout << "Check passed" << std::endl;
    }
}

void integer_underflow_tests()
{
    signed_underflow();
    unsigned_wrapping_underflow();
    pointer_underflow();
    underflow_compare();
}
