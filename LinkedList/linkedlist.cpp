//
//  main.cpp
//
//
//  Created by Yann Ouedraogo on 2014-10-18.
//  Copyright (c) 2014 Yann Ghislain Ouedraogo. All rights reserved.
//  eyo3005@umoncton.ca

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//on cree un nouveau type qui peut contenir 3 string
typedef struct unNoeud
{
    string nom;
    string prenom;
    string age;
    unNoeud* suivant;
}unNoeud;
// la class list avec les fonction necessaire
class list
{
private:

    //definition des pointeurs pour cree notre listte chainé
    unNoeud* tete;
    unNoeud* curr;
    unNoeud* queue;
    int longueur;

public:
    list();
    void ajoutCustom(string nomFichier);//fonction d'ajout personaliser pour le probleme
    void imprimer();//afiche notre liste apres les ajouts des elements
    string nom;
    string prenom;
    string age;
};
list::list()//constructeur initialisation des pointeurs et de la variable qui verifie la taille de notre liste
{
    tete=NULL;
    curr=NULL;
    queue=NULL;
    longueur=0;
}

    
void list::ajoutCustom(string nomFichier)
{
    ifstream readfile(nomFichier,ios::in);//ouverture du fichier
    longueur=0;
    if (readfile.is_open())
    {
        while (!readfile.eof())//tant que le fichier nest pas fermer
        {
            //il preleve chaque ligne tant quil ne rencontre pas le retour chariot et les retient
            getline(readfile,nom);//en tant que nom
            getline(readfile,prenom);// en temps que prenom
            getline(readfile,age);// en temps qu'age
            unNoeud* n= new unNoeud;//creation d'un nouveau pointeur
            if (longueur<5)//premiere partie de l'ajout on ajoute a la fin
            {
                //on ajout a la queue donc ladresse qui vient apres n doit etre a null
                n->suivant=NULL;
                n->nom=nom;//ajout dans les case de la structure
                n->prenom=prenom;
                n->age=age;
                //si tete ne pointe plus vers null
                if (tete!=NULL)
                {
                    curr=tete;//cette instruction demande a curr de pointer a la meme chose que pointe tete
                    while (curr->suivant !=NULL)//on parcour la liste jusqu'a la fin
                    {
                        curr=curr->suivant;//deplacement
                    }
                    curr->suivant=n;//on ajoute les valeur ici on fait grandir la list
                    n->suivant=NULL;//comme on ajoute a la queue avant de sortir de la boucle il faut rapeller que l'adress qui suit n sera a null
                }
                else//si c'est le premier element de la liste tete sera egale a n
                {
                    tete=n;
                }

            }
            //ajout a la tete
            else if(longueur<10)
            {
                n->suivant=tete;//on dit a n de pointer a tete on revient a la tete de la liste deja cree
                tete=n;//on dit a tete de pointer sur ce que n pointe ces a dire lui meme et d'ajouter
                n->nom=nom;
                n->prenom=prenom;
                n->age=age;
            }
            else if (longueur>=10)// dernier partie de l'ajout
            {
                unNoeud* defil=tete;// on cree un pointeur defil qui pointe ver ce que la tete pusque on l'a laisser dans l'etat ou il pointe vers lui meme
                for (int i=1; i<3; i++)
                {
                    defil=defil->suivant;//on se rend au deuxieme element apres la tete et on insert
                }
                n->nom=nom;
                n->prenom=prenom;
                n->age=age;
                n->suivant=defil->suivant;//on fait pointer le n a la valeur du troisieme element de la liste
                defil->suivant=n;//maintenant on peut faire pointer la partie next de defil a ce que n pointe
            }
            longueur++; //a chaque fois quon ajoute un element la longueur s'incremente
        }
        readfile.close(); //fermeture du fichier
    }
    else
    {
        cout<<"le Fichier n'a pas pu s'ouvrir..."<<endl;
    }
    //cout<<longueur;
    
}



void list:: imprimer()
{
    if (longueur==0)
    {
        cout<<"Vous n'avez aucun element dans la list"<<endl;
    }
    else// vu que on ne perd jamais le debut de la liste grace au pointeur tete on affiche a partir de laba
    {
        curr=tete;
        while (curr!=NULL)
        {
            cout<< curr->nom<<endl;
            cout<< curr->prenom<<endl;
            cout<< curr->age<<endl;
            cout<<endl;
            curr=curr->suivant;
        }

    }
}


int main()
{
    //appel des fonctions
    list etudiant;
    string nomduFichier;
    cout<<"Entrez le nom du fichier .txt, s'il vous plait"<<endl;
    cin>>nomduFichier;
    etudiant.ajoutCustom(nomduFichier);
    etudiant.imprimer();
    system("pause");
    return 0;
    
}
