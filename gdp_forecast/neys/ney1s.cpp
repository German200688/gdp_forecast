#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney1s.h"
#include "../kernel/nvidia/cuda/nvidiac.h"

using namespace std;

void layer1::Weights1addition1(vector<double>& Weights1, int64_t countbefore, vector<int64_t>& Count) //количество весов в векторе всего, при добавлении одного показателя работает. countbefore c 1
{

	int64_t c1 = countbefore+1;
	int64_t c2 = countbefore * (countbefore - 1) * (countbefore - 2);
	

	int64_t c4 = c1 - 3;

	if (c4 <= 0) { return; }

	int64_t c7 = 2;

	int64_t c8 = c2 / c7;


	if (Count.size() == 0) { Count.push_back(0); Count.push_back(0); Count.push_back(0);}
	if (Count.size() == 1) { Count.push_back(0); Count.push_back(0); }
	if (Count.size() == 2) { Count.push_back(0); }

	c8 -= Count[1] / 3;


	for (int64_t i = 0; i < c8; i++)
	{
		Weights1.push_back(0.01);
		Weights1.push_back(0.02);
		Weights1.push_back(0.03);
		int64_t i11 = 3;
		Count[1] += i11;

	}
	
	

}

void layer1::neurons_count_ney1(vector<vector<double>>& Outputs1, vector<int64_t>& Count, int64_t& neurons_count)

{
	
	int64_t t2 = Outputs1.size();
	int64_t t3 = Outputs1[0].size();
	int64_t t4 = neurons_count - t3;
	for (int64_t i = 0; i < t4; i++)
	{
		for (int64_t i1 = 0; i1 < t2; i1++)
		{
			Outputs1[i1].push_back(0);
			Count[2] = Count[2] + 1;
		}


	}
}

void layer1::neurons_count_quoter1(vector<vector<double>>& Outputs1, int64_t Quoter)

{
	
	if (Outputs1.size() == 0) { vector<double> t0 = { 0 }; Outputs1.push_back(t0); }
	int64_t t0 = Outputs1.size();
	t0 -= 1;
	int64_t t1 = Outputs1[0].size();


	vector<double> t3 = {};
	for (int64_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t0 < Quoter)
	{
		Outputs1.push_back(t3);
		
		t0++;

	}
	

}


void layer1::summneyquoter1(vector<int64_t>& Count, vector<vector<double>>& Cash1, vector<double>& Weights1, vector<vector<double>>& Outputs1, int64_t Quoter, vector<string>& indicators) //квартал идет от 0
{
	
	Neyron obj1;
	layer1 obj2;

	//проверяем данные
	int64_t ind1 = indicators.size();
	int64_t neurons_count = 0;
	int64_t neurons_weights = 3;
	int64_t t0 = Count.size();
	if (t0 <= 1) { Count.push_back(0); }
	if (t0 <= 2) { Count.push_back(0); }
	int64_t t1 = Count[0];
	if (Quoter > t1) { std::cout << "Система рассчитывает данные только на один квартал вперед!"<< endl; return; }
	
	int64_t t3 = 1;
	int64_t t66 = ind1 - neurons_weights;
	int64_t t67 = ind1 - t66;

	for (int64_t i = 0; i < t67; i++)
	{
		int64_t t2 = ind1;
		t2 -= i;
		t3 *= t2;

	}
	int64_t t4 = 1;
		for (int64_t i = 1; i <= neurons_weights; i++)
		{
			t4 *= i;
		}
	neurons_count = t3 / t4;
	int64_t t6 = Weights1.size() / neurons_weights;
	if (Weights1.size() % neurons_weights > 0) { std::cout << "Произошла разбалансировка данными, необходимо переустановить программу и перезаполнить ее данными!" << endl; std::cout << "3" << endl; return;  }
	


	if (neurons_count > t6) { std::cout << "Произошла разбалансировка данными, необходимо переустановить программу и перезаполнить ее данными!" << endl; std::cout << "4" << endl; return; } // заполнить Weights1 - СДЕЛАЛ
	t6 = Outputs1.size(); 

	


	
	
	if (t6 < Quoter) {obj2.neurons_count_quoter1(Outputs1, Quoter); } // Outputs1 изменился квартал

	int64_t t7 = Outputs1[0].size();

	if (neurons_count > t7) {
		obj2.neurons_count_ney1(Outputs1, Count, neurons_count);
	} // Outputs1 изменился показатель




	//Count[1] = neurons_weights; //количество весов
	Count[2] = neurons_count; // количество нейронов

	//Рассчет
	vector<double> neyronin1 = {0, 0, 0}; 
	vector<double > OutputQ1 = {};
	vector<double> weight1 = {0, 0, 0};

	vector<double> cashq = {}; //данные квартала в одном векторе
	vector<double> neyronin1all = {}; //все данные
	double in0 = 0;
	double in1 = 0;
	double in2 = 0;
	int64_t i1 = 0;
	int64_t i2 = 0;
	int64_t i3 = 0;

	// наполняем вектор данными только квартала
	int64_t t8 = Cash1.size();

	for (int64_t i = 0; i < t8; i++)
	{
		cashq.push_back(Cash1[i][Quoter]);
	}
	int64_t c1 = cashq.size();


	// наполняем всеми входящими данными общий вектор входных данных

	while (i1 < c1)
	{
		i2 = i1 +1;
		while (i2 < c1)
		{
			i3 = i2+1;
			while (i3 < c1)
			{
				neyronin1all.push_back(cashq [i1]);
				neyronin1all.push_back(cashq[i2]);
				neyronin1all.push_back(cashq[i3]);
				i3++;
			}


			i2++;
}


		i1++;
	}

	//по 3 передаем в функцию
	int64_t s0 = 0;
	double out1 = 0;
	for (int64_t i = 0; i < neurons_count; i++)
	{
		neyronin1[0] = neyronin1all[s0];
		weight1[0] = Weights1[s0];
		s0++;

		neyronin1[1] = neyronin1all[s0];
		weight1[1] = Weights1[s0];
		s0++;

		neyronin1[2] = neyronin1all[s0];
		weight1[2] = Weights1[s0];
		s0++;

		out1 = obj1.valueneyTwoOner(neyronin1, weight1);
		OutputQ1.push_back(out1);

	}


	//вызываем функцию рассчета
	Outputs1[Quoter] = OutputQ1;

}

void layer1::summneyall1(vector<int64_t>& Count, vector<vector<double>>& Cash1, vector<double>& Weights1, vector<vector<double>>& Outputs1, vector<string>& indicators)

{
	int64_t Quoter = 0;
	int64_t t0 = Cash1[0].size();
	layer1 obj2;
	for (int64_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter1(Count, Cash1, Weights1, Outputs1, Quoter, indicators);

	}

}



void layer1::teachdel1(vector<double >& delta2, int64_t& Quoter, vector<vector<double>>& Weights2, vector<double>& Weights1, vector<vector<double>>& Outputs1, vector<double >& delta1)

{

	Neyron obj2;

	vector<double > Outputs;
	vector<double> Weightsl;
	int64_t t0 = Weights2.size();
	vector<double > delta(t0);

	Outputs = Outputs1[Quoter];
	Weightsl = Weights2[0];
	int64_t t2 = Outputs1[Quoter].size();
	int64_t t1 = delta2.size();

	double alpha = 0.07;
	int64_t t9 = Weights2.size();

	for (int64_t i1 = 0; i1 < t2; i1++)
	{
		vector<double> Weightsll(t9);
		for (int64_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights2[i0][i1];

		}

		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta2, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta1 = delta;
}



void layer1::teachdel1ma(vector<double >& delta2, int64_t& Quoter, vector<vector<double>>& Weights2, vector<double>& Weights1, vector<vector<double>>& Outputs1, vector<double >& delta1, double*& dvec_a1, double*& dvec_b1, double*& dvec_c1)

{

	nvidiac obj2;


	
	int64_t t0 = Weights2.size();
	vector<double > delta(t0);
	double* deltama = delta.data();

	double*  Outputs = Outputs1[Quoter].data();
	double*  Weightsl = Weights2[0].data();

	int64_t t1 = delta2.size();

	double alpha = 0.07;




	for (int64_t i1 = 0; i1 < t1; i1++)
	{
		double a = delta2[i1];
		
		obj2.deltaMiddlema(t1, Weightsl, deltama, a, alpha, Outputs, dvec_a1, dvec_b1, dvec_c1);


	}

	delta1 = delta;
}


void layer1::teach1(int64_t& Quoter, vector<vector<double>>& Outputs1, double alpha, vector<double>& Weights1, vector<double >& delta1)


//	(vector<int64_t>&Count, vector<vector<double>>&Cash1, vector<double>&Weights1, vector<vector<double>>&Outputs1, int64_t Quoter, vector<string>&indicators) //квартал идет от 0
	

{
	Neyron obj2;

	//альфа*значение низ * дельта
	int64_t t0 = Outputs1[Quoter].size();
	vector<double > Outputs(t0);
	vector<double> neyronin1 = { 0, 0, 0 };
	Outputs = Outputs1[Quoter];
	vector<double> cashq = {}; //данные квартала в одном векторе
	vector<double> neyronin1all = {}; //все данные
	int64_t t1 = 3;
	int64_t t2 = 0;
	int64_t t3 = 0;

		///Weightsa1[0].size();

	
// наполняем всеми входящими данными общий вектор входных данных

while (i1 < c1)
{
	i2 = i1 + 1;
	while (i2 < c1)
	{
		i3 = i2 + 1;
		while (i3 < c1)
		{
			neyronin1all.push_back(cashq[i1]);
			neyronin1all.push_back(cashq[i2]);
			neyronin1all.push_back(cashq[i3]);
			i3++;
		}


		i2++;
	}


	i1++;
}

//по 3 передаем в функцию
int64_t s0 = 0.01;
double out1 = 0;
for (int64_t i = 0; i < neurons_count; i++)
{
	neyronin1[0] = neyronin1all[s0];
	weight1[0] = Weights1[s0];
	s0 += 0.01;

	neyronin1[1] = neyronin1all[s0];
	weight1[1] = Weights1[s0];
	s0 += 0.01;;

	neyronin1[2] = neyronin1all[s0];
	weight1[2] = Weights1[s0];
	s0 += 0.01;;

	out1 = obj1.valueneyTwoOner(neyronin1, weight1);
	OutputQ1.push_back(out1);

}
