#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "slice.h"

static size_t DEFAULT_SLICE_SIZE = 10;
static size_t BASE_GROWTH_FACTOR = 2;
static float SHRINK_FACTOR = 0.7;

/**
 * return pointer to empty slice
 */
slice *init_slice() {
    slice *slc = (slice *) malloc(sizeof(slice));
    slc->len = 0;
    slc->data = (int *) malloc(sizeof(int) * DEFAULT_SLICE_SIZE);
    slc->capacity = DEFAULT_SLICE_SIZE;

    return slc;
}

/**
 * add element to the slice
 *
 * slice *slc - target slice
 * int element - element to add
 * 
 * return int - 0 for success, 1 - for failure
 */
int add_element(slice *slc, int element) {
    if ((slc->capacity) > (float) (slc->len + 1)) {
        (slc->data)[slc->len] = element;
        slc->len++;

        return 0;
    } else {
        int *new = (int *) realloc(slc->data, sizeof(int) * (slc->capacity * BASE_GROWTH_FACTOR));

        if (new == NULL) {
            printf("add failed: failed to reallocate buffer. \n");

            return 1;
        }

        slc->capacity = (slc->capacity) * BASE_GROWTH_FACTOR;
        slc->data = new;
        (slc->data)[slc->len] = element;
        slc->len++;

        return 0;
    }
}

/**
 * remove element from the slice
 *
 * slice *slc - target slice
 * size_t index - element to add
 * 
 * return int - 0 for success, 1 - for failure
 */
int remove_element(slice *slc, size_t index) {
    if (index > (slc->len - 1)) {
        printf("index out of boundaries \n");

        return 1;
    }
    
    for (size_t i = index; i < (slc->len - 1); i++) {
        (slc->data)[i] = (slc->data)[i+1];
    }

    if ((slc->len - 1) < (slc->capacity * SHRINK_FACTOR)) {
        int *new = (int *) realloc(slc->data, sizeof(int) * (slc->len - 1));

        if (new == NULL) {
            printf("failed to reallocate buffer \n");

            return 1;
        }

        slc->capacity = (slc->len) - 1;
        slc->data = new;
    } else {
        (slc->data)[slc->len - 1] = 0;
    }

    slc->len--;
    return 0;
}

void print_slice(slice *slc) {
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

