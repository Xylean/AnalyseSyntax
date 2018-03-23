//
// Created by xyle7 on 22/03/2018.
//

#include <stdio.h>
#include "menu.h"

void effacerEcran(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
void ecranAcceuil(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c   Le Grapheur   %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c 1. Debut        %c\n",h,h);
    printf("%c 2. Explication  %c\n",h,h);
    printf("%c 3. Credit       %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranCredit(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c   Le Grapheur   %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",k,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,l);
    printf("%c Antoine (CP)    %c\n",h,h);
    printf("%c Georges         %c\n",h,h);
    printf("%c Lorin           %c\n",h,h);
    printf("%c Nadir           %c\n",h,h);
    printf("%c Theo            %c\n",h,h);
    printf("%c Theodore        %c\n",h,h);
    printf("%c Xylean          %c\n",h,h);
    printf("%c 1. Retour       %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void ecranDebut(){
    char b = 205, d = 201, g = 187, f = 188, j = 200, h = 186, k = 204, l = 185;
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",d,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,g);
    printf("%c   Entrez f(x)   %c\n",h,h);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",j,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,b,f);
}

void menu (){
    char tab[5];
    ecranAcceuil();
    switch (fgets(tab,5,stdin)[0]){
        case '1':
            printf("* ");
            break;
        case '2':
            printf("^ ");
            break;
        case '3':
            effacerEcran();
            ecranCredit();
            while (fgets(tab,5,stdin)[0] != '1');
            effacerEcran();
            menu();
            break;
        default:
            effacerEcran();
            break;
    }
}