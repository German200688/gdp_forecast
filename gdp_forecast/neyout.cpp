#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "kernel/neyron.h"
#include "kernel/OB1.h"

#pragma once

using namespace std;

void teachdel3(const signed char& neyrontest, const signed char& neyrontestres, vector<signed char >& delta5)

{
	Neyron obj;
	
	//vector<signed char > delta3 = {};
	
	delta5 = obj.deltaout(delta5, neyrontest, neyrontestres);

}





void teachlayer3(vector<vector<signed char>>& Weights5, int64_t Quoter,  vector<vector<signed char>>& Outputs4, vector<signed char >& delta5)

{
	Neyron obj;

	signed char t0 = delta5[0];

	obj.dellayerlast(Weights5, Quoter, Outputs4, t0);

}



void printerrr(signed char& result)
{
	int64_t in1 = int64_t(result);
	in1 = in1 * 2; // нивелируем шаг
	double in2 = in1;
	in2 = in2 / 10; // корректно отображаем десятые процента
	
	cout << "В указанном квартале ожидается прирост ВВП в размере " << in2 << "%" << endl;

}


void weightsaddl12(vector<vector<signed char>>& Weights5, int64_t t01)
{
	int64_t t02 = Weights5[0].size()-1;
	signed char a = 10;

	while (t02 < t01)
	{
		Weights5[0].push_back(a);



		t02++;
	}

}

signed char weightsumm(vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Outputs4, int64_t Quoter)
{

	Neyron obj1;


	int64_t t01 = Outputs4[0].size(); // нейроны

	int64_t tt02 = Weights5.size();
	if (Weights5.size() == 0)
	{
		vector<signed char > W (1, 10 );
		Weights5.push_back(W);

	}

	int64_t t02 = Weights5[0].size();
	if (t01 > t02) { weightsaddl12(Weights5, t01); }

	vector<signed char > Weights50 = Weights5[0];
	vector<signed char > Outputs40 = Outputs4[Quoter];

	signed char neyrontest = obj1.valueneyTwoOner(Outputs40, Weights50);

	return neyrontest;


}