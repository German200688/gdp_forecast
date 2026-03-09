#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer3m
{
protected:
	void neyronoutindadd3m(vector<vector<signed char>>& Outputs3m, vector<int32_t>& Count, int32_t& CountOutputs2);
	void neyronoutqadd3m(vector<vector<signed char>>& Outputs3m, int32_t Quoter);
	void weightsaddl23m(vector<vector<signed char>>& Weights3m, int32_t ney1);
	void weightsaddl33m(vector<vector<signed char>>& Weights3m, int32_t CountWeights3);
	



public:
	void summneyquoter3m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs2m, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Outputs3m, int32_t Quoter);
	void summneyall3m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs2m, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Outputs3m);
	void teachdel3m(vector<signed char >& delta4m, int32_t& Quoter, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Outputs3m, vector<signed char >& delta3m);
	void teach3m(int32_t& Quoter, vector<vector<signed char>>& Outputs3m, signed char alpha, vector<vector<signed char>>& Weights3m, vector<signed char >& delta3m);
	void teachdel3mam(vector<signed char >& delta4m, int32_t& Quoter, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Weights3m, vector<vector<signed char>>& Outputs3m, vector<signed char >& delta3, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);
	void teach3mam(int32_t& Quoter, vector<vector<signed char>>& Outputs3m, signed char alpham, vector<vector<signed char>>& Weights3m, vector<signed char >& delta3m, signed char*& vec_d, signed char*& vec_a);

};