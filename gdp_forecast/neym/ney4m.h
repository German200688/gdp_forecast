#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer4m
{
protected:
	void neyronoutindadd4m(vector<vector<signed char>>& Outputs4m, vector<int32_t>& Count, int32_t& CountOutputs4);
	void neyronoutqadd4m(vector<vector<signed char>>& Outputs4m, int32_t Quoter);
	void weightsaddl34m(vector<vector<signed char>>& Weights4m, int32_t ney1);
	void weightsaddl44m(vector<vector<signed char>>& Weights4m, int32_t CountWeights4);




public:
	void summneyquoter4m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs3m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m, int32_t Quoter);
	void summneyall4m(vector<int32_t>& Count, vector<vector<signed char>>& Outputs3m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m);
	void teachdel4m(vector<signed char >& delta5m, int32_t& Quoter, vector<vector<signed char>>& Weights5m, vector<vector<signed char>>& Weights4m, vector<vector<signed char>>& Outputs4m, vector<signed char >& delta4m);
	void teach4m(int32_t& Quoter, vector<vector<signed char>>& Outputs4m, signed char alpham, vector<vector<signed char>>& Weights4m, vector<signed char >& delta4m);
};