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
	void additionvectordate(vector<double>& vecdate, int64_t& Quoter);
	void additiondatedate(double& datedate);
	bool checkdate(vector<double>& vecdate, int64_t& Quoter, double& datedate1, double& datedate2);
	void zerodate(vector<double>& vecdate, double& datedate1, double& datedate2);

};