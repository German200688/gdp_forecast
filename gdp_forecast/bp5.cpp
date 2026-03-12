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
#include "kernel/other.h"
#include "kernel/nvidia/cuda/nvidiac.h"
#include "bp3.cpp"


#pragma once

using namespace std;

void teachonline(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<signed char>& TheoWeights, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<signed char> Weights1, vector<int32_t>& Count, vector<vector<signed char>>& Outputs1, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2,  vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Weights5, signed char& result1, signed char& result2, signed char& result,
	vector<signed char>& Weights1m,
	vector<vector<signed char>>& Weights2m,
	vector<vector<signed char>>& Weights3m,
	vector<vector<signed char>>& Weights4m,
	vector<vector<signed char>>& Weights5m,
	vector<vector<signed char>>& Outputs1m,
	vector<vector<signed char>>& Outputs2m,
	vector<vector<signed char>>& Outputs3m,
	vector<vector<signed char>>& Outputs4m,
	const signed char& alpha,
	const int32_t& iterationney,
	const int32_t& iteration)
{
	Other obj3;
	nvidiac obj1;

	//Запись параметра
	//vector<string> vvodindicv;
	//string indicator = "";
	string err = "";
	//string space = " ";
	//string vvodindic;
	//char t1 = ':';
	//int32_t t2 = 0;
	vector <vector <int32_t>> dates;
	double d0 = 0.0;
	vector<int32_t> index;

		bool check = obj3.checkcin();
		if (!check) { std::cout << "Вы ничего не ввели. Введите пожалуйста данные." << endl;  return;}
		
		

	

	//Запись квартала и значения
	string dateraw = "";

	double date2 = 0.0;
	int32_t w = 1;
	while (w < 2)
	{
		int32_t st0 = std::cin.peek();

		if (st0 == 10) { w = 2; }
		else
		{

			bool check = obj3.checkcin();
			if (check == true) { cin >> dateraw; }

			//работа с кварталом

			std::regex patQ{ R"(\d\.\d\d\d\d)" };
			if (!std::regex_match(dateraw, patQ))
			{
				std::cout << "Неверно введен квартал года или сам год " << dateraw << endl << "Пример - 4.1999 " << endl;
				getline(cin, err);
				return;
			};

			////что-то делаем с годом и кварталом
			char q10 = dateraw[0];
			int32_t q0 = 0;
			char q5 = 52;
			char q6 = 49;
			if (q10 == 49)  q0 = 1;
			else if (q10 == 50)  q0 = 2;
			else if (q10 == 51)  q0 = 3;
			else if (q10 == 52)  q0 = 4;
			else { std::cout << "Неверно введен квартал года " << dateraw << endl << "Пример - 4.1999 " << endl; getline(cin, err);  return; }
			string q1 = dateraw.substr(2, 4);
			int32_t q2 = stoi(q1);
			if (q2 < 1990) { std::cout << "Неверно введен год " << dateraw << endl << "Пример - 4.1999 " << endl; getline(cin, err); return; }



			int32_t qy = q2 - 1990;
			qy = qy * 4;
			qy -= 1;
			qy += q0; // индекс в векторе
			qy--;
			int32_t te1 = indicatDate[0].size();
			if (qy > te1) { cout << "К сожалению данные за предыдущий квартал отсутствуют и рассчет не может быть осуществлен. Введите данные и повторите снова." << endl; }
			dateraw = "";

			check = obj3.checkcin();
			if (check == true) { cin >> dateraw; }

			char t0 = dateraw.back();

			char t5 = ';';
			int32_t a = 4;

			if (t0 != t5) { std::cout << "Где-то пропущена ; или значение. Ошибка выявлена на цифре -  " << dateraw << endl; getline(cin, err); return; }
			else
			{
				dateraw.pop_back();
				d0 = stod(dateraw); //значение в векторе

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
				int32_t incrf = int(incr4);

				vector <int32_t > dates12(2);
				dates12[0] = qy;
				dates12[1] = d0;
				dates.push_back(dates12);


			}
			

		}

	}


	getline(cin, err);
	std::cout << "Значения приняты. Начинаем рассчет" << endl;

	signed char* dvec_a1, * dvec_b1, * dvec_c1, *vec_a23, *vec_b23, *dvec_a4, *dvec_b4, *dvec_c4, *vec_a4, *vec_b4, * ab;
		//int N1, int N23, int N4, int N44, signed char*& ab

	int32_t Quoter = dates[0][0];

	calcgdpteach(indicators, indicatDate, TheoWeights, indicatDateInc, Cash1, Weights1, Count, Outputs1, Weights2, Outputs2, Quoter, Weights3, Outputs3, Weights4, Outputs4, Weights5, result1, result2, result,
		Weights1m,
		Weights2m,
		Weights3m,
		Weights4m,
		Weights5m,
		Outputs1m,
		Outputs2m,
		Outputs3m,
		Outputs4m
	);
	int32_t N1 = 3;
	int32_t N23 = Weights2[0].size();
	int32_t N44 = Weights4[0].size();
	int32_t N4 = Weights5[0].size();


	obj1.addobj(dvec_a1, dvec_b1, dvec_c1, vec_a23, vec_b23, dvec_a4, dvec_b4, dvec_c4, vec_a4, vec_b4, N1, N23, N4, N44, ab);
	int t12 = dates.size();

	for (int32_t i0 = 0; i0 < iteration; i0++)
	{
		for (int32_t i1 = 0; i1 < t12; i1++)
		{
			int quot = dates[i1][0];
			int resi = dates[i1][1];
			signed char res = static_cast<signed char>(resi);

			for (int32_t i2 = 0; i2 < iterationney; i2++)

			{
				calcgdpteach(indicators, indicatDate, TheoWeights, indicatDateInc, Cash1, Weights1, Count, Outputs1, Weights2, Outputs2, quot, Weights3, Outputs3, Weights4, Outputs4, Weights5, result1, result2, result,
					Weights1m,
					Weights2m,
					Weights3m,
					Weights4m,
					Weights5m,
					Outputs1m,
					Outputs2m,
					Outputs3m,
					Outputs4m
				);



				teachquoterm(quot, result1, result2, result, Weights5, Weights4, Weights3, Weights2, Weights1, Outputs4, Outputs3, Outputs2, Outputs1, alpha, res,
					Weights1m,
					Weights2m,
					Weights3m,
					Weights4m,
					Weights5m,
					Outputs1m,
					Outputs2m,
					Outputs3m,
					Outputs4m,
					dvec_a1,
					dvec_b1,
					dvec_c1,
					//signed char*& vec_a1, 
					//signed char*& vec_b1, 
					//signed char*& vec_c1, 
					vec_a23,
					vec_b23,
					//signed char*& vec_c23, 
					dvec_a4,
					dvec_b4,
					dvec_c4,
					vec_a4,
					vec_b4,
					//signed char*& vec_c4, 
					ab
				);

			}


		}





	}


	obj1.delobj(dvec_a1, dvec_b1, dvec_c1, vec_a23, vec_b23, dvec_a4, dvec_b4, dvec_c4, vec_a4, vec_b4, ab);


	std::cout << "Рассчет завершен" << endl;

}