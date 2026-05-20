#include <chrono>
#include <cstdint>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>


using namespace std;


class Activat
{
public:
	/*
	double relup(double& reluin);
	vector<double> reluvp(vector<double>& reluinv);
	double reludivp(double& reluin);
	double reludivp(const double& reludivin);
	vector<double> reluvp(vector<double> reludivinv);
	double relum(double& reluin);
	vector <double> reluvm(vector <double>& reluinv);
	double reludivm(const double& reludivin);
	vector <double> reluvm(vector <double> reludivinv);
	*/
	double sigmd(double out);
	double tanh(double& out);
	double tanhd(double& out);
	double ssignd(double out);
	double ssign(double out);
	double sigm(double out);
	double swish(double out);
	double swishd(double out);
	double gsigm(double out);
	double gswish(double out);
	double gswishd(double out);

};