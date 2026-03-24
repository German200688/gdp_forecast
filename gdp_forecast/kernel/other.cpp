
#include <string>
#include <iostream>
#include <cctype>
#include <chrono>
#include "other.h"

#pragma once

using namespace std;

atomic<bool> offlineUse = false;

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


void Other::additionvectordate(vector<unsigned char>& vecdate, int64_t& Quoter)
{
	int64_t t1 = vecdate.size();
	if (Quoter > vecdate.size())
	{
		while (vecdate.size() <= Quoter)
		{
			vecdate.push_back(0);

		}
	}

		vecdate[Quoter] = vecdate[Quoter] + 1;
	}

void Other::additiondatedate(unsigned char& datedate)
{
	datedate = datedate+1;

}

bool Other::checkdate(vector<unsigned char>& vecdate, int64_t& Quoter, unsigned char& datedate1, unsigned char& datedate2)
{
	if (datedate1 > 0) { return true; }
	else if (datedate2 > 0) { return true; }
	else if (vecdate.size()>= Quoter) {if(vecdate[Quoter] > 0) return true;}
	
	else return false;
}


void Other::zerodate(vector<unsigned char>& vecdate, unsigned char& datedate1, unsigned char& datedate2)
{
	fill(vecdate.begin(), vecdate.end(), 0);
	datedate1 = 0;
	datedate2 = 0;
}

