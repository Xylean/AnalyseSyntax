#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#define SIZE 20000

#include "token.h"
#include "global.h"

//#include "analyseLex/analyseLex.h"
#include "analyseSyntax/analyseSyntax.h"
//#include "evaluateur/evaluateur.h"
//#include "graph/graph.h"

/** Mettre code de fin à la fin des tableaux **/

float start, stop;

int main()
{
    char texte[1000];
    Item* equation = NULL;
    Point* liste = NULL;
    Arbre arbre = NULL;

    liste = (Point*)malloc(sizeof(Point)*SIZE);

    /// Tests tableaux : création d'un tableau


    //do{
        /*saisie(texte);
        equation = analyseLex(texte);
        arbre = analyseSyntax(equation);
        liste = evaluateur(arbre);
        graph(liste);*/
    //}while(1);
    return 0;
}
