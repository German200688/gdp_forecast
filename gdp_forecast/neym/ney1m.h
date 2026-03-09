// OB1.h : работа с первым слоем
#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer1m
{
protected:
	void neurons_count_quoter1m(vector<vector<signed char>>& Outputs1m, int32_t Quoter);
	void neurons_count_ney1m(vector<vector<signed char>>& Outputs1m, vector<int32_t>& Count, int32_t& neurons_count);


public:
	void Weights1addition1m(vector<signed char>& Weights1m, vector<signed char>& Weights1, vector<int32_t>& Count); // вычисляется количество весов при добалении одного параметра. Вектор весов, количество нейронов до, cлужебный
	void summneyquoter1m(vector<int32_t>& Count, vector<vector<signed char>>& Cash1, vector<signed char>& Weights1m, vector<vector<signed char>>& Outputs1m, int32_t Quoter, vector<string>& indicators); // вычиляется выход по каждому нейрону первого слоя. Служебный, подготовленные данные, веса, вектор вывода, квартал который вычисляем
	void summneyall1m(vector<int32_t>& Count, vector<vector<signed char>>& Cash1, vector<signed char>& Weights1m, vector<vector<signed char>>& Outputs1m, vector<string>& indicators);
	void teachdel1m(vector<signed char >& delta2m, int32_t& Quoter, vector<vector<signed char>>& Weights2m, vector<signed char>& Weights1m, vector<vector<signed char>>& Outputs1m, vector<signed char >& delta1m);
	void teach1m(int32_t& Quoter, vector<vector<signed char>>& Outputs1m, signed char alpha, vector<signed char>& Weights1m, vector<signed char >& delta1m);
	void teachdel1mam(vector<signed char >& delta2m, int32_t& Quoter, vector<vector<signed char>>& Weights2m, vector<vector<signed char>>& Weights1m, vector<vector<signed char>>& Outputs1m, vector<signed char >& delta1m, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);
};