#pragma once
#include "SolutionBuilder.h"
class AdaptiveGreedyHeuristic :
	public SolutionBuilder
{
private:
	bool* current_solution; // Solução corrente
	int* minus;				// Guarda a soma dos pesos das cláusulas onde ocorre o literal negado de cada variável x_i
	int* plus;				// Guarda a soma dos pesos das cláusulas onde ocorre o literal de cada variável x_i

public:
	AdaptiveGreedyHeuristic(INSTANCE i);
	~AdaptiveGreedyHeuristic();

	bool* BuildASolution() override;
	void AdaptGreedyFunction(int s);
	int GreedyChoice();
	void InitializeWeightOfVariables();
};

