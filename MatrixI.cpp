#include "libs.h"
#include "MatrixI.h"

MatrixI::MatrixI(){}

MatrixI::~MatrixI() {
	delete tab;
}

MatrixI::MatrixI(int s) {
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

void MatrixI::display() {
	for(int i=0;i<this->m_size;i++) {
		for(int j=0;j<this->m_size;j++) {
			cout << this->tab[i][j] << "\t";
		}
		cout << endl;
    }
}
