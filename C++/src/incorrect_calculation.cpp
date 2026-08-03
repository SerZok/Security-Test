#include "incorrect_calculation.h"
#include <iostream>

void off_by_one_error()
{
    int array[10] = {0};
    int sum = 0;

    for (int i = 1; i <= 10; i++)
    {
        sum += array[i];
    }
    std::cout << "Sum: " << sum << std::endl;
}

void wrong_operator_usage()
{
    int value = 0;
    if (value = 10)
    {
        std::cout << "Value is: " << value << std::endl;
    }
}

void logic_error_in_comparison()
{
    int x = 5;
    int y = 10;

    if (x > 0 || y > 0)
    {
        std::cout << "Both should be negative" << std::endl;
    }
}

void incorrect_math_for_loop()
{
    int total = 100;
    int step = 0;

    for (int i = 0; i < total; i += step)
    {
        std::cout << "i = " << i << std::endl;
    }
}

void incorrect_calculation_tests()
{
    off_by_one_error();
    wrong_operator_usage();
    logic_error_in_comparison();
    incorrect_math_for_loop();
}
