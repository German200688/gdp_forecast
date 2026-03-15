#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney2s.h"
#include "ney3s.h"
#include "../kernel/nvidia/cuda/nvidiac.h"
#include "../kernel/OB1.h"

using namespace std;

void layer3::neyronoutindadd3(vector<vector<signed char>>& Outputs3, vector<int64_t>& Count, int64_t& CountOutputs2)

{

	int64_t t2 = Outputs3.size();
	int64_t t3 = Outputs3[0].size();
	int64_t t4 = CountOutputs2 - t3;

	if (Count.size() == 4) { Count.push_back(0); }
	Count[4] = t3;
	for (int64_t i = 0; i < t4; i++)
	{
		for (int64_t i1 = 0; i1 < t2; i1++)
		{
			Outputs3[i1].push_back(0);
			
		}


	}
}






void layer3::neyronoutqadd3(vector<vector<signed char>>& Outputs3, int64_t Quoter)

{

	vector<signed char> t0 = { 0 };
	if (Outputs3.size() == 0) { Outputs3.push_back(t0); }
	int64_t t1 = Outputs3.size();
	t1 -= 1;
	int64_t t2 = Outputs3[0].size();


	vector<signed char> t3 = {};
	for (int64_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs3.push_back(t3);

		t1++;

	}


}





void layer3::weightsaddl23(vector<vector<signed char>>& Weights3, int64_t ney1)


{
	int64_t t0 = Weights3.size();
	int64_t t01 = Weights3[0].size();


	
	signed char t1 = 0;
	int64_t t4 = ney1 - t0;

	


	for (int64_t i = 0; i < t0; i++)
	{
		for (int64_t i1 = 0; i1 < t4; i1++)
		{
			int64_t a = 0;
			
			if (t1 < 5 && a == 0) {
				Weights3[i].push_back(t1); t1++; a = 1;
			}
			
			
		
			if (t1 >= 5 && a == 0) {
				Weights3[i].push_back(t1); t1 = 0; a = 1;
			}

			

		}


	}
	

}



void layer3::weightsaddl33(vector<vector<signed char>>& Weights3, int64_t CountWeights3)

{
	if (Weights3.size() == 0) { vector<signed char> t0 = { 0 }; Weights3.push_back(t0); }


	

	int64_t t1 = Weights3[0].size();
	int64_t t2 = Weights3.size();
	int64_t t4 = CountWeights3 - t2;
	t2 -= 1;


	vector<signed char> t3 = {};
	signed char t5 = 5;
	for (int64_t i = 0; i < t1; i++)
	{
		int64_t a = 0;
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
		Weights3.push_back(t3);
		t2++;

	}
	
	
}



void layer3::summneyquoter3(vector<int64_t>& Count, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, int64_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer3 obj2;

	int64_t t0 = Outputs2.size(); //квартал
	int64_t t01 = Outputs2[0].size(); // нейроны



	int64_t t11 = t01;
	signed char t1 = 0;
	vector<signed char> neyronin(t01, t1);
	int64_t t2 = Outputs3.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) { obj2.neyronoutqadd3(Outputs3, Quoter); 
	} // не хватает квартала в нейронах слоя 2

	
	int64_t t3 = Outputs3[0].size();

	t3 -= 1;
	if (t01 > t3) {
		obj2.neyronoutindadd3(Outputs3, Count, t01); 
	} //не хватает нейронов в слое2
	t3 = Outputs3[0].size();

	vector<signed char> neyronout(t3, t1);

	if (Weights3.size() == 0) { vector<signed char> v0 = { 0 }; Weights3.push_back(v0); }
	int64_t t4 = Weights3[0].size();

	if (t01 > t4) { obj2.weightsaddl23(Weights3, t01); } //не хватает весов для слоя 1

	int64_t t5 = Weights3.size();
	
	if (t5 < t01) { obj2.weightsaddl33(Weights3, t11); 
	} // не хватает весов для нейрона слоя 2
	
	//заполняем первичными данными

		neyronin = Outputs2[Quoter];

	int64_t f0 = neyronout.size();


	/////
	for (int64_t i = 0; i < f0; i++)

	{


		vector<signed char> Weight2 = Weights3[i];



		neyronout[i] = obj1.valueneyTwoOner(neyronin, Weight2);

	}

		while (t01 > neyronout.size())
		{
			neyronout.push_back(t1);

		}


	

	
		Outputs3[Quoter] = neyronout;


}



void layer3::summneyall3(vector<int64_t>& Count, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3)

{
	layer3 obj2;
	
	int64_t Quoter = 0;
	int64_t t0 = Outputs2[0].size();

	

	for (int64_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter3(Count, Outputs2, Weights3, Outputs3, Quoter);

	}

}


void layer3::teachdel3(vector<signed char >& delta4, int64_t& Quoter, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<signed char >& delta3)

{
	
	Neyron obj2;

	vector<signed char > Outputs;
	vector<signed char> Weightsl;
	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs3[Quoter].size();
	vector<signed char > delta(t0);
	
	Outputs = Outputs3[Quoter];
	Weightsl = Weights4[0];

	int64_t t1 = delta4.size();
	int64_t t2 = Outputs3[Quoter].size();
	vector<signed char > delta1(t1);
	signed char alpha = 100;
	int64_t t9 = Weights4.size();

	for (int64_t i1 = 0; i1 < t2; i1++)
	{
		vector<signed char> Weightsll(t9);
		for (int64_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights4[i0][i1];

		}
		
		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta4, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta3 = delta;
}




void layer3::teachdel3ma(vector<signed char >& delta4, int64_t& Quoter, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<signed char >& delta3, signed char*& dvec_a23, signed char*& dvec_b23)

{

	Neyron obj2;

	vector<signed char > Outputs;
	vector<signed char> Weightsl;
	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs3[Quoter].size();
	vector<signed char > delta(t0);

	Outputs = Outputs3[Quoter];
	Weightsl = Weights4[0];

	int64_t t1 = delta4.size();
	int64_t t2 = Outputs3[Quoter].size();
	vector<signed char > delta1(t1);
	signed char alpha = 100;
	int64_t t9 = Weights4.size();

	for (int64_t i1 = 0; i1 < t2; i1++)
	{
		vector<signed char> Weightsll(t9);
		for (int64_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights4[i0][i1];

		}

		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta4, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta3 = delta;
}



void layer3::teach3(int64_t& Quoter, vector<vector<signed char>>& Outputs3, signed char alpha, vector<vector<signed char>>& Weights3, vector<signed char >& delta3)

{
	Neyron obj2;
	
	//альфа*значение низ * дельта
	int64_t t0 = Outputs3[Quoter].size();
	vector<signed char > Outputs(t0);
	Outputs = Outputs3[Quoter];
	int64_t t1 = Weights3[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		signed char Output = Outputs[i];
		signed char delta = delta2[i];
		vector<signed char > Weights = Weights2[i];
		*/
		signed char t55 = delta3[i];
		Weights3[i] = obj2.MiddleTeach(Weights3[i], Outputs[i], delta3[i], t1, alpha);

	}
}

void layer3::teach3ma(int64_t& Quoter, vector<vector<signed char>>& Outputs3, signed char alpha, vector<vector<signed char>>& Weights3, vector<signed char >& delta3, signed char*& vec_d, signed char*& vec_a)

{
	nvidiac obj2;
	Signch obj1;


	//альфа*значение низ * дельта
	int64_t t0 = Outputs3[Quoter].size();
	vector<signed char > Outputs(t0);
	Outputs = Outputs3[Quoter];
	int64_t t1 = Weights3[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		signed char Output = Outputs[i];
		signed char delta = delta2[i];
		vector<signed char > Weights = Weights2[i];
		*/
		signed char t55 = delta3[i];
		signed char t11 = obj1.multtt(Outputs[i], delta3[i]);
		signed char t21 = obj1.multtt(t11, alpha);
		signed char* Weightsl = Weights3[i].data();
		obj2.MiddleTeachM(Weightsl, t11, t1, vec_d, vec_a);


	}
}