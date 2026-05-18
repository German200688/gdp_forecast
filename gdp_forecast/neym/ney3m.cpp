#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney2m.h"
#include "ney3m.h"
#include "../kernel/nvidia/cuda/nvidiac.h"
#include "../kernel/activat.h"
//#include "../kernel/OB1.h"

using namespace std;

void layer3m::neyronoutindadd3m(vector<vector<double>>& Outputs3m, vector<int64_t>& Count, int64_t& CountOutputs2)

{

	int64_t t2 = Outputs3m.size();
	int64_t t3 = Outputs3m[0].size();
	int64_t t4 = CountOutputs2 - t3;

	if (Count.size() == 4) { Count.push_back(0); }
	Count[4] = t3;
	for (int64_t i = 0; i < t4; i++)
	{
		for (int64_t i1 = 0; i1 < t2; i1++)
		{
			Outputs3m[i1].push_back(0);
			
		}


	}
}






void layer3m::neyronoutqadd3m(vector<vector<double>>& Outputs3m, int64_t Quoter)

{

	vector<double> t0 = { 0 };
	if (Outputs3m.size() == 0) { Outputs3m.push_back(t0); }
	int64_t t1 = Outputs3m.size();
	t1 -= 1;
	int64_t t2 = Outputs3m[0].size();


	vector<double> t3 = {};
	for (int64_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t1 < Quoter)
	{
		Outputs3m.push_back(t3);

		t1++;

	}


}





void layer3m::weightsaddl23m(vector<vector<double>>& Weights3m, int64_t ney1)


{
	int64_t t0 = Weights3m.size();
	int64_t t01 = Weights3m[0].size();


	
	double t1 = 0.05;
	int64_t t4 = ney1 - t0;

	


	for (int64_t i = 0; i < t0; i++)
	{
		for (int64_t i1 = 0; i1 < t4; i1++)
		{
			int64_t a = 0;
			
			if (t1 < 0.05 && a == 0) {
				Weights3m[i].push_back(t1); t1+=0.05; a = 1;
			}
			
			
		
			if (t1 >= 0.05 && a == 0) {
				Weights3m[i].push_back(t1); t1 = 0.05; a = 1;
			}

			

		}


	}
	

}



void layer3m::weightsaddl33m(vector<vector<double>>& Weights3m, int64_t CountWeights3)

{
	if (Weights3m.size() == 0) { vector<double> t0 = { 0 }; Weights3m.push_back(t0); }


	

	int64_t t1 = Weights3m[0].size();
	int64_t t2 = Weights3m.size();
	int64_t t4 = CountWeights3 - t2;
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
		Weights3m.push_back(t3);
		t2++;

	}
	
	
}



void layer3m::summneyquoter3m(vector<int64_t>& Count, vector<vector<double>>& Outputs2m, vector<vector<double>>& Weights3m, vector<vector<double>>& Outputs3m, int64_t Quoter) //квартал идет от 0 у каждого нейрона свой вектор

{
	Neyron obj1;
	layer3m obj2;

	int64_t t0 = Outputs2m.size(); //квартал
	int64_t t01 = Outputs2m[0].size(); // нейроны



	int64_t t11 = t01;
	double t1 = 0;
	vector<double> neyronin(t01, t1);
	int64_t t2 = Outputs3m.size();
	t0 -= 1;
	//t2 -= 1;
	if (t2 < Quoter) { obj2.neyronoutqadd3m(Outputs3m, Quoter); 
	} // не хватает квартала в нейронах слоя 2

	
	int64_t t3 = Outputs3m[0].size();

	t3 -= 1;
	if (t01 > t3) {
		obj2.neyronoutindadd3m(Outputs3m, Count, t01); 
	} //не хватает нейронов в слое2
	t3 = Outputs3m[0].size();

	vector<double> neyronout(t3, t1);

	if (Weights3m.size() == 0) { vector<double> v0 = { 0.01 }; Weights3m.push_back(v0); }
	int64_t t4 = Weights3m[0].size();

	if (t01 > t4) { obj2.weightsaddl23m(Weights3m, t01); } //не хватает весов для слоя 1

	int64_t t5 = Weights3m.size();
	
	if (t5 < t01) { obj2.weightsaddl33m(Weights3m, t11); 
	} // не хватает весов для нейрона слоя 2
	
	//заполняем первичными данными

		neyronin = Outputs2m[Quoter];

	int64_t f0 = neyronout.size();


	/////
	for (int64_t i = 0; i < f0; i++)

	{


		vector<double> Weight2 = Weights3m[i];



		neyronout[i] = obj1.valueneyTwoOnerm(neyronin, Weight2);

	}

		while (t01 > neyronout.size())
		{
			neyronout.push_back(t1);

		}


	

	
		Outputs3m[Quoter] = neyronout;


}



void layer3m::summneyall3m(vector<int64_t>& Count, vector<vector<double>>& Outputs2m, vector<vector<double>>& Weights3m, vector<vector<double>>& Outputs3m)

{
	layer3m obj2;
	
	int64_t Quoter = 0;
	int64_t t0 = Outputs2m[0].size();

	

	for (int64_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter3m(Count, Outputs2m, Weights3m, Outputs3m, Quoter);

	}

}


void layer3m::teachdel3m(vector<double >& delta4m, int64_t& Quoter, vector<vector<double>>& Weights4m, vector<vector<double>>& Weights3m, vector<vector<double>>& Outputs3m, vector<vector<double>>& Outputs2m, vector<double >& delta3m, double alpha)

{
	
	Neyron obj2;
	Activat Activat;
	Neyron obj1;

	vector<double > Outputs;
	vector<double> Weightsl;
	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs3m[Quoter].size();
	vector<double > delta(t0);
	
	Outputs = Outputs3m[Quoter];
	Weightsl = Weights4m[0];

	int64_t t1 = delta4m.size();
	int64_t t2 = Outputs3m[Quoter].size();

	//double alpha = 0.07;

	int64_t t9 = Weights4m.size();



	/////////////////////////////////////////////////////////////////
	int64_t t01 = Outputs3m[0].size();
	vector<double> neyronin(t01, 0);

	neyronin = Outputs2m[Quoter];
	double OutputD3 = 0;
	vector<double > OUT3(t2, 0);
	for (int64_t i = 0; i < t2; i++)

	{


		vector<double> Weight3 = Weights3m[i];



		OUT3[i] = obj1.valueneyTwoOnerD(neyronin, Weight3);

	}





	for (int64_t i = 0; i < t0; i++)
	{
		OutputD3 += OUT3[i];

	}

	double OutputD3f = 0;
	//OutputD4f = Other.sigm(OutputD4);
	//OutputD4f = Other.tanhd(OutputD4);
	OutputD3f = Activat.tanhd(OutputD3);


	//////////////////////////////////////////////////////////////////


	for (int64_t i1 = 0; i1 < t2; i1++)
	{
		vector<double> Weightsll(t9);
		for (int64_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights4m[i0][i1];

		}

		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta4m, alpha, Outputs[i1], OutputD3);
		//summ (Weights4[i]*delta4[i])

	}

	delta3m = delta;
}



void layer3m::teachdel3mam(vector<double >& delta4m, int64_t& Quoter, vector<vector<double>>& Weights4m, vector<vector<double>>& Weights3m, vector<vector<double>>& Outputs3m, vector<vector<double>>& Outputs2m, vector<double >& delta3m, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d, double alpha)

{

	Neyron obj2;
	Activat Activat;
	Neyron obj1;

	vector<double > Outputs;
	vector<double> Weightsl;
	//int64_t t0 = Weights3.size();
	int64_t t0 = Outputs3m[Quoter].size();
	vector<double > delta(t0);

	Outputs = Outputs3m[Quoter];
	Weightsl = Weights4m[0];

	int64_t t1 = delta4m.size();
	int64_t t2 = Outputs3m[Quoter].size();

	//double alpha = 0.07;

	int64_t t9 = Weights4m.size();

	/////////////////////////////////////////////////////////////////
	int64_t t01 = Outputs3m[0].size();
	vector<double> neyronin(t01, 0);

	neyronin = Outputs2m[Quoter];
	double OutputD3 = 0;
	vector<double > OUT3(t2, 0);
	for (int64_t i = 0; i < t2; i++)

	{


		vector<double> Weight3 = Weights3m[i];



		OUT3[i] = obj1.valueneyTwoOnerD(neyronin, Weight3);

	}





	for (int64_t i = 0; i < t0; i++)
	{
		OutputD3 += OUT3[i];

	}

	double OutputD3f = 0;
	//OutputD4f = Other.sigm(OutputD4);
	//OutputD4f = Other.tanhd(OutputD4);
	OutputD3f = Activat.tanhd(OutputD3);


	//////////////////////////////////////////////////////////////////


	for (int64_t i1 = 0; i1 < t2; i1++)
	{
		vector<double> Weightsll(t9);
		for (int64_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights4m[i0][i1];

		}

		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta4m, alpha, Outputs[i1], OutputD3f);
		//summ (Weights4[i]*delta4[i])

	}

	delta3m = delta;
}





void layer3m::teach3m(int64_t& Quoter, vector<vector<double>>& Outputs3m, double alpha, vector<vector<double>>& Weights3m, vector<double >& delta3m)

{
	Neyron obj2;


	int64_t t0 = delta3m.size();
	int64_t t00 = Outputs3m[Quoter].size();
	vector<double > Outputs(t00);
	Outputs = Outputs3m[Quoter];
	int64_t t1 = Weights3m[0].size();
	for (int64_t i0 = 0; i0 < t0; i0++)
	{
		double t01 = delta3m[i0];
		//double* Weightsl = Weights3[i0].data();
		//Weightsl - Outputs * t01;
		//obj2.MiddleTeachM(Weightsl, Outputs, t01, t1, vec_d, vec_a, vec_b);
		obj2.MiddleTeach(Weights3m[i0], Outputs, t01, t1, alpha);
	}

	/*

	//альфа*значение низ * дельта
	int64_t t0 = Outputs3m[Quoter].size();
	vector<double > Outputs(t0);
	Outputs = Outputs3m[Quoter];
	int64_t t1 = Weights3m[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		double Output = Outputs[i];
		double delta = delta2[i];
		vector<double > Weights = Weights2[i];
		*/
	/*
		double t55 = delta3m[i];
		Weights3m[i] = obj2.MiddleTeach(Weights3m[i], Outputs[i], delta3m[i], t1, alpha);

	}
*/
}

void layer3m::teach3mam(int64_t& Quoter, vector<vector<double>>& Outputs3m, double alpham, vector<vector<double>>& Weights3m, vector<double >& delta3m, double*& vec_d, double*& vec_a, double*& vec_b)

{
	nvidiac obj2;
	//Signch obj1;

	int64_t t0 = delta3m.size();
	//int64_t t00 = Outputs3[Quoter].size();
	double* Outputs = Outputs3m[Quoter].data();
	int64_t t1 = Weights3m[0].size();
	for (int64_t i0 = 0; i0 < t0; i0++)
	{
		double t01 = delta3m[i0];
		double* Weightsl = Weights3m[i0].data();
		//Weightsl - Outputs * t01;
		obj2.MiddleTeachM(Weightsl, Outputs, t01, t1, vec_d, vec_a, vec_b, alpham);

	}



	/*
	//альфа*значение низ * дельта
	int64_t t0 = Outputs3m[Quoter].size();
	vector<double > Outputs(t0);
	Outputs = Outputs3m[Quoter];
	int64_t t1 = Weights3m[0].size();


	for (int64_t i = 0; i < t0; i++)
	{
		/*
		double Output = Outputs[i];
		double delta = delta2[i];
		vector<double > Weights = Weights2[i];
		*/
	/*
		double t55 = delta3m[i];
		double t11 = Outputs[i] * delta3m[i];
			//obj1.multtt(Outputs[i], delta3m[i]);
		double t21 = t11 * alpham;
			//obj1.multtt(t11, alpham);
		double* Weightsl = Weights3m[i].data();
		obj2.MiddleTeachM(Weightsl, t11, t1, vec_d, vec_a);
	}
	*/
}