//
//  main.cpp
//  hashing2
//
//  Created by Yann Ouedraogo on 2014-12-02.
//  Copyright (c) 2014 Yann Ghislain Ouedraogo. All rights reserved.
//
#include <iostream>
using namespace std;

typedef struct elem// type element
{
    int data;
    elem* next;
}elem;

class Hash
{
public:
    Hash();
    Hash(int);
    void inserer(int);
    void afficher();
private:
    static const int size=13;// on vas utiliser une taille statique pour la table de hachage
    elem* HashTable[size];
};
Hash::Hash()// initialisation tous les element a -1
{
    for (int i=0;i<size; i++)
    {
        HashTable[i]=new elem;
        HashTable[i]->data=-1;
        HashTable[i]->next=NULL;
    }
}
void Hash::inserer(int number)//pendant l'insertion en cas de colision on cree une liste liee au point de collision et on y insert la valeur a cette place
{
    int index=number%size;
    if (HashTable[index]->data==-1)
    {
        HashTable[index]->data=number;
    }
    else
    {
        elem* temp=HashTable[index];
        elem* n=new elem;
        n->data=number;
        n->next=NULL;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n;
    }
}
void Hash:: afficher()// afficher la table
{
    for (int i=0; i<size; i++)
    {
        cout<<HashTable[i]->data<<" ";
    }
}

int main()

{
    int keys[8]={2,8,31,20,19,18,53,27};
    Hash u;
    for (int i=0; i<8; i++)
    {
        u.inserer(keys[i]);
    }
    u.inserer(8);
    u.afficher();
    system("pause");
    return 0;
    
}

