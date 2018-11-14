<<<<<<< HEAD
#include "libs.h"
#include "MatrixI.h"

using namespace std;

/* voir le descriptif des methodes dans .h*/
=======
#include "MatrixI.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cstdlib>     // bibliotheque c standart
#include <iostream>    // flux d'entrÈe sortie
#include <iomanip>

using namespace std;
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a

MatrixI::MatrixI()
{}

<<<<<<< HEAD
=======

>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
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

<<<<<<< HEAD
MatrixI::MatrixI(const MatrixI*)
{

}

=======
>>>>>>> ee2a716bb9dd5ca8cb22dd7e4459354f87d7f36a
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
