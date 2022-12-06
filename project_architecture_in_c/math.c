#include "math.h"
#include <stdlib.h>

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

/**
 * La logique pour détruire un tableau de valeur est à peu prêt la même.
 * Il me faut simplement pas oublier d'aller libérer l'espace de chaque point avant de libérer le premier pointeur.
*/
void delete_array_of_point(point_t ** arr, unsigned int n) {
    // on désaloue l'espace alloué précédement à chaque point.
    for(int i=0; i < n; ++i) {
        free(arr[i]); 
    }

    // puis on libère le pointeur vers le tableau de point.
    free(arr);
}


//////////////////////////////// les fonctions mathématiques d'exemple

/**
 * La fonction pour retourner la valeur absolue d'un entier.
 * 
 * La 1ere version est volontairement erroné, on peut la commenter et décommenter l'autre
 * et vis versa pour tester celle que l'on souhaite et illustrer le fonctionnement des fichier en .o
*/
// 1ère version, volontairement erronée.
int val_abs(int x) {
    return x;
}
// 2ème version, correcte
/* int val_abs(int x) {
    // j'utilise ici l'opérateur ternaire: il fonctionne de la façon suivante:
    // à la manière d'un if else, il evalue l'expersion avant le '?' (ici: x est-il négatif)
    // si elle est vrai, alors il choisi l'expression juste après le '?' (ici: -x)
    // sinon l'expression après le ':' (ici x)
    // on pourrait le lire comme: if (x < 0) then -x else x
    // ou (notation en python): (-x) if (x < 0) else (x)     // les parenthèse ne sont pas obligatoire.
    return (x < 0) ? -x : x;
} */


/**
 * Fonction pour retourner la puissance n d'un entier x donnée
*/
int expo(int x, int n) {
    int res = 1;
    for(int i=0; i < n; ++i) {
        res *= x; 
        // l'opérateur *= veut est équivalent à faire res = res * x
        // il existe un opérateur similaire += ou /= pour faire respectivement res = res + x ou res = res / x
    }
    return res;
}

/**
 * Il existe une méthode plus rapide (autrement dit dans un nombre d'étape moins grand)
 * pour faire une puissance.
*/
int speed_expo(int x, int n) {
    if(n <= 0) { // on regarde si n = 0, ce qui voudrait dire qu'on l'entier à renvoyer est 1. car pour tout entier à la puissance 0, il est égale à 1.
        return 1;
    }
    if(n == 1) { // si n = 1, alors on retourn x, car tout entier à la puissance 1 est égale à lui même.
        return x;
    }

    int tmp = speed_expo(x, n/2); // comme on sait maintenant que n >= 2, on peut donc diviser le problème en 2 en faisant (x^(n/2))^2 
    if(n % 2 == 0) { // si n est pair, alors on peut diviser n entièrement sans reste et donc continuer comme ça
        return tmp * tmp;
    }

    // dans le cas ou n n'est pas pair, on peut donc le diviser par 2 mais en ayant un reste de 1, il s'agit donc de la même chose
    // que ci-dessus, mais en prenant ce reste en considération, ici, notre x
    return tmp*tmp* x;

}