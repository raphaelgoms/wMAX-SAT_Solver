// wMAX-SAT_Solver.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>

#include "GreedyHeuristic.h"

using namespace std;

int main(int argc, char* argv[])
{
	InstanceIO* io = new InstanceIO();
	INSTANCE instance = io->loadInstance(argv[1]);

	GreedyHeuristic* construtor = new GreedyHeuristic(instance);

	bool* solution = construtor->BuildASolution(); // Constroi uma solução 
}
