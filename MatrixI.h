#ifndef MATRIXI_H
#define MATRIXI_H

#include "libs.h"

using namespace std;

 /*
pour les graphes orientés :
	Aij = -1 si arc est sortant de Vi
	Aij = 1 si arc est entrant de Vi
	Aij = 0 si pas d'arc
pour les graphes non oriientés :
	Aij = 1 si arc
	Aij = 2 si arc est une boucle
	Aij = 0 si pas darc
*/

class MatrixI
{
	public :
		MatrixI(); //useless
		~MatrixI();
		MatrixI(int);
		void display(); //affiche la matrice
	private :
	    int m_size; //taille de la matrice
		int** tab; //tableau de la matrice
};

#endif
