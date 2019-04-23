/*
	Implementa procedimentos de leitura das instancias e de impress�o da solu��o e demais informa��es 
*/
#pragma once
#include<string>
#include<vector>
using namespace std;

struct INSTANCE {
	int nvar = 0; // numero de vari�veis
	int nclauses = 0; // n�mero de cl�usulas
	int *w; // vetor de pesos
	int* vn; // vetor de nega��o(indica vari�veis negadas)
};


class InstanceIO
{
public:
	InstanceIO();
	~InstanceIO();

	INSTANCE loadInstance(std::string instance);

	// m�todos auxiliares
	std::vector<std::string> split(const std::string& s);

};

