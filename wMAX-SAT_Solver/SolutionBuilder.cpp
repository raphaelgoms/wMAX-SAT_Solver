#include "SolutionBuilder.h"

SolutionBuilder::SolutionBuilder(INSTANCE i)
{
	nclauses = i.nclauses;
	nvar = i.nvar;
	w = i.w;
	vn = i.vn;

	solution = new bool[nclauses * nclauses];
}

SolutionBuilder::~SolutionBuilder()
{
}


void SolutionBuilder::PrintCurrentSolution()
{
}

