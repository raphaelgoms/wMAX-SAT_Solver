// wMAX-SAT_Solver.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	cout << argv[1] << endl;

	string line;
	ifstream readfile;
	readfile.open(argv[1]);

	if (readfile.is_open())
	{
		while (getline(readfile, line))
			cout << line << endl;
		readfile.close();
	}
	else
		cout << "Impossível abrir o arquivo.";
}
