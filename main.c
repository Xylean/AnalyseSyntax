#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

#include "token.h"
#include "global.h"
#include "menu/menu.h"
#include "analyseLex/analyseLex.h"
#include "analyseSyntax/analyseSyntax.h"
//#include "evaluateur/evaluateur.h"
//#include "graph/graph.h"

/** Mettre code de fin à la fin des tableaux **/

double start, stop;

void printArbre(Arbre b, int current_level, int max_level){
    //Affichage en infixe pour un affichage vertical
    int i;
    if (b != NULL) {
    //Il construit la partie existente de l'arbre
        printArbre(b->filsGauche, current_level + 1, max_level);
        for (i = 0; i < current_level; i++) {
            printf("               ");
        }
        printf("%d", b->item.token);
        printf("%d\n", b->item.valeur);
        printArbre(b->filsDroit, current_level + 1, max_level);
    } else {
    //IL construit la partie inexistente de l'arbre
        if (current_level < max_level) {
            printArbre(NULL, current_level + 1, max_level);
            for (i = 0; i < current_level; i++) {
                printf("               ");
            }
        printf("..\n");
        printArbre(NULL, current_level + 1, max_level);
        }
    }
}

int main()
{
    char texte[SIZE];
    Item* equation = NULL;
    Point* liste = NULL;
    Arbre arbre = NULL;

    start = -100;
    stop = 100;

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

    /// Test afficherTableaub
    test_afficherTableau(tab);

    /// Test tailleTableau
    test_tailleTableau(tab);

    /// Test scinderTableau
    test_scinderTableau(tab);

    /// Test nombreOperateurDisponible
    test_nombreOperateurDisponible(tab);

    /// Test supprimerParantheseInutile
    test_supprimerParantheseInutile(tab);

    /// Test conversionTableauArbre
    test_conversionTableauArbre(tab);

    ///Test analyseSyntax
    test_analyseSyntax(tab);

    //menu();
    /*do{
        saisie(texte);
       char* texte = "((1)+(x)+(1))\n"; //+(1)\n";
        equation = analyseLex(texte);

        lectureItem(equation);printf("\n");
        afficherTableau(equation);
        //printf("La taille : %d\n", tailleTableau(equation));


       // printf("Nombre d'opérateur disponible dans la fonction : %d", nombreOperateurDisponible(equation));
        arbre = analyseSyntax(equation);
        //equation = supprimerPare3ntheseInutile(equation);
        //afficherTableau(equation);

        printArbre(arbre, 0, 6);

        //liste = evaluateur(arbre, start, stop);
        //graph(liste);
        free(liste);
        free(equation);
    }while(0);*/
    return 0;
}
