#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "slice.h"

int main() {
    slice *slc1 = init_slice();
    slice *slc2 = init_slice();

    slice *slc3 = concat(slc1, slc2);

    print_slice(slc3);

    return EXIT_SUCCESS;
}
