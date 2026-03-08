//операция с нейронами
#pragma once

#include <chrono>
#include <cstdint>

using namespace std;

class Neyron
{
public:
	signed char valueneyTwoOne(vector<signed char>& neyronin, vector<signed char>& weight);
	vector<signed char> valueneyOneTwo(vector<signed char>& neyronin, vector<signed char>& weight);
	vector <signed char> teacherOneTwo(vector <signed char> weight1, signed char input, int32_t ig, int32_t ip); //вектор значений, значение входного нейрона, какой результат надо, какой вернула сеть
	signed char valueneyTwoOner(vector<signed char>& neyronin, vector<signed char>& weight); //с релу 
	vector<signed char> valueneyOneTwor(vector<signed char>& neyronin, vector<signed char>& weight); //с релу
	vector<signed char > deltaout(vector<signed char >& delta, const signed char& neyrontest, const signed char& neyrontestres); //дельта для постеднего ряда
	void dellayerlast(vector<vector<signed char>>& Weights3, int32_t Quoter, vector<vector<signed char>>& Outputs2, const signed char& delta); //пересчет весов последнего ряда
	vector<signed char > deltaMiddle(int32_t& Weightslsize, vector <signed char>& Weightsl, vector <signed char>& delta, signed char& deltal, signed char& alpha, vector<signed char >& Outputs);
	vector<signed char > MiddleTeach(vector<signed char >& Weights, signed char& Output, signed char& delta, int32_t& size, signed char& alpha);
	signed char valueneyTwoOnerm(vector<signed char>& neyronin, vector<signed char>& weight);
	vector<signed char> valueneyOneTworm(vector<signed char>& neyronin, vector<signed char>& weight);
	vector<signed char > deltaMiddlem(int32_t& Weightslsize, vector <signed char>& Weightsl, vector <signed char>& delta, signed char& deltal, signed char& alpha, vector<signed char >& Outputs);
};