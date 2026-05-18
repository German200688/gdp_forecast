

#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney4m.h"
#include "ney3m.h"
#include "../kernel/nvidia/cuda/nvidiac.h"
#include "../kernel/activat.h"
//#include "../kernel/OB1.h"

using namespace std;

void layer4m::neyronoutindadd4m(vector<vector<double>>& Outputs4m, vector<int64_t>& Count, int64_t& CountOutputs4)

{

	int64_t t2 = Outputs4m.size();
	int64_t t3 = Outputs4m[0].size();
	int64_t t4 = CountOutputs4 - t3;

	if (Count.size() == 5) { Count.push_back(0); }
	Count[5] = t3;
	for (int64_t i = 0; i < t4; i++)
	{
		for (int64_t i1 = 0; i1 < t2; i1++)
		{
			Outputs4m[i1].push_back(0);

		}


	}
}






void layer4m::neyronoutqadd4m(vector<vector<double>>& Outputs4m, int64_t Quoter)

{

	vector<double> t0 = { 0 };
	if (Outputs4m.size() == 0) { Outputs4m.push_back(t0); }
	int64_t t1 = Outputs4m.size();
	t1 -= 1;
	int64_t t2 = Outputs4m[0].size();


	vector<double> t3 = {};
	for (int64_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs4m.push_back(t3);

		t1++;

	}


}





void layer4m::weightsaddl34m(vector<vector<double>>& Weights4m, int64_t ney1)


{
	int64_t t0 = Weights4m.size();
	int64_t t01 = Weights4m[0].size();



	double t1 = 0.05;
	int64_t t4 = ney1 - t0;




	for (int64_t i = 0; i < t0; i++)
	{
		for (int64_t i1 = 0; i1 < t4; i1++)
		{
			int64_t a = 0;

			if (t1 < 0.25 && a == 0) {
				Weights4m[i].push_back(t1); t1+=0.05; a = 1;
			}



			if (t1 >= 0.25 && a == 0) {
				Weights4m[i].push_back(t1); t1 = 0.05; a = 1;
			}



		}


	}


}



void layer4m::weightsaddl44m(vector<vector<double>>& Weights4m, int64_t CountWeights4)

{
	if (Weights4m.size() == 0) { vector<double> t0 = { 0 }; Weights4m.push_back(t0); }




	int64_t t1 = Weights4m[0].size();
	int64_t t2 = Weights4m.size();
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
		Weights4m.push_back(t3);
		t2++;

	}


}



void layer4m::summneyquoter4m(vector<int64_t>& Count, vector<vector<double>>& Outputs3m, vector<vector<double>>& Weights4m, vector<vector<double>>& Outputs4m, int64_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer4m obj2;

	int64_t t0 = Outputs3m.size(); //квартал
	int64_t t01 = Outputs3m[0].size(); // нейроны



	int64_t t11 = t01;
	double t1 = 0;
	vector<double> neyronin(t01, t1);
	int64_t t2 = Outputs4m.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) {
		obj2.neyronoutqadd4m(Outputs4m, Quoter);
	} // не хватает квартала в нейронах слоя 2


	int64_t t3 = Outputs4m[0].size();

	t3 -= 1;
	int64_t t16 = 6;
	if (t16 > t3) {
		obj2.neyronoutindadd4m(Outputs4m, Count, t16);
	} //не хватает нейронов в слое2
	t3 = Outputs4m[0].size();

	vector<double> neyronout(t3, t1);

	if (Weights4m.size() == 0) { vector<double> v0 = { 0.01 }; Weights4m.push_back(v0); }
	int64_t t4 = Weights4m[0].size();

	if (t01 > t4) { obj2.weightsaddl34m(Weights4m, t11); } //не хватает весов для слоя 1

	int64_t t5 = Weights4m.size();

	if (t5 < t01) {
		obj2.weightsaddl44m(Weights4m, t16);
	} // не хватает весов для нейрона слоя 2

	//заполняем первичными данными

	neyronin = Outputs3m[Quoter];

	int64_t f0 = neyronout.size();


	/////
	for (int64_t i = 0; i < f0; i++)

	{


		vector<double> Weight4 = Weights4m[i];



		neyronout[i] = obj1.valueneyTwoOnerm(neyronin, Weight4);

	}

	while (t16 > neyronout.size())
	{
		neyronout.push_back(t1);

	}





	Outputs4m[Quoter] = neyronout;


}



void layer4m::summneyall4m(vector<int64_t>& Count, vector<vector<double>>& Outputs3m, vector<vector<double>>& Weights4m, vector<vector<double>>& Outputs4m)

{
	layer4m obj2;

	int64_t Quoter = 0;
	int64_t t0 = Outputs3m[0].size();



	for (int64_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter4m(Count, Outputs3m, Weights4m, Outputs4m, Quoter);

	}

}


void layer4m::teachdel4m(vector<double >& delta5m, int64_t& Quoter, vector<vector<double>>& Weights5m, vector<vector<double>>& Weights4m, vector<vector<double>>& Outputs4m, vector<vector<double>>& Outputs3m, vector<double >& delta4m, double alpha)

{

	Neyron obj2;
	Activat Activat;
	Neyron obj1;

	vector<double > Outputs;
	vector<double> Weightsl;
	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs4m[Quoter].size();
	vector<double > delta(t0);

	Outputs = Outputs4m[Quoter];
	Weightsl = Weights5m[0];

	int64_t t1 = delta5m.size();
	int64_t t2 = Outputs4m[Quoter].size();
	double delta1m = delta5m[0];
	//double alpha = 0.07;

	/////////////////////////////////////////////////////////////////
	int64_t t01 = Outputs3m[0].size();
	vector<double> neyronin(t01, 0);

	neyronin = Outputs3m[Quoter];
	double OutputD4 = 0;
	vector<double > OUT4(t2, 0);
	for (int64_t i = 0; i < t2; i++)

	{


		vector<double> Weight4 = Weights4m[i];



		OUT4[i] = obj1.valueneyTwoOnerD(neyronin, Weight4);

	}





	for (int64_t i = 0; i < t0; i++)
	{
		OutputD4 += OUT4[i];

	}

	double OutputD4f = 0;
	//OutputD4f = Other.sigm(OutputD4);
	//OutputD4f = Other.tanhd(OutputD4);
	OutputD4f = Activat.swishd(OutputD4);

	double delta1f = delta1m * OutputD4f;
	//////////////////////////////////////////////////////////////////


	for (int64_t i1 = 0; i1 < t2; i1++)
	{

		delta[i1] = obj2.deltafin(t1, Weightsl[i1], delta1m, alpha, Outputs[i1]);
		//delta[i1] = obj2.deltaMiddle(t1, Weights5m[i1], delta5m, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta4m = delta;
}



void layer4m::teachdel4mam(vector<double >& delta5m, int64_t& Quoter, vector<vector<double>>& Weights5m, vector<vector<double>>& Weights4m, vector<vector<double>>& Outputs4m, vector<vector<double>>& Outputs3m, vector<double >& delta4m, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& ab, double& alpha )

{

	nvidiac obj2;
	Activat Activat;
	Neyron obj1;

	

	int64_t t0 = Outputs4m[Quoter].size();
	vector<double > deltaw(t0);
	double* delta = deltaw.data();

	double* Outputs = Outputs4m[Quoter].data();
	double* Weightsl = Weights5m[0].data();

	int64_t t1 = delta5m.size();
	int64_t t2 = Outputs4m[Quoter].size();
	double delta1 = delta5m[0];
	//double alpha = 0.21;

	/////////////////////////////////////////////////////////////////
	int64_t t01 = Outputs3m[0].size();
	vector<double> neyronin(t01, 0);

	neyronin = Outputs3m[Quoter];
	double OutputD4 = 0;
	vector<double > OUT4(t2, 0);
	for (int64_t i = 0; i < t2; i++)

	{


		vector<double> Weight4 = Weights4m[i];



		OUT4[i] = obj1.valueneyTwoOnerD(neyronin, Weight4);

	}





	for (int64_t i = 0; i < t0; i++)
	{
		OutputD4 += OUT4[i];

	}

	double OutputD4f = 0;
	//OutputD4f = Other.sigm(OutputD4);
	//OutputD4f = Other.tanhd(OutputD4);
	OutputD4f = Activat.swishd(OutputD4);

	double delta1f = delta1 * OutputD4f;
	//////////////////////////////////////////////////////////////////

	obj2.deltafimanmam4(delta, delta1, t0, Outputs, Weightsl, dvec_a4, dvec_b4, dvec_c4, ab, alpha);
	delta4m = deltaw;

}



void layer4m::teach4m(int64_t& Quoter, vector<vector<double>>& Outputs4m, double alpha, vector<vector<double>>& Weights4m, vector<double >& delta4m)

{
	Neyron obj2;


	int64_t t0 = delta4m.size();
	int64_t t00 = Outputs4m[Quoter].size();
	vector<double > Outputs(t00);
	Outputs = Outputs4m[Quoter];
	int64_t t1 = Weights4m[0].size();
	for (int64_t i0 = 0; i0 < t0; i0++)
	{
		double t01 = delta4m[i0];
		//double* Weightsl = Weights3[i0].data();
		//Weightsl - Outputs * t01;
		//obj2.MiddleTeachM(Weightsl, Outputs, t01, t1, vec_d, vec_a, vec_b);
		obj2.MiddleTeach(Weights4m[i0], Outputs, t01, t1, alpha);
	}


	/*
	//альфа*значение низ * дельта
	int64_t t0 = Outputs4m[Quoter].size();
	vector<double > Outputs(t0);
	Outputs = Outputs4m[Quoter];
	int64_t t1 = Weights4m[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		double Output = Outputs[i];
		double delta = delta2[i];
		vector<double > Weights = Weights2[i];
		*/
	/*
		double t55 = delta4m[i];
		Weights4m[i] = obj2.MiddleTeach(Weights4m[i], Outputs[i], delta4m[i], t1, alpha);

	}
	*/
}



void layer4m::teach4mam(int64_t& Quoter, vector<vector<double>>& Outputs4m, double alpham, vector<vector<double>>& Weights4m, vector<double >& delta4m, double*& vec_d, double*& vec_a, double*& vec_b)

{
	nvidiac obj2;
	//Signch obj1;


	int64_t t0 = delta4m.size();
	//int64_t t00 = Outputs3[Quoter].size();
	double* Outputs = Outputs4m[Quoter].data();
	int64_t t1 = Weights4m[0].size();
	for (int64_t i0 = 0; i0 < t0; i0++)
	{
		double t01 = delta4m[i0];
		double* Weightsl = Weights4m[i0].data();
		//Weightsl - Outputs * t01;
		obj2.MiddleTeachM(Weightsl, Outputs, t01, t1, vec_d, vec_a, vec_b, alpham);

	}



/*
	//альфа*значение низ * дельта
	int64_t t0 = Outputs4m[Quoter].size();
	vector<double > Outputs(t0);
	Outputs = Outputs4m[Quoter];
	int64_t t1 = Weights4m[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		double Output = Outputs[i];
		double delta = delta2[i];
		vector<double > Weights = Weights2[i];
		*/
	/*
		double t55 = delta4m[i];
		double t11 = Outputs[i] * delta4m[i];
			//obj1.multtt(Outputs[i], delta4m[i]);
		double t21 = t11 * alpham;
			//obj1.multtt(t11, alpham);
		double* Weightsl = Weights4m[i].data();
		obj2.MiddleTeachM(Weightsl, t11, t1, vec_d, vec_a);
	}
	*/
}
