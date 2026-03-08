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

using namespace std;
#ifdef _DEBUG 
void calcgdpt(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<signed char>& TheoWeights, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<signed char> Weights1, vector<int32_t>& Count, vector<vector<signed char>>& Outputs1, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2, int32_t& Quoter, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Weights5, signed char& result1, signed char& result2, signed char& result,
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

	layer1m obj21;
	layer2m obj41;
	layer3m obj51;


	Other obj3;
	//работа с кварталом
	string quoteraw = "";
	string err;

	bool check = obj3.checkcin();
	if (check == true) { cin >> quoteraw; }

	////что-то делаем с годом и кварталом

	std::regex patQ{ R"(\d\.\d\d\d\d)" };
	if (!std::regex_match(quoteraw, patQ))
	{
		std::cout << "Неверно введен квартал года или сам год " << quoteraw << endl << "Пример - 4.1999 " << endl;
		getline(cin, err);
		return;
	};


	int32_t q0 = quoteraw[0];

	char q5 = 52;
	char q6 = 49;
	if (q0 > q5 || q0 < 49) { std::cout << "Неверно введен квартал года " << quoteraw << endl << "Пример - 4.1999 " << endl; getline(cin, err);  return; }
	string q1 = quoteraw.substr(2, 4);
	int32_t q2 = stoi(q1);
	if (q2 < 1990) { std::cout << "Неверно введен год " << quoteraw << endl << "Пример - 4.1999 " << endl; getline(cin, err);  return; }
	int32_t qy = q2 - 1990;
	qy = qy * 4;
	qy -= 1;
	int32_t q10 = 0;
	if (q0 == 49) { q10 = 1; }
	if (q0 == 50) { q10 = 2; }
	if (q0 == 51) { q10 = 3; }
	if (q0 == 52) { q10 = 4; }
	qy += q10;                  
	Quoter = qy;
	int32_t qy1 = qy + 1;
	
	             
	cout << "Показатели и их веса:" << endl;
	int32_t i1 = indicators.size();

	for (int32_t i = 0; i < i1; i++)
	{
		std::cout << "Параматр  " << indicators[i] << "  вес " << int32_t(TheoWeights[i]) << "%" << ";" << endl;

	}


	                 
	std::cout << "Данные по индикаторам" << endl;

	int32_t q3 = indicators.size();
	if (q3 == 0) { std::cout << "Нет данных" << endl; return; }
	int32_t q4 = indicatDate[0].size();
	if (q4 == 0) { std::cout << "Нет данных" << endl; return; }
	for (int32_t i = 0; i < q3; i++)
	{
		std::cout << indicators[i] << "    " << indicatDate[i][qy] << endl;

	}
	
	            
	cout << "Прирост данных:" << endl;
	incrquotercalc(qy, indicatDate, indicatDateInc);
	cashquoter(qy, TheoWeights, indicatDateInc, Cash1);

	for (int32_t i = 0; i < q3; i++)
	{
		signed char in0 = Cash1[i][qy];
		int32_t in1 = int32_t(in0);
		in1 = in1 * 2; //нивелируем шаг
		double in2 = in1;
		in2 = in2 / 10; // получаем все для дабл
		std::cout << indicators[i] << "    " << in2 << "%;" << endl;

	}


	        
	std::cout << "Веса первого положительного слоя:" << endl;
	int32_t t100 = Weights1.size();

	for (int32_t i = 0; i < t100; i++)
	{
		signed char in0 = Weights1[i];
		int32_t in1 = int32_t(in0);
		std::cout << i << "    " << in1 << "%;" << endl;

	}


	
	std::cout << "Веса первого отрицательного слоя:" << endl;
	int32_t t1001 = Weights1m.size();

	for (int32_t i = 0; i < t1001; i++)
	{
		signed char in0 = Weights1m[i];
		int32_t in1 = int32_t(in0);
		std::cout << i << "    " << in1 << "%;" << endl;

	}




	       
	std::cout << "Данные идущие на вход второго положительного слоя:" << endl;

	obj2.summneyquoter1(Count, Cash1, Weights1, Outputs1, qy, indicators);

	int32_t t101 = Outputs1[qy].size();

	for (int32_t i = 0; i < t101; i++)
	{
		int32_t i11 = int32_t(Outputs1[qy][i]);
		std::cout << i << "    " << i11 << endl;

	}


	
	std::cout << "Данные идущие на вход второго отрицательного слоя:" << endl;

	obj21.summneyquoter1m(Count, Cash1, Weights1m, Outputs1m, qy, indicators);

	int32_t t1011 = Outputs1m[qy].size();

	for (int32_t i = 0; i < t1011; i++)
	{
		int32_t i11 = int32_t(Outputs1m[qy][i]);
		std::cout << i << "    " << i11 << endl;

	}


	         
	std::cout << "Расчет весов для 2-го положительного слоя:" << endl;
	obj4.summneyquoter2(Count, Outputs1, Weights2, Outputs2, qy);

	int32_t t102 = Weights2.size();
	int32_t t103 = Weights2[0].size();


	for (int32_t i1 = 0; i1 < t103; i1++)
	{
		std::cout << "Веса нейрона" << i1 << ":" << endl;

		for (int32_t i = 0; i < t102; i++)
		{
			signed char in0 = Weights2[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}



	
	std::cout << "Расчет весов для 2-го отрицательного слоя:" << endl;
	obj41.summneyquoter2m(Count, Outputs1m, Weights2m, Outputs2m, qy);

	int32_t t1021 = Weights2m.size();
	int32_t t1031 = Weights2m[0].size();


	for (int32_t i1 = 0; i1 < t1031; i1++)
	{
		std::cout << "Веса нейрона" << i1 << ":" << endl;

		for (int32_t i = 0; i < t1021; i++)
		{
			signed char in0 = Weights2m[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}
	
	
	cout << "Данные идущие на вход 3-го положительного слоя:" << endl;
	
	obj4.summneyquoter2(Count, Outputs1, Weights2, Outputs2, Quoter);

	int32_t t113 = Outputs2[qy].size();

	for (int32_t i = 0; i < t113; i++)
	{
		int32_t i13 = int32_t(Outputs2[qy][i]);
		std::cout << i << "    " << i13 << endl;

	}


	
	cout << "Данные идущие на вход 3-го отрицательного слоя:" << endl;

	obj41.summneyquoter2m(Count, Outputs1m, Weights2m, Outputs2m, Quoter);

	int32_t t1131 = Outputs2m[qy].size();

	for (int32_t i = 0; i < t1131; i++)
	{
		int32_t i13 = int32_t(Outputs2m[qy][i]);
		std::cout << i << "    " << i13 << endl;

	}

	

	
	std::cout << "Расчет весов 3-го положительного слоя:" << endl;
	obj5.summneyquoter3(Count, Outputs2, Weights3, Outputs3, qy);

	int32_t t112 = Weights3.size();
	int32_t t123 = Weights3[0].size();


	for (int32_t i1 = 0; i1 < t123; i1++)
	{
		std::cout << "Веса нейрона" << i1 << ":" << endl;

		for (int32_t i = 0; i < t112; i++)
		{
			signed char in0 = Weights3[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}


	
	std::cout << "Расчет весов 3-го отрицательного слоя:" << endl;
	obj51.summneyquoter3m(Count, Outputs2m, Weights3m, Outputs3m, qy);

	int32_t t1121 = Weights3m.size();
	int32_t t1231 = Weights3m[0].size();


	for (int32_t i1 = 0; i1 < t1231; i1++)
	{
		std::cout << "Веса нейрона:" << i1 << ":" << endl;

		for (int32_t i = 0; i < t1121; i++)
		{
			signed char in0 = Weights3m[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}




	
	cout << "Данные поступающие на вход 4-го положительного слоя:" << endl;

	for (int32_t i = 0; i < t101; i++)
	{
		int32_t i100 = int32_t(Outputs3[qy][i]);
		
		std::cout << i << "    " << i100 << endl;

	}


	
	cout << "Данные поступающие на вход 4-го отрицательного слоя::" << endl;

	for (int32_t i = 0; i < t1011; i++)
	{
		int32_t i100 = int32_t(Outputs3m[qy][i]);

		std::cout << i << "    " << i100 << endl;

	}
	
	layer4 obj44;
	layer4m obj441;

	
	std::cout << "Рассчет весов 4-го положительно слоя:" << endl;
	obj44.summneyquoter4(Count, Outputs3, Weights4, Outputs4, qy);

	int32_t t114 = Weights4.size();
	int32_t t125 = Weights4[0].size();


	for (int32_t i1 = 0; i1 < t114; i1++)
	{
		std::cout << "Веса нейрона " << i1 << ":" << endl;

		for (int32_t i = 0; i < t125; i++)
		{
			signed char in0 = Weights4[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}



	
	std::cout << "Рассчет весов 4-го отрицателльного слоя:" << endl;
	obj441.summneyquoter4m(Count, Outputs3m, Weights4m, Outputs4m, qy);

	int32_t t1141 = Weights4m.size();
	int32_t t1251 = Weights4m[0].size();


	for (int32_t i1 = 0; i1 < t1141; i1++)
	{
		std::cout << "Веса нейрона " << i1 << ":" << endl;

		for (int32_t i = 0; i < t1251; i++)
		{
			signed char in0 = Weights4m[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}


	

	int32_t t101111 = Outputs4[qy].size();

	cout << "Данные идущие на вход 5-го положительного слоя:" << endl;

	for (int32_t i = 0; i < t101111; i++)
	{
		int32_t i100 = int32_t(Outputs4[qy][i]);

		std::cout << i << "    " << i100 << endl;

	}


	

	int32_t t10111 = Outputs4m[qy].size();

	cout << "Данные идущие на вход 5-го отрицательного слоя:" << endl;

	for (int32_t i = 0; i < t10111; i++)
	{
		int32_t i100 = int32_t(Outputs4m[qy][i]);

		std::cout << i << "    " << i100 << endl;

	}



	
	result1 = weightsumm(Weights5, Outputs4, Quoter);
	cout << "Результат 5-го положительного слоя: "  << int32_t(result1)  << endl;

	result2 = weightsumm(Weights5m, Outputs4m, Quoter);
	cout << "Результат 5-го отрицательного слоя: " << int32_t(result2) << endl;

	//signed char r = result1 + result2;

	if (std::abs(static_cast<int32_t>(result1)) > std::abs(static_cast<int32_t>(result2))) result = result1;
	else result = result2;


	printerrr(result);

}
#endif


#ifdef _DEBUG 
void teacher(int32_t& Quoter, signed char& result1, signed char& result2, signed char& result, vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Weights2, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Outputs1, signed char alpha, string dateraw,
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
	std::cout << "incr3 = " << int32_t(incr2) << endl;

	while (incr3 > 100)
	{
		incr3 = 100;
	}

	while (incr3 < -100)
	{
		incr3 = -100;
	}

	signed char incr4 = static_cast<signed char>(incr3);
	std::cout << "incr3 = " << incr3 << endl;
	std::cout << "incr4 = " << incr4 << endl;
	std::cout << "Данные после обработки = " << int32_t(incr4) << endl;



	
	teachdel3(result1, incr4, delta5);
	int32_t a0 = delta5.size();
	std::cout << "!!!!!teachdel3(result1, incr4, delta5) !" << endl;
	for (int32_t i = 0; i < a0; i++)
	{
		std::cout << i << "......." << int32_t(delta5[i]) << endl;

	}


	
	teachdel3(result2, incr4, delta5m);
	int32_t a01 = delta5m.size();
	std::cout << "!!!!!teachdel3(result2, incr4, delta5m) !" << endl;
	for (int32_t i = 0; i < a01; i++)
	{
		std::cout << i << "......." << int32_t(delta5m[i]) << endl;

	}



	
	obj7.teachdel4(delta5, Quoter, Weights5, Weights4, Outputs4, delta4);
	int32_t a0111 = delta4.size();
	cout << "!!!!!teachdel4(delta5, Quoter, Weights5, Weights4, Outputs4, delta4) !" << endl;
	for (int32_t i = 0; i < a0111; i++)
	{
		cout << i << "......." << int32_t(delta4[i]) << endl;

	}


	
	obj71.teachdel4m(delta5, Quoter, Weights5m, Weights4m, Outputs4m, delta4m);
	int32_t a011 = delta4.size();
	cout << "!!!!!teachdel4m(delta5, Quoter, Weights5m, Weights4m, Outputs4m, delta4m) !" << endl;
	for (int32_t i = 0; i < a011; i++)
	{
		cout << i << "......." << int32_t(delta4m[i]) << endl;

	}



	
	obj6.teachdel3(delta4, Quoter, Weights4, Weights3, Outputs3, delta3);

	int32_t a1 = delta3.size();
	std::cout << "!!!!!teachdel3(delta4, Quoter, Weights4, Weights3, Outputs3, delta3) !" << endl;
	for (int32_t i = 0; i < a1; i++)
	{
		std::cout << i << "......." << int32_t(delta3[i]) << endl;

	}


	
	obj61.teachdel3m(delta4m, Quoter, Weights4m, Weights3m, Outputs3m, delta3m);

	int32_t a11 = delta3m.size();
	std::cout << "!!!!!teachdel3m(delta4m, Quoter, Weights4m, Weights3m, Outputs3m, delta3m) !" << endl;
	for (int32_t i = 0; i < a11; i++)
	{
		std::cout << i << "......." << int32_t(delta3m[i]) << endl;

	}
	

	
	obj4.teachdel2(delta3, Quoter, Weights3, Weights2, Outputs2, delta2);
	int32_t a1111 = delta2.size();
	std::cout << "!!!!!teachdel2(delta3, Quoter, Weights3, Weights2, Outputs2, delta2) !" << endl;
	for (int32_t i = 0; i < a1111; i++)
	{
		std::cout << i << "......." << int32_t(delta2[i]) << endl;

	}


	
	obj41.teachdel2m(delta3m, Quoter, Weights3m, Weights2m, Outputs2m, delta2m);
	int32_t a111 = delta2m.size();
	std::cout << "!!!!!teachdel2m(delta3m, Quoter, Weights3m, Weights2m, Outputs2m, delta2m) !" << endl;
	for (int32_t i = 0; i < a111; i++)
	{
		std::cout << i << "......." << int32_t(delta2m[i]) << endl;

	}


	

	
	obj5.teachdel1(delta2, Quoter, Weights2, Weights1, Outputs1, delta1);

	int32_t a2 = delta1.size();
	std::cout << "!!!!!teachdel1(delta2, Quoter, Weights2, Weights1, Outputs1, delta1) !" << endl;
	for (int32_t i = 0; i < a2; i++)
	{
		cout << i << "......." << int32_t(delta1[i]) << endl;

	}


	
	obj51.teachdel1m(delta2m, Quoter, Weights2m, Weights1m, Outputs1m, delta1m);

	int32_t a21 = delta1.size();
	std::cout << "!!!!!teachdel1m(delta2m, Quoter, Weights2m, Weights1m, Outputs1m, delta1m) !" << endl;
	for (int32_t i = 0; i < a21; i++)
	{
		cout << i << "......." << int32_t(delta1m[i]) << endl;

	}





	
	teachlayer3(Weights5, Quoter, Outputs4, delta5);

	int32_t a3 = Weights5[0].size();
	std::cout << "!!!!!teachlayer3(Weights5, Quoter, Outputs4, delta5) !" << endl;
	for (int32_t i = 0; i < a3; i++)
	{
		cout << i << "......." << int32_t(Weights5[0][i]) << endl;

	}

	
	teachlayer3(Weights5m, Quoter, Outputs4m, delta5m);

	int32_t a31 = Weights5m[0].size();
	std::cout << "!!!!!teachlayer3(Weights5m, Quoter, Outputs4m, delta5m) !" << endl;
	for (int32_t i = 0; i < a31; i++)
	{
		cout << i << "......." << int32_t(Weights5m[0][i]) << endl;

	}



	
	std::cout << "Рассчет данных 4-го положительного слоя:" << endl;

	obj6.teach3(Quoter, Outputs4, alpha, Weights4, delta4);

	



	int32_t t1021 = Weights4.size();
	int32_t t1031 = Weights4[0].size();


	for (int32_t i1 = 0; i1 < t1021; i1++)
	{
		cout << "Веса нейрона " << i1 << ":" << endl;

		for (int32_t i = 0; i < t1031; i++)
		{
			signed char in0 = Weights4[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}




	
	std::cout << "Рассчет данных 4-го отрицательного слоя:" << endl;

	obj61.teach3m(Quoter, Outputs4m, alpha, Weights4m, delta4m);

	


	int32_t t10211 = Weights4m.size();
	int32_t t10311 = Weights4m[0].size();


	for (int32_t i1 = 0; i1 < t10211; i1++)
	{
		cout << "Веса нейрона " << i1 << ":" << endl;

		for (int32_t i = 0; i < t10311; i++)
		{
			signed char in0 = Weights4m[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}


	
	std::cout << "РАссчет весов 3-го положительного слоя:" << endl;

	obj6.teach3(Quoter, Outputs3, alpha, Weights3, delta3);

	


	int32_t t102 = Weights3.size();
	int32_t t103 = Weights3[0].size();


	for (int32_t i1 = 0; i1 < t103; i1++)
	{
		cout << "Данные нейрона " << i1 << ":" << endl;

		for (int32_t i = 0; i < t102; i++)
		{
			signed char in0 = Weights3[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}



	
	std::cout << "Рассчет весов 3-го отрицательного слоя:" << endl;

	obj61.teach3m(Quoter, Outputs3m, alpha, Weights3m, delta3m);

	


	int32_t t102111 = Weights3m.size();
	int32_t t103111 = Weights3m[0].size();


	for (int32_t i1 = 0; i1 < t103111; i1++)
	{
		cout << "Данные нейрона " << i1 << ":" << endl;

		for (int32_t i = 0; i < t102111; i++)
		{
			signed char in0 = Weights3m[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}



	

	std::cout << "Веса 2-го положительного слоя:" << endl;

	obj4.teach2(Quoter, Outputs2, alpha, Weights2, delta2);

	

	int32_t t122 = Weights2.size();
	int32_t t123 = Weights2[0].size();


	for (int32_t i1 = 0; i1 < t123; i1++)
	{
		std::cout << "Данные нейрона " << i1 << ":" << endl;

		for (int32_t i = 0; i < t122; i++)
		{
			signed char in0 = Weights2[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}


	
	std::cout << "Веса 2-го отрицательного слоя:" << endl;

	obj41.teach2m(Quoter, Outputs2m, alpha, Weights2m, delta2m);

	

	int32_t t1221 = Weights2m.size();
	int32_t t1231 = Weights2m[0].size();


	for (int32_t i1 = 0; i1 < t1231; i1++)
	{
		std::cout << "Веса нейрона " << i1 << ":" << endl;

		for (int32_t i = 0; i < t1221; i++)
		{
			signed char in0 = Weights2m[i1][i];
			int32_t in1 = int32_t(in0);
			std::cout << i << "    " << in1 << "%;" << endl;

		}

	}



	obj5.teach1(Quoter, Outputs1, alpha, Weights1, delta1);

	cout << "Веса первого положительного слоя:" << endl;
	int32_t t100 = Weights1.size();

	for (int32_t i = 0; i < t100; i++)
	{
		signed char in0 = Weights1[i];
		int32_t in1 = int32_t(in0);
		std::cout << i << "    " << in1 << "%;" << endl;

	}


	
	obj51.teach1m(Quoter, Outputs1m, alpha, Weights1m, delta1m);

	cout << "Веса первого отрицательного слоя:" << endl;
	int32_t t1001 = Weights1m.size();

	for (int32_t i = 0; i < t1001; i++)
	{
		signed char in0 = Weights1m[i];
		int32_t in1 = int32_t(in0);
		std::cout << i << "    " << in1 << "%;" << endl;

	}



}
#endif 