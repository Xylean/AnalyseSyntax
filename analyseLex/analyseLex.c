#include "analyseLex.h"

#include "../global.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void saisie(char* equation) //--Procèdure qui permet de saisir une fonction
{
  fgets(equation, SIZE, stdin); /*--Fonction qui permet de récupérer le flux d'entrée
	                        du clavier et de le copier dans le chaine de caractère associés--*/
}

void delete_blank_space(Item* tabItems)
{
  int n = 0,i = 0;
  while(tabItems[n].token != FIN)
  {
    if(tabItems[n].token == ERREUR && tabItems[n].valeur.erreur == ERR_BLANK_SPACE)
      {
          i = n;
        while(tabItems[i].token != FIN)
          {
            tabItems[i] = tabItems[i+1];
            i++;
          }
      }
      n++;
  }
}

Item* analyseLex(char* texte)
{
    //--Allocation dynamique
    Item* tabItems = (Item*)malloc((1+strlen(texte))*sizeof(Item));
    int i;
    int n=0;
    char temp[6] = {};
    //double somme=0;
    int incrementitem=0;

    int length = strlen(texte);

    for(i=0; i<length; i++)
    {
        int conditionChiffre = (texte[i]== '0' || texte[i]== '1' || texte[i]== '2' || texte[i]== '3' || texte[i]== '4' || texte[i]== '5' || texte[i]== '6' || texte[i]== '7' || texte[i]== '8' || texte[i]== '9' || texte[i]== '.');
        int conditionLettreFonction = (texte[i]== 'a' || texte[i]== 'b' || texte[i]== 's' || texte[i]== 'i' || texte[i]== 'n' || texte[i]== 'c' || texte[i]== 'o' || texte[i]== 't'|| texte[i]== 'h' || texte[i]== 'q' || texte[i]== 'r' || texte[i]== 'l'|| texte[i]== 'g' || texte[i]== 'e' || texte[i]== 'v');
        if(!conditionChiffre && !conditionLettreFonction)//SI pas chiffre et lettre
        {
            n=0;
            if(temp[0]!='\0')
            {
                tabItems[incrementitem] = creationItem(temp[0],temp);
                incrementitem++;
            }
            tabItems[incrementitem] = creationItem(texte[i],NULL);
            incrementitem++;
            temp[n]='\0';
            //RECUP les valeurs
        }
        else
        {
            temp[n]= texte[i];
            temp[n+1]='\0';
            n++;
        }
    }
    Item* newItem = NULL;
    lectureItem(tabItems);printf("\n");
    //newItem = processingitemarray(tabItems);
    //lectureItem(newItem);printf("\n");
    return tabItems;
}

Item creationItem(char premierelettre, char* temp)
{
    Item item;
    Item testtoken = test_array(premierelettre);
    if(testtoken.token == REEL)
    {
        item.token = REEL;
        item.valeur.reel = atof(temp);
    }
    else if(testtoken.token == FONCTION)
    {
        item = typevaleur_fonction(temp);
    }
    else if(testtoken.token == OPERATEUR)
    {
        item = typevaleur_operateur(premierelettre);
    }
    else if(testtoken.token==ERREUR)
    {
      item = testtoken;
    }
    else if(testtoken.token==FIN)
    {
        item = testtoken;
    }
    else if(testtoken.token==PARENTHESE_O)
    {
        item = testtoken;
    }
    else if(testtoken.token==PARENTHESE_F)
    {
        item = testtoken;
    }
    else if(testtoken.token==VARIABLE)
    {
        item = testtoken;
    }
    return item;
}

Item test_array(char car)
{
  Item item;
  if(car == '0'||car == '1'||car == '2'||car == '3'
    ||car == '4'||car == '5'||car == '6'||car == '7'
    ||car == '8'||car == '9')
  {
    item.token = REEL;
  }
  else if(car == 'a'||car == 's'||car == 'c'||car == 't'
    ||car == 'e'||car == 'l'||car == 'v')
  {
    item.token = FONCTION;
  }
  else if(car == '+'||car == '-'||car == '*'||car == '^'
    ||car == '/'||car == '%')
  {
    item.token = OPERATEUR;
  }
  else if(car == '\n')
  {
    item.token = FIN;
  }
  else if(car == '(')
  {
    item.token = PARENTHESE_O;
  }
  else if(car == ')')
  {
    item.token = PARENTHESE_F;
  }
  else if(car == 'x')
  {
    item.token = VARIABLE;
  }

  return item;
}

void lectureItem(Item* tabItems)
{
    int n;
    for(n=0; tabItems[n].token!=FIN; n++)
    {
     printf("%d", tabItems[n].token);
    }
}

Item typevaleur_fonction(char* str)
{
  Item item;
  item.token = FONCTION;
  if(strcmp(str, "abs") == 0) {item.valeur.fonction = ABS;}
  else if(strcmp(str, "sin") == 0) {item.valeur.fonction = SIN;}
  else if(strcmp(str, "cos") == 0) {item.valeur.fonction = COS;}
  else if(strcmp(str, "tan") == 0) {item.valeur.fonction = TAN;}
  else if(strcmp(str, "sinh") == 0) {item.valeur.fonction = SINH;}
  else if(strcmp(str, "cosh") == 0) {item.valeur.fonction = COSH;}
  else if(strcmp(str, "tanh") == 0) {item.valeur.fonction = TANH;}
  else if(strcmp(str, "sqrt") == 0) {item.valeur.fonction = SQRT;}
  else if(strcmp(str, "ln") == 0) {item.valeur.fonction = LOG;}
  else if(strcmp(str, "exp") == 0) {item.valeur.fonction = EXP;}
  else if(strcmp(str, "val_neg") == 0) {item.valeur.fonction = VAL_NEG;}

  else{ printf("Error : %s\n",str); }

  return item;
}

Item typevaleur_operateur(char charactere)
{
  Item item;
  item.token = OPERATEUR;
  if(charactere == '+') {item.valeur.operateur = PLUS;}
  else if(charactere == '-') {item.valeur.operateur = MOINS;}
  else if(charactere == '/') {item.valeur.operateur = DIV;}
  else if(charactere == '*') {item.valeur.operateur = MULTI;}
  else if(charactere == '^') {item.valeur.operateur = PUIS;}
  else if(charactere == '%') {item.valeur.operateur = MOD;}
  else{ printf("Error : %s\n",charactere); }

  return item;
}

int tailletabItems(Item* tabItems)
{
    int taille, n;
    for(n=0; tabItems[n].token!=4; n++)//Parcours du tableau d'Item
    {
        taille=n;
    }
    taille+=2;
    return taille;
}

Item* processingitemarray(Item* tabItems)
{
    int n;
    Item* newItemTab = NULL;
    newItemTab = tabItems;
    for(n=0; tabItems[n].token!=FIN; n++)//Parcours du tableau d'Item
    {
        if(tabItems[n].token == VARIABLE)
        {
            newItemTab = setfoisvariable(tabItems, n);
        }
        if(tabItems[n].token == OPERATEUR)
        {
            if(tabItems[n].valeur.operateur == DIV || tabItems[n].valeur.operateur == MULTI || tabItems[n].valeur.operateur == PUIS)
            {
                newItemTab = checkparantgauche(newItemTab, n);
                newItemTab = checkparantdroite(newItemTab, n+1);
            }
        }
    }
    return newItemTab;
}

Item* insererparantouvrante(Item* tabItems, int position)
{
    Item* itemfinale = malloc((1+tailletabItems(tabItems))*sizeof(Item));
    int n;
    for(n=0;n<position;n++)
    {
        itemfinale[n]=tabItems[n];
    }
    itemfinale[position].token=PARENTHESE_O;
    int i;
    for(n=position+1; n<tailletabItems(tabItems)+1; n++)
    {
        i=n-1;
        itemfinale[n] = tabItems[i];
    }
    free(tabItems);
    return itemfinale;
}

Item* insererparantfermante(Item* tabItems, int position)
{
    Item* itemfinale = NULL;
    itemfinale = malloc((1+tailletabItems(tabItems))*sizeof(Item));
    int n;
    for(n=0;n<position;n++)
    {
        itemfinale[n]=tabItems[n];
    }
    itemfinale[position].token=PARENTHESE_F;
    int i;
    for(n=position+1; n<tailletabItems(tabItems)+1; n++)
    {
        i=n-1;
        itemfinale[n] = tabItems[i];
    }
    free(tabItems);
    return itemfinale;
}

Item* checkparantgauche(Item* tabItems, int position)
{
    if(tabItems[position-1].token==REEL)
    {
        tabItems = insererparantouvrante(tabItems, position-1);
    }
    else
    {
        if(tabItems[position-1].token==PARENTHESE_F)
        {
            int i, compteur = 0;
            for(i=position; i>=0; i--)
            {
                if(tabItems[i].token==PARENTHESE_F)
                {
                    compteur++;
                }
                if(tabItems[i].token==PARENTHESE_O && compteur == 0)
                {
                    tabItems = insererparantouvrante(tabItems, i);
                    i=-1;//Pour sortir du for
                }
                if(tabItems[i].token==PARENTHESE_O && compteur != 0)
                {
                    compteur--;
                }
            }
        }
    }
    return tabItems;
}

Item* checkparantdroite(Item* tabItems, int position)
{
    int taille = tailletabItems(tabItems);
    if(tabItems[position+1].token==REEL)
    {
        tabItems = insererparantfermante(tabItems, position+2);
    }
    else
    {
        if(tabItems[position+1].token==PARENTHESE_O)
        {
            int i;
            for(i=position; i<=taille; i++)
            {
                if(tabItems[i].token==PARENTHESE_F)
                {
                    tabItems = insererparantfermante(tabItems, i);
                    i=taille++;//Pour sortir du for
                }
            }
        }
    }
    return tabItems;
}

Item* setparantdroite(Item* tabItems, int position)
{
    int taille = tailletabItems(tabItems);
    {
        int i;
        for(i=position; i<=taille; i++)
        {
            if(tabItems[i].token==PARENTHESE_F)
            {
                tabItems = insererparantfermante(tabItems, i);
                i=taille++;//Pour sortir du for
            }

        }
    }
    return tabItems;
}

Item* setfoisvariable(Item* tabItems, int position)
{
    //Check a gauche de la var si Variable ou parantheses fermantes
    Item* newItem = tabItems;
    lectureItem(tabItems);printf("\n");
    if (position > 0){
        if(newItem[position-1].token==REEL || newItem[position-1].token==PARENTHESE_F)
        {
            newItem = insererfois(newItem, position);
            position++;

        }
    }
    else if(newItem[position+1].token==REEL || newItem[position+1].token==PARENTHESE_O)
    {
        newItem = insererfois(newItem, position+1);
        position++;


    }
    return newItem;
}

Item* insererfois(Item* tabItems, int position)
{

    Item* itemfinale = NULL;
    itemfinale = malloc((1+tailletabItems(tabItems))*sizeof(Item));
    int n;
    for(n=0;n<position;n++)
    {
        itemfinale[n]=tabItems[n];
    }
    itemfinale[position].token=OPERATEUR;
    itemfinale[position].valeur.operateur = MULTI;
    int i;
    for(n=position+1; n<tailletabItems(tabItems)+1; n++)
    {
        i=n-1;
        itemfinale[n] = tabItems[i];
    }
    free(tabItems);
    return itemfinale;
}
