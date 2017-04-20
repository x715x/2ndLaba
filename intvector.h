#ifndef INTVECTOR_H
#define INTVECTOR_H
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} intVector;

intVector* int_vector_new(size_t initial_capacity);
intVector *int_vector_copy(const intVector *vect);
void int_vector_free(intVector *vect);
int int_vector_get_item(const intVector *vect, size_t index);
void int_vector_set_item(const intVector *vect, size_t index, int item);
size_t int_vector_get_size(const intVector *vect);
size_t int_vector_get_capacity(const intVector *vect);
int int_vector_push_back(intVector *vect, int item);
void int_vector_pop_back(intVector *vect);
int int_vector_shrink_to_fit(intVector *vect);
int int_vector_resize(intVector *vect, size_t new_size);
int int_vector_reserve(intVector *vect, size_t new_capacity);
void print_vector(intVector *vect);
#endif
