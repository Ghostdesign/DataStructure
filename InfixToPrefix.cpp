//
//  main.cpp
//  
//
//  Created by Yann Ouedraogo on 2014-11-01.
//  Copyright (c) 2014 Yann Ghislain Ouedraogo. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
//creation d'un nouveau type de données sous forme de structure pour la liste qu'on s'apprete a cree
typedef struct noeud
{
    char data;
    noeud* next;
    
}noeud;
//class stacking ou on implement toute les fonctions necessaire a l'operation
class stacking
{
private:
    noeud* tete;//declation d'un pointeur tete du type noeud
public:
    stacking();//constructeur de la class
    void push(char data);// fonction qui permet l'ajout sur la pile
    char pop();// fonction qui supprime element a la tete de la pile
    bool estVide();// fonction qui determine si la pile est vide ou pas
    bool estUnOperateur(char c);// verifie si lelement lu est un operateur ou non
    int priorite(char p,char q);// verifie la priorite des operateur
    void infixToPrefix(char expression[50]);// fonction qui convertie de infix a prefix
};
stacking::stacking()
{
    tete=NULL;// initialisation dans le constructeur
}

void stacking::push(char data)
{
    noeud* n=new noeud;// creation d'un nouveau pointeur
    n->next=tete;
    tete=n;//la tete pointe vers ce n pointe cest a dire lui meme donc ajout a la tete
    n->data=data;// ajout dans la case data de la structure
}
// fonction qui permet de supprimer a la tete de la pile first in last out
char stacking::pop()
{
    noeud* temp=new noeud;
    char ch;
    temp=tete;//pointeur temporaire qui pointe vers ce que la tete pointe
    tete=tete->next;//acces a la case next de la structure sur la quel tete pointe
    ch=temp->data;//ch prend la valeur du data qui sera supprime
    delete temp;// en supprimant temp on supprime tete
    return ch;//et on retourne le charactere supprime
}

// on determine si la fonction est vide ou pas en verifiant si la tete n'est plus egale a NULL et sa nous retourne un bool
bool stacking::estVide()
{
    
    if (tete==NULL)
        return true;
    else
        return false;
}
//fonction qui verifie si le caractere en parametre n'est pas un operateur de base et nous retourne un bool
bool stacking:: estUnOperateur(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    else
        return false;
}
//fonction qui verifie les priorites basees sur les comparaisons et retourne une valeur dependament des cas
int stacking:: priorite(char p,char q)
{
    //on sait que + et - ont la meme priorite a leur niveau ainsi que * / aussi a leur niveau donc en les comparant
    if ((p=='+'||p=='-')&&(q=='*' ||q=='/'))
        return 2;// on retourne la valeur 2 en cas de comparaison entre des operateur de meme priorite tel que + - et * /
    else if((p=='*'||p=='/')&&(q=='-' ||q=='+'))
        return 4;// on retourne la valeur 4 en cas de comparaison entre des operateur de meme priorite tel que * / et - +
    return 3;// retourne 3 au cas ou les comparaison ne sont pas gerer dans les cas definit
}
//fonction pour la conversion qui prend en parametre l'expression a convertir
void stacking:: infixToPrefix(char expression[50])
{
    string postfix;
    char *base=expression;// on utilise un pointeur qui pointe vers le premier element de l'expression en parametre de la fonction vu que l'expression est un tableau de charcactere
    while (*base!='\0')// tant que le caracter de retour chariot n'a pas ete rencontrer
    {
        if (!estUnOperateur(*base)&& *base!='(' && *base!=')' )//s'il n'est pas un operateur et que cest pas des parenthese ajouter a l'expression final vu que les non operateur reste a la meme place dans l'expression final
        {
            postfix+=*base;// ajout dans l'expression final
        }
        //si on a affaire a un operateur de base cest a dire + - * ou /
        else if(estUnOperateur(*base))
        {
            // si la pile n'est pas vide on compare la priorite de ce qui sur la pile avec le nouvelle operateur rencontre dans l'expression
            while (!estVide() && priorite(tete->data,*base)>=3 && tete->data !='(' )
            {
                // si on est a ce niveau ces que certenement l'operateur est * ou - ou que le cas de comparaison n'Est pas prit en compte donc on peut lajouter a l'expression final
                postfix+=tete->data;
                pop();
            }
            // si la pile n'est pas vide ajouter l'operateur sur la pile
            push(*base);
        }
        // gestion des paranthese
        else if(*base=='(')//si on rencontre une tel parenthese on l'ajoute sur la pile
            push(*base);
        else if (*base==')')//si on rencontre un tel parenthese
        {
            while (!estVide() )// on verifie que la pile nest pas vide
            {
                if(tete->data=='(')//si l'element de la pile est une tel parenthese on la supprime de la pile
                {
                    pop();
                    break;
                }
                postfix+=tete->data;// et on l'ajoute dans l'expression final les element qui sont sur la pile
                pop();
            }
        }
        base++;// pour se deplacer dans le tableau de caractere
    }
    // s'il reste des element sur la pile les ajouter a l'expression final
    while (!estVide() )
    {
        postfix+=tete->data;
        pop();
    }
    cout<<postfix<<endl;// affiche l'expression final
}

int main()
{
    //appel des fonctions
    stacking pile;
    cout<<"entrez l'expression: ";
    char expression[50];
    cin>>expression;
    pile.infixToPrefix(expression);
	system("pause");
    return 0;
}
