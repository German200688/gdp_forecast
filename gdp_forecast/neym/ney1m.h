// OB1.h : работа с первым слоем
#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer1m
{
protected:
	void neurons_count_quoter1m(vector<vector<double>>& Outputs1m, int64_t Quoter);
	void neurons_count_ney1m(vector<vector<double>>& Outputs1m, vector<int64_t>& Count, int64_t& neurons_count);


public:
	void Weights1addition1m(vector<double>& Weights1m, vector<double>& Weights1, vector<int64_t>& Count); // вычисляется количество весов при добалении одного параметра. Вектор весов, количество нейронов до, cлужебный
	void summneyquoter1m(vector<int64_t>& Count, vector<vector<double>>& Cash1, vector<double>& Weights1m, vector<vector<double>>& Outputs1m, int64_t Quoter, vector<string>& indicators); // вычиляется выход по каждому нейрону первого слоя. Служебный, подготовленные данные, веса, вектор вывода, квартал который вычисляем
	void summneyall1m(vector<int64_t>& Count, vector<vector<double>>& Cash1, vector<double>& Weights1m, vector<vector<double>>& Outputs1m, vector<string>& indicators);
	void teachdel1m(vector<double >& delta2m, int64_t& Quoter, vector<vector<double>>& Weights2m, vector<double>& Weights1m, vector<vector<double>>& Outputs1m, vector<double >& delta1m, double alpha);
	void teach1m(int64_t& Quoter, vector<vector<double>>& Outputs1m, double alpha, vector<double>& Weights1m, vector<double >& delta1m);
	//void teachdel1mam(vector<double >& delta2m, int64_t& Quoter, vector<vector<double>>& Weights2m, vector<double>& Weights1m, vector<vector<double>>& Outputs1m, vector<double >& delta1m, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d);

};