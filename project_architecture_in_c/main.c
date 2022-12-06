#include <stdio.h>
#include <stdlib.h>

#include "math.h"

int main(int argc, char *argv[]) {
    printf("Hello World!");

    point_t * pp = create_point_p(5,5);
    afficher_pts(pp);

    return 0;
}

void afficher_pts(point_t * pp) {
    printf("Point(%d,%d", pp->x, pp->y);
}

// todo difference manipulation entre point_t et point_t *

/**
 * The command to compile main et math is:
 * gcc -o main main.c math.c
 * // voir warning et erreur
*/