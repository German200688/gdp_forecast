#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "kernel/neyron.h"
//#include "kernel/OB1.h"

#pragma once

using namespace std;

void teachdel3(const double& neyrontest, const double& neyrontestres, vector<double >& delta5)

{
	Neyron obj;
	
	//vector<double > delta3 = {};
	
	delta5 = obj.deltaout(delta5, neyrontest, neyrontestres);

}





void teachlayer3(vector<vector<double>>& Weights5, int64_t Quoter,  vector<vector<double>>& Outputs4, vector<double >& delta5)

{
	Neyron obj;

	double t0 = delta5[0];

	obj.dellayerlast(Weights5, Quoter, Outputs4, t0);

}



void printerrr(double& result)
{
	double in1 = result;
	in1 = in1; // нивелируем шаг
	double in2 = in1;
	in2 = in2; // корректно отображаем десятые процента
	
	cout << "В указанном квартале ожидается прирост ВВП в размере " << in2 << "%" << endl;

}


void weightsaddl12(vector<vector<double>>& Weights5, int64_t t01)
{
	int64_t t02 = Weights5[0].size()-1;
	double a = 10;

	while (t02 < t01)
	{
		Weights5[0].push_back(a);



		t02++;
	}

}

double weightsumm(vector<vector<double>>& Weights5, vector<vector<double>>& Outputs4, int64_t Quoter)
{

	Neyron obj1;


	int64_t t01 = Outputs4[0].size(); // нейроны

	int64_t tt02 = Weights5.size();
	if (Weights5.size() == 0)
	{
		vector<double > W (1, 10 );
		Weights5.push_back(W);

	}

	int64_t t02 = Weights5[0].size();
	if (t01 > t02) { weightsaddl12(Weights5, t01); }

	vector<double > Weights50 = Weights5[0];
	vector<double > Outputs40 = Outputs4[Quoter];

	double neyrontest = obj1.valueneyTwoOner(Outputs40, Weights50);

	return neyrontest;


}