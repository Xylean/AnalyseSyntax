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
    /*char texte[1000];
    Item* equation = NULL;
    Point* liste = NULL;
    Arbre arbre = NULL;

    liste = (Point*)malloc(sizeof(Point)*SIZE);*/

    /// Tests tableaux : création d'un tableau
    Item tab[16];
    tab[0].valeur.fonction = COS;
    tab[1].token=PARENTHESE_O;
    tab[2].token=PARENTHESE_O;
    tab[3].token=REEL;
    tab[3].valeur.reel=3;
    tab[4].valeur.operateur=MULTI;
    tab[5].token=VARIABLE;
    tab[6].token=PARENTHESE_F;
    tab[7].valeur.operateur=PLUS;
    tab[8].token=REEL;
    tab[8].valeur.reel=2;
    tab[9].token=PARENTHESE_F;
    tab[10].valeur.operateur=PLUS;
    tab[11].valeur.fonction = EXP;
    tab[12].token=PARENTHESE_O;
    tab[13].token=VARIABLE;
    tab[14].token=PARENTHESE_F;
    tab[15].token=FIN;

    /// Test tailleTableau
    printf("%d", tailleTableau(tab));


    //do{
        /*saisie(texte);
        equation = analyseLex(texte);
        arbre = analyseSyntax(equation);
        liste = evaluateur(arbre);
        graph(liste);*/
    //}while(1);
    return 0;
}
