#ifndef TOKEN_H_INCLUDED
#define TOKEN_H_INCLUDED

//Les lexems
typedef enum{
    REEL, FONCTION, OPERATEUR, ERREUR, FIN, PARENTHESE_O, PARENTHESE_F, VARIABLE
}Token;

//Les functions
typedef enum{
    ABS, SIN, COS, TAN, SINH, COSH, TANH, SQRT, LOG, EXP, VAL_NEG
}Fonction;

//Les opérateurs
typedef enum{
    PLUS, MOINS, DIV, MULTI, PUIS, MOD
}Operateur;

/** Elles sont à definir **/
//Les erreurs
typedef enum{
    NON_VALID_VALUE
}Erreur;


typedef union{
    double reel;
    Fonction fonction;
    Operateur operateur;
    Erreur erreur;
}TypeValeur;

struct ItemSt {
    Token token;
    TypeValeur valeur;
};typedef struct ItemSt Item;

struct PointSt {
    double x;
    double y;
};typedef struct PointSt Point;

struct ArbreSt {
    Item item;
    struct ArbreSt* filsGauche;
    struct ArbreSt* filsDroit;
};typedef struct ArbreSt* Arbre;

#endif // TOKEN_H_INCLUDED
