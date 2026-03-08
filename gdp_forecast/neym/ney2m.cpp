#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney1m.h"
#include "ney2m.h"

using namespace std;

void layer2m::neyronoutindadd2m(vector<vector<signed char>>& Outputs2m, vector<int32_t>& Count, int32_t& CountOutputs1)

{

	int32_t t2 = Outputs2m.size();
	int32_t t3 = Outputs2m[0].size();
	int32_t t4 = CountOutputs1 - t3;

	if (Count.size() == 3) { Count.push_back(0); }
	Count[3] = t3;
	for (int32_t i = 0; i < t4; i++)
	{
		for (int32_t i1 = 0; i1 < t2; i1++)
		{
			Outputs2m[i1].push_back(0);
			
		}


	}
}






void layer2m::neyronoutqadd2m(vector<vector<signed char>>& Outputs2m, int32_t Quoter)

{

	vector<signed char> t0 = { 0 };
	if (Outputs2m.size() == 0) { Outputs2m.push_back(t0); }
	int32_t t1 = Outputs2m.size();
	t1 -= 1;
	int32_t t2 = Outputs2m[0].size();


	vector<signed char> t3 = {};
	for (int32_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs2m.push_back(t3);

		t1++;

	}


}





void layer2m::weightsaddl12m(vector<vector<signed char>>& Weights2m, int32_t ney1)


{
	int32_t t0 = Weights2m.size();
	int32_t t01 = Weights2m[0].size();


	
	signed char t1 = 0;
	int32_t t4 = ney1 - t0;

	


	for (int32_t i = 0; i < t0; i++)
	{
		for (int32_t i1 = 0; i1 < t4; i1++)
		{
			int32_t a = 0;
			
			if (t1 < 5 && a == 0) {
				Weights2m[i].push_back(t1); t1++; a = 1;
			}
			
			
		
			if (t1 >= 5 && a == 0) {
				Weights2m[i].push_back(t1); t1 = 0; a = 1;
			}

			

		}


	}
	

}



void layer2m::weightsaddl22m(vector<vector<signed char>>& Weights2m, int32_t CountWeights2)

{
	if (Weights2m.size() == 0) { vector<signed char> t0 = { 0 }; Weights2m.push_back(t0); }


	

	int32_t t1 = Weights2m[0].size();
	int32_t t2 = Weights2m.size();
	int32_t t4 = CountWeights2 - t2;
	t2 -= 1;


	vector<signed char> t3 = {};
	signed char t5 = 5;
	for (int32_t i = 0; i < t1; i++)
	{
		int32_t a = 0;
		if (t5 < 25 && a ==0) {
			t3.push_back(t5); t5+=5; a = 1;
		}

		if (t5 >= 25 && a == 0) {
			t3.push_back(t5); t5 = 5; a = 1;
		}

	}

	
	t2 = 0;
	while (t2 < t4)
	{
		Weights2m.push_back(t3);
		t2++;

	}
	
	
}



void layer2m::summneyquoter2m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs1m, vector<vector<signed char>>& Weights2m, vector<vector<signed char>>& Outputs2m, int32_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer2m obj2;

	int32_t t0 = Outputs1m.size(); //квартал
	int32_t t01 = Outputs1m[0].size(); // нейроны



	int32_t t11 = t01;
	signed char t1 = 0;
	vector<signed char> neyronin(t01, t1);
	int32_t t2 = Outputs2m.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) { obj2.neyronoutqadd2m(Outputs2m, Quoter); 
	} // не хватает квартала в нейронах слоя 2

	
	int32_t t3 = Outputs2m[0].size();

	t3 -= 1;
	if (t01 > t3) {
		obj2.neyronoutindadd2m(Outputs2m, Count, t01); 
	} //не хватает нейронов в слое2
	t3 = Outputs2m[0].size();

	vector<signed char> neyronout(t3, t1);

	if (Weights2m.size() == 0) { vector<signed char> v0 = { 0 }; Weights2m.push_back(v0); }
	int32_t t4 = Weights2m[0].size();

	if (t01 > t4) { obj2.weightsaddl12m(Weights2m, t01); } //не хватает весов для слоя 1

	int32_t t5 = Weights2m.size();
	
	if (t5 < t01) { obj2.weightsaddl22m(Weights2m, t11); 
	} // не хватает весов для нейрона слоя 2
	
	//заполняем первичными данными

		neyronin = Outputs1m[Quoter];

	int32_t f0 = neyronout.size();


	/////
	for (int32_t i = 0; i < f0; i++)

	{


		vector<signed char> Weight2 = Weights2m[i];



		neyronout[i] = obj1.valueneyTwoOnerm(neyronin, Weight2);

	}

		while (t01 > neyronout.size())
		{
			neyronout.push_back(t1);

		}


	

	
		Outputs2m[Quoter] = neyronout;


}



void layer2m::summneyall2m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs1m, vector<vector<signed char>>& Weights2m, vector<vector<signed char>>& Outputs2m)

{
	layer2m obj2;
	
	int32_t Quoter = 0;
	int32_t t0 = Outputs1m[0].size();

	

	for (int32_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter2m(Count, Outputs1m, Weights2m, Outputs2m, Quoter);

	}

}


void layer2m::teachdel2m(vector<signed char >& delta3m, int32_t& Quoter, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Weights2m, vector<vector<signed char>>& Outputs2m, vector<signed char >& delta2m)

{
	
	Neyron obj2;

	vector<signed char > Outputs;
	vector<signed char> Weightsl;
	//int32_t t0 = Weights3.size();
	int32_t t0 = Outputs2m[Quoter].size();
	vector<signed char > delta(t0);

	Outputs = Outputs2m[Quoter];
	Weightsl = Weights3m[0];

	int32_t t1 = delta3m.size();
	int32_t t2 = Outputs2m[Quoter].size();

	signed char alpha = 100;

	for (int32_t i1 = 0; i1 < t1; i1++)
	{
		signed char a = delta3m[i1];
		
		delta = obj2.deltaMiddlem(t2, Weightsl, delta, a, alpha, Outputs);


	}

	delta2m = delta;
}



void layer2m::teach2m(int32_t& Quoter, vector<vector<signed char>>& Outputs2m, signed char alpha, vector<vector<signed char>>& Weights2m, vector<signed char >& delta2m)

{
	Neyron obj2;
	
	//альфа*значение низ * дельта
	int32_t t0 = Outputs2m[Quoter].size();
	vector<signed char > Outputs(t0);
	Outputs = Outputs2m[Quoter];
	int32_t t1 = Weights2m[0].size();


	for (int32_t i = 0; i < t0; i++)
	{
		/*
		signed char Output = Outputs[i];
		signed char delta = delta2[i];
		vector<signed char > Weights = Weights2[i];
		*/
		signed char t55 = delta2m[i];
		Weights2m[i] = obj2.MiddleTeach(Weights2m[i], Outputs[i], delta2m[i], t1, alpha);

	}
}