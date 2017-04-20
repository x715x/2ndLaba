#include "intvector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    size_t i;
    intVector* vctr;
    vctr = int_vector_new(10);
    int_vector_reserve(vctr, 22);
    int_vector_push_back(vctr, 10);
    print_vector(vctr);
    int_vector_push_back(vctr, 12);
    print_vector(vctr);
    for(i = 0; i < 13; ++i){
        int_vector_push_back(vctr, i*i);
    }
    print_vector(vctr);
    int_vector_pop_back(vctr);
    print_vector(vctr);
    for (i = 0; i < 10; ++i){
        int_vector_set_item(vctr, i, i+i);
    };
    print_vector(vctr);
    int_vector_shrink_to_fit(vctr);
    print_vector(vctr);
    int_vector_resize(vctr, 20);
    print_vector(vctr);
    intVector *vctr2;
    vctr2 = int_vector_copy(vctr);
    print_vector(vctr2);
    int_vector_reserve(vctr2, 22);
    print_vector(vctr2);
    int_vector_free(vctr2);
    int_vector_free(vctr);
    return 0;
}
