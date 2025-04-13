#include <stdio.h>
#include <math.h>
#include <stdint.h>

void overflow() {
    int16_t a = 0;

    int current;
    for (int i = 0; i < 12; i++) {
        current = pow((double) i, (double) i);

        printf("i: %d \n", i);
        if (INT16_MAX - a < current) {
            printf("overflow, exiting! \n");
            break;
        } else {
            a += current;
            printf("a: %d \n", (int) a);
        }
    }

}
