//
//  main.cpp
//  hashing
//
//  Created by Yann Ouedraogo on 2014-12-02.
//  Copyright (c) 2014 Yann Ghislain Ouedraogo. All rights reserved.
//

#include <iostream>
using namespace std;

class Hash
{
public:
    Hash(int);
    void inserer(int);
    void afficher();
private:
    int H1(int);
    int H2(int);
    int rev(int);
    int *table;
    int size;
    int elem;
    
};
//constructeur
Hash::Hash(int taille)
{
    table=new int[taille];//on initialise tous les element vide du tableau a -1
    for(int i=0;i<taille;i++)
    {
        table[i]=-1;
    }
    elem=0;
    size=taille;
};
int Hash::H1(int n)//premier fonction de hashage
{
    return n%13;
}
int Hash::rev(int n)// fonction pour renveser deux nombre
{
    int result=0;
    int modulo=0;
    if(n>=0 && n<=9)// si le nombre est moins grand que 10 on le renverse pas
        return n;
    else
    {
        while(n>0)
        {
            modulo=n%10;// le modulo nous permet d'acceder a chaque nombre individelmement jusqua ce quil soit plus petit que zero
            result=result*10+modulo;//et on additionne de lensemble des modulo toute en multipliant par 10
            n/=10;
        }
        return result;// quand la boucle est briser on recupere le nombre inversé
    }
}

// fonction 2 de hachage
int Hash::H2(int n)
{
    return (rev(n+1)%11);
}
// fonction d'insertion
void Hash::inserer(int n)
{
    int i,j;
    if(elem==size)
        return ;
    i=H1(n);// chercher une case vide
    if (table[i]==-1)
        table[i]=n;//si on trouve une case vide on insert
    else// sinon en cas de collision par exemple
    {
        j=H2(n);//essailler de trouver une autre case vide
        if(table[j]==-1)
        {
            table[j]=n;
        }//si oon trouve une autre case on insert
        else
        {
            while (table[j]!=-1)
            {
                j=((j*2)%13);
            }
            table[j]=n;
        }
    }
    elem++;
}
void Hash::afficher()
{
    for(int i=0;i<size;i++)
    {
        cout<<table[i]<<" ";
    }
}
int main()
{
    int keys[8]={2,8,31,20,19,18,53,27};
    Hash h(13);
    //inserer les elemtents dans le tableau 
    for(int i=0;i<8;i++)
    {
        h.inserer(keys[i]);
    }
    h.afficher();
    system("pause");
    return 0;
}
/*
la fonction de resolution de colision ici qui impleter a l'aide de H2 ne pourra plus ressoudre les probleme d'adress 
que l'orsque le tableau sera plein.Parce quil recherche la case suivante vide pour inserer en cas de colission.
Plus de case vide donc sa ne fonctionera plus. Dans ce cas il faudrait utilise une fonction de gestion 
de colission avec liste lié pour etre sur de regler le probleme. la complexite algorithmique
de notre nouvel solution sera O(n)/k en realite o(n) mais on a plus probabilite de ne pas aller jusqua la fin 
de la liste.
 */

