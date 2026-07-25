cmake_minimum_required(VERSION 3.10)
project(Security-Test VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-w)

add_executable(security_test
    src/main.cpp
    src/buffer_overflow.cpp
    src/command_injection.cpp
    src/use_after_free.cpp
    src/weak_crypto.cpp
    src/hardcoded_secrets.cpp
    src/integer_overflow.cpp
    src/memory_leak.cpp
    src/invalid_free.cpp
    src/out_of_bounds.cpp
    src/divide_zero.cpp
    src/null_pointer.cpp
    src/heap_overflow.cpp
)

find_package(OpenSSL QUIET)
if(OpenSSL_FOUND)
    target_link_libraries(security_test OpenSSL::SSL OpenSSL::Crypto)
    target_compile_definitions(security_test PRIVATE HAS_OPENSSL)
endif()
