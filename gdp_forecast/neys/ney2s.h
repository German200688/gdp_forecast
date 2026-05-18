#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer2
{
protected:
	void neyronoutindadd2(vector<vector<double>>& Outputs2, vector<int64_t >& Count, int64_t & CountOutputs1);
	void neyronoutqadd2(vector<vector<double>>& Outputs2, int64_t Quoter);
	void weightsaddl12(vector<vector<double>>& Weights2, int64_t ney1);
	void weightsaddl22(vector<vector<double>>& Weights2, int64_t CountWeights2);
	



public:
	void summneyquoter2(vector<int64_t >& Count, vector<vector<double>>& Outputs1, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2, int64_t Quoter);
	void summneyall2(vector<int64_t >& Count, vector<vector<double>>& Outputs1, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2);
	void teachdel2(vector<double >& delta3, int64_t & Quoter, vector<vector<double>>& Weights3, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2, vector<vector<double>>& Outputs1, vector<double >& delta2, double alpha);
	void teach2(int64_t & Quoter, vector<vector<double>>& Outputs2, double alpha, vector<vector<double>>& Weights2, vector<double >& delta2);
	void teachdel2ma(vector<double >& delta3, int64_t& Quoter, vector<vector<double>>& Weights3, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2, vector<vector<double>>& Outputs1, vector<double >& delta2, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d, double alpha);
	void teach2ma(int64_t& Quoter, vector<vector<double>>& Outputs2, double alpha, vector<vector<double>>& Weights2, vector<double >& delta2, double*& vec_d, double*& vec_a, double*& vec_b);

};