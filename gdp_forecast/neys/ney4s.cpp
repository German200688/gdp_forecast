

#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney4s.h"
#include "ney3s.h"

using namespace std;

void layer4::neyronoutindadd4(vector<vector<signed char>>& Outputs4, vector<int32_t>& Count, int32_t& CountOutputs4)

{

	int32_t t2 = Outputs4.size();
	int32_t t3 = Outputs4[0].size();
	int32_t t4 = CountOutputs4 - t3;

	if (Count.size() == 5) { Count.push_back(0); }
	Count[5] = t3;
	for (int32_t i = 0; i < t4; i++)
	{
		for (int32_t i1 = 0; i1 < t2; i1++)
		{
			Outputs4[i1].push_back(0);

		}


	}
}






void layer4::neyronoutqadd4(vector<vector<signed char>>& Outputs4, int32_t Quoter)

{

	vector<signed char> t0 = { 0 };
	if (Outputs4.size() == 0) { Outputs4.push_back(t0); }
	int32_t t1 = Outputs4.size();
	t1 -= 1;
	int32_t t2 = Outputs4[0].size();


	vector<signed char> t3 = {};
	for (int32_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs4.push_back(t3);

		t1++;

	}


}





void layer4::weightsaddl34(vector<vector<signed char>>& Weights4, int32_t ney1)


{
	int32_t t0 = Weights4.size();
	int32_t t01 = Weights4[0].size();



	signed char t1 = 0;
	int32_t t4 = ney1 - t0;




	for (int32_t i = 0; i < t0; i++)
	{
		for (int32_t i1 = 0; i1 < t4; i1++)
		{
			int32_t a = 0;

			if (t1 < 5 && a == 0) {
				Weights4[i].push_back(t1); t1++; a = 1;
			}



			if (t1 >= 5 && a == 0) {
				Weights4[i].push_back(t1); t1 = 0; a = 1;
			}



		}


	}


}



void layer4::weightsaddl44(vector<vector<signed char>>& Weights4, int32_t CountWeights4)

{
	if (Weights4.size() == 0) { vector<signed char> t0 = { 0 }; Weights4.push_back(t0); }




	int32_t t1 = Weights4[0].size();
	int32_t t2 = Weights4.size();
	int32_t t4 = CountWeights4 - t2;
	t2 -= 1;


	vector<signed char> t3 = {};
	signed char t5 = 5;
	for (int32_t i = 0; i < t1; i++)
	{
		int32_t a = 0;
		if (t5 < 25 && a == 0) {
			t3.push_back(t5); t5+=5; a = 1;
		}

		if (t5 >= 25 && a == 0) {
			t3.push_back(t5); t5 = 5; a = 1;
		}

	}


	t2 = 0;
	while (t2 < t4)
	{
		Weights4.push_back(t3);
		t2++;

	}


}



void layer4::summneyquoter4(vector<int32_t>& Count, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, int32_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer4 obj2;

	int32_t t0 = Outputs3.size(); //квартал
	int32_t t01 = Outputs3[0].size(); // нейроны



	int32_t t11 = t01;
	signed char t1 = 0;
	vector<signed char> neyronin(t01, t1);
	int32_t t2 = Outputs4.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) {
		obj2.neyronoutqadd4(Outputs4, Quoter);
	} // не хватает квартала в нейронах слоя 2


	int32_t t3 = Outputs4[0].size();

	t3 -= 1;
	int32_t t16 = 6;
	if (t16 > t3) {
		obj2.neyronoutindadd4(Outputs4, Count, t16);
	} //не хватает нейронов в слое2
	t3 = Outputs4[0].size();

	vector<signed char> neyronout(t3, t1);

	if (Weights4.size() == 0) { vector<signed char> v0 = { 0 }; Weights4.push_back(v0); }
	int32_t t4 = Weights4[0].size();

	if (t01 > t4) { obj2.weightsaddl34(Weights4, t11); } //не хватает весов для слоя 1

	int32_t t5 = Weights4.size();

	if (t5 < t16) {
		obj2.weightsaddl44(Weights4, t16);
	} // не хватает весов для нейрона слоя 2

	//заполняем первичными данными

	neyronin = Outputs3[Quoter];

	int32_t f0 = neyronout.size();


	/////
	for (int32_t i = 0; i < f0; i++)

	{


		vector<signed char> Weight4 = Weights4[i];



		neyronout[i] = obj1.valueneyTwoOner(neyronin, Weight4);

	}

	while (t16 > neyronout.size())
	{
		neyronout.push_back(t1);

	}





	Outputs4[Quoter] = neyronout;


}



void layer4::summneyall4(vector<int32_t>& Count, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4)

{
	layer4 obj2;

	int32_t Quoter = 0;
	int32_t t0 = Outputs3[0].size();



	for (int32_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter4(Count, Outputs3, Weights4, Outputs4, Quoter);

	}

}


void layer4::teachdel4(vector<signed char >& delta5, int32_t& Quoter, vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<signed char >& delta4)

{

	Neyron obj2;

	vector<signed char > Outputs;
	vector<signed char> Weightsl;
	//int32_t t0 = Weights3.size();
	int32_t t0 = Outputs4[Quoter].size();
	vector<signed char > delta(t0);

	Outputs = Outputs4[Quoter];
	Weightsl = Weights5[0];

	int32_t t1 = delta5.size();
	int32_t t2 = Outputs4[Quoter].size();

	signed char alpha = 100;

	for (int32_t i1 = 0; i1 < t1; i1++)
	{
		signed char a = delta5[i1];

		delta = obj2.deltaMiddle(t2, Weightsl, delta, a, alpha, Outputs);


	}

	delta4 = delta;
}



void layer4::teach4(int32_t& Quoter, vector<vector<signed char>>& Outputs4, signed char alpha, vector<vector<signed char>>& Weights4, vector<signed char >& delta4)

{
	Neyron obj2;

	//альфа*значение низ * дельта
	int32_t t0 = Outputs4[Quoter].size();
	vector<signed char > Outputs(t0);
	Outputs = Outputs4[Quoter];
	int32_t t1 = Weights4[0].size();


	for (int32_t i = 0; i < t0; i++)
	{
		/*
		signed char Output = Outputs[i];
		signed char delta = delta2[i];
		vector<signed char > Weights = Weights2[i];
		*/
		signed char t55 = delta4[i];
		Weights4[i] = obj2.MiddleTeach(Weights4[i], Outputs[i], delta4[i], t1, alpha);

	}
}
