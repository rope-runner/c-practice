#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "slice.h"

int main() {
    slice *arr = init_array();

    print_array(arr);

    if (add_element(arr, 12) == 0) printf("added 12 \n");
    if (add_element(arr, 122) == 0) printf("added 122 \n");

    print_array(arr);


    remove_element(arr, 12);

    print_array(arr);


    remove_element(arr, 0);

    print_array(arr);

    return EXIT_SUCCESS;
}
