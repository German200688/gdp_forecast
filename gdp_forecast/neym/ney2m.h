#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer2m
{
protected:
	void neyronoutindadd2m(vector<vector<double>>& Outputs2m, vector<int64_t>& Count, int64_t& CountOutputs1);
	void neyronoutqadd2m(vector<vector<double>>& Outputs2m, int64_t Quoter);
	void weightsaddl12m(vector<vector<double>>& Weights2m, int64_t ney1);
	void weightsaddl22m(vector<vector<double>>& Weights2m, int64_t CountWeights2);
	



public:
	void summneyquoter2m(vector<int64_t>& Count, vector<vector<double>>& Outputs1m, vector<vector<double>>& Weights2m, vector<vector<double>>& Outputs2m, int64_t Quoter);
	void summneyall2m(vector<int64_t>& Count, vector<vector<double>>& Outputs1m, vector<vector<double>>& Weights2m, vector<vector<double>>& Outputs2m);
	void teachdel2m(vector<double >& delta3m, int64_t& Quoter, vector<vector<double>>& Weights3m, vector<vector<double>>& Weights2m, vector<vector<double>>& Outputs2m, vector<vector<double>>& Outputs1m, vector<double >& delta2m, double& alpha);
	void teach2m(int64_t& Quoter, vector<vector<double>>& Outputs2m, double alpha, vector<vector<double>>& Weights2m, vector<double >& delta2m);
	void teachdel2mam(vector<double >& delta3m, int64_t& Quoter, vector<vector<double>>& Weights3m, vector<vector<double>>& Weights2m, vector<vector<double>>& Outputs2m, vector<vector<double>>& Outputs1m, vector<double >& delta2m, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d, double& alpha);
	void teach2mam(int64_t& Quoter, vector<vector<double>>& Outputs2m, double alpham, vector<vector<double>>& Weights2m, vector<double >& delta2m, double*& vec_d, double*& vec_a, double*& vec_b);


};