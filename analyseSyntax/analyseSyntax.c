#include <malloc.h>
#include <stdio.h>
#include "../token.h"

void freeArbre (Arbre arbre)
{
    if (arbre!=NULL)
    {
        freeArbre(arbre->filsGauche);
        freeArbre (arbre->filsDroit);
        free(arbre);
    }
}

void printTree (Arbre arbre)
{
    if (arbre!=NULL)
    {
        printTree(arbre->filsGauche);
        if (arbre->item.token==REEL) printf ("reel\n");
        else if (arbre->item.token==FONCTION)printf("fonction\n");
        else if (arbre->item.token==OPERATEUR)printf("operateur\n" );
        else if (arbre->item.token==VARIABLE)printf("variable\n" );
        printTree (arbre->filsDroit);
    }
}

int tailleTableau(Item tab[])
{
    int i = 0;
    if (tab == NULL) return 0;
    while (tab [i].token != FIN){
        i++;
    }
    return i+1;
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
                    printf("a ");
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
        printf ("Erreur : parenthese ouverte non ferme\n");
        printErreur (liste, compt+1);
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
        printErreur (liste, compt-1);
    }
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

Arbre creerArbre ()
{
    return NULL;
}

Arbre creerNoeud (Arbre arbre, Token type, TypeValeur value)
{
    arbre = (Arbre)malloc(sizeof(struct ArbreSt));
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
    return resultat;
}

int testParentheseComplex (Item  * liste)
{
    int preTest = testParentheseSimple (liste);
    if (preTest < 0) testParentheseFerme (liste);
    else if (preTest > 0) testParentheseOuvert (liste);
    return preTest;
}

Item *scinderTableau(Item tab[], int debut, int fin)
{
    int difference = fin - debut, i, taille = tailleTableau(tab);
    Item *tableau = malloc((difference+2)*sizeof(Item));
    if (difference < taille && difference >= 0){
        for (i = debut; i <= fin; i ++)
        {
            tableau[i-debut] = tab[i];
        }
        if (tab[fin].token != FIN) tableau[difference+1].token=FIN;
    } else tableau = tab;
    return tableau;
}

int nombreOperateurDisponible(Item tab[])
{
    int i, res = 0, paranthese = 0, taille = tailleTableau(tab);
    for(i=0; i < taille-1; i++){
        if (tab[i].token == PARENTHESE_O) paranthese++;
        if (tab[i].token == PARENTHESE_F) paranthese--;
        if (tab[i].token == OPERATEUR && paranthese == 0){
            res++;
        }
    }
    return res;
}

Item *supprimerParentheseInutile(Item tab[])
{
    int taille = tailleTableau(tab);

    if (taille > 2) while(nombreOperateurDisponible(tab) == 0 && tab[0].token == PARENTHESE_O && tab[taille-2].token == PARENTHESE_F)
    {
        tab = scinderTableau(tab,1, taille-3);
        taille = tailleTableau(tab);
    }
    return tab;

}

Arbre conversionTableauArbre(Arbre abr, Item tab[])
{
    tab = supprimerParentheseInutile(tab);
    afficherTableau(tab);
    int i,j, taille = tailleTableau(tab), paranthese = 0;
    if (nombreOperateurDisponible(tab) != 0) {
        for (i=0; i < taille; i++) {
            //On traite uniquement ce qui est en dehors des parenthese
            if (tab[i].token == PARENTHESE_O) paranthese++;
            if (tab[i].token == PARENTHESE_F) paranthese--;
            if (tab[i].token == OPERATEUR && paranthese == 0) {
                abr = creerNoeud(abr, tab[i].token, tab[i].valeur);
                // On scinde l'expression à droite et à gauche de l'operateur
                // Puis on utilise conversionTableauArbre avec les deux nouveaux tableaux obtenus.
                abr->filsDroit = conversionTableauArbre(abr->filsDroit, scinderTableau(tab, i + 1, taille));
                if (i != 0) abr->filsGauche = conversionTableauArbre(abr->filsGauche, scinderTableau(tab, 0, i - 1));
            }
        }
    } else if (nombreOperateurDisponible(tab) == 0) {
        // On procède la meme maniere pour les fonctions
        for (j=0; j < taille; j++) {
            if (tab[j].token == PARENTHESE_O) paranthese++;
            if (tab[j].token == PARENTHESE_F) paranthese--;
            if (tab[j].token == FONCTION && paranthese == 0) {
                abr = creerNoeud(abr, tab[j].token, tab[j].valeur);
                abr->filsGauche = conversionTableauArbre(abr->filsGauche, scinderTableau(tab, j + 1, taille));
            } else if ((tab[j].token == REEL || tab[j].token == VARIABLE) && paranthese == 0){
                // Pour les variables nous créeons directement un noeud qui prend ses valeurs
                abr = creerNoeud(abr, tab[j].token, tab[j].valeur);
            }
        }
    }
    return abr;
}

Arbre analyseSyntax(Item * table)
{
    int testValid =0;
    Arbre abr = creerArbre();
    if (testParentheseComplex(table) == 0){
        //printf("\ncoucou\n");
        abr = conversionTableauArbre(abr,table);
        testValid = testArbreValid(abr, testValid);
        if (testValid != 0) abr = NULL; //printf("\nShit Append!");
    }
    return abr;
}

void test_afficherTableau(Item * tab){
    printf("f(x) = ");
    afficherTableau(tab);
    printf("----------\n");
}

void test_tailleTableau(Item * tab){
    printf("La taille du tableau : %d", tailleTableau(tab));
    printf("\n----------\n");
}

void test_scinderTableau(Item * tab){
    Item * tab1;
    tab1 = scinderTableau(tab,5,8);
    printf("g(x) = ");
    afficherTableau(tab1);
    printf("----------\n");
}

void test_nombreOperateurDisponible(Item * tab){
    afficherTableau(tab);
    printf("Il y a %d operateur(s) disponible(s)", nombreOperateurDisponible(tab));
    printf("\n----------\n");
    tab = scinderTableau(tab,0,9);
    afficherTableau(tab);
    printf("Il y a %d operateur(s) disponible(s)", nombreOperateurDisponible(tab));
    printf("\n----------\n");
}

void test_supprimerParantheseInutile(Item * tab){
    tab = scinderTableau(tab,1,9);
    printf("h(x) = ");
    afficherTableau(tab);
    printf("----------\n");
    printf("Suppression des parenthese intulies :\n");
    tab = supprimerParentheseInutile(tab);
    printf("h(x) = ");
    afficherTableau(tab);
    printf("----------\n");
}

void test_conversionTableauArbre(Item * tab){
    Arbre abr;
    abr = creerArbre();
    abr = conversionTableauArbre(abr,tab);
    printf("----------\n");
    printTree(abr);
    printf("----------\n");
}

void test_analyseSyntax(Item * tab){
    Arbre abr = creerArbre();
    abr = analyseSyntax(tab);
    printf("----------\n");
    if (abr != NULL) printf("Sucess!");else printf("FAIL!!!");
    printf("\n----------\n");
}