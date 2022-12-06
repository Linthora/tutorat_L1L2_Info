

/**
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

// Déclaration de la fonction pour créer un tableau de points:
point_t ** create_array_of_point(unsigned int n);

// Déclaration de la fonction pour détruire un tableau de points:
void delete_array_of_point(unsigned int n);

// Déclaration de la fonction pour faire l'opération valeur absolue:
unsigned int val_abs(int x);

// Déclaration de la fonction pour mettre au carré
int exp(int x, int n);