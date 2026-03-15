#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer3
{
protected:
	void neyronoutindadd3(vector<vector<signed char>>& Outputs3, vector<int64_t>& Count, int64_t& CountOutputs2);
	void neyronoutqadd3(vector<vector<signed char>>& Outputs3, int64_t Quoter);
	void weightsaddl23(vector<vector<signed char>>& Weights3, int64_t ney1);
	void weightsaddl33(vector<vector<signed char>>& Weights3, int64_t CountWeights3);
	



public:
	void summneyquoter3(vector<int64_t>& Count, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, int64_t Quoter);
	void summneyall3(vector<int64_t>& Count, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3);
	void teachdel3(vector<signed char >& delta4, int64_t& Quoter, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<signed char >& delta3);
	void teach3(int64_t& Quoter, vector<vector<signed char>>& Outputs3, signed char alpha, vector<vector<signed char>>& Weights3, vector<signed char >& delta3);
	void teachdel3ma(vector<signed char >& delta4, int64_t& Quoter, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<signed char >& delta3, signed char*& dvec_a23, signed char*& dvec_b23);
	void teach3ma(int64_t& Quoter, vector<vector<signed char>>& Outputs3, signed char alpha, vector<vector<signed char>>& Weights3, vector<signed char >& delta3, signed char*& vec_d, signed char*& vec_a);

};