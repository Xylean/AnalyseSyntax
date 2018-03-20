#include <malloc.h>
#include <stdio.h>
#include "../token.h"

//
// Created by xyle7 on 20/03/2018.
int tailleTableau(Item tab[])
{
    int i = 0;
    while (tab [i].token != FIN){
        i++;
    }
    return i+1;
}

Item *scinderTableau(Item tab[], int debut, int fin)
{
    int difference = fin - debut, i, taille = tailleTableau(tab);
    Item *tableau = malloc((difference+2)*sizeof(Item));
    if (difference < taille){
        for (i = debut; i <= fin; i ++)
        {
            tableau[i-debut] = tab[i];
        }
        if (tab[fin].token != FIN) tableau[difference+2].token=FIN;
    } else tableau = tab;
    return tableau;
}

int emplacementPremierOperateur(Item tab[])
{
    int i = 0, res;
    while ((tab[i].token != OPERATEUR) && (tab[i].token != FIN ))
    {
        i++;
    }
    if (tab[i].token == FIN) res =-1;
    else res= i;
    return res;
}

Arbre conversionTableauArbre(Arbre abr, Item tab[])
{
    int i, taille = tailleTableau(tab), paranthese = 0;
    if (emplacementPremierOperateur(tab) != -1) {
        for (i=0; i < taille; i++) {
            if (tab[i].token == PARENTHESE_O) paranthese++;
            if (tab[i].token == PARENTHESE_F) paranthese--;
            if (tab[i].token == OPERATEUR && paranthese == 0) {
                abr->item = tab[i]; //Belle fonction Lorin
                abr->filsGauche = conversionTableauArbre(abr->filsGauche, scinderTableau(tab, 0, i - 1));
                if (i != 0) abr->filsDroit = conversionTableauArbre(abr->filsDroit, scinderTableau(tab, i + 1, taille - 1));
            }
        }
    } else if (emplacementPremierOperateur(tab) != -1) {
        for (i=0; i < taille; i++) {
            if (tab[i].token == PARENTHESE_O) paranthese++;
            if (tab[i].token == PARENTHESE_F) paranthese--;
            if (tab[i].token == FONCTION && paranthese == 0) {
                abr->item = tab[i]; //Belle fonction Lorin + Rajouter suppression des parathèses de la fonction
                abr->filsGauche = conversionTableauArbre(abr->filsGauche, scinderTableau(tab, 0, i - 1));
                if (i != 0) abr->filsDroit = conversionTableauArbre(abr->filsDroit, scinderTableau(tab, i + 1, taille - 1));
            }
        }
    }
    return abr;
}


void afficherTableau(Item tab[])
{
    int i;
    for (i = 0; tab[i].token != FIN; i++) {
        if (tab[i].token == OPERATEUR) {
            switch (tab[i].valeur.operateur) {
                case PLUS:
                    printf("+ ");
                    break;
                case MOINS:
                    printf("- ");
                    break;
                case DIV:
                    printf("/ ");
                    break;
                case MULTI:
                    printf("* ");
                    break;
                case PUIS:
                    printf("^ ");
                    break;
                default:
                    printf("");
                    break;
            }
        } else if (tab[i].token == FONCTION) {
            switch (tab[i].valeur.fonction) {
                case ABS:
                    printf("abs ");
                    break;
                case SIN:
                    printf("sin ");
                    break;
                case COS:
                    printf("cos ");
                    break;
                case EXP:
                    printf("exp ");
                    break;
                case TAN:
                    printf("tan ");
                    break;
                case COSH:
                    printf("cosh ");
                    break;
                case SINH:
                    printf("sinh ");
                    break;
                case TANH:
                    printf("tanh ");
                    break;
                case SQRT:
                    printf("sqrt ");
                    break;
                case LOG:
                    printf("log ");
                    break;
                case VAL_NEG:
                    printf("- ");
                    break;
                case MOD:
                    printf("°/. ");
                    break;
                default:
                    printf("");
                    break;
            }
        } else {
            switch (tab[i].token) {
                case PARENTHESE_F:
                    printf(") ");
                    break;
                case PARENTHESE_O:
                    printf("( ");
                    break;
                case REEL:
                    printf("%lf ", tab[i].valeur.reel);
                    break;
                case VARIABLE:
                    printf("x ");
                    break;
                default:
                    printf("");
                    break;
            }
        }
    }
}
