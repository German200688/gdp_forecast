#include <chrono>
#include <cstdint>

#pragma once

using namespace std;


class layer3
{
protected:
	void neyronoutindadd3(vector<vector<double>>& Outputs3, vector<int64_t>& Count, int64_t& CountOutputs2);
	void neyronoutqadd3(vector<vector<double>>& Outputs3, int64_t Quoter);
	void weightsaddl23(vector<vector<double>>& Weights3, int64_t ney1);
	void weightsaddl33(vector<vector<double>>& Weights3, int64_t CountWeights3);
	



public:
	void summneyquoter3(vector<int64_t>& Count, vector<vector<double>>& Outputs2, vector<vector<double>>& Weights3, vector<vector<double>>& Outputs3, int64_t Quoter);
	void summneyall3(vector<int64_t>& Count, vector<vector<double>>& Outputs2, vector<vector<double>>& Weights3, vector<vector<double>>& Outputs3);
	void teachdel3(vector<double >& delta4, int64_t& Quoter, vector<vector<double>>& Weights4, vector<vector<double>>& Weights3, vector<vector<double>>& Outputs3, vector<vector<double>>& Outputs2, vector<double >& delta3, double alpha);
	void teach3(int64_t& Quoter, vector<vector<double>>& Outputs3, double alpha, vector<vector<double>>& Weights3, vector<double >& delta3);
	void teachdel3ma(vector<double >& delta4, int64_t& Quoter, vector<vector<double>>& Weights4, vector<vector<double>>& Weights3, vector<vector<double>>& Outputs3, vector<vector<double>>& Outputs2, vector<double >& delta3, double*& dvec_a23, double*& dvec_b23, double alpha);
	void teach3ma(int64_t& Quoter, vector<vector<double>>& Outputs3, double alpha, vector<vector<double>>& Weights3, vector<double >& delta3, double*& vec_d, double*& vec_a, double*& vec_b);

};