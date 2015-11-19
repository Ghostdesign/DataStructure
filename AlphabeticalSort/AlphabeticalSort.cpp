//
//  main.cpp
//  eyo3005@umoncton.ca
//
//  Created by Yann Ouedraogo on 2014-10-07.
//  Copyright (c) 2014 Yann Ghislain Ouedraogo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
const int MaxList=15;// le tableau peut contenir 15 elements au maximum
using namespace std;


typedef struct eleve //struct de type eleve contenant les information necessaire pour les donne
{
    string nom;
    string prenom;
    string age;
}eleve;

class listeDesEtudiant //class des etudiant avec tte les fonction requise pour le programe
{
public:
    listeDesEtudiant();
    string nom;
    string prenom;
    string age;
    void inserEtudiant(string nomFichier);
    void trieAlpa();//trie le tableau en ordre alphabetique
    void afficherList();// affiche la liste peut importe son etat
private:
    int taille;// qui nous donne en temps reel ou est rendu le tableau pendant les ajouts
    eleve etudiant[MaxList];//creation du tableau qui contient les element
    
};
listeDesEtudiant::listeDesEtudiant()// initialise le constructeur de la classe
{
    
    for (int i=0; i!=MaxList; i++)
    {
        etudiant[i].nom="";
        etudiant[i].prenom="";
        etudiant[i].age="";
    }
}

void listeDesEtudiant::inserEtudiant(string nomFichier)
{
    ifstream readfile(nomFichier,ios::in);//ouverture du fichier
    int i=0;
    taille=0;
    if (readfile.is_open())
    {
        while (!readfile.eof())//tant que le fichier nest pas fermer
        {
            //il preleve chaque ligne tant quil ne rencontre pas le retour chariot et les retient
            getline(readfile,nom);//en tant que nom
            getline(readfile,prenom);// en temps que prenom
            getline(readfile,age);// en temps qu'age
            etudiant[i].nom=nom+ " " +prenom+" "+age;// savegarde definitive
            taille++;// on augemente la taille
            i++;
        }
        readfile.close(); //fermeture du fichier
    }
    else
    {
        cout<<"le Fichier n'a pas pu s'ouvrir..."<<endl;
    }
    
}

    
void listeDesEtudiant::trieAlpa()//trie par selection adapter au probleme
{
    int length=taille;//on copie ta taille en lieu sur pour eviter de corompre sa vrai valeur
    string temp;// une variable temporaire qui nous permet de permuter les element
    int l,maximum;// les variable quon utilise pour la comparaison
    while (length>0)// tant que la taille du tableau est tjr positive
    {
        maximum=0;
        for (l=1; l<length;l++)// on utilise une boucle qui compare les element entre eux le premier ainsique lavant dernier et ainsi de suite
        {
            if (etudiant[l].nom > etudiant[maximum].nom)// les string nous permet de faire la comparaison
            {
                maximum=l;
            }
        }
        temp=etudiant[maximum].nom;// vu que la variable nom est associer avec le prenom et l'age on fait un seul type dechange elle deplace uniquement les case d'etudiant dont le nom est juger superieur a la case comparer baser sur les comparaison des noms grace au string
        etudiant[maximum].nom=etudiant[length-1].nom;
        etudiant[length-1].nom=temp;
        length--;//on diminue la longueur pour etre en mesure de sasurrer quon parcour tous le tableau

        
    }
}


void listeDesEtudiant::afficherList()
{
    for (int j=0;j<taille ; j++)
    {
        cout<<etudiant[j].nom<<" "<<etudiant[j].age<<endl;
        //parcour le tableau et affiche chaque element quelque soit l'etat du tableau
    }

}

int main()
{
    int numberchoice;
    bool doitagain=true;
    listeDesEtudiant etudiantUmoncton;
    string nomFichier="";
    do{
        cout<<"==================================================================="<<endl;
        cout<<"1. Lecture et Trie du fichier .txt dans le dossier de l'excecutable"<<endl;
        cout<<"2. Lecture et Trie du fichier .txt dans le repertoire desirer"<<endl;
        cout<<"3. Arret du programme"<<endl;
        cout<<"===================================================================="<<endl;
        do
        {
            cout<<"Entrez votre choix s'il vous plait:";
            cin>>numberchoice;
        }
        while (numberchoice<1 || numberchoice>3);
        switch(numberchoice)
        {
            case 1:
                cout<<"Entrez le nom du fichier .txt, s'il vous plait"<<endl;
                cin>>nomFichier;
                etudiantUmoncton.inserEtudiant(nomFichier);
                etudiantUmoncton.trieAlpa();
                etudiantUmoncton.afficherList();
                break;
            case 2:
                cout<<"Entrez le repertoire ou se trouve votre fichier txt s'il vous plait"<<endl;
                cin>>nomFichier;
                etudiantUmoncton.inserEtudiant(nomFichier);
                etudiantUmoncton.trieAlpa();
                etudiantUmoncton.afficherList();
                break;
            case 3:
                cout<<"Arret du programe.."<<endl;
                doitagain=false;
                break;
        }
    }
    while(doitagain);
    return 0;
}
