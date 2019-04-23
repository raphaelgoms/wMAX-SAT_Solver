/* 
	Implementa heuristicas contrustivas para o problema
*/

#pragma once
#include "InstanceIO.h"

class SolutionBuilder
{
protected:
	bool* solution; // solu��o do problema
	int nclauses;	// n�mero de cl�usulas
	int nvar;		// n�mero de vari�veis
	int* w;			// vetor de pesos
	int* vn;		// 

public:
	SolutionBuilder(INSTANCE i);
	virtual ~SolutionBuilder();
	virtual bool* BuildASolution() = 0;
	void PrintCurrentSolution();
};

