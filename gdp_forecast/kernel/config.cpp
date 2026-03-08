
#include <iostream>
#include <string>
#include <fstream> 
#include <map>
#include <chrono>
#include <clocale>
#include "config.h"

using namespace std;

map<string, string> Config::configread()
{

	map<string, string> config1;

	const string filename = "config.txt";

	ifstream file(filename);

	if (!file.is_open()) {

		std::cerr << "ERROR: Cannot open: " << filename << std::endl;
		return config1;
	}

	string line;

	while (getline(file, line)) {

		stringstream fw(line);
		string param = "";
		fw >> param;
		size_t t1 = line.find(':');
		line.erase(0, t1 + 1);
		string data = "";
		stringstream sw(line);
		sw >> data;
		
		config1.insert({ param, data });
		};

	return config1;

	}
	

	