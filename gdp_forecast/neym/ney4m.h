#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer4m
{
protected:
	void neyronoutindadd4m(vector<vector<signed char>>& Outputs4m, vector<int64_t>& Count, int64_t& CountOutputs4);
	void neyronoutqadd4m(vector<vector<signed char>>& Outputs4m, int64_t Quoter);
	void weightsaddl34m(vector<vector<signed char>>& Weights4m, int64_t ney1);
	void weightsaddl44m(vector<vector<signed char>>& Weights4m, int64_t CountWeights4);




public:
	void summneyquoter4m(vector<int64_t>& Count, vector<vector<signed char>>& Outputs3m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m, int64_t Quoter);
	void summneyall4m(vector<int64_t>& Count, vector<vector<signed char>>& Outputs3m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m);
	void teachdel4m(vector<signed char >& delta5m, int64_t& Quoter, vector<vector<signed char>>& Weights5m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m, vector<signed char >& delta4m);
	void teach4m(int64_t& Quoter, vector<vector<signed char>>& Outputs4m, signed char alpham, vector<vector<signed char>>& Weights4m, vector<signed char >& delta4m);
	void teachdel4mam(vector<signed char >& delta5, int64_t& Quoter, vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<signed char >& delta4, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);
	void teach4mam(int64_t& Quoter, vector<vector<signed char>>& Outputs4m, signed char alpham, vector<vector<signed char>>& Weights4m, vector<signed char >& delta4m, signed char*& vec_d, signed char*& vec_a);

};