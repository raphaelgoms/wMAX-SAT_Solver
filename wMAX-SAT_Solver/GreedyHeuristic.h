#pragma once
#include "SolutionBuilder.h"
class GreedyHeuristic :
	public SolutionBuilder
{
public:
	GreedyHeuristic(INSTANCE i);
	~GreedyHeuristic();
	bool* BuildASolution() override;
};

