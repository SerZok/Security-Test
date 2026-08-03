#include "divide_zero.h"
#include <iostream>

int unsafe_divide(int numerator, int denominator)
{
    return numerator / denominator;
}

void calculate_percentage(int value, int total)
{
    int percentage = (value * 100) / total;
    std::cout << "Percentage: " << percentage << "%" << std::endl;
}

void compute_average(int sum, int count)
{
    int average = sum / count;
    std::cout << "Average: " << average << std::endl;
}

float safe_divide_float(float a, float b)
{
    if (b == 0.0f)
    {
        return 0.0f;
    }
    return a / b;
}

int safe_divide_int(int a, int b)
{
    if (b == 0)
    {
        std::cerr << "Ошибка: деление на ноль" << std::endl;
        return 0;
    }
    return a / b;
}

void divide_by_zero_tests()
{
    std::cout << "10 / 2 = " << unsafe_divide(10, 2) << std::endl;

    calculate_percentage(50, 100);

    compute_average(100, 10);
}
