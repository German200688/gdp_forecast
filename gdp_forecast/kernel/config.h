
#include <map>
#include <iostream>
#include <string>
#include <fstream> 
#include <clocale>

using namespace std;

class Config
{
public:
	map<string, string> configread();
};