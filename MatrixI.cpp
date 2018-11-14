#include "libs.h"
#include "MatrixI.h"

using namespace std;

/* voir le descriptif des methodes dans .h*/

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

MatrixI::MatrixI(const MatrixI*)
{

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
