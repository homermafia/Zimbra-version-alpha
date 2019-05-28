#include <stdio.h>
#include <stdlib.h>

void vider_buffer(void) {
    int c = getchar();

    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}
