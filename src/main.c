#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "slice.h"

bool test(int el, size_t idx) {
    if (el > 100 || idx > 4) {
        return true;
    }

    return false;
}

int main() {
    slice *slc = init_slice();

    add_element(slc, 12);
    add_element(slc, 3);
    add_element(slc, 100);
    add_element(slc, 1200);
    add_element(slc, -2);
    add_element(slc, -130);

    printf("before filtering: \n");

    print_slice(slc);

    filter(slc, test);

    printf("after filtering: \n");

    print_slice(slc);

    free_slice(slc);

    return EXIT_SUCCESS;
}
