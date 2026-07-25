// CWE-369: Divide by zero - деление на ноль
#include "divide_zero.h"
#include <iostream>

int unsafe_divide(int numerator, int denominator)
{
    // Уязвимость: нет проверки делителя
    return numerator / denominator; // ПЛОХО: denominator может быть 0
}

void calculate_percentage(int value, int total)
{
    // Уязвимость: деление без проверки
    int percentage = (value * 100) / total; // ПЛОХО: total может быть 0
    std::cout << "Percentage: " << percentage << "%" << std::endl;
}

void compute_average(int sum, int count)
{
    // Уязвимость: деление на count без проверки
    int average = sum / count; // ПЛОХО: count может быть 0
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
    // unsafe_divide(10, 0); // Сработает деление на ноль

    calculate_percentage(50, 100);
    // calculate_percentage(50, 0); // Сработает деление на ноль

    compute_average(100, 10);
    // compute_average(100, 0); // Сработает деление на ноль
}
