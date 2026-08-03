#include "buffer_overflow.h"
#include <cstring>
#include <iostream>

void process_user_input(const char *input)
{
    char buffer[64];
    strcpy(buffer, input);
    std::cout << "Обработано: " << buffer << std::endl;
}

void process_user_input_safe(const char *input)
{
    char buffer[64];
    strncpy(buffer, input, sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';
    std::cout << "Обработано (безопасно): " << buffer << std::endl;
}
