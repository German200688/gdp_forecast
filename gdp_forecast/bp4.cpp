#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <regex>
#include <map>
#include <cstdint>
#include "increase.cpp"
#include "neys/ney1s.h"
#include "neym/ney1m.h"
#include "kernel/other.h"
#include "cash.cpp"
#include "neys/ney2s.h"
#include "neys/ney3s.h"
#include "neys/ney4s.h"
#include "neym/ney2m.h"
#include "neym/ney3m.h"
#include "neym/ney4m.h"
#include "neyout.cpp"





void teachquoter(int32_t& Quoter1, signed char& result1, signed char& result2, signed char& result, vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Weights2, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Outputs1, signed char alpha, signed char incr4,
	vector<signed char>& Weights1m,
	vector<vector<signed char>>& Weights2m,
	vector<vector<signed char>>& Weights3m,
	vector<vector<signed char>>& Weights4m,
	vector<vector<signed char>>& Weights5m,
	vector<vector<signed char>>& Outputs1m,
	vector<vector<signed char>>& Outputs2m,
	vector<vector<signed char>>& Outputs3m,
	vector<vector<signed char>>& Outputs4m,
	signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d
)
{
	Other obj3;
	layer4 obj7;
	layer3 obj6;
	layer2 obj4;
	layer1 obj5;

	layer4m obj71;
	layer3m obj61;
	layer2m obj41;
	layer1m obj51;

	vector<signed char > delta5;
	vector<signed char > delta4;
	vector<signed char > delta3;
	vector<signed char > delta2;
	vector<signed char > delta1;
	vector<signed char > delta5m;
	vector<signed char > delta4m;
	vector<signed char > delta3m;
	vector<signed char > delta2m;
	vector<signed char > delta1m;



	//	string dateraw;
	bool check;
	string err;
	int32_t Quoter = Quoter1 - 1;



	/*

	char t0 = dateraw.back();

	char t5 = ';';
	int32_t a = 4;
	double d0 = 0.0;
	if (t0 != t5) { std::cout << "Некорректно введены данные " << dateraw << endl; getline(cin, err); return; }
	else
	{
		dateraw.pop_back();
		d0 = stod(dateraw);
		std::cout << "Введены данные = " << d0 << endl;
	}

	double incr2 = d0 * 5; //x*100*10/2 - 100-Р 


	int32_t incr3 = int32_t(incr2);
	//std::cout << "incr3 = " << int(incr2) << endl;

	while (incr3 > 100)
	{
		incr3 = 100;
	}

	while (incr3 < -100)
	{
		incr3 = -100;
	}

	signed char incr4 = static_cast<signed char>(incr3);

	*/

	//Считаем дельту

	teachdel3(result1, incr4, delta5);



	teachdel3(result2, incr4, delta5m);

	obj7.teachdel4ma(delta5, Quoter, Weights5, Weights4, Outputs4, delta4, vec_a, vec_b, vec_c, vec_d);

	obj71.teachdel4mam(delta5m, Quoter, Weights5m, Weights4m, Outputs4m, delta4m, vec_a, vec_b, vec_c, vec_d);


	obj6.teachdel3ma(delta4, Quoter, Weights4, Weights3, Outputs3, delta3, vec_a, vec_b, vec_c, vec_d);

	obj61.teachdel3mam(delta4m, Quoter, Weights4m, Weights3m, Outputs3m, delta3m, vec_a, vec_b, vec_c, vec_d);

	obj4.teachdel2ma(delta3, Quoter, Weights3, Weights2, Outputs2, delta2, vec_a, vec_b, vec_c, vec_d);

	obj41.teachdel2mam(delta3m, Quoter, Weights3m, Weights2m, Outputs2m, delta2m, vec_a, vec_b, vec_c, vec_d);

	obj5.teachdel1ma(delta2, Quoter, Weights2, Weights1, Outputs1, delta1, vec_a, vec_b, vec_c, vec_d);
	

	obj51.teachdel1mam(delta2m, Quoter, Weights2m, Weights1m, Outputs1m, delta1m, vec_a, vec_b, vec_c, vec_d);

	//Считаем веса
	teachlayer3(Weights5, Quoter, Outputs4, delta5);

	teachlayer3(Weights5m, Quoter, Outputs4m, delta5m);

	// "Рассчет данных 4-го положительного слоя:" 

	obj7.teach4ma(Quoter, Outputs4, alpha, Weights4, delta4, vec_a, vec_d);

	// "Рассчет данных 4-го отрицательного слоя:" 

	obj71.teach4mam(Quoter, Outputs4m, alpha, Weights4m, delta4m, vec_a, vec_d);


	// "РАссчет весов 3-го положительного слоя:"

	obj6.teach3ma(Quoter, Outputs3, alpha, Weights3, delta3, vec_a, vec_d);

	// "Рассчет весов 3-го отрицательного слоя:" << endl;

	obj61.teach3mam(Quoter, Outputs3m, alpha, Weights3m, delta3m, vec_a, vec_d);


	// "Веса 2-го положительного слоя:" << endl;

	obj4.teach2ma(Quoter, Outputs2, alpha, Weights2, delta2, vec_a, vec_d);



	// "Веса 2-го отрицательного слоя:" << endl;

	obj41.teach2mam(Quoter, Outputs2m, alpha, Weights2m, delta2m, vec_a, vec_d);

	// "Веса первого положительного слоя:"

	obj5.teach1(Quoter, Outputs1, alpha, Weights1, delta1);

	// "Веса первого отрицательного слоя:" 

	obj51.teach1m(Quoter, Outputs1m, alpha, Weights1m, delta1m);


}