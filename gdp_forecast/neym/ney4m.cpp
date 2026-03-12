

#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney4m.h"
#include "ney3m.h"
#include "../kernel/nvidia/cuda/nvidiac.h"
#include "../kernel/OB1.h"

using namespace std;

void layer4m::neyronoutindadd4m(vector<vector<signed char>>& Outputs4m, vector<int32_t>& Count, int32_t& CountOutputs4)

{

	int32_t t2 = Outputs4m.size();
	int32_t t3 = Outputs4m[0].size();
	int32_t t4 = CountOutputs4 - t3;

	if (Count.size() == 5) { Count.push_back(0); }
	Count[5] = t3;
	for (int32_t i = 0; i < t4; i++)
	{
		for (int32_t i1 = 0; i1 < t2; i1++)
		{
			Outputs4m[i1].push_back(0);

		}


	}
}






void layer4m::neyronoutqadd4m(vector<vector<signed char>>& Outputs4m, int32_t Quoter)

{

	vector<signed char> t0 = { 0 };
	if (Outputs4m.size() == 0) { Outputs4m.push_back(t0); }
	int32_t t1 = Outputs4m.size();
	t1 -= 1;
	int32_t t2 = Outputs4m[0].size();


	vector<signed char> t3 = {};
	for (int32_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs4m.push_back(t3);

		t1++;

	}


}





void layer4m::weightsaddl34m(vector<vector<signed char>>& Weights4m, int32_t ney1)


{
	int32_t t0 = Weights4m.size();
	int32_t t01 = Weights4m[0].size();



	signed char t1 = 0;
	int32_t t4 = ney1 - t0;




	for (int32_t i = 0; i < t0; i++)
	{
		for (int32_t i1 = 0; i1 < t4; i1++)
		{
			int32_t a = 0;

			if (t1 < 5 && a == 0) {
				Weights4m[i].push_back(t1); t1++; a = 1;
			}



			if (t1 >= 5 && a == 0) {
				Weights4m[i].push_back(t1); t1 = 0; a = 1;
			}



		}


	}


}



void layer4m::weightsaddl44m(vector<vector<signed char>>& Weights4m, int32_t CountWeights4)

{
	if (Weights4m.size() == 0) { vector<signed char> t0 = { 0 }; Weights4m.push_back(t0); }




	int32_t t1 = Weights4m[0].size();
	int32_t t2 = Weights4m.size();
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
		Weights4m.push_back(t3);
		t2++;

	}


}



void layer4m::summneyquoter4m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs3m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m, int32_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer4m obj2;

	int32_t t0 = Outputs3m.size(); //квартал
	int32_t t01 = Outputs3m[0].size(); // нейроны



	int32_t t11 = t01;
	signed char t1 = 0;
	vector<signed char> neyronin(t01, t1);
	int32_t t2 = Outputs4m.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) {
		obj2.neyronoutqadd4m(Outputs4m, Quoter);
	} // не хватает квартала в нейронах слоя 2


	int32_t t3 = Outputs4m[0].size();

	t3 -= 1;
	int32_t t16 = 6;
	if (t16 > t3) {
		obj2.neyronoutindadd4m(Outputs4m, Count, t16);
	} //не хватает нейронов в слое2
	t3 = Outputs4m[0].size();

	vector<signed char> neyronout(t3, t1);

	if (Weights4m.size() == 0) { vector<signed char> v0 = { 0 }; Weights4m.push_back(v0); }
	int32_t t4 = Weights4m[0].size();

	if (t01 > t4) { obj2.weightsaddl34m(Weights4m, t11); } //не хватает весов для слоя 1

	int32_t t5 = Weights4m.size();

	if (t5 < t01) {
		obj2.weightsaddl44m(Weights4m, t16);
	} // не хватает весов для нейрона слоя 2

	//заполняем первичными данными

	neyronin = Outputs3m[Quoter];

	int32_t f0 = neyronout.size();


	/////
	for (int32_t i = 0; i < f0; i++)

	{


		vector<signed char> Weight4 = Weights4m[i];



		neyronout[i] = obj1.valueneyTwoOnerm(neyronin, Weight4);

	}

	while (t16 > neyronout.size())
	{
		neyronout.push_back(t1);

	}





	Outputs4m[Quoter] = neyronout;


}



void layer4m::summneyall4m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs3m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m)

{
	layer4m obj2;

	int32_t Quoter = 0;
	int32_t t0 = Outputs3m[0].size();



	for (int32_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter4m(Count, Outputs3m, Weights4m, Outputs4m, Quoter);

	}

}


void layer4m::teachdel4m(vector<signed char >& delta5m, int32_t& Quoter, vector<vector<signed char>>& Weights5m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m, vector<signed char >& delta4m)

{

	Neyron obj2;

	vector<signed char > Outputs;
	vector<signed char> Weightsl;
	//int32_t t0 = Weights3.size();
	int32_t t0 = Outputs4m[Quoter].size();
	vector<signed char > delta(t0);

	Outputs = Outputs4m[Quoter];
	Weightsl = Weights5m[0];

	int32_t t1 = delta5m.size();
	int32_t t2 = Outputs4m[Quoter].size();
	signed char delta1m = delta5m[0];
	signed char alpha = 100;

	for (int32_t i1 = 0; i1 < t2; i1++)
	{

		delta[i1] = obj2.deltafin(t1, Weightsl[i1], delta1m, alpha, Outputs[i1]);
		//delta[i1] = obj2.deltaMiddle(t1, Weights5m[i1], delta5m, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta4m = delta;
}



void layer4m::teachdel4mam(vector<signed char >& delta5m, int32_t& Quoter, vector<vector<signed char>>& Weights5m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m, vector<signed char >& delta4m, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& ab)

{

	nvidiac obj2;
	

	int32_t t0 = Outputs4m[Quoter].size();
	vector<signed char > deltaw(t0);
	signed char* delta = deltaw.data();

	signed char* Outputs = Outputs4m[Quoter].data();
	signed char* Weightsl = Weights5m[0].data();

	int32_t t1 = delta5m.size();
	int32_t t2 = Outputs4m[Quoter].size();
	signed char delta1 = delta5m[0];
	signed char alpha = 100;

	obj2.deltafimanmam4(delta, delta1, t0, Outputs, Weightsl, dvec_a4, dvec_b4, dvec_c4, ab);
	delta4m = deltaw;

}



void layer4m::teach4m(int32_t& Quoter, vector<vector<signed char>>& Outputs4m, signed char alpha, vector<vector<signed char>>& Weights4m, vector<signed char >& delta4m)

{
	Neyron obj2;

	//альфа*значение низ * дельта
	int32_t t0 = Outputs4m[Quoter].size();
	vector<signed char > Outputs(t0);
	Outputs = Outputs4m[Quoter];
	int32_t t1 = Weights4m[0].size();


	for (int32_t i = 0; i < t0; i++)
	{
		/*
		signed char Output = Outputs[i];
		signed char delta = delta2[i];
		vector<signed char > Weights = Weights2[i];
		*/
		signed char t55 = delta4m[i];
		Weights4m[i] = obj2.MiddleTeach(Weights4m[i], Outputs[i], delta4m[i], t1, alpha);

	}
}



void layer4m::teach4mam(int32_t& Quoter, vector<vector<signed char>>& Outputs4m, signed char alpham, vector<vector<signed char>>& Weights4m, vector<signed char >& delta4m, signed char*& vec_d, signed char*& vec_a)

{
	nvidiac obj2;
	Signch obj1;


	//альфа*значение низ * дельта
	int32_t t0 = Outputs4m[Quoter].size();
	vector<signed char > Outputs(t0);
	Outputs = Outputs4m[Quoter];
	int32_t t1 = Weights4m[0].size();


	for (int32_t i = 0; i < t0; i++)
	{
		/*
		signed char Output = Outputs[i];
		signed char delta = delta2[i];
		vector<signed char > Weights = Weights2[i];
		*/
		signed char t55 = delta4m[i];
		signed char t11 = obj1.multtt(Outputs[i], delta4m[i]);
		signed char t21 = obj1.multtt(t1, alpham);
		signed char* Weightsl = Weights4m[i].data();
		obj2.MiddleTeachM(Weightsl, t1, t21, vec_d, vec_a);
	}
}
