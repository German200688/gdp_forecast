#include <cstdio>
#include <string>﻿
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <regex>
#include <map>
#include <cstdint>
#include <cstdint>
#include "increase.cpp"
#include "bp2.cpp"
#include "bp3.cpp"
#include "bp4.cpp"
#include "neys/ney1s.h"
#include "kernel/other.h"




#pragma once

using namespace std;


void uploadparamd(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<int32_t>& Count, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1 ) // Пример - uploadparamd param: 4.1999 28,5; 2.1998 28; Нажимаем enter"

{
	Other obj3;
	
	//Запись параметра
	vector<string> vvodindicv;
	string indicator = "";
	string err = "";
	string space = " ";
	string vvodindic;
	char t1 = ':';
	int32_t t2 = 0;
	map<int32_t, double> dates;
	double d0 = 0.0; 
	vector<int32_t> index;

	while (t2 < 1)
	{
		
		bool check = obj3.checkcin();
		if (check == true) { cin >> vvodindic; }
		if (!vvodindic.empty()) {
			char t0 = vvodindic.back();
			if (t0 == t1) { vvodindic.pop_back(); vvodindicv.push_back(vvodindic); vvodindic = ""; t2 = 1; } 
			else
			{
				vvodindicv.push_back(vvodindic);
				vvodindic = "";

			}

		}
		else
		{
			std::cout << "Вы ничего не ввели. Введите пожалуйста данные." << endl;
			return;
		}


	}
	
	int32_t t0 = vvodindicv.size();
	for (int32_t t1 = 0; t1 < t0; t1++)
	{
		indicator = indicator + vvodindicv[t1] + space;

	}
	indicator.pop_back();
	// Проверка наличия параметра
	auto t4 = find(indicators.begin(), indicators.end(), indicator);
	if (t4 == indicators.end())
	{

		std::cout << "Параметр " << indicator << " еще не добавлен. Добавьте, пожалуйста, параметр " << indicator << " и повторите попытку." << endl;
		getline(cin, err);
		return;
	}
	auto t9 = std::distance(indicators.begin(), t4);

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

				dateraw = "";

				check = obj3.checkcin();
				if (check == true) { cin >> dateraw; }

				t0 = dateraw.back();

				char t5 = ';';
				int32_t a = 4;

				if (t0 != t5) { std::cout << "Где-то пропущена ; или значение. Ошибка выявлена на цифре -  " << dateraw << endl; getline(cin, err); return; }
				else
				{
					dateraw.pop_back();
					d0 = stod(dateraw); //значение в векторе

				}

				// наполняем map
				dates[qy] = d0;
				index.push_back(qy);

		}
		
	}

	

	//наполянем финальный вектор
	int32_t dq0 = index.size();
	

	for (int32_t i = 0; i < dq0; i++)
	{
	
		int32_t dq1 = index[i];
		int32_t dq2 = indicatDate[t9].size()-1;
		signed char dq3 = 0;
		if (dq2 < dq1)
		{
			
			int32_t qd5 = indicatDate.size();
			for (int32_t i = 0; i < qd5; i++)
			{
				
				dq2 = indicatDate[i].size() - 1;
				while (dq2 <= dq1)
				{
					
					indicatDateInc[i].push_back(0);
					Cash1[i].push_back(0);
					indicatDate[i].push_back(0.0);
					dq2 = indicatDate[i].size() - 1;

				}
			}
			
			
			indicatDate[t9][dq1] = dates[dq1];

			dq1 += 1;
			if (Count.size() == 0) Count.push_back(dq1);
			else { Count[0] = dq1; }




			}
		else {
			
			indicatDate[t9][dq1] = dates[dq1];
		}

	}
	getline(cin, err);
	std::cout << "Значения успешно записаны. Для вывода по всем значениям показателя, воспользуйтесь командой paramdatelist" << endl;

}



void info()
{
	string err;
	std::cout <<
		"Справка по командам программы:" << endl
		<< "   \033[34m uploadparamd \033[35m Команда данные показателя с разделителем - uploadparamd показатель в конце которого стоит двоеточие квартал.год данные;.\033[0m Пример - uploadparamd param: 4.1999 28,5; 2.1998 28; нажимаем enter" << endl
		<< "   \033[34m addparam \033[35m Команда добавляет новый экономический индикатор. \033[0m Пример - addparam salery" << endl
		<< "   \033[34m paramlist \033[35m Команда выводит список используемых экономических индикаторов. \033[0m Пример - paramlist" << endl
		<< "   \033[34m  paramdatelist \033[35m Команда выводит все имеющие данные по определенному экономическому индикатору. \033[0m Пример - paramdatelist param нажимаем enter" << endl
		<< "   \033[34m quoterlist \033[35m Команда выводит все имеющиеся данные по всем показателям за квартал. \033[0m Пример - quoterlist 4.1998 нажимаем enter" << endl
		<< "   \033[34m incr \033[35m Команда выводит прирост по отношению к пердыдущему кварталу всех имеющихся данных по всем показателям за квартал. \033[0m Пример - incr 4.1998 нажимаем enter" << endl
		<< "   \033[34m theorlist \033[35m Команда выводит список теоретических коэффициентов \033[0m Пример - theorlist нажимаем enter" << endl
		<< "   \033[34m uploadtheor \033[35m Команда загружает теоретические веса для каждого показателя. Показатель может быть от минус 100 процентов до 100 процентов. \033[0m Пример1 - uploadtheor param: 10 нажимаем enter. Пример2 - uploadtheor param: -15 нажимаем enter." << endl
		<< "   \033[34m calcgdp \033[35m Команда рассчитывает прогноз прироста ВВП в определенном квартале. \033[0m Пример - calcgdp 3.2010" << endl
		<< "   Обучить модель - teach далее вообится квартал.год размер ВВП" << endl
		<< "   \033[34m info \033[35m Команда выводит текущую справку по командам. \033[0m Пример - info нажимаем enter" << endl
		<< "   \033[34m end \033[35m Команда заверщает программу с сохранением всех данных. Если надо завершить программу без сохранения, нажмите крестик в текущем окне. \033[0m  Пример - end нажимаем enter" << endl;
	
#ifdef _DEBUG 
	std::cout
		<< " \033[31m -------- СТРОГО ДЛЯ РАЗРАБОТКИ И ОТЛАДКИ --------" << endl
		<< "   \033[31m calcgdp \033[31m Команда рассчитывает прогноз прироста ВВП в определенном квартале. \033[0m Пример - calcgdpt 3.2010" << endl;
#endif

	getline(cin, err);
}




void addparam(vector<string>& indicators, vector<signed char>& TheoWeights, vector<vector<double>>& indicatDate, int32_t count1, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<signed char>& Weights1, vector<signed char>& Weights1m, vector<int32_t>& Count)
{
	
	
	layer1 Obj1;
	layer1m Obj11;

	string vvodparam;
	string err;
	getline(cin, vvodparam);
	

	
		if (!vvodparam.empty() && vvodparam[0] == ' ') {
		vvodparam.erase(0, 1);
	}
	
	signed char weight = 0;
	auto b1 = find(indicators.begin(), indicators.end(), vvodparam);
	std::regex patQ1{R"(\s*$)"};
		if (vvodparam.empty()) { std::cout << "Параметр не введен." << endl; return; }
		if (std::regex_match(vvodparam, patQ1))
		{
			std::cout << "Параметр не введен." << endl; return;
		}
		int32_t b3 = indicators.size();
		int32_t b6 = indicators.size();

	
		if (b1 == indicators.end())
	{
		indicators.push_back(vvodparam);
		TheoWeights.push_back(weight);

		vector<double > dates = {};
		vector<signed char > dates2 = {};
		double b2 = 0.0;
		signed char b3 = 0;
		for (int32_t i = 0; i < count1; i++) {
			int32_t i1 = i - 1; dates.push_back(b2); dates2.push_back(b3);
		}
		
		indicatDate.push_back(dates);
		indicatDateInc.push_back(dates2); 
		Cash1.push_back(dates2);

		Obj1.Weights1addition1(Weights1, b6, Count);
		Obj11.Weights1addition1m(Weights1m, Weights1, Count);
		
		std::cout << "Параметр " << vvodparam << " успешно добавлен." << endl;
		
	}
	else
	{
		std::cout << "Параметр " << vvodparam << " уже есть. Для вывода всех имеющихся параметров воспользуйтесь командой paramlist." << endl;
		return;
	}
	

}
	

void paramlist(vector<string>& indicators)
{
	 
	locale::global(locale("ru_RU.UTF-8"));
	string err;
	int32_t i1 = indicators.size();
	if (i1 == 0) { std::cout << "Список параметров пуст." << endl; getline(cin, err); return; }
	for (int32_t i = 0; i < i1; i++)
	{
		std::cout << indicators[i] << ";" << endl;
		
	}
	getline(cin, err);
	
}



void uploadtheor(vector<string>& indicators, vector<signed char>& TheoWeights) // Пример2: uploadtheor param: -15 нажимаем enter.
{

	Other obj3;
	
	vector<string> vvoduploadtheo;
	string space = " ";
	string err = "";
	string indicator = "";
	string vvoduploadtheor; 
	char t1 = ':';
	int32_t t2 = 0;

	while (t2 < 1)
	{

		bool check = obj3.checkcin();
		if (check == true) { cin >> vvoduploadtheor; }
		if (!vvoduploadtheor.empty()) {
			char t0 = vvoduploadtheor.back();
			if (t0 == t1) { vvoduploadtheor.pop_back(); vvoduploadtheo.push_back(vvoduploadtheor); vvoduploadtheor = ""; t2 = 1;
			}
			else
			{
				vvoduploadtheo.push_back(vvoduploadtheor);
				vvoduploadtheor = "";
			}
		}
		else
		{
			std::cout << "Вы ничего не ввели. Введите пожалуйста данные." << endl;
			return;
		}

	}

	int32_t t0 = vvoduploadtheo.size();
	for (int32_t t1 = 0; t1 < t0; t1++)
	{
		indicator = indicator + vvoduploadtheo[t1] + space;

	}
	indicator.pop_back();
	// Проверка наличия параметра
	auto t4 = find(indicators.begin(), indicators.end(), indicator);
	if (t4 == indicators.end())
	{

		std::cout << "Параметр " << indicator << " еще не добавлен. Добавьте, пожалуйста, параметр " << indicator << " и повторите попытку." << endl;
		getline(cin, err);
		return;
	}
	auto t9 = std::distance(indicators.begin(), t4);



	int32_t t5;
	int32_t t6 = 0;
	while (t6 < 1 && cin >> t5) { t6++;}
	if (t5>100 && t5 < -100) { std::cout << t5 << " не явялется показателем от -100 до 100." << endl; getline(cin, err); return;}
	signed char TheoWeight = static_cast<signed char>(t5);
	TheoWeights[t9] = TheoWeight;
	std::cout << "В параметр " << indicator << " добавили теоретичиский коэффициент равный " << int32_t(TheoWeight) << "%." << endl;
	getline(cin, err);


}



void theorlist(vector<string>& indicators, vector<signed char>& TheoWeights)
{
	string err;
	int32_t i1 = indicators.size();

	for (int32_t i = 0; i < i1; i++)
	{
		std::cout << "Параматр " << indicators[i] << "  вес " << int32_t(TheoWeights[i])  << "%" << ";" << endl;

	}
	getline(cin, err);
}




void quoterlist(vector<string>& indicators, vector<vector<double>>& indicatDate)

{
	Other obj3;
	
	string quoteraw = "";
	string err;
	
	bool check = obj3.checkcin();
	if (check == true) { cin >> quoteraw; }

		//работа с кварталом

	std::regex patQ{ R"(\d\.\d\d\d\d)" };
	if (!std::regex_match(quoteraw, patQ))
	{
		std::cout << "Неверно введен квартал года или сам год " << quoteraw << endl << "Пример - 4.1999 " << endl;
		getline(cin, err);
		return;
	};
	
	
		////что-то делаем с годом и кварталом
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
		int32_t q3 = indicators.size();
		if (q3 == 0) { std::cout << "Нет данных" << endl; return; }
		int32_t q4 = indicatDate[0].size();
		if (q4 == 0) { std::cout << "Нет данных" << endl; return; }
		for (int32_t i = 0; i < q3; i++)
		{
			std::cout << indicators[i] << "    " << indicatDate[i][qy] << endl;

		}
		getline(cin, err);
}


void paramdatelist(vector<string>& indicators, vector<vector<double>>& indicatDate)

{
	Other obj3;
	
	int32_t st10 = std::cin.peek();

	if (st10 != 10)
	{

		//Запись параметра
		vector<string> vvodindicv;
		string err;
		string indicator = "";
		string space = " ";
		string vvodindic;
		char t1 = ' ';
		int32_t t2 = 0;
		map<int32_t, double> dates;
		double d0 = 0.0;
		vector<int32_t> index;

		while (t2 < 1)
		{
			int32_t st11 = std::cin.peek();
			if (st11 != 10)
			{
				bool check = obj3.checkcin();
				if (check == true) { cin >> vvodindic; }
				if (!vvodindic.empty()) {
					char t0 = vvodindic.back();
				//	if (t0 == t1) { vvodindic.pop_back(); vvodindicv.push_back(vvodindic); vvodindic = ""; t2 = 1; }
				//	else
					{
						vvodindicv.push_back(vvodindic);
						vvodindic = "";

					}

				}
				else
				{
					std::cout << "Вы ничего не ввели. Введите пожалуйста данные." << endl;
					return;
				}
			}
			else { t2 = 1; }
		}


		int32_t t0 = vvodindicv.size();
		for (int32_t t1 = 0; t1 < t0; t1++)
		{
			indicator = indicator + vvodindicv[t1] + space;

		}
		indicator.pop_back();

		// Проверка наличия параметра
		auto t4 = find(indicators.begin(), indicators.end(), indicator);
		
		if (t4 == indicators.end())
		{
			
			std::cout << "Параметр " << indicator << " еще не добавлен. Добавьте, пожалуйста, параметр " << indicator << " и повторите попытку." << endl;
			return;
		}
		
		auto t9 = std::distance(indicators.begin(), t4);


		int32_t t10 = indicatDate[t9].size();
		int32_t i11 = 0;
		while( i11 < t10 )
		{
			int32_t t11 = i11+1;
			int32_t t12 = t11 / 4;
			int32_t t13 = t11 % 4;
			t12 += 1990;
			if (t13 == 0) { t12 -= 1;  t13 = 4; }
			string t14 = to_string(t12);
			string t15 = to_string(t13);
			string t16 = ".";
			string t17 = t15 + t16 + t14;

			double t18 = indicatDate[t9][i11];
			std::cout << t17 << "      " << t18 << endl;
			i11++;

		}

		getline(cin, err);
	}
	else { std::cout << "Вы ничего не ввели. Введите пожалуйста название параметра." << endl; }
}



void incr(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<vector<signed char>>& indicatDateInc)
{
	
	Other obj3;
	
	string quoteraw = "";
		string err;

		bool check = obj3.checkcin();
		if (check == true) { cin >> quoteraw; }

		//работа с кварталом

		std::regex patQ{ R"(\d\.\d\d\d\d)" };
		if (!std::regex_match(quoteraw, patQ))
		{
			std::cout << "Неверно введен квартал года или сам год " << quoteraw << endl << "Пример - 4.1999 " << endl;
			getline(cin, err);
			return;
		};


		////что-то делаем с годом и кварталом
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
		int32_t q3 = indicators.size();
		if (q3 == 0) { std::cout << "Нет данных" << endl; return; }
		int32_t q4 = indicatDate[0].size();
		if (q4 == 0) { std::cout << "Нет данных" << endl; return; }

		incrquotercalc(qy, indicatDate, indicatDateInc);


		for (int32_t i = 0; i < q3; i++)
		{
			signed char in0 = indicatDateInc[i][qy];
			int32_t in1 = int32_t(in0);
			in1 = in1 * 2; // нивелируем шаг
			double in2 = in1;
			in2 = in2 / 10; // корректно отображаем десятые процента
			std::cout << indicators[i] << "    " << in2 << "%;" << endl;

		}
		getline(cin, err);
	}







	void bpv(vector<string>& indicators, vector<signed char>& TheoWeights, vector<vector<double>>& indicatDate, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<int32_t>& Count,
		vector<signed char>& Weights1,
		vector<vector<signed char>>& Outputs1, 
		vector<vector<signed char>>& Weights2, 
		vector<vector<signed char>>& Outputs2,
		vector<vector<signed char>>& Weights3,
		vector<vector<signed char>>& Outputs3, 
		vector<vector<signed char>>& Weights4,
		vector<vector<signed char>>& Outputs4,
		vector<vector<signed char>>& Weights5,
		vector<signed char>& Weights1m, 
	vector<vector<signed char>>& Weights2m, 
	vector<vector<signed char>>& Weights3m, 
	vector<vector<signed char>>& Weights4m, 
	vector<vector<signed char>>& Weights5m, 
	vector<vector<signed char>>& Outputs1m,
	vector<vector<signed char>>& Outputs2m, 
	vector<vector<signed char>>& Outputs3m, 
	vector<vector<signed char>>& Outputs4m, 
		const signed char alpha
	)
{
	
		Other obj3;
		signed char result;

		signed char result1;
		signed char result2;
		signed char a = 0;
		// signed char alpha = 15;
	string err;
	signed char p0 = 0;

	int32_t Quoter;


	string m0 = "uploadparamd";
	string m1 = "addparam";
	string m2 = "paramlist";
	string m3 = "paramdatelist";
	string m4 = "quoterlist";
	string m5 = "incr";
	string m6 = "theorlist";
	string m7 = "uploadtheor";
	string m8 = "calcgdp";
	string m9 = "teach";
	string m10 = "info";
	string m11 = "end";
	string m12 = "calcgdpt";

	



	signed char b2 = 0;
	

	while (a < 1)
	{

		string vvod;
		int32_t count = 0;
		int32_t s0 = Count.size();
		if (s0 != 0) count = Count[0];
		if (b2 == 0)
		{
			cout << "Введите необходимую вам команду. Для вызова справки введите info." << endl << ">>> ";
			vvod = "";

			bool check = obj3.checkcin();
			if (check == true) { cin >> vvod; }
			/*
			if (vvod == "") { cout << endl << "Ваша команда не распознана. Скорректируйте команду или воспользуйтесь командой info для справок" << endl; getline(cin, err); }
			else
			*/
			if (vvod == m11) a = 1;
			else if (vvod == m10) info();
			else if (vvod == m0) uploadparamd(indicators, indicatDate, Count, indicatDateInc, Cash1);
			else if (vvod == m1) addparam(indicators, TheoWeights, indicatDate, count, indicatDateInc, Cash1, Weights1, Weights1m, Count);
			else if (vvod == m2) paramlist(indicators);
			else if (vvod == m3) paramdatelist(indicators, indicatDate);
			else if (vvod == m4) quoterlist(indicators, indicatDate);
			else if (vvod == m5) incr(indicators, indicatDate, indicatDateInc);
			else if (vvod == m6) theorlist(indicators, TheoWeights);
			else if (vvod == m7) uploadtheor(indicators, TheoWeights);
			else if (vvod == m8) {
				bool a11 = calcgdp(indicators, indicatDate, TheoWeights, indicatDateInc, Cash1, Weights1, Count, Outputs1, Weights2, Outputs2, Quoter, Weights3, Outputs3, Weights4, Outputs4, Weights5, result1, result2, result,
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
				if (a11) b2 = 2;
				else b2 = 0;
				getline(cin, err);
			}
			else if (vvod == m9);
			
#ifdef _DEBUG 
			else if (vvod == m12) { calcgdpt(indicators, indicatDate, TheoWeights, indicatDateInc, Cash1, Weights1, Count, Outputs1, Weights2, Outputs2, Quoter, Weights3, Outputs3, Weights4, Outputs4, Weights5, result1, result2, result,
				Weights1m,
				Weights2m,
				Weights3m,
				Weights4m,
				Weights5m,
				Outputs1m,
				Outputs2m,
				Outputs3m,
				Outputs4m
				); b2 = 1; }
#endif
			else {
				std::cout << endl << "Ваша команда не распознана. Скорректируйте команду или воспользуйтесь командой info для справок" << endl; getline(cin, err);
			}
		}
		
#ifdef _DEBUG 	
		else if (b2 == 1) {

			std::cout << "Введите название характеристики фрукта на английском: " << endl << ">>> ";
			vvod = "";
			//bool check = obj3.checkcin();
			//if (check == true) { cin >> vvod; }
			cin >> vvod;
			teacher(Quoter, result1, result2, result, Weights5, Weights4, Weights3, Weights2, Weights1, Outputs4, Outputs3, Outputs2, Outputs1, alpha, vvod,
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

			b2 = 0;

		}
		
#endif
		
		
		else  {

			std::cout << "Введите, пожалуйста корректный парирост ВВП и завершите его ; Пример - 12,5; " << endl << ">>> ";
			vvod = "";
			//bool check = obj3.checkcin();
			//if (check == true) { cin >> vvod; }
			cin >> vvod;
			teachquoter(Quoter, result1, result2, result, Weights5, Weights4, Weights3, Weights2, Weights1, Outputs4, Outputs3, Outputs2, Outputs1, alpha, vvod,
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

			b2 = 0;

		}

		

	}

}
