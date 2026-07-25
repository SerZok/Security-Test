// CWE-401: Memory leak - утечка памяти
#include "memory_leak.h"
#include <cstring>
#include <iostream>

char *cache_data;
int cache_size = 0;

void store_data(const char *input)
{
    cache_data = new char[strlen(input) + 1];
    strcpy(cache_data, input);
    cache_size = strlen(input) + 1;
    // Уязвимость: cache_data не освобождается перед повторным выделением
}

void process_data_multiple_times(const char *input1, const char *input2, const char *input3)
{
    store_data(input1);
    store_data(input2); // ПЛОХО: утечка памяти от input1
    store_data(input3); // ПЛОХО: утечка памяти от input2
    // Утечка памяти от input3 при завершении
}

class ResourceManager
{
private:
    char *resource;
    int size;

public:
    ResourceManager(int s) : size(s)
    {
        resource = new char[size];
    }

    // Уязвимость: деструктор не виртуальный, при удалении через базовый указатель будет утечка
    ~ResourceManager()
    {
        delete[] resource;
    }

    void fill_data(const char *data)
    {
        strcpy(resource, data);
    }
};

class DerivedResource : public ResourceManager
{
private:
    char *extra_data;

public:
    DerivedResource(int s) : ResourceManager(s)
    {
        extra_data = new char[128];
    }

    // Уязвимость: деструктор не виртуальный
    ~DerivedResource()
    {
        delete[] extra_data;
    }
};

void leaky_function()
{
    ResourceManager *res = new DerivedResource(256);
    res->fill_data("test data");
    // ПЛОХО: delete res вызовет только деструктор ResourceManager, extra_data утечет
    delete res;
}
