#include "MatrixI.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstdlib>     // bibliotheque c standart
#include <iostream>    // flux d'entrÈe sortie
#include <iomanip>

using namespace std;

MatrixI::MatrixI()
{}


MatrixI::~MatrixI()
{
	delete tab;
}

MatrixI::MatrixI(int s)
{
    this->m_size = s;
    this->tab = new int* [s];
    for(int i=0;i<this->m_size;i++)
	{
        this->tab[i] = new int [s];
		for(int j=0;j<this->m_size;j++)
		{
			this->tab[i][j]=0;
		}
	}
}

void MatrixI::display()
{
	for(int i=0;i<this->m_size;i++)
	{
		for(int j=0;j<this->m_size;j++)
		{
			std::cout << this->tab[i][j] << "\t";
		}
		cout << endl;
    }
}
