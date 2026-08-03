#include "command_injection.h"
#include <cstdlib>
#include <iostream>

void execute_command(const std::string &user_input)
{
    std::string command = "echo " + user_input;
    system(command.c_str());
}

void execute_command_safe(const std::string &user_input)
{
    for (char c : user_input)
    {
        if (!isalnum(c) && c != ' ' && c != '.' && c != '-')
        {
            std::cerr << "Неверный ввод" << std::endl;
            return;
        }
    }
    std::string command = "echo " + user_input;
    system(command.c_str());
}
