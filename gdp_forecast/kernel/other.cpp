
#include <string>
#include <iostream>
#include <cctype>
#include "other.h"

#pragma once

using namespace std;

string Other::readcincheck(string& errmes, string& data)
{
	string err;
	while (std::cin.peek() == 32) { cin.ignore(1, '\n'); }
	if (std::cin.peek() == 10) { cout << endl << errmes << endl; }
	else
	{
		cin >> data;
	}

	return data;

}


bool Other::checkcin()
{
	bool res = true;
	while (std::cin.peek() == 32) { cin.ignore(1, '\n'); }
	if (std::cin.peek() == 10) { res = false; }

	return res;


}







void Other::start()
  
{
	

	cout << "\033[33m " << endl
		<< R"(           ______   ______   ______       _____   _____    _____    _____    _____                _____   _______    )" << endl
		<< R"(          / ____ | |  __  \ |  __  |     | ____| /  __ \  |  __ \  | ____|  / ____|      /\      / ____| |__   __|   )" << endl
		<< R"(          | |      | |  | | | |  | |     | |     | |  | | | |  | | | |      | |         /  \     | /        | |      )" << endl
		<< R"(          | |  __  | |  | | | |__| |     | |__   | |  | | | |__| | | |__    | |        / /\ \    | \__      | |      )" << endl
		<< R"(          | | |_ | | |  | | |  ___/      |  __|  | |  | | |  _  /  |  __|   | |       / /__\ \    \__ \     | |      )" << endl
		<< R"(          | |__| | | |__| | | |          | |     | |__| | | | \ \  | |____  | |___   / /____\ \   ___| |    | |      )" << endl
		<< R"(          \_____ | | _____/ |_|          |_|      \____/  |_|  \_\ | _____| \_____| /_/      \ \ |____ /    |_|      )" << endl
		<< "\033[0m" << endl
		<< endl;


	   }