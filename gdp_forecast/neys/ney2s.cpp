#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney1s.h"
#include "ney2s.h"
#include "../kernel/nvidia/cuda/nvidiac.h"
//#include "../kernel/OB1.h"

using namespace std;

void layer2::neyronoutindadd2(vector<vector<double>>& Outputs2, vector<int64_t>& Count, int64_t& CountOutputs1)

{

	int64_t t2 = Outputs2.size();
	int64_t t3 = Outputs2[0].size();
	int64_t t4 = CountOutputs1 - t3;

	if (Count.size() == 3) { Count.push_back(0); }
	Count[3] = t3;
	for (int64_t i = 0; i < t4; i++)
	{
		for (int64_t i1 = 0; i1 < t2; i1++)
		{
			Outputs2[i1].push_back(0);
			
		}


	}
}






void layer2::neyronoutqadd2(vector<vector<double>>& Outputs2, int64_t Quoter)

{

	vector<double> t0 = { 0 };
	if (Outputs2.size() == 0) { Outputs2.push_back(t0); }
	int64_t t1 = Outputs2.size();
	t1 -= 1;
	int64_t t2 = Outputs2[0].size();


	vector<double> t3 = {};
	for (int64_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs2.push_back(t3);

		t1++;

	}


}





void layer2::weightsaddl12(vector<vector<double>>& Weights2, int64_t ney1)


{
	int64_t t0 = Weights2.size();
	int64_t t01 = Weights2[0].size();


	
	double t1 = 0.05;
	int64_t t4 = ney1 - t0;

	


	for (int64_t i = 0; i < t0; i++)
	{
		for (int64_t i1 = 0; i1 < t4; i1++)
		{
			int64_t a = 0;
			
			if (t1 < 0.25 && a == 0) {
				Weights2[i].push_back(t1); t1+=0.05; a = 1;
			}
			
			
		
			if (t1 >= 0.25 && a == 0) {
				Weights2[i].push_back(t1); t1 = 0.05; a = 1;
			}

			

		}


	}
	

}



void layer2::weightsaddl22(vector<vector<double>>& Weights2, int64_t CountWeights2)

{
	if (Weights2.size() == 0) { vector<double> t0 = { 0 }; Weights2.push_back(t0); }


	

	int64_t t1 = Weights2[0].size();
	int64_t t2 = Weights2.size();
	int64_t t4 = CountWeights2 - t2;
	t2 -= 1;


	vector<double> t3 = {};
	double t5 = 0.05;
	for (int64_t i = 0; i < t1; i++)
	{
		int64_t a = 0;
		if (t5 < 0.25 && a ==0) {
			t3.push_back(t5); t5+=0.05; a = 1;
		}

		if (t5 >= 0.25 && a == 0) {
			t3.push_back(t5); t5 = 0.05; a = 1;
		}

	}

	
	t2 = 0;
	while (t2 < t4)
	{
		Weights2.push_back(t3);
		t2++;

	}
	
	
}



void layer2::summneyquoter2(vector<int64_t>& Count, vector<vector<double>>& Outputs1, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2, int64_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer2 obj2;

	int64_t t0 = Outputs1.size(); //квартал
	int64_t t01 = Outputs1[0].size(); // нейроны



	int64_t t11 = t01;
	double t1 = 0;
	vector<double> neyronin(t01, t1);
	int64_t t2 = Outputs2.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) { obj2.neyronoutqadd2(Outputs2, Quoter); 
	} // не хватает квартала в нейронах слоя 2

	
	int64_t t3 = Outputs2[0].size();

	t3 -= 1;
	if (t01 > t3) {
		obj2.neyronoutindadd2(Outputs2, Count, t01); 
	} //не хватает нейронов в слое2
	t3 = Outputs2[0].size();

	vector<double> neyronout(t3, t1);

	if (Weights2.size() == 0) { vector<double> v0 = { 0.01 }; Weights2.push_back(v0); }
	int64_t t4 = Weights2[0].size();

	if (t01 > t4) { obj2.weightsaddl12(Weights2, t01); } //не хватает весов для слоя 1

	int64_t t5 = Weights2.size();
	
	if (t5 < t01) { obj2.weightsaddl22(Weights2, t11); 
	} // не хватает весов для нейрона слоя 2
	
	//заполняем первичными данными

		neyronin = Outputs1[Quoter];

	int64_t f0 = neyronout.size();


	/////
	for (int64_t i = 0; i < f0; i++)

	{


		vector<double> Weight2 = Weights2[i];



		neyronout[i] = obj1.valueneyTwoOner(neyronin, Weight2);

	}

		while (t01 > neyronout.size())
		{
			neyronout.push_back(t1);

		}


	

	
		Outputs2[Quoter] = neyronout;


}



void layer2::summneyall2(vector<int64_t>& Count, vector<vector<double>>& Outputs1, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2)

{
	layer2 obj2;
	
	int64_t Quoter = 0;
	int64_t t0 = Outputs1[0].size();

	

	for (int64_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter2(Count, Outputs1, Weights2, Outputs2, Quoter);

	}

}


void layer2::teachdel2(vector<double >& delta3, int64_t& Quoter, vector<vector<double>>& Weights3, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2, vector<double >& delta2)

{
	
	Neyron obj2;

	vector<double > Outputs;
	vector<double> Weightsl;
	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs2[Quoter].size();
	vector<double > delta(t0);

	Outputs = Outputs2[Quoter];
	Weightsl = Weights3[0];

	int64_t t1 = delta3.size();
	int64_t t2 = Outputs2[Quoter].size();

	double alpha = 0.07;

	int64_t t9 = Weights3.size();

	for (int64_t i1 = 0; i1 < t2; i1++)
	{
		vector<double> Weightsll(t9);
		for (int64_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights3[i0][i1];

		}

		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta3, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta2 = delta;
}



void layer2::teachdel2ma(vector<double >& delta3, int64_t& Quoter, vector<vector<double>>& Weights3, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2, vector<double >& delta2, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d)

{

	Neyron obj2;

	vector<double > Outputs;
	vector<double> Weightsl;
	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs2[Quoter].size();
	vector<double > delta(t0);

	Outputs = Outputs2[Quoter];
	Weightsl = Weights3[0];

	int64_t t1 = delta3.size();
	int64_t t2 = Outputs2[Quoter].size();

	double alpha = 0.07;

	int64_t t9 = Weights3.size();

	for (int64_t i1 = 0; i1 < t2; i1++)
	{
		vector<double> Weightsll(t9);
		for (int64_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights3[i0][i1];

		}

		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta3, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta2 = delta;
}


void layer2::teach2(int64_t& Quoter, vector<vector<double>>& Outputs2, double alpha, vector<vector<double>>& Weights2, vector<double >& delta2)

{
	Neyron obj2;
	
	//альфа*значение низ * дельта
	int64_t t0 = Outputs2[Quoter].size();
	vector<double > Outputs(t0);
	Outputs = Outputs2[Quoter];
	int64_t t1 = Weights2[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		double Output = Outputs[i];
		double delta = delta2[i];
		vector<double > Weights = Weights2[i];
		*/
		double t55 = delta2[i];
		Weights2[i] = obj2.MiddleTeach(Weights2[i], Outputs[i], delta2[i], t1, alpha);

	}
}



void layer2::teach2ma(int64_t& Quoter, vector<vector<double>>& Outputs2, double alpha, vector<vector<double>>& Weights2, vector<double >& delta2, double*& vec_d, double*& vec_a)

{
	nvidiac obj2;
	//Signch obj1;


	//альфа*значение низ * дельта
	int64_t t0 = Outputs2[Quoter].size();
	vector<double > Outputs(t0);
	Outputs = Outputs2[Quoter];
	int64_t t1 = Weights2[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		double Output = Outputs[i];
		double delta = delta2[i];
		vector<double > Weights = Weights2[i];
		*/
		double t55 = delta2[i];
		double t11 = Outputs[i] * delta2[i];
			//obj1.multtt(Outputs[i], delta2[i]);
		double t21 = t11 * alpha;
			//obj1.multtt(t11, alpha);
		double* Weightsl = Weights2[i].data();
		obj2.MiddleTeachM(Weightsl, t11, t1, vec_d, vec_a);
	}







}