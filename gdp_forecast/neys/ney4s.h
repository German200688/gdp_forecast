#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer4
{
protected:
	void neyronoutindadd4(vector<vector<signed char>>& Outputs4, vector<int64_t>& Count, int64_t& CountOutputs4);
	void neyronoutqadd4(vector<vector<signed char>>& Outputs4, int64_t Quoter);
	void weightsaddl34(vector<vector<signed char>>& Weights4, int64_t ney1);
	void weightsaddl44(vector<vector<signed char>>& Weights4, int64_t CountWeights4);




public:
	void summneyquoter4(vector<int64_t>& Count, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, int64_t Quoter);
	void summneyall4(vector<int64_t>& Count, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4);
	void teachdel4(vector<signed char >& delta5, int64_t& Quoter, vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<signed char >& delta4);
	void teach4(int64_t& Quoter, vector<vector<signed char>>& Outputs4, signed char alpha, vector<vector<signed char>>& Weights4, vector<signed char >& delta4);
	void teachdel4ma(vector<signed char >& delta5, int64_t& Quoter, vector<vector<signed char>>& Weights5, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<signed char >& delta4, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& ab);
	void teach4ma(int64_t& Quoter, vector<vector<signed char>>& Outputs4, signed char alpha, vector<vector<signed char>>& Weights4, vector<signed char >& delta4, signed char*& vec_d, signed char*& vec_a);

};