

#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney4s.h"
#include "ney3s.h"
#include "../kernel/nvidia/cuda/nvidiac.h"
//#include "../kernel/OB1.h"

using namespace std;

void layer4::neyronoutindadd4(vector<vector<double>>& Outputs4, vector<int64_t>& Count, int64_t& CountOutputs4)

{

	int64_t t2 = Outputs4.size();
	int64_t t3 = Outputs4[0].size();
	int64_t t4 = CountOutputs4 - t3;

	if (Count.size() == 5) { Count.push_back(0); }
	Count[5] = t3;
	for (int64_t i = 0; i < t4; i++)
	{
		for (int64_t i1 = 0; i1 < t2; i1++)
		{
			Outputs4[i1].push_back(0);

		}


	}
}






void layer4::neyronoutqadd4(vector<vector<double>>& Outputs4, int64_t Quoter)

{

	vector<double> t0 = { 0 };
	if (Outputs4.size() == 0) { Outputs4.push_back(t0); }
	int64_t t1 = Outputs4.size();
	t1 -= 1;
	int64_t t2 = Outputs4[0].size();


	vector<double> t3 = {};
	for (int64_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs4.push_back(t3);

		t1++;

	}


}





void layer4::weightsaddl34(vector<vector<double>>& Weights4, int64_t ney1)


{
	int64_t t0 = Weights4.size();
	int64_t t01 = Weights4[0].size();



	double t1 = 0.05;
	int64_t t4 = ney1 - t0;




	for (int64_t i = 0; i < t0; i++)
	{
		for (int64_t i1 = 0; i1 < t4; i1++)
		{
			int64_t a = 0;

			if (t1 < 0.25 && a == 0) {
				Weights4[i].push_back(t1); t1 += 0.05; a = 1;
			}



			if (t1 >= 0.25 && a == 0) {
				Weights4[i].push_back(t1); t1 = 0.05; a = 1;
			}



		}


	}


}



void layer4::weightsaddl44(vector<vector<double>>& Weights4, int64_t CountWeights4)

{
	if (Weights4.size() == 0) { vector<double> t0 = { 0 }; Weights4.push_back(t0); }




	int64_t t1 = Weights4[0].size();
	int64_t t2 = Weights4.size();
	int64_t t4 = CountWeights4 - t2;
	t2 -= 1;


	vector<double> t3 = {};
	double t5 = 0.05;
	for (int64_t i = 0; i < t1; i++)
	{
		int64_t a = 0;
		if (t5 < 0.25 && a == 0) {
			t3.push_back(t5); t5+=0.05; a = 1;
		}

		if (t5 >= 0.25 && a == 0) {
			t3.push_back(t5); t5 = 0.05; a = 1;
		}

	}


	t2 = 0;
	while (t2 < t4)
	{
		Weights4.push_back(t3);
		t2++;

	}


}



void layer4::summneyquoter4(vector<int64_t>& Count, vector<vector<double>>& Outputs3, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, int64_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer4 obj2;

	int64_t t0 = Outputs3.size(); //квартал
	int64_t t01 = Outputs3[0].size(); // нейроны



	int64_t t11 = t01;
	double t1 = 0;
	vector<double> neyronin(t01, t1);
	int64_t t2 = Outputs4.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) {
		obj2.neyronoutqadd4(Outputs4, Quoter);
	} // не хватает квартала в нейронах слоя 2


	int64_t t3 = Outputs4[0].size();

	t3 -= 1;
	int64_t t16 = 6;
	if (t16 > t3) {
		obj2.neyronoutindadd4(Outputs4, Count, t16);
	} //не хватает нейронов в слое2
	t3 = Outputs4[0].size();

	vector<double> neyronout(t3, t1);

	if (Weights4.size() == 0) { vector<double> v0 = { 0.01 }; Weights4.push_back(v0); }
	int64_t t4 = Weights4[0].size();

	if (t01 > t4) { obj2.weightsaddl34(Weights4, t11); } //не хватает весов для слоя 1

	int64_t t5 = Weights4.size();

	if (t5 < t16) {
		obj2.weightsaddl44(Weights4, t16);
	} // не хватает весов для нейрона слоя 2

	//заполняем первичными данными

	neyronin = Outputs3[Quoter];

	int64_t f0 = neyronout.size();


	/////
	for (int64_t i = 0; i < f0; i++)

	{


		vector<double> Weight4 = Weights4[i];



		neyronout[i] = obj1.valueneyTwoOner(neyronin, Weight4);

	}

	while (t16 > neyronout.size())
	{
		neyronout.push_back(t1);

	}





	Outputs4[Quoter] = neyronout;


}



void layer4::summneyall4(vector<int64_t>& Count, vector<vector<double>>& Outputs3, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4)

{
	layer4 obj2;

	int64_t Quoter = 0;
	int64_t t0 = Outputs3[0].size();



	for (int64_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter4(Count, Outputs3, Weights4, Outputs4, Quoter);

	}

}


void layer4::teachdel4(vector<double >& delta5, int64_t& Quoter, vector<vector<double>>& Weights5, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, vector<double >& delta4)

{

	Neyron obj2;

	vector<double > Outputs;
	vector<double> Weightsl;
	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs4[Quoter].size();
	vector<double > delta(t0);

	Outputs = Outputs4[Quoter];
	Weightsl = Weights5[0];

	int64_t t1 = delta5.size();
	int64_t t2 = Outputs4[Quoter].size();
	double delta1 = delta5[0];
	double alpha = 0.07;

	for (int64_t i1 = 0; i1 < t2; i1++)
	{


		delta[i1] = obj2.deltafin(t1, Weightsl[i1], delta1, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta4 = delta;
}


void layer4::teachdel4ma(vector<double >& delta5, int64_t& Quoter, vector<vector<double>>& Weights5, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, vector<double >& delta4, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& ab)

{

	nvidiac obj2;




	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs4[Quoter].size();
	vector<double > deltaw(t0);
	double* delta = deltaw.data();

	double* Outputs = Outputs4[Quoter].data();
	double* Weightsl = Weights5[0].data();

	int64_t t1 = delta5.size();
	int64_t t2 = Outputs4[Quoter].size();
	double delta1 = delta5[0];
	double alpha = 0.07;

	obj2.deltafimanma4(delta, delta1, t0, Outputs, Weightsl, dvec_a4, dvec_b4, dvec_c4, ab);

#ifdef _DEBUG
	cout << int(deltaw[0]) << endl;

	cout << " после рассчета int(deltaw[i]):" << endl;

	int t001 = deltaw.size();
	for (int i = 0; i < t001; i++)
	{
		cout << int(deltaw[i]) << endl;
	}

	cout << " после рассчета int(delta[i]):" << endl;

	
	for (int i = 0; i < t001; i++)
	{
		cout << int(delta[i]) << endl;
	}
#endif

	delta4 = deltaw;



	}




void layer4::teach4(int64_t& Quoter, vector<vector<double>>& Outputs4, double alpha, vector<vector<double>>& Weights4, vector<double >& delta4)

{
	Neyron obj2;

	//альфа*значение низ * дельта
	int64_t t0 = Outputs4[Quoter].size();
	vector<double > Outputs(t0);
	Outputs = Outputs4[Quoter];
	int64_t t1 = Weights4[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		double Output = Outputs[i];
		double delta = delta2[i];
		vector<double > Weights = Weights2[i];
		*/
		double t55 = delta4[i];
		Weights4[i] = obj2.MiddleTeach(Weights4[i], Outputs[i], delta4[i], t1, alpha);

	}
}


void layer4::teach4ma(int64_t& Quoter, vector<vector<double>>& Outputs4, double alpha, vector<vector<double>>& Weights4, vector<double >& delta4, double*& vec_d, double*& vec_a)

{
	nvidiac obj2;
	//Signch obj1;


	//альфа*значение низ * дельта
	int64_t t0 = Outputs4[Quoter].size();
	vector<double > Outputs(t0);
	Outputs = Outputs4[Quoter];
	int64_t t1 = Weights4[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		double Output = Outputs[i];
		double delta = delta2[i];
		vector<double > Weights = Weights2[i];
		*/
		double t55 = delta4[i];
		double t11 = Outputs[i] * delta4[i];
			//obj1.multtt(Outputs[i], delta4[i]);
		double t21 = t11 * alpha;
			//obj1.multtt(t11, alpha);
		double* Weightsl = Weights4[i].data();
		obj2.MiddleTeachM(Weightsl, t11, t1, vec_d, vec_a);
	}
}
