#ifndef MATRIXI_H
#define MATRIXI_H

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
		MatrixI(const MatrixI*);
		MatrixI(int);
		void display();
	private :
	    int m_size;
		int** tab;
};

#endif
