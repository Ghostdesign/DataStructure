//
//  main.cpp
//
//  Created by Yann Ouedraogo on 2014-11-25.
//  Copyright (c) 2014 Yann Ghislain Ouedraogo. All rights reserved.
//  Adresse: eyo3005@umoncton.ca
//

#include <iostream>
#include <assert.h>
#include <string>
#include <fstream>
const int MaxList=30;// on prend le double des valeur qu'on a a traite comme limite
using namespace std;

typedef struct eleve //struct de type eleve contenant les informations necessaires pour les donne
{
	string nom;
    string age;
}eleve;
class MinHeap
{
private:
    eleve* e;
	int numb;//correspond au donne a trie qui s'incrementeront a chaque fois qu'on ajoute un element
public:
    MinHeap();
	~MinHeap();
    void insert();
    void print();
    int isAleaf(int position);
    int leftchild(int);
    void Heapagain(int racine);
    int parent(int child);
    void remove();
    bool IsFull();
    void switches(int racine,int j,eleve x[MaxList]);
};
MinHeap::MinHeap()//constructeur
{
    e=new eleve[MaxList];
    numb=0;
}
MinHeap::~MinHeap()//destructeur
{
	delete[]e;
}
int MinHeap::leftchild(int position)//position du fils gauche
{
    return 2*position+1;
}
int MinHeap::isAleaf(int position)//Position d'une feuille dans le tableau qui doit etre au moi egale au nombre delement du tableau/2
{
    return (position>=numb/2)&&(position<numb);
}
int MinHeap::parent(int child)
{
    assert(child != 0); //la racine n'a pas d'enfant
	return (child - 1) / 2;//position du parent de maniere a ce que pour obtenir la position de lenfant le plus eloigne il faut faire 2k+1 d'ou loperation inverse ici
}
void MinHeap::switches(int racinee,int j,eleve x[MaxList])//la fonction switches a pour but d'echanger deux elements d'un tableau
{
	eleve temp;//on cree un troisieme tableau pour stocker temporairement les donne a echanger
    temp.age=x[racinee].age;
    temp.nom=x[racinee].nom;
    x[racinee].age=x[j].age;
    x[racinee].nom=x[j].nom;
    x[j].age=temp.age;
    x[j].nom=temp.nom;  
}
void MinHeap::Heapagain(int racine)//fonction pour reordonne le tableau quand on fait des changements de position 
{
    if (racine>=0 && racine<numb)
    {
        while (!isAleaf(racine))
        {
            int j=leftchild(racine);
            if (j<(numb-1) && (e[j].age>=e[j+1].age))
            {
                j++;
            }
            if ((e[racine].age)<(e[j].age))
            {
                return;
            }
            switches(racine, j, e);
            racine=j;
        }
    }
}
bool MinHeap::IsFull()//verifie si le nombre d'element dans le tableau ne depasse pas la taille maximal
{
    if (numb==MaxList)
        return true;
    else
        return false;
}
void MinHeap::insert()
{
    string name,age,monFichier="etudiants.txt";
    ifstream readfile(monFichier,ios::in);//ouvrir le fichier
    if (readfile.is_open())
    {
         while (!readfile.eof())
         {
             getline(readfile,name);//on parcour chaque ligne jusqu'a la fin du fichier txt la premier ligne corespond au nom 
             getline(readfile,age);// la deuxieme a l'age et ainsi de suite
             assert(!IsFull()); //Arret securitaire si le tableau est plein
             int current=numb;
             numb++;//incrementation a chaque element ajouter au tableau
             e[current].nom=name;
             e[current].age=age;
             while(current!=0 && (e[current].age <= e[parent(current)].age))
             {
                 switches(current, parent(current), e);
                 current=parent(current);
             }
         }
        readfile.close();
    }
}
void MinHeap::remove()
{
    if(numb>0)
    {
        numb--;//decremente si le tableau n'est pas vide et
        int i=0;
		switches (i,numb,e);
        if(numb != 0)
        {
			Heapagain(i);//on reconstrui le tableau si on a supprimer la tete pendant les modifications
        }  
    }	
}
void MinHeap::print()
{
	int count=numb;//parcourir et afficher jusqu'a la taille actuel du tableau
    cout<<"================"<<endl;
    cout<<" Avant Heapsort "<<endl;
    cout<<"================"<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<e[i].nom<<endl;
        cout<<e[i].age<<endl;
    }
    for(int i=0;i<count;i++)
    {
		remove();//trie le tableau et le reconstrue eventuellement si on change de racine
    }
    cout<<"==============================="<<endl;
    cout<<" Apres Heapsort selon l'age "<<endl;
    cout<<"==============================="<<endl;
    for(int i=0;i<count;i++)
    {
        cout<<e[i].nom<<endl;
        cout<<e[i].age<<endl;
    }
    
}
int main()
{
	//appel des fonction
    MinHeap test;
    test.insert();
    test.print();
    system("pause");
    return 0;
}
