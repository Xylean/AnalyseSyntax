#ifndef ANALYSESYNTAX_H_INCLUDED
#define ANALYSESYNTAX_H_INCLUDED

Arbre analyseSyntax(Item*);

int testArbreValid (Arbre, int);

void freeArbre (Arbre);

void printTree (Arbre);

Arbre creerArbre();

Arbre creerNoeud (Arbre, Token, TypeValeur);

int testParentheseSimple (Item *);

int testParentheseComplex (Item *);

void testParentheseOuvert (Item *);

void testParentheseFerme (Item *);

void printErreur (Item *, int);

// Cette fonction retoure la taille du tableau mis en paramètre (l'Item FIN n'est pas compté)
int tailleTableau(Item *);

// Retourne un tableau qui ne contient que les Items entre les bornes mis en paramètre
Item *scinderTableau(Item *, int, int);

// Retourne le tableau mis en parrametre dont les paranthèses dites inutiles ont étées supprimées[ Exemple : ((((((x + 2)))))) --> x + 2 ]
Item *supprimerParantheseInutile(Item *);

// Affiche le tableau mis en parametre
void afficherTableau(Item *);

// Retourne le nombre d'opérateur disponible dans le tableau mis en paramètre (un opérateur est dit disponible lorsqu'il n'est pas entre paranthèse)
int nombreOperateurDisponible(Item *);

// Prends en paramètre un arbre vide et un tableau d'Item. Retourne le tableau convertit en arbre
Arbre conversionTableauArbre(Arbre, Item *);

#endif // ANALYSESYNTAX_H_INCLUDED
