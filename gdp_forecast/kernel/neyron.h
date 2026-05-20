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
	vector <double> teacherOneTwo(vector <double> weight1, double input, int64_t ig, int64_t ip, double alpha); //вектор значений, значение входного нейрона, какой результат надо, какой вернула сеть
	double valueneyTwoOner(vector<double>& neyronin, vector<double>& weight);
	double valueneyTwoOner2(vector<double>& neyronin, vector<double>& weight); //с релу 
	double valueneyTwoOner3(vector<double>& neyronin, vector<double>& weight); //с релу 
	double valueneyTwoOner4(vector<double>& neyronin, vector<double>& weight);
	vector<double> valueneyOneTwor(vector<double>& neyronin, vector<double>& weight, double a); //с релу
	vector<double > deltaout(vector<double >& delta, const double& neyrontest, const double& neyrontestres); //дельта для постеднего ряда
	void dellayerlast(vector<vector<double>>& Weights3, int64_t Quoter, vector<vector<double>>& Outputs2, const double& delta, double alpha); //пересчет весов последнего ряда
	double deltaMiddle(int64_t Weightslsize, vector<double >& Weights, vector<double >& delta, double& alpha, double& Outputs, double& OutputD4f);
	vector<double > MiddleTeach(vector<double >& Weights, vector<double >& Output, double& delta, int64_t& size, double& alpha);
	double valueneyTwoOnerm(vector<double>& neyronin, vector<double>& weight);
	vector<double> valueneyOneTworm(vector<double>& neyronin, vector<double>& weight);
	double deltaMiddlem(int64_t Weightslsize, vector<double >& Weights, vector<double >& delta, double& alpha, double& Outputs);
	double deltafin(int64_t Weightslsize, double& Weight, double& delta, double& alpha, double& Outputs);
	double deltafinm(int64_t Weightslsize, double& Weight, double& delta, double& alpha, double& Outputs);
	double valueneyTwoOnerD(vector<double>& neyronin, vector<double>& weight);
	double valueneyTwoOner4m(vector<double>& neyronin, vector<double>& weight);
};