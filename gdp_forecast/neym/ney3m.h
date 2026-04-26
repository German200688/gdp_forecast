#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer3m
{
protected:
	void neyronoutindadd3m(vector<vector<double>>& Outputs3m, vector<int64_t>& Count, int64_t& CountOutputs2);
	void neyronoutqadd3m(vector<vector<double>>& Outputs3m, int64_t Quoter);
	void weightsaddl23m(vector<vector<double>>& Weights3m, int64_t ney1);
	void weightsaddl33m(vector<vector<double>>& Weights3m, int64_t CountWeights3);
	



public:
	void summneyquoter3m(vector<int64_t>& Count, vector<vector<double>>& Outputs2m, vector<vector<double>>& Weights3m, vector<vector<double>>& Outputs3m, int64_t Quoter);
	void summneyall3m(vector<int64_t>& Count, vector<vector<double>>& Outputs2m, vector<vector<double>>& Weights3m, vector<vector<double>>& Outputs3m);
	void teachdel3m(vector<double >& delta4m, int64_t& Quoter, vector<vector<double>>& Weights4m, vector<vector<double>>& Weights3m, vector<vector<double>>& Outputs3m, vector<double >& delta3m);
	void teach3m(int64_t& Quoter, vector<vector<double>>& Outputs3m, double alpha, vector<vector<double>>& Weights3m, vector<double >& delta3m);
	void teachdel3mam(vector<double >& delta4m, int64_t& Quoter, vector<vector<double>>& Weights4m, vector<vector<double>>& Weights3m, vector<vector<double>>& Outputs3m, vector<double >& delta3, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d);
	void teach3mam(int64_t& Quoter, vector<vector<double>>& Outputs3m, double alpham, vector<vector<double>>& Weights3m, vector<double >& delta3m, double*& vec_d, double*& vec_a);

};