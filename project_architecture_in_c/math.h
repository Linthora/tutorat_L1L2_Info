#ifndef __MATH_H__
// cette ligne regarde si la constante __MATH_H__ est défini.
// si ce n'est pas le cas, on reprend la lecture à la fin de ce if.

#define __MATH_H__
// ici on défini la constante __MATH_H__
// Elle sert à faire comprendre au compilateur qu'on a déjà inclu ce fichier.

/**
 * Structure:
 * En terme de nom et usage: 
 * 1: point_s est le nom de la structure:
 *      - pour l'utiliser en tant que tel il faut faire:
 *      struct point_s mon_point; pour l'utiliser
 * 
 * 2: point_t est un alias de 'struct point_s':
 *      - cela permet d'utiliser directement la structure comme tel:
 *      point_t mon_point;
 */
typedef struct point_s {
    int x;
    int y;
} point_t;

// Déclaration de la fonction pour créer un point:
point_t create_point(int x, int y);

// Déclaration de la création qui crée un point_t sous forme de pointeur:
point_t * create_point_p(int x, int y);

// Déclaration de la fonction qui détruit un point.
void delete_point_p(point_t * pp);

// Déclaration de la fonction pour créer un tableau de n points
point_t ** create_array_of_point(unsigned int n);

// Déclaration de la fonction pour détruire un tableau de n points
void delete_array_of_point(point_t ** arr, unsigned int n);


//////////////////////////////// les fonctions mathématiques d'exemple

// Déclaration de la fonction pour faire l'opération valeur absolue:
int val_abs(int x);

// Déclaration de la fonction pour mettre au carré
int expo(int x, int n);

// Déclaration de la fonction pour mettre au carré un entier en moins d'opération.
int speed_expo(int x, int n);


#endif
// fin de la condition du if au début du fichier, autrement dit on ne lit rien d'autre.
