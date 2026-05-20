
#include <chrono>
#include <cstdint>
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include "activat.h"

#pragma once
using namespace std;


double Activat::tanh(double& out) {
	double t4;
	t4 = std::tanh(out);
	return t4;
}



double Activat::tanhd(double& out) {
	out = clamp(out, -5.0, 5.0);
	double t0 = out;
	double t1 = 0;
	double t2 = 0;
	double t3 = 0;
	double t4 = 0;

	//	double t5 = 0;

	t1 = exp(-t0);
	t2 = exp(t0);

	t3 = (t2 - t1) / (t2 + t1);
	t4 = 1 - (t3 * t3);

	//t5 = static_cast<double>(t4);
	return t4;
}



///функции Softsign
double Activat::ssign(double out) {
	double t0 = 0;
	double t1 = 0;
	double t2 = 0;
	t0 = clamp(out, -99.0, 99.0);
	t1 = 1 + abs(t0);


	t2 = t0 / t1;

	return t2;
}

double Activat::ssignd(double out) {
	double t0 = 0;
	double t1 = 0;
	double t2 = 0;
	t0 = clamp(out, -99.0, 99.0);
	t1 = 1 + abs(t0);


	t2 = 1 / (t1 * t1);

	return t2;
}
// функции сигмоиды
double Activat::sigm(double out) {
	return 1.0 / (1.0 + exp(-out));
}

double Activat::sigmd(double out) {
	double t0 = 0;
	double t1 = 0;
	double t2 = 0;
	t0 = clamp(out, -9.2, 9.2);
	t1 = 1.0 / (1.0 + exp(-t0));

	t2 = t1 * (1.0 - t1);

	return t2;
}

// функции gсигмоиды
double Activat::gsigm(double out) {
	return 1.0 / (1.0 + exp(out));
}


// функции gSwish
double Activat::gswish(double out) {

	return out * gsigm(out);
}


double Activat::gswishd(double out) {
	//double t0 = clamp(out, -9.2, 9.2);
	double t0 = out;
	double t1 = exp(t0);
	double t2 = t1*(1 - t0);
	double t3 = 1 + t2;

	double t4 = (1 + t0) * (1 + t0);

	return t3 / t4;;
}


// функции Swish
double Activat::swish(double out) {
	
	return out * sigm(out);
}


double Activat::swishd(double out) {
	double t0 = sigm(out);
	double t1 = out * t0;
	return t1 + t0 * (1.0 - t1);
}


/*
double Activat::reludivp(double& reluin)
{
	if (reluin > 0) return 100;
	else return 1; //0


}


double Activat::relup(double& reluin)
{
	if (reluin > 0) return reluin;
	else return 1; //0;



}


vector<double> Activat::reluvp(vector<double>& reluinv)
{
	int64_t t0 = reluinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reluinv[i] <= 0) reluinv[i] = 1; //0;

	}

	return reluinv;

}



double Activat::reludivp(const double& reludivin)
{
	if (reludivin > 0) return 100;
	else return 1; //0


}


vector<double> Activat::reluvp(vector<double> reludivinv)
{
	int64_t t0 = reludivinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reludivinv[i] < 0) reludivinv[i] = 1; //0;

	}

	return reludivinv;

}







double Activat::relum(double& reluin)
{
	if (reluin < 0) return reluin;
	else return 1; //0;


}


vector <double> Activat::reluvm(vector <double>& reluinv)
{
	int64_t t0 = reluinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reluinv[i] >= 0) reluinv[i] = 1;//0;

	}

	return reluinv;

}



double Activat::reludivm(const double& reludivin)
{
	if (reludivin < 0) return 100;
	else return 1; //0


}


vector <double> Activat::reluvm(vector <double> reludivinv)
{
	int64_t t0 = reludivinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reludivinv[i] >= 0) reludivinv[i] = 1; //0;

	}

	return reludivinv;

}
*/