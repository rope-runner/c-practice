#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "slice.h"

int main() {
    slice *slc = init_slice();

    for (int i = 0; i < 10; i++) {
        add_element(slc, i + i);
    }

    printf("index: 2, val: %d \n", *at(slc, 69));

    return EXIT_SUCCESS;
}
