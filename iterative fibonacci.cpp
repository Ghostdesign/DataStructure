//
//  main.cpp
//  
//
//  Created by Yann Ouedraogo on 2014-09-30.
//  Copyright (c) 2014 Yann Ghislain Ouedraogo. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

long fibi(int n)
{ // Iterative Fibonacci generator
    // fibi(46) is largest value that fits in a long
    if((n < 0) && (n > 47))
       cout<<"Input out of range";
    long past, prev, curr;  // Store temporary values
    past = prev = curr = 1;    // initialize
    for (int i=3; i<=n; i++)
    { // Compute next value
        past = prev;  // past holds fibi(i-2)
        prev = curr; // prev holds fibi(i-1)
        curr = past + prev;  // curr now holds fibi(i)
    }
    return curr;

}

int main()
{   
    ofstream file("fibi.txt",ios::out);
    for (int i=1;i<47; i++)
    {
        clock_t t;// intialise les coup d'horloge
        t=clock();// nombre de coup d'horloge des le debut de lapel de la fonction
        fibi(i);// appelle de la fonction
        t=clock()-t;//temps reel d'execution qui soustrait le nombre de coup d'horloge actuel a l'horloge actuel
        double time=((double) t)/CLOCKS_PER_SEC;
        if (file)
            file<<"n: "<<i<<"   "<<"runningtime: "<<time<<"s"<<endl; //ecrire dans le fichier le running time
        
    }
    file.close();// on ferme le fichier
	cout<<"the work is donne please check fibi.txt"<<endl;
	getchar();

    return 0;
	
}
