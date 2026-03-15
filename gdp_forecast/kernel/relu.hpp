
#include <chrono>
#include <cstdint>


using namespace std;


class Relu
{
public:
	signed char relup(signed char& reluin);
	vector<signed char> reluvp(vector<signed char>& reluinv);
	signed char reludivp(signed char& reluin);
	signed char reludivp(const signed char& reludivin);
	vector<signed char> reluvp(vector<signed char> reludivinv);
	signed char relum(signed char& reluin);
	vector <signed char> reluvm(vector <signed char>& reluinv);
	signed char reludivm(const signed char& reludivin);
	vector <signed char> reluvm(vector <signed char> reludivinv);

};



signed char Relu::reludivp(signed char& reluin)
{
	if (reluin > 0) return 100;
	else return 0;


}


signed char Relu::relup(signed char& reluin)
{
	if (reluin > 0) return reluin;
	else return 0;


}


vector<signed char> Relu::reluvp(vector<signed char>& reluinv)
{
	int64_t t0 = reluinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reluinv[i] < 0) reluinv[i] = 0;

	}

	return reluinv;

}



signed char Relu::reludivp(const signed char& reludivin)
{
	if (reludivin > 0) return 100;
	else return 0;


}


vector<signed char> Relu::reluvp(vector<signed char> reludivinv)
{
	int64_t t0 = reludivinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reludivinv[i] < 0) reludivinv[i] = 0;

	}

	return reludivinv;

}







signed char Relu::relum(signed char& reluin)
{
	if (reluin < 0) return reluin;
	else return 0;


}


vector <signed char> Relu::reluvm(vector <signed char>& reluinv)
{
	int64_t t0 = reluinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reluinv[i] > 0) reluinv[i] = 0;

	}

	return reluinv;

}



signed char Relu::reludivm(const signed char& reludivin)
{
	if (reludivin < 0) return 1;
	else return 0;


}


vector <signed char> Relu::reluvm(vector <signed char> reludivinv)
{
	int64_t t0 = reludivinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reludivinv[i] > 0) reludivinv[i] = 0;

	}

	return reludivinv;

}
