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


bool calcgdp(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<signed char>& TheoWeights, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<signed char> Weights1, vector<int32_t>& Count, vector<vector<signed char>>& Outputs1, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2, int32_t& Quoter, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Weights5, signed char& result1, signed char& result2, signed char& result,
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


	int32_t q0 = quoteraw[0];

	char q5 = 52;
	char q6 = 49;
	char q66 = 50;
	
	if (q0 > q5 || q0 < 49) { std::cout << "Неверно введен квартал года " << quoteraw << endl << "Пример - 4.1999 " << endl; getline(cin, err);  return false ; }
	string q1 = quoteraw.substr(2, 4);
	int32_t q2 = stoi(q1);
	if (q0 == q6 && q2 == 1990) { std::cout << "Данные рассчитываются за период не ранее 3-го квартала 1990 года" << endl; getline(cin, err);  return false; }
	if (q0 == q66 && q2 == 1990) { std::cout << "Данные рассчитываются за период не ранее 3-го квартала 1990 года" << endl; getline(cin, err);  return false; }
	if (q2 < 1990) { std::cout << "Неверно введен год " << quoteraw << endl << "Пример - 4.1999 " << endl; getline(cin, err);  return false; } 
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
	int32_t qy2 = qy - 1;//используются данные за предыдущий квартал
	int32_t qy1 = qy; ///+ 1;
	int32_t te1 = indicatDate[0].size();
	if (qy2 > te1) { cout << "К сожалению данные за предыдущий квартал отсутствуют и рассчет не может быть осуществлен. Введите данные и повторите снова." << endl; return false; }
	
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
	

	if (std::abs(static_cast<int32_t>(result1)) > std::abs(static_cast<int32_t>(result2))) result = result1;
	else result = result2;


	printerrr(result);

	return true;

}



void teachquoter(int32_t& Quoter1, signed char& result1, signed char& result2, signed char& result, vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Weights2, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Outputs1, signed char alpha, string dateraw,
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
	int32_t Quoter = Quoter1 - 1;





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
	




	teachdel3(result1, incr4, delta5);
	



	teachdel3(result2, incr4, delta5m);
	




	obj7.teachdel4(delta5, Quoter, Weights5, Weights4, Outputs4, delta4);
	



	obj71.teachdel4m(delta5m, Quoter, Weights5m, Weights4m, Outputs4m, delta4m);
	




	obj6.teachdel3(delta4, Quoter, Weights4, Weights3, Outputs3, delta3);

	



	obj61.teachdel3m(delta4m, Quoter, Weights4m, Weights3m, Outputs3m, delta3m);

	



	obj4.teachdel2(delta3, Quoter, Weights3, Weights2, Outputs2, delta2);
	



	obj41.teachdel2m(delta3m, Quoter, Weights3m, Weights2m, Outputs2m, delta2m);
	





	obj5.teachdel1(delta2, Quoter, Weights2, Weights1, Outputs1, delta1);

	



	obj51.teachdel1m(delta2m, Quoter, Weights2m, Weights1m, Outputs1m, delta1m);

	






	teachlayer3(Weights5, Quoter, Outputs4, delta5);

	


	teachlayer3(Weights5m, Quoter, Outputs4m, delta5m);

	




	// "Рассчет данных 4-го положительного слоя:" 

	obj6.teach3(Quoter, Outputs4, alpha, Weights4, delta4);



	// "Рассчет данных 4-го отрицательного слоя:" 

	obj61.teach3m(Quoter, Outputs4m, alpha, Weights4m, delta4m);




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

	cout << "\033[32m ----- Рассчет завершен -----" << endl;
	
}