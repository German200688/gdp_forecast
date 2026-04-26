
#include <chrono>
#include <cstdint>


using namespace std;


class Relu
{
public:
	double relup(double& reluin);
	vector<double> reluvp(vector<double>& reluinv);
	double reludivp(double& reluin);
	double reludivp(const double& reludivin);
	vector<double> reluvp(vector<double> reludivinv);
	double relum(double& reluin);
	vector <double> reluvm(vector <double>& reluinv);
	double reludivm(const double& reludivin);
	vector <double> reluvm(vector <double> reludivinv);

};



double Relu::reludivp(double& reluin)
{
	if (reluin > 0) return 100;
	else return 1; //0


}


double Relu::relup(double& reluin)
{
	if (reluin > 0) return reluin;
	else return 1; //0;



}


vector<double> Relu::reluvp(vector<double>& reluinv)
{
	int64_t t0 = reluinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reluinv[i] <= 0) reluinv[i] = 1; //0;

	}

	return reluinv;

}



double Relu::reludivp(const double& reludivin)
{
	if (reludivin > 0) return 100;
	else return 1; //0


}


vector<double> Relu::reluvp(vector<double> reludivinv)
{
	int64_t t0 = reludivinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reludivinv[i] < 0) reludivinv[i] = 1; //0;

	}

	return reludivinv;

}







double Relu::relum(double& reluin)
{
	if (reluin < 0) return reluin;
	else return 1; //0;


}


vector <double> Relu::reluvm(vector <double>& reluinv)
{
	int64_t t0 = reluinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reluinv[i] >= 0) reluinv[i] = 1;//0;

	}

	return reluinv;

}



double Relu::reludivm(const double& reludivin)
{
	if (reludivin < 0) return 100;
	else return 1; //0


}


vector <double> Relu::reluvm(vector <double> reludivinv)
{
	int64_t t0 = reludivinv.size();

	for (int64_t i = 0; i < t0; i++)

	{
		if (reludivinv[i] >= 0) reludivinv[i] = 1; //0;

	}

	return reludivinv;

}
