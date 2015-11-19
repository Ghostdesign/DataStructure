//
//  main.cpp
//  
//
//  Created by Yann Ouedraogo on 2014-09-30.
//  Copyright (c) 2014 Yann Ghislain Ouedraogo. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

long fibr(int n) { // Recursive Fibonacci generator
    // fibr(46) is largest value that fits in a long
    
    if((n < 0) && (n > 47))
        cout<<"Input out of range"<<endl;
    if ((n == 1) || (n == 2))
        return 1; // Base cases
    return fibr(n-1) + fibr(n-2);       // Recursion
}


int main()
{   
    ofstream file("fibr.txt",ios::out);
    for (int i=1;i<47; i++)
    {
        clock_t t;// intialise les coup d'horloge
        t=clock();// nombre de coup d'horloge des le debut de lapel de la fonction
        fibr(i);// appelle de la fonction
        t=clock()-t;//temps reel d'execution qui soustrait le nombre de coup d'horloge actuel a l'horloge actuel

        double time=((double) t)/CLOCKS_PER_SEC;
        if (file)
            file<<"n: "<<i<<"   "<<"runningtime: "<<time<<"s"<<endl;//ecrire dans le fichier le running time
        
    }
    file.close();
    cout<<"the work is donne please check fibr.txt";// on ferme le fichier
	getchar();
    return 0;
}
