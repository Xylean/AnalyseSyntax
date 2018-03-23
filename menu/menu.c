#include <stdio.h>
#include "menu.h"

void effacerEcran(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void ecranAcceuil(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c      Le Grapheur      %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c 1. Debut              %c\n",h,h);
    printf("%c 2. Explication        %c\n",h,h);
    printf("%c 3. Credit             %c\n",h,h);
    printf("%c 4. Quitter            %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranCredit(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c      Le Grapheur      %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c Antoine (CP)          %c\n",h,h);
    printf("%c Georges               %c\n",h,h);
    printf("%c Lorin                 %c\n",h,h);
    printf("%c Nadir                 %c\n",h,h);
    printf("%c Theo                  %c\n",h,h);
    printf("%c Theodore              %c\n",h,h);
    printf("%c Xylean                %c\n",h,h);
    printf("%c 1. Retour             %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranDebut(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c      Entrez f(x)     %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranExplication1(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c        Explications        %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c Pour qu'une expression soit%c\n",h,h);
    printf("%c acceptee par le grapheur   %c\n",h,h);
    printf("%c l'utilisateur ne doit pas  %c\n",h,h);
    printf("%c oublier les parentheses.   %c\n",h,h);
    printf("%c Voici un exemple d'expres- %c\n",h,h);
    printf("%c sion valide :              %c\n",h,h);
    printf("%c      sin(2+x)+(2*(4+x))    %c\n",h,h);
    printf("%c 1. Continuer               %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranExplication2(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c      Fonctions disponibles      %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c Sinus : sin()                   %c\n",h,h);
    printf("%c Cosinus : cos()                 %c\n",h,h);
    printf("%c Tangeante : tan()               %c\n",h,h);
    printf("%c Cosinus hyperbolique : cosh()   %c\n",h,h);
    printf("%c Sinus hyperbolique : sinh()     %c\n",h,h);
    printf("%c Tangeante hyperbolique : tanh() %c\n",h,h);
    printf("%c Logarithme neperien : ln()      %c\n",h,h);
    printf("%c Exponentielle : e()             %c\n",h,h);
    printf("%c Valeur absolue : abs()          %c\n",h,h);
    printf("%c Reel negatif : val_neg()        %c\n",h,h);
    printf("%c Racine carree : sqrt()          %c\n",h,h);
    printf("%c 1. Continuer                    %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranExplication3(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c      Operateurs disponibles     %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c Plus : +                        %c\n",h,h);
    printf("%c Moins : -                       %c\n",h,h);
    printf("%c Multiplication : *              %c\n",h,h);
    printf("%c Division : /                    %c\n",h,h);
    printf("%c Puissance : ^                   %c\n",h,h);
    printf("%c Modulo : %%                      %c\n",h,h);
    printf("%c 1. Continuer                    %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranExplication4(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c       Controles grapheur        %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c A : Affichage de l'integrale    %c\n",h,h);
    printf("%c E : Affichage de la derivee     %c\n",h,h);
    printf("%c Z : Zoom avant|S : Zoom arriere %c\n",h,h);
    printf("%c Q : Translation gauche          %c\n",h,h);
    printf("%c D : Translation droite          %c\n",h,h);
    printf("%c W : Reinitialisation camera     %c\n",h,h);
    printf("%c C : Reinitialisation courbe     %c\n",h,h);
    printf("%c V : Reinitialisation grille     %c\n",h,h);
    printf("%c B : Desactivation de la grille  %c\n",h,h);
    printf("%c I : Reduction de la grille      %c\n",h,h);
    printf("%c K : Grossissement de la grille  %c\n",h,h);
    printf("%c 1. Continuer                    %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranExplication5(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c Deplacement de la Tangeante n 1 %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c R : Rapide vers la gauche       %c\n",h,h);
    printf("%c T : Lent vers la gauche         %c\n",h,h);
    printf("%c U : Rapide vers la droite       %c\n",h,h);
    printf("%c Y : Lent vers la droite         %c\n",h,h);
    printf("%c 1. Continuer                    %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranExplication6(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c Deplacement de la Tangeante n 2 %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c F : Rapide vers la gauche       %c\n",h,h);
    printf("%c G : Lent vers la gauche         %c\n",h,h);
    printf("%c J : Rapide vers la droite       %c\n",h,h);
    printf("%c H : Lent vers la droite         %c\n",h,h);
    printf("%c 1. Retour menu                  %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void menu (){
    char tab[5];
    ecranAcceuil();
    switch (fgets(tab,5,stdin)[0]){
        case '1':
            effacerEcran();
            ecranDebut();
            // Inssertion code
            break;
        case '2':
            effacerEcran();
            ecranExplication1();
            while (fgets(tab,5,stdin)[0] != '1');
            effacerEcran();
            ecranExplication2();
            while (fgets(tab,5,stdin)[0] != '1');
            effacerEcran();
            ecranExplication3();
            while (fgets(tab,5,stdin)[0] != '1');
            effacerEcran();
            ecranExplication4();
            while (fgets(tab,5,stdin)[0] != '1');
            effacerEcran();
            ecranExplication5();
            while (fgets(tab,5,stdin)[0] != '1');
            effacerEcran();
            ecranExplication6();
            while (fgets(tab,5,stdin)[0] != '1');
            effacerEcran();
            menu();
            break;
        case '3':
            effacerEcran();
            ecranCredit();
            while (fgets(tab,5,stdin)[0] != '1');
            effacerEcran();
            menu();
            break;
        case '4':
            break;
        default:
            menu();
            effacerEcran();
            break;
    }
}