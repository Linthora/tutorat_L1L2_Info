#include <stdio.h>
#include <stdlib.h>

#include "math.h"

void afficher_pts(point_t * pp);

int * create_array(unsigned int n);

//void afficher_array_pts(point_t[] arr, unsigned int n);
void afficher_array_pts(point_t** arr, unsigned int n);

int main(int argc, char *argv[]) {
    printf("Hello World!");

    point_t * pp = create_point_p(5,5);
    afficher_pts(pp);
    delete_point_p(pp);

    int x = -5;
    printf("absolut value of %d: %d\n", x, val_abs(x));

    printf("\n\nTestMalloc pour liste\n");
    int n = 10;
    point_t ** array_of_point_p = create_array_of_point(n);
    printf("Taille de notre tableau fait avec un pointeur: %ld\n", sizeof(array_of_point_p));
    point_t test_array[n];
    printf("Taille de notre tableau fait sans les pointeurs: %ld\n", sizeof(test_array));
    printf("taille pointeur quelconque sur notre machine: %ld\n", sizeof(void*));

    // exemple de manipulation
    printf("\nAffichons notre tableau de points:\n");
    for(int i=0; i < n; i++) {
      afficher_pts(array_of_point_p[i]);
    }

    printf("\nAvec notre deuxième méthode:\n");
    afficher_array_pts(array_of_point_p, n);

    //afficher_array_pts(test_array, n);

    delete_array_of_point(array_of_point_p, n);

    printf("\n\nFin des tests sur malloc\n");
    int* arr_int = create_array(n);
    for(int i=0; i < n; ++i) {
      printf("Entier de arr[%d] = %d\n", i, arr_int[i]);
    }
    arr_int[2] = 7;
    arr_int[6] = 435;
    free(arr_int);
    arr_int = create_array(n);
    for(int i=0; i < n; ++i) {
      printf("Entier de arr[%d] = %d\n", i, arr_int[i]);
    }
    free(arr_int);


    return 0;
}

void afficher_pts(point_t * pp) {
    printf("Point(%d,%d)\n", pp->x, pp->y);
}

//void afficher_array_pts(point_t[] arr, unsigned int n) {
void afficher_array_pts(point_t** arr, unsigned int n) {
  for(int i=0; i < n; ++i) {
    afficher_pts(arr[i]);
  }
  arr = NULL;
}

int * create_array(unsigned int n) {
  int * array = malloc( n * sizeof(int) );
  // demo si on a pas initalisé (commenter la boucle for).
  /*for(int i=0; i < n; ++i) {
    array[i] = 0;
    }*/
  return array;
}


/**
 * Pour compiler main et math:
 * gcc -c main.c math.c               /// ou juste 1 des deux
 * gcc math.o main.o -o exe
 *
 * Ou: directement gcc math.c main.c -o exe
 * mais ne créera pas les .o
 *
 * tests des fuites de mémoires:
 * valgrind --tool=memcheck ./exe
*/
