#pragma once
#include "AdaptiveGreedyHeuristic.h"
class AdaptiveSemiGreedyHeuristic :
	public AdaptiveGreedyHeuristic
{
public:
	AdaptiveSemiGreedyHeuristic(INSTANCE i);
	~AdaptiveSemiGreedyHeuristic();

	bool* BuildASolution() override;
	void MakeRCL(double alpha);
};

