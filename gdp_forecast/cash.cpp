#include <chrono>
#include <iostream>
#include <vector>
#include <cstdint>
#include "kernel/OB1.h"

#pragma once

void cashquoter(int64_t quot, vector<signed char>& TheoWeights, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1)
{
	Signch obj1;
	
	int64_t t2 = indicatDateInc[0].size() - 1;
	if (quot > t2) { return; }
	int64_t t1 = indicatDateInc.size();

	for (int64_t i = 0; i < t1; i++)
	{
		signed char t3 = TheoWeights[i];
        signed char t4 = indicatDateInc[i][quot];
		signed char t5 = obj1.multtt(t3, t4);
		Cash1[i][quot] = t5;

	}

}


void cashall(vector<signed char>& TheoWeights, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1)
{
	int64_t quot = 0;
	int64_t t0 = indicatDateInc[0].size();
	while (quot < t0)

	{
		cashquoter(quot, TheoWeights, indicatDateInc, Cash1);

		quot++;
	}


}