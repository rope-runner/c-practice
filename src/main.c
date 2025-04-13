#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "slice.h"

int main() {
    slice *arr = init_array();

    print_array(arr);

    add_element(arr, 1);
    add_element(arr, 2);
    add_element(arr, 3);
    add_element(arr, 4);
    add_element(arr, 5);
    add_element(arr, 6);
    add_element(arr, 7);

    print_array(arr);

    add_element(arr, 8);
    print_array(arr);

    return EXIT_SUCCESS;
}
