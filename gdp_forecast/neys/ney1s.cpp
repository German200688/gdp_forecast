#include <iostream>
#include <string>
#include <chrono>
#include <cstdint>
#include "../kernel/neyron.h"
#include "ney1s.h"
#include "../kernel/nvidia/cuda/nvidiac.h"

using namespace std;

void layer1::Weights1addition1(vector<signed char>& Weights1, int32_t countbefore, vector<int32_t>& Count) //количество весов в векторе всего, при добавлении одного показателя работает. countbefore c 1
{

	int32_t c1 = countbefore+1;
	int32_t c2 = 1;
	for (int32_t i = 0; i < c1; i++)
	{
		int32_t c3 = c1 - i;
		c2 *= c3;

	}

	int32_t c4 = c1 - 3;

	if (c4 <= 0) { return; }
	int32_t c6 = 1;
	for (int32_t i = 1; i <= c4; i++)
	{
		
		c6 *= i;

	}

	int32_t c7 = 6;

	int32_t c8 = c2 / (c7 * c6);


	if (Count.size() == 0) { Count.push_back(0); Count.push_back(0); Count.push_back(0);}
	if (Count.size() == 1) { Count.push_back(0); Count.push_back(0); }
	if (Count.size() == 2) { Count.push_back(0); }

	c8 -= Count[1] / 3;


	for (int32_t i = 0; i < c8; i++)
	{
		Weights1.push_back(10);
		Weights1.push_back(20);
		Weights1.push_back(30);
		int32_t i11 = 3;
		Count[1] += i11;

	}
	
	

}

void layer1::neurons_count_ney1(vector<vector<signed char>>& Outputs1, vector<int32_t>& Count, int32_t& neurons_count)

{
	
	int32_t t2 = Outputs1.size();
	int32_t t3 = Outputs1[0].size();
	int32_t t4 = neurons_count - t3;
	for (int32_t i = 0; i < t4; i++)
	{
		for (int32_t i1 = 0; i1 < t2; i1++)
		{
			Outputs1[i1].push_back(0);
			Count[2] = Count[2] + 1;
		}


	}
}

void layer1::neurons_count_quoter1(vector<vector<signed char>>& Outputs1, int32_t Quoter)

{
	
	if (Outputs1.size() == 0) { vector<signed char> t0 = { 0 }; Outputs1.push_back(t0); }
	int32_t t0 = Outputs1.size();
	t0 -= 1;
	int32_t t1 = Outputs1[0].size();


	vector<signed char> t3 = {};
	for (int32_t i = 0; i < t1; i++)
	{
		t3.push_back(0);

	}

	while (t0 < Quoter)
	{
		Outputs1.push_back(t3);
		
		t0++;

	}
	

}


void layer1::summneyquoter1(vector<int32_t>& Count, vector<vector<signed char>>& Cash1, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs1, int32_t Quoter, vector<string>& indicators) //квартал идет от 0
{
	
	Neyron obj1;
	layer1 obj2;

	//проверяем данные
	int32_t ind1 = indicators.size();
	int32_t neurons_count = 0;
	int32_t neurons_weights = 3;
	int32_t t0 = Count.size();
	if (t0 <= 1) { Count.push_back(0); }
	if (t0 <= 2) { Count.push_back(0); }
	int32_t t1 = Count[0];
	if (Quoter > t1) { std::cout << "Система рассчитывает данные только на один квартал вперед!"<< endl; return; }
	
	int32_t t3 = 1;
	int32_t t66 = ind1 - neurons_weights;
	int32_t t67 = ind1 - t66;

	for (int32_t i = 0; i < t67; i++)
	{
		int32_t t2 = ind1;
		t2 -= i;
		t3 *= t2;

	}
	int32_t t4 = 1;
		for (int32_t i = 1; i <= neurons_weights; i++)
		{
			t4 *= i;
		}
	neurons_count = t3 / t4;
	int32_t t6 = Weights1.size() / neurons_weights;
	if (Weights1.size() % neurons_weights > 0) { std::cout << "Произошла разбалансировка данными, необходимо переустановить программу и перезаполнить ее данными!" << endl; std::cout << "3" << endl; return;  }
	


	if (neurons_count > t6) { std::cout << "Произошла разбалансировка данными, необходимо переустановить программу и перезаполнить ее данными!" << endl; std::cout << "4" << endl; return; } // заполнить Weights1 - СДЕЛАЛ
	t6 = Outputs1.size(); 

	


	
	
	if (t6 < Quoter) {obj2.neurons_count_quoter1(Outputs1, Quoter); } // Outputs1 изменился квартал

	int32_t t7 = Outputs1[0].size();

	if (neurons_count > t7) {
		obj2.neurons_count_ney1(Outputs1, Count, neurons_count);
	} // Outputs1 изменился показатель




	//Count[1] = neurons_weights; //количество весов
	Count[2] = neurons_count; // количество нейронов

	//Рассчет
	vector<signed char> neyronin1 = {0, 0, 0}; 
	vector<signed char > OutputQ1 = {};
	vector<signed char> weight1 = {0, 0, 0};

	vector<signed char> cashq = {}; //данные квартала в одном векторе
	vector<signed char> neyronin1all = {}; //все данные
	signed char in0 = 0;
	signed char in1 = 0;
	signed char in2 = 0;
	int32_t i1 = 0;
	int32_t i2 = 0;
	int32_t i3 = 0;

	// наполняем вектор данными только квартала
	int32_t t8 = Cash1.size();

	for (int32_t i = 0; i < t8; i++)
	{
		cashq.push_back(Cash1[i][Quoter]);
	}
	int32_t c1 = cashq.size();


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
	int32_t s0 = 0;
	signed char out1 = 0;
	for (int32_t i = 0; i < neurons_count; i++)
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

void layer1::summneyall1(vector<int32_t>& Count, vector<vector<signed char>>& Cash1, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs1, vector<string>& indicators)

{
	int32_t Quoter = 0;
	int32_t t0 = Cash1[0].size();
	layer1 obj2;
	for (int32_t Quoter = 0; Quoter < t0; Quoter++)
	{
		obj2.summneyquoter1(Count, Cash1, Weights1, Outputs1, Quoter, indicators);

	}

}



void layer1::teachdel1(vector<signed char >& delta2, int32_t& Quoter, vector<vector<signed char>>& Weights2, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs1, vector<signed char >& delta1)

{

	Neyron obj2;

	vector<signed char > Outputs;
	vector<signed char> Weightsl;
	int32_t t0 = Weights2.size();
	vector<signed char > delta(t0);

	Outputs = Outputs1[Quoter];
	Weightsl = Weights2[0];
	int32_t t2 = Outputs1[Quoter].size();
	int32_t t1 = delta2.size();

	signed char alpha = 100;
	int32_t t9 = Weights2.size();

	for (int32_t i1 = 0; i1 < t2; i1++)
	{
		vector<signed char> Weightsll(t9);
		for (int32_t i0 = 0; i0 < t9; i0++)
		{
			Weightsll[i0] = Weights2[i0][i1];

		}

		delta[i1] = obj2.deltaMiddle(t1, Weightsll, delta2, alpha, Outputs[i1]);
		//summ (Weights4[i]*delta4[i])

	}

	delta1 = delta;
}



void layer1::teachdel1ma(vector<signed char >& delta2, int32_t& Quoter, vector<vector<signed char>>& Weights2, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs1, vector<signed char >& delta1, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d)

{

	nvidiac obj2;


	
	int32_t t0 = Weights2.size();
	vector<signed char > delta(t0);
	signed char* deltama = delta.data();

	signed char*  Outputs = Outputs1[Quoter].data();
	signed char*  Weightsl = Weights2[0].data();

	int32_t t1 = delta2.size();

	signed char alpha = 100;




	for (int32_t i1 = 0; i1 < t1; i1++)
	{
		signed char a = delta2[i1];
		
		obj2.deltaMiddlema(t1, Weightsl, deltama, a, alpha, Outputs, vec_a, vec_b, vec_c, vec_d);


	}

	delta1 = delta;
}


void layer1::teach1(int32_t& Quoter, vector<vector<signed char>>& Outputs1, signed char alpha, vector<signed char>& Weights1, vector<signed char >& delta1)

{
	Neyron obj2;

	//альфа*значение низ * дельта
	int32_t t0 = Outputs1[Quoter].size();
	vector<signed char > Outputs(t0);

	Outputs = Outputs1[Quoter];
	int32_t t1 = 3;
	int32_t t2 = 0;
	int32_t t3 = 0;

		///Weightsa1[0].size();


	for (int32_t i = 0; i < t0; i++)
	{
		vector<signed char > Weightsn(3);
		Weightsn[0] = Weights1[t2];
		t2++;
		Weightsn[1] = Weights1[t2];
		t2++;
		Weightsn[2] = Weights1[t2];
		t2++;

		Weightsn = obj2.MiddleTeach(Weightsn, Outputs[i], delta1[i], t1, alpha);

		Weights1[t3] = Weightsn[0];
		t3++;
		Weights1[t3] = Weightsn[1];
		t3++;
		Weights1[t3] = Weightsn[2];
		t3++;

	}
}