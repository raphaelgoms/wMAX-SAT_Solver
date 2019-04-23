/* 
	Implementa heuristicas contrustivas para o problema
*/

#pragma once
#include "InstanceIO.h"

class SolutionBuilder
{
protected:
	bool* solution; // solução do problema
	int nclauses;	// número de cláusulas
	int nvar;		// número de variáveis
	int* w;			// vetor de pesos
	int* vn;		// 

public:
	SolutionBuilder(INSTANCE i);
	virtual ~SolutionBuilder();
	virtual bool* BuildASolution() = 0;
	void PrintCurrentSolution();
};

