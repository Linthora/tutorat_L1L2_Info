#include "math.h"

/**
 * La définition de la fonction déclarée dans le fichier en .h
*/
point_t create_point(int x, int y) {
    point_t res; // on commence par initialisé la variable directement.
    res.x = x; // puis on lui donne ces attributs directement à l'endroit de sa déclaration avec <nom>.<attribut visé> = ...;
    res.y = y;
    return res; // cette méthode de création de nécessite pas de destruction.
}

/**
 * Création d'un pointeur sur un point dont on nous donne les attributs.
 * Nécessite d'être détruit pour libérer la mémoire.
*/
point_t * create_point_p(int x, int y) {
    // on déclare le type de la variable suivit d'une étoile pour indiqué sa nature de pointeur
    // la fonction malloc va attribuer un espace de taille donné dans le tas. Et retourner un pointeur sur cet espace alloué..
    // sizeof retourne la taille en octet de la strucutre donnée.
    point_t * res_p = malloc(sizeof(point_t));
    res_p->x = x; // on peut ensuite initialisé chacun des attributs avec ceux donnés grâce a une flèche.
    res_p->y = y;
    return res_p;
}

/**
 * Fonction pour désalouer (libérer) l'espace attribué à un point.
 * Cela permet de ne pas trop entammer la mémoire ce qui peut faire planter le programme.
*/
void delete_point_p(point_t * pp) {
    free(pp);
}

/**
 * Malloc pour créer des tableau de pointeurs sur point:
 * Il s'agit de la même chose mais il faut le faire en plusieurs étapes:
*/
point_t ** create_array_of_point(unsigned int n) {
    // on commence par attribuer un espace vers un nombre de pointeurs de la taille de notre tableau.
    point_t ** res  = malloc(sizeof(point_t*) * n);

    // on doit ensuite attribuer pour chacun de ces points un espace également:
    for(int i=0; i < n; ++i) {
        // première option, tout faire à la main:
        //res[i] = malloc(sizeof(point_t));
        //res[i]->x = 0;
        //res[i]->y = 0;

        // deuxième option, réutiliser ce qu'on a fait précedement:
        res[i] = create_point_p(-i,i);
    }
    // note: il est préférable de tout initalisé à 0 (ou une valeur par défaut décidée pour être sur de ce 
    // qu'on trouvera si jamais on se manipule directement sans avoir instancié ces valeur)

    return res;
}


