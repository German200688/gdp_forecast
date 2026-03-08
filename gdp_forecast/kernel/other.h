#include <string>
#include <iostream>
#include <cctype>

#pragma once
using namespace std;

class Other
{
public:
	bool checkcin();
	string readcincheck(string& errmes, string& data);
	void start();
};