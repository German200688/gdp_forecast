#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer2
{
protected:
	void neyronoutindadd2(vector<vector<signed char>>& Outputs2, vector<int32_t >& Count, int32_t & CountOutputs1);
	void neyronoutqadd2(vector<vector<signed char>>& Outputs2, int32_t Quoter);
	void weightsaddl12(vector<vector<signed char>>& Weights2, int32_t ney1);
	void weightsaddl22(vector<vector<signed char>>& Weights2, int32_t CountWeights2);
	



public:
	void summneyquoter2(vector<int32_t >& Count, vector<vector<signed char>>& Outputs1, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2, int32_t Quoter);
	void summneyall2(vector<int32_t >& Count, vector<vector<signed char>>& Outputs1, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2);
	void teachdel2(vector<signed char >& delta3, int32_t & Quoter, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2, vector<signed char >& delta2);
	void teach2(int32_t & Quoter, vector<vector<signed char>>& Outputs2, signed char alpha, vector<vector<signed char>>& Weights2, vector<signed char >& delta2);
	void teachdel2ma(vector<signed char >& delta3, int32_t& Quoter, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2, vector<signed char >& delta2, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);
};