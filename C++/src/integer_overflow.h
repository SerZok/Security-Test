#ifndef INTEGER_OVERFLOW_H
#define INTEGER_OVERFLOW_H

#include <cstddef>

void process_size_overflow(int input_size);
void copy_with_overflow(const char *src, int src_size, char *dest, int dest_size);
void allocate_large_buffer(int count);

#endif // INTEGER_OVERFLOW_H
