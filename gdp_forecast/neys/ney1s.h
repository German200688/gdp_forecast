// OB1.h : работа с первым слоем
#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer1
{
protected:
	void neurons_count_quoter1(vector<vector<double>>& Outputs1, int64_t Quoter);
	void neurons_count_ney1(vector<vector<double>>& Outputs1, vector<int64_t>& Count, int64_t& neurons_count);


public:
	void Weights1addition1(vector<double>& Weights1, int64_t countbefore, vector<int64_t>& Count); // вычисляется количество весов при добалении одного параметра. Вектор весов, количество нейронов до, cлужебный
	void summneyquoter1(vector<int64_t>& Count, vector<vector<double>>& Cash1, vector<double>& Weights1, vector<vector<double>>& Outputs1, int64_t Quoter, vector<string>& indicators); // вычиляется выход по каждому нейрону первого слоя. Служебный, подготовленные данные, веса, вектор вывода, квартал который вычисляем
	void summneyall1(vector<int64_t>& Count, vector<vector<double>>& Cash1, vector<double>& Weights1, vector<vector<double>>& Outputs1, vector<string>& indicators);
	void teachdel1(vector<double >& delta2, int64_t& Quoter, vector<vector<double>>& Weights2, vector<double>& Weights1, vector<vector<double>>& Outputs1, vector<double >& delta1);
	void teach1(int64_t& Quoter, vector<vector<double>>& Outputs1, double alpha, vector<double>& Weights1, vector<double >& delta1);
	void teachdel1ma(vector<double >& delta2, int64_t& Quoter, vector<vector<double>>& Weights2, vector<double>& Weights1, vector<vector<double>>& Outputs1, vector<double >& delta1, double*& dvec_a1, double*& dvec_b1, double*& dvec_c1);

};