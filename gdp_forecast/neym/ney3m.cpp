#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney2m.h"
#include "ney3m.h"
#include "../kernel/nvidia/cuda/nvidiac.h"

using namespace std;

void layer3m::neyronoutindadd3m(vector<vector<signed char>>& Outputs3m, vector<int32_t>& Count, int32_t& CountOutputs2)

{

	int32_t t2 = Outputs3m.size();
	int32_t t3 = Outputs3m[0].size();
	int32_t t4 = CountOutputs2 - t3;

	if (Count.size() == 4) { Count.push_back(0); }
	Count[4] = t3;
	for (int32_t i = 0; i < t4; i++)
	{
		for (int32_t i1 = 0; i1 < t2; i1++)
		{
			Outputs3m[i1].push_back(0);
			
		}


	}
}






void layer3m::neyronoutqadd3m(vector<vector<signed char>>& Outputs3m, int32_t Quoter)

{

	vector<signed char> t0 = { 0 };
	if (Outputs3m.size() == 0) { Outputs3m.push_back(t0); }
	int32_t t1 = Outputs3m.size();
	t1 -= 1;
	int32_t t2 = Outputs3m[0].size();


	vector<signed char> t3 = {};
	for (int32_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs3m.push_back(t3);

		t1++;

	}


}





void layer3m::weightsaddl23m(vector<vector<signed char>>& Weights3m, int32_t ney1)


{
	int32_t t0 = Weights3m.size();
	int32_t t01 = Weights3m[0].size();


	
	signed char t1 = 0;
	int32_t t4 = ney1 - t0;

	


	for (int32_t i = 0; i < t0; i++)
	{
		for (int32_t i1 = 0; i1 < t4; i1++)
		{
			int32_t a = 0;
			
			if (t1 < 5 && a == 0) {
				Weights3m[i].push_back(t1); t1++; a = 1;
			}
			
			
		
			if (t1 >= 5 && a == 0) {
				Weights3m[i].push_back(t1); t1 = 0; a = 1;
			}

			

		}


	}
	

}



void layer3m::weightsaddl33m(vector<vector<signed char>>& Weights3m, int32_t CountWeights3)

{
	if (Weights3m.size() == 0) { vector<signed char> t0 = { 0 }; Weights3m.push_back(t0); }


	

	int32_t t1 = Weights3m[0].size();
	int32_t t2 = Weights3m.size();
	int32_t t4 = CountWeights3 - t2;
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
		Weights3m.push_back(t3);
		t2++;

	}
	
	
}



void layer3m::summneyquoter3m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs2m, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Outputs3m, int32_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer3m obj2;

	int32_t t0 = Outputs2m.size(); //квартал
	int32_t t01 = Outputs2m[0].size(); // нейроны



	int32_t t11 = t01;
	signed char t1 = 0;
	vector<signed char> neyronin(t01, t1);
	int32_t t2 = Outputs3m.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) { obj2.neyronoutqadd3m(Outputs3m, Quoter); 
	} // не хватает квартала в нейронах слоя 2

	
	int32_t t3 = Outputs3m[0].size();

	t3 -= 1;
	if (t01 > t3) {
		obj2.neyronoutindadd3m(Outputs3m, Count, t01); 
	} //не хватает нейронов в слое2
	t3 = Outputs3m[0].size();

	vector<signed char> neyronout(t3, t1);

	if (Weights3m.size() == 0) { vector<signed char> v0 = { 0 }; Weights3m.push_back(v0); }
	int32_t t4 = Weights3m[0].size();

	if (t01 > t4) { obj2.weightsaddl23m(Weights3m, t01); } //не хватает весов для слоя 1

	int32_t t5 = Weights3m.size();
	
	if (t5 < t01) { obj2.weightsaddl33m(Weights3m, t11); 
	} // не хватает весов для нейрона слоя 2
	
	//заполняем первичными данными

		neyronin = Outputs2m[Quoter];

	int32_t f0 = neyronout.size();


	/////
	for (int32_t i = 0; i < f0; i++)

	{


		vector<signed char> Weight2 = Weights3m[i];



		neyronout[i] = obj1.valueneyTwoOnerm(neyronin, Weight2);

	}

		while (t01 > neyronout.size())
		{
			neyronout.push_back(t1);

		}


	

	
		Outputs3m[Quoter] = neyronout;


}



void layer3m::summneyall3m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs2m, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Outputs3m)

{
	layer3m obj2;
	
	int32_t Quoter = 0;
	int32_t t0 = Outputs2m[0].size();

	

	for (int32_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter3m(Count, Outputs2m, Weights3m, Outputs3m, Quoter);

	}

}


void layer3m::teachdel3m(vector<signed char >& delta4m, int32_t& Quoter, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Outputs3m, vector<signed char >& delta3m)

{
	
	Neyron obj2;

	vector<signed char > Outputs;
	vector<signed char> Weightsl;
	//int32_t t0 = Weights3.size();
	int32_t t0 = Outputs3m[Quoter].size();
	vector<signed char > delta(t0);
	
	Outputs = Outputs3m[Quoter];
	Weightsl = Weights4m[0];

	int32_t t1 = delta4m.size();
	int32_t t2 = Outputs3m[Quoter].size();

	signed char alpha = 100;

	for (int32_t i1 = 0; i1 < t1; i1++)
	{
		signed char a = delta4m[i1];
		
		delta = obj2.deltaMiddlem(t2, Weightsl, delta, a, alpha, Outputs);


	}

	delta3m = delta;
}



void layer3m::teachdel3mam(vector<signed char >& delta4m, int32_t& Quoter, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Outputs3m, vector<signed char >& delta3m, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d)

{

	nvidiac obj2;


	//int32_t t0 = Weights3.size();
	int32_t t011 = Outputs3m[Quoter].size();
	vector<signed char > delta(t011);
	signed char* deltama = delta.data();

	signed char* Outputs = Outputs3m[Quoter].data();
	signed char* Weightsl = Weights4m[0].data();

	int32_t t1 = delta4m.size();
	int32_t t2 = Outputs3m[Quoter].size();

	signed char alpha = 100;




	for (int32_t i1 = 0; i1 < t1; i1++)
	{
		signed char a = delta4m[i1];

		obj2.deltaMiddlemam(t2, Weightsl, deltama, a, alpha, Outputs, vec_a, vec_b, vec_c, vec_d);


	}

	delta3m = delta;
}





void layer3m::teach3m(int32_t& Quoter, vector<vector<signed char>>& Outputs3m, signed char alpha, vector<vector<signed char>>& Weights3m, vector<signed char >& delta3m)

{
	Neyron obj2;
	
	//альфа*значение низ * дельта
	int32_t t0 = Outputs3m[Quoter].size();
	vector<signed char > Outputs(t0);
	Outputs = Outputs3m[Quoter];
	int32_t t1 = Weights3m[0].size();


	for (int32_t i = 0; i < t0; i++)
	{
		/*
		signed char Output = Outputs[i];
		signed char delta = delta2[i];
		vector<signed char > Weights = Weights2[i];
		*/
		signed char t55 = delta3m[i];
		Weights3m[i] = obj2.MiddleTeach(Weights3m[i], Outputs[i], delta3m[i], t1, alpha);

	}
}