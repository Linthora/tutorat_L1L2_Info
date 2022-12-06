#include <stdio.h>
#include <stdlib.h>

#include "math.h"

void afficher_pts(point_t * pp);

int main(int argc, char *argv[]) {
    printf("Hello World!");

    point_t * pp = create_point_p(5,5);
    afficher_pts(pp);

    int x = -5;
    printf("absolut value of %d: %d\n", x, val_abs(x));

    return 0;
}

void afficher_pts(point_t * pp) {
    printf("Point(%d,%d)\n", pp->x, pp->y);
}

// todo difference manipulation entre point_t et point_t *

/**
 * The command to compile main et math is:
 * gcc -c main.c math.c               /// ou juste 1 des deux
 * gcc math.o main.o -o exe
*/