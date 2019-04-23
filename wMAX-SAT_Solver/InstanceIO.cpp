#include "InstanceIO.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>

InstanceIO::InstanceIO()
{
}


InstanceIO::~InstanceIO()
{
}

INSTANCE InstanceIO::loadInstance(std::string instance)
{
	INSTANCE i;

	string line;
	ifstream readfile;
	readfile.open(instance);

	if (readfile.is_open())
	{
		while (getline(readfile, line))
		{
			if (line[0] == 'c')
				continue;

			if (line[0] == 'p')
			{
				vector<string> _line = split(line);
				i.nvar = stoi(_line[2]);
				i.nclauses = stoi(_line[3]);
				i.w = new int[i.nclauses];
				i.vn = new int[i.nclauses * i.nvar];
				memset(i.vn, 0, sizeof(i.nvar));

				for (int j = 0; j < i.nclauses; j++)
				{
					getline(readfile, line);
					_line = split(line);
					i.w[j] = stoi(_line[0]);
					for (int l = 1; l < _line.size() - 1; l++)
					{
						if (stoi(_line[l]) < 0)
							i.vn[abs(stoi(_line[l])) - 1] = -1;
						else i.vn[abs(stoi(_line[l])) - 1] = 1;
					}
				}
			}
		}
		readfile.close();
	}
	else
	{
		cout << "Impossível abrir o arquivo.";
	}

	return i;
}


std::vector<std::string> InstanceIO::split(const std::string& s)
{
	std::istringstream iss(s);
	std::vector<std::string> tokens(std::istream_iterator<std::string>{iss},
		std::istream_iterator<std::string>());

	return tokens;
}