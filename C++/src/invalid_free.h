// CWE-590: Free of memory not on heap
#ifndef INVALID_FREE_H
#define INVALID_FREE_H

void free_stack_memory();
void free_global_memory();
void double_free_example();
void use_after_free_advanced();
void invalid_free_test();

#endif // INVALID_FREE_H
