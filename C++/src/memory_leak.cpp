#include "memory_leak.h"
#include <cstring>
#include <iostream>

void memory_leak_reassignment(const char *input1, const char *input2)
{
    char *cache_data = new char[strlen(input1) + 1];
    strcpy(cache_data, input1);

    char *new_data = new char[strlen(input2) + 1];
    strcpy(new_data, input2);
    cache_data = new_data;
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

    ~DerivedResource()
    {
        delete[] extra_data;
    }
};

void leaky_function()
{
    ResourceManager *res = new DerivedResource(256);
    res->fill_data("test data");
    delete res;
}
