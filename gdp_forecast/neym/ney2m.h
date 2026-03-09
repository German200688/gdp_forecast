#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer2m
{
protected:
	void neyronoutindadd2m(vector<vector<signed char>>& Outputs2m, vector<int32_t>& Count, int32_t& CountOutputs1);
	void neyronoutqadd2m(vector<vector<signed char>>& Outputs2m, int32_t Quoter);
	void weightsaddl12m(vector<vector<signed char>>& Weights2m, int32_t ney1);
	void weightsaddl22m(vector<vector<signed char>>& Weights2m, int32_t CountWeights2);
	



public:
	void summneyquoter2m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs1m, vector<vector<signed char>>& Weights2m, vector<vector<signed char>>& Outputs2m, int32_t Quoter);
	void summneyall2m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs1m, vector<vector<signed char>>& Weights2m, vector<vector<signed char>>& Outputs2m);
	void teachdel2m(vector<signed char >& delta3m, int32_t& Quoter, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Weights2m, vector<vector<signed char>>& Outputs2m, vector<signed char >& delta2m);
	void teach2m(int32_t& Quoter, vector<vector<signed char>>& Outputs2m, signed char alpha, vector<vector<signed char>>& Weights2m, vector<signed char >& delta2m);
	void teachdel2mam(vector<signed char >& delta3m, int32_t& Quoter, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Weights2m, vector<vector<signed char>>& Outputs2m, vector<signed char >& delta2m, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);
	void teach2mam(int32_t& Quoter, vector<vector<signed char>>& Outputs2m, signed char alpham, vector<vector<signed char>>& Weights2m, vector<signed char >& delta2m, signed char*& vec_d, signed char*& vec_a);


};