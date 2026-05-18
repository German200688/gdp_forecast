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


bool calcgdp(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<double>& TheoWeights, vector<vector<double>>& indicatDateInc, vector<vector<double>>& Cash1, vector<double>& Weights1, vector<int64_t>& Count, vector<vector<double>>& Outputs1, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2, int64_t& Quoter, vector<vector<double>>& Weights3, vector<vector<double>>& Outputs3, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, vector<vector<double>>& Weights5, double& result1, double& result2, double& result,
	vector<double>& Weights1m,
	vector<vector<double>>& Weights2m,
	vector<vector<double>>& Weights3m,
	vector<vector<double>>& Weights4m,
	vector<vector<double>>& Weights5m,
	vector<vector<double>>& Outputs1m,
	vector<vector<double>>& Outputs2m,
	vector<vector<double>>& Outputs3m,
	vector<vector<double>>& Outputs4m
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
	
	


	Other obj3;
	//работа с кварталом
	string quoteraw = "";
	string err;

	if (indicators.size() < 4) { std::cout << "Можно проводить рассчет только при количестве индикоторов большем, чем 3." << endl << "У вас сейчас - " << indicators.size() << " индикатора." << endl; return false; }

	bool check = obj3.checkcin();
	if (check == true) { cin >> quoteraw; }

	////что-то делаем с годом и кварталом

	std::regex patQ{ R"(\d\.\d\d\d\d)" };
	if (!std::regex_match(quoteraw, patQ))
	{
		std::cout << "Неверно введен квартал года или сам год " << quoteraw << endl << "Пример - 4.1999 " << endl;
		getline(cin, err);
		return false;
	};


	int64_t q0 = quoteraw[0];

	char q5 = 52;
	char q6 = 49;
	char q66 = 50;
	
	if (q0 > q5 || q0 < 49) { std::cout << "Неверно введен квартал года " << quoteraw << endl << "Пример - 4.1999 " << endl; getline(cin, err);  return false ; }
	string q1 = quoteraw.substr(2, 4);
	int64_t q2 = stoi(q1);
	if (q0 == q6 && q2 == 1990) { std::cout << "Данные рассчитываются за период не ранее 3-го квартала 1990 года" << endl; getline(cin, err);  return false; }
	if (q0 == q66 && q2 == 1990) { std::cout << "Данные рассчитываются за период не ранее 3-го квартала 1990 года" << endl; getline(cin, err);  return false; }
	if (q2 < 1990) { std::cout << "Неверно введен год " << quoteraw << endl << "Пример - 4.1999 " << endl; getline(cin, err);  return false; } 
	int64_t qy = q2 - 1990;
	qy = qy * 4;
	qy -= 1;
	int64_t q10 = 0;
	if (q0 == 49) { q10 = 1; }
	if (q0 == 50) { q10 = 2; }
	if (q0 == 51) { q10 = 3; }
	if (q0 == 52) { q10 = 4; }
	qy += q10;
	Quoter = qy;
	int64_t qy2 = qy - 1;//используются данные за предыдущий квартал
	int64_t qy1 = qy; ///+ 1;
	int64_t te1 = indicatDate[0].size();
	if (qy2 > te1) { cout << "К сожалению данные за предыдущий квартал отсутствуют и рассчет не может быть осуществлен. Введите данные и повторите снова." << endl; return false; }
	
	// "Прирост данных:" 
	incrquotercalc(qy2, indicatDate, indicatDateInc);
	cashquoter(qy2, TheoWeights, indicatDateInc, Cash1);

	

	// "Данные идущие на вход второго положительного слоя:" 

	obj2.summneyquoter1(Count, Cash1, Weights1, Outputs1, qy2, indicators);
	double tttt1 = Weights1[2];
	cout << "Weights1[2] " << tttt1 << endl;
	cout << "Outputs1 " << std::fixed << std::setprecision(17) << Outputs1[qy2][3] << "%" << endl;
	
	// "Данные идущие на вход второго отрицательного слоя:" 

	obj21.summneyquoter1m(Count, Cash1, Weights1m, Outputs1m, qy2, indicators);

	

	// "Расчет весов для 2-го положительного слоя:" 
	obj4.summneyquoter2(Count, Outputs1, Weights2, Outputs2, qy2);
	double tttt2 = Weights2[2][2];
	cout << "Weights2[2][2] " << tttt2 << endl;
	cout << "Outputs2 " << std::fixed << std::setprecision(17) << Outputs2[qy2][3] << "%" << endl;
	
	//"Расчет весов для 2-го отрицательного слоя:"
	obj41.summneyquoter2m(Count, Outputs1m, Weights2m, Outputs2m, qy2);
/*
	// "Данные идущие на вход 3-го положительного слоя:"

	obj4.summneyquoter2(Count, Outputs1, Weights2, Outputs2, qy2);

	// "Данные идущие на вход 3-го отрицательного слоя:"

	obj41.summneyquoter2m(Count, Outputs1m, Weights2m, Outputs2m, qy2);
*/
	// "Расчет весов 3-го положительного слоя:"
	obj5.summneyquoter3(Count, Outputs2, Weights3, Outputs3, qy2);
	double tttt3 = Weights3[3][2];
	cout << "Weights3[3][2] " << tttt3 << endl;
	cout << "Outputs3 " << std::fixed << std::setprecision(17) << Outputs3[qy2][3] << "%" << endl;

	// "Расчет весов 3-го отрицательного слоя:"
	obj51.summneyquoter3m(Count, Outputs2m, Weights3m, Outputs3m, qy2);

	


	// "Рассчет весов 4-го положительно слоя:"
	obj44.summneyquoter4(Count, Outputs3, Weights4, Outputs4, qy2);
	double tttt4 = Weights4[3][2];
	cout << "Weights4[3][2] " << tttt4 << endl;
	cout << "Outputs4 " << std::fixed << std::setprecision(17) << Outputs4[qy2][3] << "%" << endl;

	//"Рассчет весов 4-го отрицателльного слоя:"
	obj441.summneyquoter4m(Count, Outputs3m, Weights4m, Outputs4m, qy2);



	//рассчет результата 5го слоя положительного
	result1 = weightsumm(Weights5, Outputs4, qy2);
	//cout << "result1" << result1 << endl;
	cout << "result1 " << std::fixed << std::setprecision(17) << result1 << "%" << endl;


	//рассчет результата 5го слоя отрицительного
	result2 = weightsumm(Weights5m, Outputs4m, qy2);
	cout << int(result2) << endl;

	if (std::abs(static_cast<int64_t>(result1)) > std::abs(static_cast<int64_t>(result2))) result = result1;
	else 
		result = result1;
	

	printerrr(result);

	return true;

}



void teachquoter(int64_t& Quoter1, double& result1, double& result2, double& result, vector<vector<double>>& Weights5, vector<vector<double>>& Weights4, vector<vector<double>>& Weights3, vector<vector<double>>& Weights2, vector<double>& Weights1, vector<vector<double>>& Outputs4, vector<vector<double>>& Outputs3, vector<vector<double>>& Outputs2, vector<vector<double>>& Outputs1, double alpha, string dateraw,
	vector<double>& Weights1m,
	vector<vector<double>>& Weights2m,
	vector<vector<double>>& Weights3m,
	vector<vector<double>>& Weights4m,
	vector<vector<double>>& Weights5m,
	vector<vector<double>>& Outputs1m,
	vector<vector<double>>& Outputs2m,
	vector<vector<double>>& Outputs3m,
	vector<vector<double>>& Outputs4m
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

	vector<double > delta5;
	vector<double > delta4;
	vector<double > delta3;
	vector<double > delta2;
	vector<double > delta1;
	vector<double > delta5m;
	vector<double > delta4m;
	vector<double > delta3m;
	vector<double > delta2m;
	vector<double > delta1m;



	//	string dateraw;
	bool check = true;
	string err;
	int64_t Quoter = Quoter1 - 1;





	char t0 = dateraw.back();

	char t5 = ';';
	int64_t a = 4;
	double d0 = 0.0;
	if (t0 != t5) { std::cout << "Некорректно введены данные " << dateraw << endl; getline(cin, err); return; }
	else
	{
		dateraw.pop_back();
		d0 = stod(dateraw);
		std::cout << "Введены данные = " << d0 << endl;
	}

	double incr2 = d0; //x*100*10/2 - 100-Р 


	double incr3 = incr2;
	//std::cout << "incr3 = " << int(incr2) << endl;
/*
	while (incr3 > 100)
	{
		incr3 = 100;
	}

	while (incr3 < -100)
	{
		incr3 = -100;
	}
*/
	double incr4 = static_cast<double>(incr3);



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
	
	obj7.teachdel4(delta5, Quoter, Weights5, Weights4, Outputs4, Outputs3, delta4, alpha);
#ifdef _DEBUG
	cout << " после рассчета int(delta4[i]):" << endl;

	int t001 = delta4.size();
	for (int i = 0; i < t001; i++)
	{
		cout << int(delta4[i]) << endl;
	}
#endif

	obj71.teachdel4m(delta5m, Quoter, Weights5m, Weights4m, Outputs4m, Outputs3m, delta4m, alpha);

	obj6.teachdel3(delta4, Quoter, Weights4, Weights3, Outputs3, Outputs2, delta3, alpha);
#ifdef _DEBUG
	cout << " после рассчета int(delta3[i]):" << endl;

	int t0013 = delta3.size();
	for (int i = 0; i < t0013; i++)
	{
		cout << int(delta3[i]) << endl;
	}
#endif

	obj61.teachdel3m(delta4m, Quoter, Weights4m, Weights3m, Outputs3m, Outputs2m, delta3m, alpha);

	obj4.teachdel2(delta3, Quoter, Weights3, Weights2, Outputs2, Outputs1, delta2, alpha);
#ifdef _DEBUG
	cout << " после рассчета int(delta2[i]):" << endl;

	int t0012 = delta2.size();
	for (int i = 0; i < t0012; i++)
	{
		cout << int(delta2[i]) << endl;
	}
#endif

	obj41.teachdel2m(delta3m, Quoter, Weights3m, Weights2m, Outputs2m, Outputs1m, delta2m, alpha);

	obj5.teachdel1(delta2, Quoter, Weights2, Weights1, Outputs1, delta1, alpha);
#ifdef _DEBUG
	cout << " после рассчета int(delta1[i]):" << endl;

	int t0011 = delta1.size();
	for (int i = 0; i < t0011; i++)
	{
		cout << int(delta1[i]) << endl;
	}
#endif

	obj51.teachdel1m(delta2m, Quoter, Weights2m, Weights1m, Outputs1m, delta1m, alpha);

	teachlayer3(Weights5, Quoter, Outputs4, delta5, alpha);
#ifdef _DEBUG
	cout << " после рассчета Weights5[0]:" << endl;

	int t00111 = Weights5[0].size();
	for (int i = 0; i < t00111; i++)
	{
		cout << int(Weights5[0][i]) << endl;
	}
#endif

	teachlayer3(Weights5m, Quoter, Outputs4m, delta5m, alpha);



	// "Рассчет данных 4-го положительного слоя:" 

	obj7.teach4(Quoter, Outputs4, alpha, Weights4, delta4);

	// "Рассчет данных 4-го отрицательного слоя:" 

	obj71.teach4m(Quoter, Outputs4m, alpha, Weights4m, delta4m);

	// "РАссчет весов 3-го положительного слоя:"

	obj6.teach3(Quoter, Outputs3, alpha, Weights3, delta3);

// "Рассчет весов 3-го отрицательного слоя:" << endl;

	obj61.teach3m(Quoter, Outputs3m, alpha, Weights3m, delta3m);

	// "Веса 2-го положительного слоя:" << endl;

	obj4.teach2(Quoter, Outputs2, alpha, Weights2, delta2);

	// "Веса 2-го отрицательного слоя:" << endl;

	obj41.teach2m(Quoter, Outputs2m, alpha, Weights2m, delta2m);

	// "Веса первого положительного слоя:"

	obj5.teach1(Quoter, Outputs1, alpha, Weights1, delta1);

	// "Веса первого отрицательного слоя:" 

	obj51.teach1m(Quoter, Outputs1m, alpha, Weights1m, delta1m);

	cout << "\033[32m ----- Рассчет завершен -----\033[0m" << endl;

	getline(cin, err);
	
}