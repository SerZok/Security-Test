// CWE-401: Memory leak - утечка памяти
#ifndef MEMORY_LEAK_H
#define MEMORY_LEAK_H

void store_data(const char *input);
void process_data_multiple_times(const char *input1, const char *input2, const char *input3);
void leaky_function();

#endif // MEMORY_LEAK_H
