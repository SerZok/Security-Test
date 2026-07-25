// CWE-122: Heap-based buffer overflow
#ifndef HEAP_OVERFLOW_H
#define HEAP_OVERFLOW_H

void heap_buffer_overflow();
void heap_overflow_with_format(const char *input);
void heap_overflow_with_snprintf_fix();
void double_heap_overflow();
void heap_overflow_tests();

#endif // HEAP_OVERFLOW_H
