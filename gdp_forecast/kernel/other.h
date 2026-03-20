#include <string>
#include <iostream>
#include <cctype>
#include <atomic>

#pragma once
using namespace std;
extern atomic<bool> offlineUse;

class Other
{
public:
	bool checkcin();
	string readcincheck(string& errmes, string& data);
	void start();
	void additionvectordate(vector<unsigned char>& vecdate, int64_t& Quoter);
	void additiondatedate(unsigned char& datedate);
	bool checkdate(vector<unsigned char>& vecdate, int64_t& Quoter, unsigned char& datedate1, unsigned char& datedate2);
	void zerodate(vector<unsigned char>& vecdate, unsigned char& datedate1, unsigned char& datedate2);
};