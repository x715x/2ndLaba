#include "intvector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

intVector *int_vector_new(size_t initial_capacity){
    intVector *vect;
    vect = malloc(sizeof(intVector));
    if(vect != NULL){ 
        vect->data = calloc(initial_capacity, sizeof(int)); 
        if(vect->data != NULL){
            vect->size = 0;
            vect->capacity = initial_capacity;
        } else {
            free(vect);
        }
    } else {
        free(vect);
    }
    return vect;
}

intVector *int_vector_copy(const intVector *vect){
    int i;
    intVector *newvect;
    newvect = int_vector_new(vect->capacity);
    if(newvect == NULL){
        free(newvect);
    } else {
        for(i = 0; i < vect->size; i++){
            newvect->size = vect->size;
        }
        newvect->size = vect->size;
    }
    return newvect;
}                
void int_vector_free(intVector *vect){
    if(vect != NULL){
        free(vect->data);
        free(vect);
    }
}
int int_vector_get_item(const intVector *vect, size_t index){
        return vect->data[index];
}        
        
void int_vector_set_item(const intVector *vect, size_t index, int item){

    if((index <= vect->capacity) && (index >= 0)){
        vect->data[index] = item;
    }
}

size_t int_vector_get_size(const intVector *vect){
        return vect->size;
}

size_t int_vector_get_capacity(const intVector *vect){
        return vect->capacity;
}

int int_vector_push_back(intVector *vect, int item){
    if((vect != NULL) && (vect->data != NULL)){
        if(vect->size < vect->capacity){
            vect->data[vect->size] = item;
            ++vect->size;
            return 0;
        } else {
        vect->data = realloc(vect->data, sizeof(int) * (vect->capacity * 2));
        vect->capacity = vect->capacity * 2;
        vect->data[vect->size] = item;
        ++vect->size;
        return 0;
        }
    } else {
        return -1;
    }
}

void int_vector_pop_back(intVector *vect){
    if((vect != NULL) && (vect->size != 0)){
        vect->size = vect->size - 1;
    }
}

int int_vector_shrink_to_fit(intVector *vect){
    int* t;
    if((vect != NULL) && (vect->size < vect->capacity)){
        t = realloc(vect->data, vect->size * sizeof(int));
        vect->data = t;
        vect->capacity = vect->size;
        return 0;
    } else {
        return -1;
    }
}

int int_vector_resize(intVector *vect, size_t new_size){
    if((vect != NULL) && (new_size < vect->capacity)){
        if(new_size < vect->size){
            vect->data = realloc(vect->data, sizeof(int) * new_size);
            vect->size = new_size;
            vect->capacity = vect->size;
        } else {
        if(vect->size < vect->capacity){
              
            for(size_t i = vect->size; i < new_size; ++i){
                if((i <= vect->capacity) && (i >= 0)){
                    vect->data[i] = 0;  
                }
            }
            return 0;
            }
        }
        return 0;
        } else {
        return -1;
    }
}                 
int int_vector_reserve(intVector *vect, size_t new_capacity){
    int *data;
	if(new_capacity > vect->capacity){
		data = realloc(vect->data, new_capacity * sizeof(int));
		if (data == NULL){
		    return -1;
	    }
        vect->capacity = new_capacity;
        vect->data = data;
        return 0;
   } else {
        return -1;
   }
}        
void print_vector(intVector *vect){
    size_t i;
    printf("size = %zu\ncapacity = %zu\n",int_vector_get_size(vect), int_vector_get_capacity(vect));
    for(i = 0; i < int_vector_get_size(vect); i++){
        printf("%d ", int_vector_get_item(vect, i));
    }
    printf("\n\n\n");
}        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
