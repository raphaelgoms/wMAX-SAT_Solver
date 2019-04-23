#include "AdaptiveGreedyHeuristic.h"

AdaptiveGreedyHeuristic::AdaptiveGreedyHeuristic(INSTANCE i)
	: SolutionBuilder(i)
{
	memset(current_solution, false, sizeof(i.nvar));
	memset(minus, 0, sizeof(i.nvar));
	memset(plus, 0, sizeof(i.nvar));
}


AdaptiveGreedyHeuristic::~AdaptiveGreedyHeuristic()
{
}

bool* AdaptiveGreedyHeuristic::BuildASolution()
{
	// Inicializa cláusulas que serão sastifeitas ao se 
	// atribuir um valor verdade para cada variável :
	InitializeWeightOfVariables();

	for (int i = 0; i < nvar; i++)
	{
		// Seleciona uma variável para receber um valor 
		// verdade (se s < 0 significa que deve receber false, e true c.c):
		int s = GreedyChoice();

		// Coloca a variável na solução:
		if (s < 0)
			current_solution[-s] = false;
		else
			current_solution[s] = true;

		// Atualiza pesos das clausulas ainda não sastifeitas, 
		// que serão sastifeitas ao se atribuir um valor verdade para cada variável
		AdaptGreedyFunction(s);
	}

	return current_solution;
}

void AdaptiveGreedyHeuristic::AdaptGreedyFunction(int s)
{
	if (s > 0)
	{
		for (int i = 0; i < nvar; i++)
		{
			if (i != s)
			{
				for (int j = 0; j < nclauses; j++)
				{
					int pos = j * nvar + i;
					if (vn[pos] < 0)
						minus[i] -= w[j];
					else if (vn[pos] > 0)
						plus[pos] += w[j];
				}
			}

			minus[s] = 0;
			plus[s] = 0;
		}
	}
	else if (s < 0)
	{
		for (int i = 0; i < nvar; i++)
		{
			if (i != -s)
			{
				for (int j = 0; j < nclauses; j++)
				{
					int pos = j * nvar + i;
					if (vn[pos] < 0)
						minus[i] -= w[j];
					else if (vn[pos] > 0)
						plus[pos] += w[j];
				}
			}

			minus[-s] = 0;
			plus[-s] = 0;
		}
	}
}

int AdaptiveGreedyHeuristic::GreedyChoice()
{
	int maxWeightedVar = 0;
	int maxWeightedNVar = 0;

	for (int i = 0; i < nvar; i++)
	{
		if (maxWeightedVar < plus[i])
			maxWeightedVar = i;

		if (maxWeightedNVar < plus[i])
			maxWeightedNVar = i;
	}

	if (plus[maxWeightedVar] > minus[maxWeightedNVar])
		return maxWeightedVar;
	else
		return -maxWeightedNVar;
}

void AdaptiveGreedyHeuristic::InitializeWeightOfVariables()
{
	for (int i = 0; i < nclauses; i++)
	{
		for (int j = 0; j < nvar; j++)
		{
			int pos = i * nvar + j;
			if (vn[pos] > 0)
				plus[j] += w[i];
			else if (vn[pos] < 0)
				minus[j] += w[i];
		}
	}
}
