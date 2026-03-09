#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer3
{
protected:
	void neyronoutindadd3(vector<vector<signed char>>& Outputs3, vector<int32_t>& Count, int32_t& CountOutputs2);
	void neyronoutqadd3(vector<vector<signed char>>& Outputs3, int32_t Quoter);
	void weightsaddl23(vector<vector<signed char>>& Weights3, int32_t ney1);
	void weightsaddl33(vector<vector<signed char>>& Weights3, int32_t CountWeights3);
	



public:
	void summneyquoter3(vector<int32_t>& Count, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, int32_t Quoter);
	void summneyall3(vector<int32_t>& Count, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3);
	void teachdel3(vector<signed char >& delta4, int32_t& Quoter, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<signed char >& delta3);
	void teach3(int32_t& Quoter, vector<vector<signed char>>& Outputs3, signed char alpha, vector<vector<signed char>>& Weights3, vector<signed char >& delta3);
	void teachdel3ma(vector<signed char >& delta4, int32_t& Quoter, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<signed char >& delta3, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);

};