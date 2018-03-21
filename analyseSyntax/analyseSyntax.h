#ifndef ANALYSESYNTAX_H_INCLUDED
#define ANALYSESYNTAX_H_INCLUDED

Arbre analyseSyntax(Item* token);

int tailleTableau(Item tab[]);

Item *scinderTableau(Item tab[], int debut, int fin);

Item *supprimerParantheseInutile(Item tab[]);

void afficherTableau(Item tab[]);

int emplacementPremierOperateur(Item tab[]);

Arbre conversionTableauArbre(Item tab[]);

#endif // ANALYSESYNTAX_H_INCLUDED
