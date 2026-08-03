#ifndef OUT_OF_BOUNDS_H
#define OUT_OF_BOUNDS_H

void write_past_buffer();
void array_index_out_of_bounds();
void pointer_arithmetic_out_of_bounds(int *array, int size);
void write_via_null_terminated_string();
void buffer_boundary_test();

#endif // OUT_OF_BOUNDS_H
