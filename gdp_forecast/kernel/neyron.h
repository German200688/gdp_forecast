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
	vector <signed char> teacherOneTwo(vector <signed char> weight1, signed char input, int64_t ig, int64_t ip); //вектор значений, значение входного нейрона, какой результат надо, какой вернула сеть
	signed char valueneyTwoOner(vector<signed char>& neyronin, vector<signed char>& weight); //с релу 
	vector<signed char> valueneyOneTwor(vector<signed char>& neyronin, vector<signed char>& weight); //с релу
	vector<signed char > deltaout(vector<signed char >& delta, const signed char& neyrontest, const signed char& neyrontestres); //дельта для постеднего ряда
	void dellayerlast(vector<vector<signed char>>& Weights3, int64_t Quoter, vector<vector<signed char>>& Outputs2, const signed char& delta); //пересчет весов последнего ряда
	signed char deltaMiddle(int64_t Weightslsize, vector<signed char >& Weights, vector<signed char >& delta, signed char& alpha, signed char& Outputs);
	vector<signed char > MiddleTeach(vector<signed char >& Weights, signed char& Output, signed char& delta, int64_t& size, signed char& alpha);
	signed char valueneyTwoOnerm(vector<signed char>& neyronin, vector<signed char>& weight);
	vector<signed char> valueneyOneTworm(vector<signed char>& neyronin, vector<signed char>& weight);
	signed char deltaMiddlem(int64_t Weightslsize, vector<signed char >& Weights, vector<signed char >& delta, signed char& alpha, signed char& Outputs);
	signed char deltafin(int64_t Weightslsize, signed char& Weight, signed char& delta, signed char& alpha, signed char& Outputs);
	signed char deltafinm(int64_t Weightslsize, signed char& Weight, signed char& delta, signed char& alpha, signed char& Outputs);
};