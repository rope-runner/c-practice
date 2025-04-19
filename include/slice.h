#ifndef SLICE__H__
#define SLICE__H__

#include <stddef.h>
#include <stdbool.h>

typedef struct slice {
    int *data;
    size_t len;
    size_t capacity;
} slice;

/**
 * Filtering function interface, which accepts 
 * element and index, must return bool value
 * for each entry
 */
typedef bool (*filter_fn)(int, size_t);

int add_element(slice *, int);

void print_slice(slice *);

slice *init_slice(void);

int remove_element(slice *, size_t);

int index_of(slice *, int);

int *at(slice *, int);

slice *concat(slice *, slice *);

void free_slice(slice *);

slice *filter(slice *slc, filter_fn);

#endif
