#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer4
{
protected:
	void neyronoutindadd4(vector<vector<double>>& Outputs4, vector<int64_t>& Count, int64_t& CountOutputs4);
	void neyronoutqadd4(vector<vector<double>>& Outputs4, int64_t Quoter);
	void weightsaddl34(vector<vector<double>>& Weights4, int64_t ney1);
	void weightsaddl44(vector<vector<double>>& Weights4, int64_t CountWeights4);




public:
	void summneyquoter4(vector<int64_t>& Count, vector<vector<double>>& Outputs3, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, int64_t Quoter);
	void summneyall4(vector<int64_t>& Count, vector<vector<double>>& Outputs3, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4);
	void teachdel4(vector<double >& delta5, int64_t& Quoter, vector<vector<double>>& Weights5, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, vector<double >& delta4);
	void teach4(int64_t& Quoter, vector<vector<double>>& Outputs4, double alpha, vector<vector<double>>& Weights4, vector<double >& delta4);
	void teachdel4ma(vector<double >& delta5, int64_t& Quoter, vector<vector<double>>& Weights5, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, vector<double >& delta4, double*& vec_a, double*& vec_b, double*& vec_c, double*& ab);
	void teach4ma(int64_t& Quoter, vector<vector<double>>& Outputs4, double alpha, vector<vector<double>>& Weights4, vector<double >& delta4, double*& vec_d, double*& vec_a);

};