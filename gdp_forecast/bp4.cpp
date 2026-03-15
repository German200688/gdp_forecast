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

#pragma once

using namespace std;



void teachquoterm(int64_t& Quoter1, signed char& result1, signed char& result2, signed char& result, vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Weights2, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Outputs1, signed char alpha, signed char incr4,
	vector<signed char>& Weights1m,
	vector<vector<signed char>>& Weights2m,
	vector<vector<signed char>>& Weights3m,
	vector<vector<signed char>>& Weights4m,
	vector<vector<signed char>>& Weights5m,
	vector<vector<signed char>>& Outputs1m,
	vector<vector<signed char>>& Outputs2m,
	vector<vector<signed char>>& Outputs3m,
	vector<vector<signed char>>& Outputs4m,
	signed char*& dvec_a1, 
	signed char*& dvec_b1, 
	signed char*& dvec_c1, 
	//signed char*& vec_a1, 
	//signed char*& vec_b1, 
	//signed char*& vec_c1, 
	signed char*& vec_a23, 
	signed char*& vec_b23, 
	//signed char*& vec_c23, 
	signed char*& dvec_a4, 
	signed char*& dvec_b4, 
	signed char*& dvec_c4, 
	signed char*& vec_a4, 
	signed char*& vec_b4, 
	//signed char*& vec_c4, 
	signed char*& ab
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
	int64_t Quoter = Quoter1;



	

	//Считаем дельту

	teachdel3(result1, incr4, delta5);

#ifdef _DEBUG
	
	cout << " после рассчета int(delta5[i]):" << endl;

	int t00123 = delta5.size();
	for (int i = 0; i < t00123; i++)
	{
		cout << int(delta5[i]) << endl;
	}
#endif

	teachdel3(result2, incr4, delta5m);
	

	obj7.teachdel4ma(delta5, Quoter, Weights5, Weights4, Outputs4, delta4, dvec_a4, dvec_b4, dvec_c4, ab);

#ifdef _DEBUG
	cout << int(Outputs4[81][3]) << endl;
	cout << " после рассчета int(delta4[i]):" << endl;

	int t001 = delta4.size();
	for (int i = 0; i < t001; i++)
	{
		cout << int(delta4[i]) << endl;
	}
#endif

	obj71.teachdel4mam(delta5m, Quoter, Weights5m, Weights4m, Outputs4m, delta4m, dvec_a4, dvec_b4, dvec_c4, ab);


	obj6.teachdel3(delta4, Quoter, Weights4, Weights3, Outputs3, delta3);

#ifdef _DEBUG
	cout << " после рассчета int(delta3[i]):" << endl;

	int t0013 = delta3.size();
	for (int i = 0; i < t0013; i++)
	{
		cout << int(delta3[i]) << endl;
	}
#endif

	obj61.teachdel3m(delta4m, Quoter, Weights4m, Weights3m, Outputs3m, delta3m);

	obj4.teachdel2(delta3, Quoter, Weights3, Weights2, Outputs2, delta2);

#ifdef _DEBUG
	cout << " после рассчета int(delta2[i]):" << endl;

	int t0012 = delta2.size();
	for (int i = 0; i < t0012; i++)
	{
		cout << int(delta2[i]) << endl;
	}
#endif

	obj41.teachdel2m(delta3m, Quoter, Weights3m, Weights2m, Outputs2m, delta2m);

	obj5.teachdel1(delta2, Quoter, Weights2, Weights1, Outputs1, delta1);

#ifdef _DEBUG
	cout << " после рассчета int(delta1[i]):" << endl;

	int t0011 = delta1.size();
	for (int i = 0; i < t0011; i++)
	{
		cout << int(delta1[i]) << endl;
	}
#endif

	obj51.teachdel1m(delta2m, Quoter, Weights2m, Weights1m, Outputs1m, delta1m);

	//Считаем веса
	teachlayer3(Weights5, Quoter, Outputs4, delta5);
#ifdef _DEBUG
	cout << " после рассчета Weights5[0]:" << endl;

	int t00111 = Weights5[0].size();
	for (int i = 0; i < t00111; i++)
	{
		cout << int(Weights5[0][i]) << endl;
	}
#endif

	teachlayer3(Weights5m, Quoter, Outputs4m, delta5m);
	
	/*
	// "Рассчет данных 4-го положительного слоя:" 

	obj7.teach4(Quoter, Outputs4, alpha, Weights4, delta4);

	// "Рассчет данных 4-го отрицательного слоя:" 

	obj71.teach4m(Quoter, Outputs4m, alpha, Weights4m, delta4m);
	*/
	// "Рассчет данных 4-го положительного слоя:" 
	
	obj7.teach4ma(Quoter, Outputs4, alpha, Weights4, delta4, vec_a4, vec_b4);
	
	// "Рассчет данных 4-го отрицательного слоя:" 

	obj71.teach4mam(Quoter, Outputs4m, alpha, Weights4m, delta4m, vec_a4, vec_b4);
	
	
	// "РАссчет весов 3-го положительного слоя:"

	obj6.teach3ma(Quoter, Outputs3, alpha, Weights3, delta3, vec_a23, vec_b23);

	// "Рассчет весов 3-го отрицательного слоя:" << endl;

	obj61.teach3mam(Quoter, Outputs3m, alpha, Weights3m, delta3m, vec_a23, vec_b23);
	
	/*

	// "РАссчет весов 3-го положительного слоя:"

	obj6.teach3(Quoter, Outputs3, alpha, Weights3, delta3);

	// "Рассчет весов 3-го отрицательного слоя:" << endl;

	obj61.teach3m(Quoter, Outputs3m, alpha, Weights3m, delta3m);
	*/

	
	// "Веса 2-го положительного слоя:" << endl;

	obj4.teach2ma(Quoter, Outputs2, alpha, Weights2, delta2, vec_a23, vec_b23);



	// "Веса 2-го отрицательного слоя:" << endl;

	obj41.teach2mam(Quoter, Outputs2m, alpha, Weights2m, delta2m, vec_a23, vec_b23);
	
	/*
	// "Веса 2-го положительного слоя:" << endl;

	obj4.teach2(Quoter, Outputs2, alpha, Weights2, delta2);

	// "Веса 2-го отрицательного слоя:" << endl;

	obj41.teach2m(Quoter, Outputs2m, alpha, Weights2m, delta2m);
	*/


	// "Веса первого положительного слоя:"

	obj5.teach1(Quoter, Outputs1, alpha, Weights1, delta1);

	// "Веса первого отрицательного слоя:" 

	obj51.teach1m(Quoter, Outputs1m, alpha, Weights1m, delta1m);
	



	
	
}




void calcgdpteach(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<signed char>& TheoWeights, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<signed char> Weights1, vector<int64_t>& Count, vector<vector<signed char>>& Outputs1, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2, int64_t& Quoter, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Weights5, signed char& result1, signed char& result2, signed char& result,
	vector<signed char>& Weights1m,
	vector<vector<signed char>>& Weights2m,
	vector<vector<signed char>>& Weights3m,
	vector<vector<signed char>>& Weights4m,
	vector<vector<signed char>>& Weights5m,
	vector<vector<signed char>>& Outputs1m,
	vector<vector<signed char>>& Outputs2m,
	vector<vector<signed char>>& Outputs3m,
	vector<vector<signed char>>& Outputs4m
)
{


	layer1 obj2;
	layer2 obj4;
	layer3 obj5;
	layer4 obj44;

	layer1m obj21;
	layer2m obj41;
	layer3m obj51;
	layer4m obj441;


	int64_t qy2 = Quoter;

	
	// "Прирост данных:" 
	incrquotercalc(qy2, indicatDate, indicatDateInc);
	cashquoter(qy2, TheoWeights, indicatDateInc, Cash1);



	// "Данные идущие на вход второго положительного слоя:" 

	obj2.summneyquoter1(Count, Cash1, Weights1, Outputs1, qy2, indicators);


	// "Данные идущие на вход второго отрицательного слоя:" 

	obj21.summneyquoter1m(Count, Cash1, Weights1m, Outputs1m, qy2, indicators);



	// "Расчет весов для 2-го положительного слоя:" 
	obj4.summneyquoter2(Count, Outputs1, Weights2, Outputs2, qy2);


	//"Расчет весов для 2-го отрицательного слоя:"
	obj41.summneyquoter2m(Count, Outputs1m, Weights2m, Outputs2m, qy2);

	// "Данные идущие на вход 3-го положительного слоя:"

	obj4.summneyquoter2(Count, Outputs1, Weights2, Outputs2, qy2);

	// "Данные идущие на вход 3-го отрицательного слоя:"

	obj41.summneyquoter2m(Count, Outputs1m, Weights2m, Outputs2m, qy2);

	// "Расчет весов 3-го положительного слоя:"
	obj5.summneyquoter3(Count, Outputs2, Weights3, Outputs3, qy2);

	// "Расчет весов 3-го отрицательного слоя:"
	obj51.summneyquoter3m(Count, Outputs2m, Weights3m, Outputs3m, qy2);




	// "Рассчет весов 4-го положительно слоя:"
	obj44.summneyquoter4(Count, Outputs3, Weights4, Outputs4, qy2);



	//"Рассчет весов 4-го отрицателльного слоя:"
	obj441.summneyquoter4m(Count, Outputs3m, Weights4m, Outputs4m, qy2);



	//рассчет результата 5го слоя положительного
	result1 = weightsumm(Weights5, Outputs4, qy2);


	//рассчет результата 5го слоя отрицительного
	result2 = weightsumm(Weights5m, Outputs4m, qy2);


	if (std::abs(static_cast<int64_t>(result1)) > std::abs(static_cast<int64_t>(result2))) result = result1;
	else result = result2;


//	printerrr(result);


}