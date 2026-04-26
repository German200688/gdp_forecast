#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer4m
{
protected:
	void neyronoutindadd4m(vector<vector<double>>& Outputs4m, vector<int64_t>& Count, int64_t& CountOutputs4);
	void neyronoutqadd4m(vector<vector<double>>& Outputs4m, int64_t Quoter);
	void weightsaddl34m(vector<vector<double>>& Weights4m, int64_t ney1);
	void weightsaddl44m(vector<vector<double>>& Weights4m, int64_t CountWeights4);




public:
	void summneyquoter4m(vector<int64_t>& Count, vector<vector<double>>& Outputs3m, vector<vector<double>>& Weights4m, vector<vector<double>>& Outputs4m, int64_t Quoter);
	void summneyall4m(vector<int64_t>& Count, vector<vector<double>>& Outputs3m, vector<vector<double>>& Weights4m, vector<vector<double>>& Outputs4m);
	void teachdel4m(vector<double >& delta5m, int64_t& Quoter, vector<vector<double>>& Weights5m, vector<vector<double>>& Weights4m, vector<vector<double>>& Outputs4m, vector<double >& delta4m);
	void teach4m(int64_t& Quoter, vector<vector<double>>& Outputs4m, double alpham, vector<vector<double>>& Weights4m, vector<double >& delta4m);
	void teachdel4mam(vector<double >& delta5, int64_t& Quoter, vector<vector<double>>& Weights5, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, vector<double >& delta4, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d);
	void teach4mam(int64_t& Quoter, vector<vector<double>>& Outputs4m, double alpham, vector<vector<double>>& Weights4m, vector<double >& delta4m, double*& vec_d, double*& vec_a);

};