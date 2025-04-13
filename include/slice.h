#ifndef SLICE__H__
#define SLICE__H__

#include <stddef.h>

typedef struct slice {
    int *data;
    size_t len;
    size_t capacity;
} slice;

int add_element(slice *, int);

void print_slice(slice *);

slice *init_slice(void);

int remove_element(slice *, size_t);

#endif
