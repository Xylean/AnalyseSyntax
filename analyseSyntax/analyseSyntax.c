#include <malloc.h>
#include <stdio.h>
#include "../token.h"

//
// Created by xyle7 on 20/03/2018.

/// Partie Lorin -----
int tailleTableau(Item tab[])
{
    int i = 0, res;
    if (tab == NULL) return 0;
    while (tab [i].token != FIN){
        i++;
    }
    return i+1;
}

int testArbreValid (Arbre arbre, int test)
{
    if (arbre!=NULL && test == 0)
    {
        test = testArbreValid (arbre->filsGauche, test);
        test = testArbreValid (arbre->filsDroit, test);
        if (arbre->item.token == OPERATEUR && (arbre->filsDroit == NULL || arbre->filsGauche == NULL))
        {
            test=1;
        }
        if (arbre->item.token == FONCTION && (arbre->filsGauche == NULL || arbre->filsDroit != NULL))
        {
            test=2;
        }
        if ((arbre->item.token == REEL || arbre->item.token == VARIABLE) && (arbre->filsDroit != NULL || arbre->filsGauche != NULL))
        {
            test=3;
        }
    }
    return test;
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
                case MOD:
                    printf("%% ");
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
                    printf("y ");
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
    printf ("\n");
}

Arbre creerArbre ()
{
    return NULL;
}

void printErreur (Item * liste, int pos)
{
    afficherTableau (liste);
    int compt;
    for (compt=0 ; compt<pos ; compt++)
    {
        if (liste[compt].token == OPERATEUR) {
            switch (liste[compt].valeur.operateur) {
                case PLUS:
                    printf("  ");
                    break;
                case MOINS:
                    printf("  ");
                    break;
                case DIV:
                    printf("  ");
                    break;
                case MULTI:
                    printf("  ");
                    break;
                case PUIS:
                    printf("  ");
                    break;
                case MOD:
                    printf("  ");
                    break;
                default:
                    printf("");
                    break;
            }
        } else if (liste[compt].token == FONCTION) {
            switch (liste[compt].valeur.fonction) {
                case ABS:
                    printf("    ");
                    break;
                case SIN:
                    printf("    ");
                    break;
                case COS:
                    printf("    ");
                    break;
                case EXP:
                    printf("    ");
                    break;
                case TAN:
                    printf("    ");
                    break;
                case COSH:
                    printf("     ");
                    break;
                case SINH:
                    printf("     ");
                    break;
                case TANH:
                    printf("     ");
                    break;
                case SQRT:
                    printf("     ");
                    break;
                case LOG:
                    printf("    ");
                    break;
                case VAL_NEG:
                    printf("  ");
                    break;
                default:
                    printf("");
                    break;
            }
        }
        else
        {
            switch (liste[compt].token) {
                case PARENTHESE_F:
                    printf("  ");
                    break;
                case PARENTHESE_O:
                    printf("  ");
                    break;
                case REEL:
                    printf("  ");
                    break;
                case VARIABLE:
                    printf("  ");
                    break;
                default:
                    printf("");
                    break;
            }
        }
    }
    printf("^");
}

Arbre creerNoeud (Arbre arbre, Token type, TypeValeur value)
{
    arbre = malloc (sizeof(struct ArbreSt));
    arbre->filsDroit = NULL;
    arbre->filsGauche = NULL;
    arbre->item.token = type;
    if (arbre->item.token==REEL)
    {
        arbre->item.valeur.reel=value.reel;
    } else if (arbre->item.token==VARIABLE)
    {
        arbre->item.valeur.reel=0;
    } else if (arbre->item.token==FONCTION)
    {
        arbre->item.valeur.fonction=value.fonction;
    } else if (arbre->item.token==OPERATEUR)
    {
        arbre->item.valeur.fonction=value.fonction;
    } else
    {
        arbre->item.valeur.erreur = NON_VALID_VALUE;
        arbre->item.token = ERREUR;
    }
    return arbre;
}

int testParentheseSimple (Item * liste)
{
    int testParenthese = 0;
    int resultat = 0;
    int tailleTable = tailleTableau (liste);
    int compt;
    for (compt=0; compt<tailleTable; compt++)
    {
        if (liste[compt].token==PARENTHESE_O) testParenthese +=1;
        if (liste[compt].token==PARENTHESE_F) testParenthese -=1;
    }
    if (testParenthese < 0) resultat = -1;
    else if (testParenthese > 0) resultat = 1;
    return testParenthese;
}

void testParentheseComplex (Item  * liste)
{
    int preTest = testParentheseSimple (liste);
    if (preTest < 0) testParentheseFerme (liste);
    else if (preTest > 0) testParentheseOuvert (liste);
}

void testParentheseOuvert (Item * liste)
{
    int compt = tailleTableau (liste)-1;
    int test = 0;
    while (test <= 0 && compt != -1)
    {
        if (liste[compt].token==PARENTHESE_F) test--;
        else if (liste[compt].token==PARENTHESE_O) test++;
        compt--;
    }
    if (compt !=1)
    {
        printf ("Erreur : parenthese oouverte non ferme\n");
        printErreur (liste, compt);
    }
}

void testParentheseFerme (Item * liste)
{
    int compt = 0;
    int taille = tailleTableau (liste)-1;
    int test = 0;
    while (test <= 0 && compt < taille)
    {
        if (liste[compt].token==PARENTHESE_F) test--;
        else if (liste[compt].token==PARENTHESE_O) test++;
        compt++;
    }
    if (compt == taille)
    {
        printf ("Erreur : parenthese ferme non ouverte\n");
        printErreur (liste, compt);
    }
}


///--------------------

Item *scinderTableau(Item tab[], int debut, int fin)
{
    int difference = fin - debut, i, taille = tailleTableau(tab);
    Item *tableau = malloc((difference+2)*sizeof(Item));
    if (difference < taille){
        for (i = debut; i <= fin; i ++)
        {
            tableau[i-debut] = tab[i];
        }
        if (tab[fin].token != FIN) tableau[difference+1].token=FIN;
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

Item *supprimerParantheseInutile(Item tab[])
{
    int taille = tailleTableau(tab);

    if (taille > 2) while(tab[0].token == PARENTHESE_O && tab[taille-2].token == PARENTHESE_F)
    {
        tab = scinderTableau(tab,1, taille-3);
    }
    /*taille = tailleTableau(tab);
    Item *tableau = malloc((taille)*sizeof(Item));
    tableau = tab;*/
    return tab;

}

Arbre conversionTableauArbre(Arbre abr, Item tab[])
{
    int i, taille = tailleTableau(tab), paranthese = 0;
    tab = supprimerParantheseInutile(tab);
    if (emplacementPremierOperateur(tab) != -1) {
        for (i=0; i < taille; i++) {
            if (tab[i].token == PARENTHESE_O) paranthese++;
            if (tab[i].token == PARENTHESE_F) paranthese--;
            if (tab[i].token == OPERATEUR && paranthese == 0) {
                //abr->item = tab[i]; //Belle fonction Lorin
                abr = creerNoeud(abr, tab[i].token, tab[i].valeur);
                abr->filsGauche = conversionTableauArbre(abr->filsGauche, scinderTableau(tab, 0, i - 1));
                if (i != 0) abr->filsDroit = conversionTableauArbre(abr->filsDroit, scinderTableau(tab, i + 1, taille - 1));
            }
        }
    } else if (emplacementPremierOperateur(tab) == -1) {
        for (i=0; i < taille; i++) {
            if (tab[i].token == PARENTHESE_O) paranthese++;
            if (tab[i].token == PARENTHESE_F) paranthese--;
            if (tab[i].token == FONCTION && paranthese == 0) {
                abr = creerNoeud(abr, tab[i].token, tab[i].valeur); //Belle fonction Lorin
                abr->filsGauche = conversionTableauArbre(abr->filsGauche, scinderTableau(tab, 0, i - 1));
                if (i != 0) abr->filsDroit = conversionTableauArbre(abr->filsDroit, scinderTableau(tab, i + 1, taille - 1));
            } else if (tab[i].token == REEL && paranthese == 0 && abr->filsGauche == NULL){
                abr->filsGauche = creerNoeud(abr->filsGauche, tab[i].token, tab[i].valeur); // Belle fonction de Lorine
            } else if (tab[i].token == REEL && paranthese == 0 && abr->filsDroit == NULL){
                abr->filsDroit = creerNoeud(abr->filsDroit, tab[i].token, tab[i].valeur); // Belle fonction de Lorine
            }
        }
    }
    return abr;
}
