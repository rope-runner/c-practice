#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "slice.h"

/**
 * return pointer to empty slice
 */
slice *init_array() {
    slice *slc = (slice *) malloc(sizeof(slice));
    slc->len = 0;
    slc->data = (int *) malloc(sizeof(int) * 0);

    return slc;
}

/**
 * add element to the slice
 *
 * slice *arr - target slice
 * int element - element to add
 * 
 * return int - 0 for success, 1 - for failure
 */
int add_element(slice *slc, int element) {
    int *new = (int *) realloc(slc->data, sizeof(int) * (slc->len + 1));

    if (new == NULL) {
        printf("failed to allocate memory for new element");
        return 1;
    }

    slc->data = new;
    (slc->data)[slc->len] = element;
    slc->len++;

    return 0;
}

int remove_element(slice *slc, size_t index) {
    if (index > (slc->len - 1)) {
        printf("index out of boundaries \n");

        return 1;
    }
    
    for (size_t i = index; i < (slc->len - 1); i++) {
        (slc->data)[i] = (slc->data)[i+1];
    }

    int *new = (int *) realloc(slc->data, sizeof(int) * (slc->len - 1));

    if (new == NULL) {
        printf("failed to reallocate buffer \n");

        return 1;
    }

    slc->data = new;
    slc->len--;

    return 0;
}

void print_array(slice *slc) {
    if (slc->len == 0) {
        printf("array is empty. \n");
        return;
    }

    printf("capacity: %lu, len: %lu \n", slc->capacity, slc->len);

    for (size_t i = 0; i < slc->len; i++) {
        printf("idx: %lu, val: %d \n", i, (slc->data)[i]);
    }

    printf("\n");
}

