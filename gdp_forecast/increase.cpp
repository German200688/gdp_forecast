
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdint>

#pragma once

using namespace std;

double calculation(double predate, double actdate)
{
	double incr1;
	double incr2;
	double incr3;
	double incr4;
	double t112 = 100.0; //100.0;

	if (predate == 0.0) { incr4 = 0;  return incr4;}
	if (actdate == 0.0) { incr4 = 0;  return incr4; }
	incr1 = actdate / predate; //- 1.0;
	incr2 = incr1 * t112; //x*100*10/2 - 100-переводим в проценты; 10 - переводим в десятые процента; 2 - добавляем шаг равный 2
	incr3 = incr2;
	/*
	while (incr3 > 100)
	{
		incr3 = 100;
	}

	while (incr3 < -100)
	{
		incr3 = -100;
	}
	*/
	incr4 = incr3;

	return incr4;
}

void incrquotercalc(int64_t& quot, vector<vector<double>>& indicatDate, vector<vector<double>>& indicatDateInc, vector<double>& incre)

{
	int64_t t1 = indicatDate.size();
	int64_t t3 = quot - 1;

	int64_t t2 = indicatDate[0].size() - 1;
	if (quot > t2) { return; }


	if (quot == 0) {

		for (int64_t i = 0; i < t1; i++)
		{
			
			indicatDateInc[i][quot] = 0;

		}



	}
	else {
		for (int64_t i = 0; i < t1; i++)
		{
			double incr4 = 0;
			double predate = 0;
			double actdate = 0;
			
			if (incre[i] == 1.0) { indicatDateInc[i][quot] = indicatDate[i][quot]; }

			else {
				t3 = quot - 1;
				predate = indicatDate[i][t3];
				actdate = indicatDate[i][quot];
				incr4 = calculation(predate, actdate);
				indicatDateInc[i][quot] = incr4;
			}
		}
	}

}


void incrallcalc(vector<vector<double>>& indicatDate, vector<vector<double>>& indicatDateInc, vector<double>& incre)
{
	int64_t quot = 0;
	int64_t size2 = indicatDate[0].size();

	while (quot < size2)
	{
		incrquotercalc(quot, indicatDate, indicatDateInc, incre);

		quot++;

	}



}