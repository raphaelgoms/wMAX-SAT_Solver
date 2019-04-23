/*
	Implementa procedimentos de leitura das instancias e de impressão da solução e demais informações 
*/
#pragma once
#include<string>
#include<vector>
using namespace std;

struct INSTANCE {
	int nvar = 0; // numero de variáveis
	int nclauses = 0; // número de cláusulas
	int *w; // vetor de pesos
	int* vn; // vetor de negação(indica variáveis negadas)
};


class InstanceIO
{
public:
	InstanceIO();
	~InstanceIO();

	INSTANCE loadInstance(std::string instance);

	// métodos auxiliares
	std::vector<std::string> split(const std::string& s);

};

