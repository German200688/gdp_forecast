//операция с нейронами
#pragma once

#include <chrono>
#include <cstdint>

using namespace std;

class Neyron
{
public:
	double valueneyTwoOne(vector<double>& neyronin, vector<double>& weight);
	vector<double> valueneyOneTwo(vector<double>& neyronin, vector<double>& weight);
	vector <double> teacherOneTwo(vector <double> weight1, double input, int64_t ig, int64_t ip); //вектор значений, значение входного нейрона, какой результат надо, какой вернула сеть
	double valueneyTwoOner(vector<double>& neyronin, vector<double>& weight); //с релу 
	vector<double> valueneyOneTwor(vector<double>& neyronin, vector<double>& weight); //с релу
	vector<double > deltaout(vector<double >& delta, const double& neyrontest, const double& neyrontestres); //дельта для постеднего ряда
	void dellayerlast(vector<vector<double>>& Weights3, int64_t Quoter, vector<vector<double>>& Outputs2, const double& delta); //пересчет весов последнего ряда
	double deltaMiddle(int64_t Weightslsize, vector<double >& Weights, vector<double >& delta, double& alpha, double& Outputs);
	vector<double > MiddleTeach(vector<double >& Weights, double& Output, double& delta, int64_t& size, double& alpha);
	double valueneyTwoOnerm(vector<double>& neyronin, vector<double>& weight);
	vector<double> valueneyOneTworm(vector<double>& neyronin, vector<double>& weight);
	double deltaMiddlem(int64_t Weightslsize, vector<double >& Weights, vector<double >& delta, double& alpha, double& Outputs);
	double deltafin(int64_t Weightslsize, double& Weight, double& delta, double& alpha, double& Outputs);
	double deltafinm(int64_t Weightslsize, double& Weight, double& delta, double& alpha, double& Outputs);
};