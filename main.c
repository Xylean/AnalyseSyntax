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

    /// Tests tableaux : création d'un tableau represantant la fonction cos(3*x+2) + exp(x)
    Item  * tab;
    tab = malloc (16*sizeof(Item));
    tab[0].valeur.fonction = COS;
    tab[0].token=FONCTION;

    tab[1].token=PARENTHESE_O;

    tab[2].token=PARENTHESE_O;

    tab[3].token=REEL;
    tab[3].valeur.reel=3;

    tab[4].valeur.operateur=MULTI;
    tab[4].token=OPERATEUR;

    tab[5].token=VARIABLE;

    tab[6].token=PARENTHESE_F;

    tab[7].valeur.operateur=PLUS;
    tab[7].token=OPERATEUR;

    tab[8].token=REEL;
    tab[8].valeur.reel=2;

    tab[9].token=PARENTHESE_F;

    tab[10].valeur.operateur=PLUS;
    tab[10].token=OPERATEUR;

    tab[11].valeur.fonction = EXP;
    tab[11].token=FONCTION;

    tab[12].token=PARENTHESE_O;

    tab[13].token=VARIABLE;

    tab[14].token=PARENTHESE_F;

    tab[15].token=FIN;

    /// Test afficherTableau
    /*afficherTableau(tab);
    printf("\n----------\n");*/

    /// Test tailleTableau
    /*printf("%d", tailleTableau(tab));
    printf("\n----------\n");*/

    /// Test scinderTableau
    /*Item * tab1;
    tab1 = scinderTableau(tab,5,8);
    afficherTableau(tab1);
    printf("\n----------\n");*/

    /// Test emplacementPremierTableau
    /*printf("%d", emplacementPremierOperateur(tab));
    printf("\n----------\n");*/

    /// Test supprimerParantheseInutile
    /*tab = scinderTableau(tab,0,9);
    afficherTableau(tab);
    printf("\n----------\n");
    printf("%d", nombreOperateurDisponible(tab));
    tab = scinderTableau(tab,1,1);
    afficherTableau(tab);
    printf("\n----------\n");
    tab = supprimerParantheseInutile(tab);
    afficherTableau(tab);
    printf("\n----------\n");*/

    /// Test de la fonction conversionTableauArbre
    //Arbre abr;
    //abr = creerArbre();
    //abr = conversionTableauArbre(abr,tab);
    //printTree(abr);



    //do{
        /*saisie(texte);
        equation = analyseLex(texte);
        arbre = analyseSyntax(equation);
        liste = evaluateur(arbre);
        graph(liste);*/
    //}while(1);
    return 0;
}
