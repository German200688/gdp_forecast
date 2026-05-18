#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney1m.h"
#include "../kernel/nvidia/cuda/nvidiac.h"

using namespace std;

void layer1m::Weights1addition1m(vector<double>& Weights1m, vector<double>& Weights1, vector<int64_t>& Count) //количество весов в векторе всего, при добавлении одного показателя работает. countbefore c 1
{

	int64_t c8 = (Weights1.size() - Weights1m.size()) / 2;



	for (int64_t i = 0; i < c8; i++)
	{
		Weights1m.push_back(-0.01);
		Weights1m.push_back(-0.02);
		//Weights1m.push_back(-0.05);
		//int64_t i11 = 3;
		//Count[1] += i11;

	}
	
	

}

void layer1m::neurons_count_ney1m(vector<vector<double>>& Outputs1m, vector<int64_t>& Count, int64_t& neurons_count)

{
	
	int64_t t2 = Outputs1m.size();
	int64_t t3 = Outputs1m[0].size();
	int64_t t4 = neurons_count - t3;
	for (int64_t i = 0; i < t4; i++)
	{
		for (int64_t i1 = 0; i1 < t2; i1++)
		{
			Outputs1m[i1].push_back(0);
			Count[2] = Count[2] + 1;
		}


	}
}

void layer1m::neurons_count_quoter1m(vector<vector<double>>& Outputs1m, int64_t Quoter)

{
	
	if (Outputs1m.size() == 0) { vector<double> t0 = { 0 }; Outputs1m.push_back(t0); }
	int64_t t0 = Outputs1m.size();
	t0 -= 1;
	int64_t t1 = Outputs1m[0].size();


	vector<double> t3 = {};
	for (int64_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t0 < Quoter)
	{
		Outputs1m.push_back(t3);
		
		t0++;

	}
	

}


void layer1m::summneyquoter1m(vector<int64_t>& Count, vector<vector<double>>& Cash1, vector<double>& Weights1m, vector<vector<double>>& Outputs1m, int64_t Quoter, vector<string>& indicators) //квартал идет от 0
{
	
	Neyron obj1;
	layer1m obj2;

	//проверяем данные
	int64_t ind1 = indicators.size();
	int64_t neurons_count = 0;
	int64_t neurons_weights = 2;
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
	int64_t t6 = Weights1m.size() / neurons_weights;
	if (Weights1m.size() % neurons_weights > 0) { std::cout << "Произошла разбалансировка данными, необходимо переустановить программу и перезаполнить ее данными!" << endl; std::cout << "3" << endl; return;  }
	

	
	//if (neurons_count > t6) { std::cout << "Произошла разбалансировка данными, необходимо переустановить программу и перезаполнить ее данными!" << endl; std::cout << "4" << endl; return; } // заполнить Weights1 - СДЕЛАЛ
	
	t6 = Outputs1m.size(); 

	


	
	
	if (t6 < Quoter) {obj2.neurons_count_quoter1m(Outputs1m, Quoter); } // Outputs1 изменился квартал

	int64_t t7 = Outputs1m[0].size();

	if (neurons_count > t7) {
		obj2.neurons_count_ney1m(Outputs1m, Count, neurons_count);
	} // Outputs1 изменился показатель




	//Count[1] = neurons_weights; //количество весов
	Count[2] = neurons_count; // количество нейронов

	//Рассчет
	vector<double> neyronin1 = {0, 0}; 
	vector<double > OutputQ1 = {};
	vector<double> weight1 = {0, 0};

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
			//i3 = i2+1;
			//while (i3 < c1)
			//{
				neyronin1all.push_back(cashq [i1]);
				neyronin1all.push_back(cashq[i2]);
				//neyronin1all.push_back(cashq[i3]);
				//i3++;
			//}


			i2++;
}


		i1++;
	}

	//по 2 передаем в функцию
	int64_t s0 = 0;
	double out1 = 0;
	for (int64_t i = 0; i < neurons_count; i++)
	{
		neyronin1[0] = neyronin1all[s0];
		weight1[0] = Weights1m[s0];
		s0++;

		neyronin1[1] = neyronin1all[s0];
		weight1[1] = Weights1m[s0];
		s0++;

	

		out1 = obj1.valueneyTwoOner(neyronin1, weight1);
		OutputQ1.push_back(out1);

	}


	//вызываем функцию рассчета
	Outputs1m[Quoter] = OutputQ1;

}

void layer1m::summneyall1m(vector<int64_t>& Count, vector<vector<double>>& Cash1, vector<double>& Weights1m, vector<vector<double>>& Outputs1m, vector<string>& indicators)

{
	int64_t Quoter = 0;
	int64_t t0 = Cash1[0].size();
	layer1m obj2;
	for (int64_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter1m(Count, Cash1, Weights1m, Outputs1m, Quoter, indicators);

	}

}



void layer1m::teachdel1m(vector<double >& delta2m, int64_t& Quoter, vector<vector<double>>& Weights2m, vector<double>& Weights1m, vector<vector<double>>& Outputs1m, vector<double >& delta1m, double alpha)

{

	Neyron obj2;

	vector<double > Outputs;
	vector<double> Weightsl;
	int64_t t0 = Weights2m.size();
	vector<double > delta(t0);

	Outputs = Outputs1m[Quoter];
	Weightsl = Weights2m[0];
	int64_t t2 = Outputs1m[Quoter].size();
	int64_t t1 = delta2m.size();

	//double alpha = 0.07;
	int64_t t9 = Weights2m.size();

	for (int64_t i1 = 0; i1 < t2; i1++)
	{
		vector<double> Weightsll(t9);
		for (int64_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights2m[i0][i1];

		}
		double imvar = 1;
		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta2m, alpha, Outputs[i1], imvar);
		//summ (Weights4[i]*delta4[i])

	}

	delta1m = delta;
}



/*

void layer1m::teachdel1mam(vector<double >& delta2m, int64_t& Quoter, vector<vector<double>>& Weights2m, vector<double>& Weights1m, vector<vector<double>>& Outputs1m, vector<double >& delta1m, double*& dvec_a1, double*& dvec_b1, double*& dvec_c1, , double alpha)

{

	nvidiac obj2;



	int64_t t0 = Weights2m.size();
	vector<double > delta(t0);
	double* deltama = delta.data();

	double* Outputs = Outputs1m[Quoter].data();
	double* Weightsl = Weights2m[0].data();

	int64_t t1 = delta2m.size();

	//double alpha = 100;




	for (int64_t i1 = 0; i1 < t1; i1++)
	{
		double a = delta2m[i1];

		obj2.deltaMiddlemam(t1, Weightsl, deltama, a, alpha, Outputs, dvec_a1, dvec_b1, dvec_c1);


	}

	delta1m = delta;
}

*/
void layer1m::teach1m(int64_t& Quoter, vector<vector<double>>& Cash1, double alpha, vector<double>& Weights1m, vector<double >& delta1m)

{
	
	Neyron obj2;

	//Наполняем вектор входной данные
	vector<double> neyronin1all;
	vector<double> cashq = {}; //данные квартала в одном векторе
	// наполняем вектор данными только квартала
	int64_t t80 = Cash1.size();

	for (int64_t i = 0; i < t80; i++)
	{
		cashq.push_back(Cash1[i][Quoter]);
	}
	int64_t c10 = cashq.size();

	int64_t i10 = 0;
	int64_t i20 = 0;
	int64_t i30 = 0;

	while (i10 < c10)
	{
		i20 = i10 + 1;
		while (i20 < c10)
		{
			//i30 = i20 + 1;
			//while (i30 < c10)
			//{
				neyronin1all.push_back(cashq[i10]);
				neyronin1all.push_back(cashq[i20]);
				//neyronin1all.push_back(cashq[i30]);
				//i30++;
			//}


			i20++;
		}


		i10++;
	}


	//альфа*значение низ * дельта
	int64_t t0 = neyronin1all.size();
	vector<vector<double >> Outputs;
	vector<vector<double >> Wheits;

	int64_t i01 = 0;
	int64_t i02 = 0;

	while (i01 < t0)
	{
		vector<double > Output;
		vector<double > Wheit;

		while (i02 < 2)
		{
			Output.push_back(neyronin1all[i01]);
			Wheit.push_back(Weights1m[i01]);
			i02++;
			i01++;

		}
		Outputs.push_back(Output);
		Wheits.push_back(Wheit);


		i02 = 0;

	}

	int64_t t01 = Outputs.size();

	for (int64_t i = 0; i < t01; i++)
	{
		double t0 = delta1m[i];
		vector<double > Output2(2);
		vector<double > Wheit2(2);
		Output2 = Outputs[i];
		Wheit2 = Wheits[i];
		for (int64_t i1 = 0; i1 < 2; i1++)
		{
			{
				vector<double > Output;
				vector<double > Wheit;
				Output.push_back(Output2[i1]);
				Wheit.push_back(Wheit2[i1]);
				for (int64_t i2 = 0; i2 < 1; i2++)
				{
					int64_t t155 = 1;
					obj2.MiddleTeach(Wheit, Output, t0, t155, alpha);

				}
				Wheit2[i1] = Wheit[0];


			}
			Wheits[i] = Wheit2;

		}

		int64_t i001 = 0;
		int64_t i002 = 0;
		int64_t i003 = 0;


		while (i001 < t0)
		{

			while (i002 < 2)
			{

				Weights1m[i001] = Wheits[i003][i002];
				i002++;
				i001++;

			}

			i003++;
			i002 = 0;

		}


	}

}