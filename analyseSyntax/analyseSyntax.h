#ifndef ANALYSESYNTAX_H_INCLUDED
#define ANALYSESYNTAX_H_INCLUDED

Arbre analyseSyntax(Item*);

int testArbreValid (Arbre, int);

void freeArbre (Arbre);

void printTree (Arbre);

Arbre creerArbre();

Arbre creerNoeud (Arbre, Token, TypeValeur);

int testParentheseSimple (Item *);

void testParentheseComplex (Item *);

void testParentheseOuvert (Item *);

void testParentheseFerme (Item *);

void printErreur (Item *, int);

int tailleTableau(Item *);

Item *scinderTableau(Item *, int, int);

Item *supprimerParantheseInutile(Item *);

void afficherTableau(Item *);

int nombreOperateurDisponible(Item *);

Arbre conversionTableauArbre(Arbre, Item *);

#endif // ANALYSESYNTAX_H_INCLUDED
