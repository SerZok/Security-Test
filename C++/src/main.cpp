#include <iostream>
#include "buffer_overflow.h"
#include "command_injection.h"
#include "use_after_free.h"
#include "weak_crypto.h"
#include "hardcoded_secrets.h"
#include "integer_overflow.h"
#include "memory_leak.h"
#include "invalid_free.h"
#include "out_of_bounds.h"
#include "divide_zero.h"
#include "null_pointer.h"
#include "heap_overflow.h"

int main()
{
    std::cout << "=== Тест-суйт для проверки безопасности ===" << std::endl;

    // Тест переполнения буфера
    std::cout << "\n1. Тестирование переполнения буфера..." << std::endl;
    process_user_input("short_input");
    process_user_input_safe("short_input");

    // Тест инъекции команд
    std::cout << "\n2. Тестирование инъекции команд..." << std::endl;
    execute_command("test");
    execute_command_safe("test");

    // Тест use-after-free
    std::cout << "\n3. Тестирование use-after-free..." << std::endl;
    Data *d = create_data(10);
    process_data(d);

    // Тест слабой криптографии
    std::cout << "\n4. Тестирование слабой криптографии..." << std::endl;
    std::string hash = hash_password_weak("password123");
    std::cout << "MD5 hash: " << hash << std::endl;
    encrypt_data_weak("sensitive_data", "key");

    // Тест захардкоженных секретов
    std::cout << "\n5. Тестирование захардкоженных секретов..." << std::endl;
    bool auth = authenticate("admin", "SuperSecretPassword123!");
    std::cout << "Результат аутентификации: " << (auth ? "успех" : "неудача") << std::endl;
    std::cout << "API ключ: " << get_api_key() << std::endl;

    // Тест целочисленного переполнения
    std::cout << "\n6. Тестирование целочисленного переполнения..." << std::endl;
    process_size_overflow(1000);
    allocate_large_buffer(1000000);

    // Тест утечек памяти
    std::cout << "\n7. Тестирование утечек памяти..." << std::endl;
    process_data_multiple_times("data1", "data2", "data3");
    leaky_function();

    // Тест невалидного освобождения памяти
    std::cout << "\n8. Тестирование невалидного освобождения..." << std::endl;
    invalid_free_test();

    // Тест выхода за границы буфера
    std::cout << "\n9. Тестирование выхода за границы..." << std::endl;
    buffer_boundary_test();

    // Тест деления на ноль
    std::cout << "\n10. Тестирование деления на ноль..." << std::endl;
    divide_by_zero_tests();

    // Тест разыменования null-указателей
    std::cout << "\n11. Тестирование null-указателей..." << std::endl;
    null_pointer_tests();

    // Тест переполнения кучи
    std::cout << "\n12. Тестирование переполнения кучи..." << std::endl;
    heap_overflow_tests();

    return 0;
}
