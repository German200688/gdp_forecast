#include <chrono>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>


#pragma once


double cashmean(const vector<double>& cashq)
{
	double t0 = std::accumulate(cashq.begin(), cashq.end(), 0.0);
	double t1 = cashq.size();
	double mean = t0 / t1;
	return mean;
}

double cashvar(const vector<double>& cashq, const double& mean)
{
	

	double t0 = 0.0;
	for (double t1 : cashq) {
		t0 += (t1 - mean) * (t1 - mean);
	}
	double t2 = t0 / cashq.size();
	double var = std::sqrt(t2);
	return var;

}


void cashquoter(int64_t quot, vector<double>& TheoWeights, vector<vector<double>>& indicatDateInc, vector<vector<double>>& Cash1)
{
//	Signch obj1;
	
	int64_t t2 = indicatDateInc[0].size() - 1;
	if (quot > t2) { return; }
	int64_t t1 = indicatDateInc.size();
	vector<double> cashq;
	//cashq.reserve(indicatDateInc[quot].size());
	for (int64_t i = 0; i < t1; i++)
	{
		double t3 = TheoWeights[i] / 100;
		double t4 = indicatDateInc[i][quot];

		double t5 = t3 * t4;
		//obj1.multtt(t3, t4);
		cashq.push_back(t5);

	}

	

	double mean = cashmean(cashq);
	double var = cashvar(cashq, mean);


	double t100 = 1;


	for (int64_t i = 0; i < t1; i++)
	{
        
		double t6 = cashq[i];
		double t7 = t6 - mean;
		double t8 = t7 / var;
		double t9 = t8 / t100;
			//obj1.multtt(t3, t4);
		Cash1[i][quot] = t9;

	}

}


void cashall(vector<double>& TheoWeights, vector<vector<double>>& indicatDateInc, vector<vector<double>>& Cash1)
{
	int64_t quot = 0;
	int64_t t0 = indicatDateInc[0].size();
	while (quot < t0)

	{
		cashquoter(quot, TheoWeights, indicatDateInc, Cash1);

		quot++;
	}


}