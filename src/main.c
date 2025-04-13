#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "slice.h"

int main() {
    slice *slc = init_slice();

    print_slice(slc);

    add_element(slc, 1);
    add_element(slc, 2);
    add_element(slc, 3);
    add_element(slc, 4);
    add_element(slc, 5);
    add_element(slc, 6);
    add_element(slc, 7);

    print_slice(slc);

    add_element(slc, 8);
    print_slice(slc);

    return EXIT_SUCCESS;
}
