#ifndef ANALYSELEX_H_INCLUDED
#define ANALYSELEX_H_INCLUDED

#include "../token.h"

void saisie(char* equation);
Item* analyseLex(char* texte); //Renvoie un pointeur vers la struc item
Item creationItem(char premierelettre, char* temp);
Item test_array(char car);
Item typevaleur_operateur(char charactere);
Item typevaleur_fonction(char* str);
void lectureItem(Item* tabItems);
void delete_blank_space(Item* tabItems);

int tailletabItems(Item* tabItems);
Item* processingitemarray(Item* tabItems);
Item* insererparantouvrante(Item* tabItems, int position);
Item* insererparantfermante(Item* tabItems, int position);
Item* checkparantgauche(Item* tabItems, int position);
Item* checkparantdroite(Item* tabItems, int position);
Item* setparantdroite(Item* tabItems, int position);
Item* setfoisvariable(Item* tabItems, int position);
Item* insererfois(Item* tabItems, int position);
#endif // ANALYSELEX_H_INCLUDED
