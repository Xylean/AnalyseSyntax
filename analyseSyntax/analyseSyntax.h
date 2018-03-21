#ifndef ANALYSESYNTAX_H_INCLUDED
#define ANALYSESYNTAX_H_INCLUDED

Arbre analyseSyntax(Item* token);

int testArbreValid (Arbre, int);
Arbre creerArbre();
Arbre creerNoeud (Arbre, Token, TypeValeur);
int testParentheseSimple (Item *);
void testParentheseComplex (Item *);
void testParentheseOuvert (Item *);
void testParentheseFerme (Item *);
void printErreur (Item *, int);

int tailleTableau(Item tab[]);

Item *scinderTableau(Item tab[], int debut, int fin);

Item *supprimerParantheseInutile(Item tab[]);

void afficherTableau(Item tab[]);

int emplacementPremierOperateur(Item tab[]);

Arbre conversionTableauArbre(Item tab[]);

#endif // ANALYSESYNTAX_H_INCLUDED
