// OB1.h : работа с первым слоем
#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer1
{
protected:
	void neurons_count_quoter1(vector<vector<signed char>>& Outputs1, int32_t Quoter);
	void neurons_count_ney1(vector<vector<signed char>>& Outputs1, vector<int32_t>& Count, int32_t& neurons_count);


public:
	void Weights1addition1(vector<signed char>& Weights1, int32_t countbefore, vector<int32_t>& Count); // вычисляется количество весов при добалении одного параметра. Вектор весов, количество нейронов до, cлужебный
	void summneyquoter1(vector<int32_t>& Count, vector<vector<signed char>>& Cash1, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs1, int32_t Quoter, vector<string>& indicators); // вычиляется выход по каждому нейрону первого слоя. Служебный, подготовленные данные, веса, вектор вывода, квартал который вычисляем
	void summneyall1(vector<int32_t>& Count, vector<vector<signed char>>& Cash1, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs1, vector<string>& indicators);
	void teachdel1(vector<signed char >& delta2, int32_t& Quoter, vector<vector<signed char>>& Weights2, vector<signed char>& Weights1, vector<vector<signed char>>& Outputs1, vector<signed char >& delta1);
	void teach1(int32_t& Quoter, vector<vector<signed char>>& Outputs1, signed char alpha, vector<signed char>& Weights1, vector<signed char >& delta1);
	void teachdel1ma(vector<signed char >& delta2, int32_t& Quoter, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Weights1, vector<vector<signed char>>& Outputs1, vector<signed char >& delta1, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);

};