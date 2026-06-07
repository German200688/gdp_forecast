
#include <windows.h>
#include <iostream>
#include <string>
#include <chrono>
#include "datapop.cpp"
#include "bp1.cpp"
#include "neys/ney1s.h"
#include "neys/ney2s.h"
#include <clocale>
#include <cstdint>
#include "kernel/config.h"
#include "kernel/other.h"
#include "kernel/nvidia/nvidiadate.h"


using namespace std;

int main()
{
	SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS);
	
	HANDLE Thread0 = GetCurrentThread();
	DWORD_PTR MyThread0 = 0x02;
	DWORD_PTR previousMask = SetThreadAffinityMask(Thread0, MyThread0);
	
	//setlocale(LC_ALL, "RU");
	
	locale::global(locale("ru_RU.UTF-8"));
	system("chcp 65001");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	Config obj1;
	nvidia obj4;
	Other other;
	mutex offlinethread;
	vector<string> indicators = {}; //параметры
	vector<double> TheoWeights = {}; //весы индикаторов
	vector<vector<double>> indicatDate = {}; //данные индикатора
	vector<vector<double>> indicatDateInc = {}; //прирост за квартал
	vector<int64_t> Count = {}; //служебный
	vector<double> incre = {}; //служебный
	vector<vector<double>> Cash1; //драфтовые параметры
	vector<double> Weights1; //слой
	vector<vector<double>> Weights2; //слой
	vector<vector<double>> Weights3; //слой
	vector<vector<double>> Weights4; //слой
	vector<vector<double>> Weights5; //слой
	vector<vector<double>> Outputs1; // исходы
	vector<vector<double>> Outputs2; // исходы
	vector<vector<double>> Outputs3; // исходы
	vector<vector<double>> Outputs4; // исходы
	vector<double> Weights1m; //слой
	vector<vector<double>> Weights2m; //слой
	vector<vector<double>> Weights3m; //слой
	vector<vector<double>> Weights4m; //слой
	vector<vector<double>> Weights5m; //слой
	vector<vector<double>> Outputs1m; // исходы
	vector<vector<double>> Outputs2m; // исходы
	vector<vector<double>> Outputs3m; // исходы
	vector<vector<double>> Outputs4m; // исходы
	bool stop = false;
	bool teach = false;
	double stopl = 0.01;
	int64_t teach_count = 10000;


	string linkfile = "";
	double alpha = 0.21;
	int64_t iterationney = 1;
	int64_t iteration = 1;

	map<string, string> configf;

	configf = obj1.configread();
	linkfile = configf["linkfile:"];
	string alphas = configf["alpha:"];
	//int64_t alphai = stoi(alphas);
	alpha = stod(alphas);//static_cast<double>(alphai);
	string iterationneys = configf["iterationney:"];
	iterationney = stoi(iterationneys);
	string iterationst = configf["iteration:"];
	iteration = stoi(iterationst);
	
	string stopst = configf["stop:"];
	stop = other.stringToBool(stopst);

	string stoplst = configf["stop_level:"];
	stopl = stod(stoplst);

	string teachst = configf["teach:"];
	teach = other.stringToBool(teachst);

	string teach_countst = configf["teach_count:"];
	teach_count = stoi(teach_countst);






	

	beginfile(indicators, TheoWeights, indicatDate, indicatDateInc, Cash1, Count, Weights1, Outputs1, Weights2, Outputs2, Outputs3, Outputs4, Weights3, Weights4, Weights5,
		Weights1m,
		Weights2m,
		Weights3m,
		Weights4m,
		Weights5m,
		Outputs1m,
		Outputs2m,
		Outputs3m,
		Outputs4m,
		linkfile,
		incre
		);
		
	
#ifdef _DEBUG
	
	obj4.nvidiadata();
#endif

	cout << "\033[31m      WELCOME TO 1.2.0" << endl;
	Other objh;
	

	objh.start();


	bpv(indicators, TheoWeights, indicatDate, indicatDateInc, Cash1, Count, Weights1, Outputs1, Weights2, Outputs2, Weights3, Outputs3, Weights4, Outputs4, Weights5,
		
		Weights1m, 
	Weights2m, 
	Weights3m, 
	Weights4m, 
	Weights5m, 
	Outputs1m, 
	Outputs2m, 
	Outputs3m, 
	Outputs4m, 
		alpha,
		iterationney,
		iteration,
		stop,
		stopl,
		teach,
		teach_count,
		incre
		);
		
	cout << "Идет процесс сохранения данных. Пожалуйста дождитесь окончания..." << endl;

	endfile(indicators, TheoWeights, indicatDate, indicatDateInc, Cash1, Count, Weights1, Outputs1, Weights2, Outputs2, Outputs3, Weights3, Outputs4, Weights4, Weights5,
		Weights1m,
		Weights2m,
		Weights3m,
		Weights4m,
		Weights5m,
		Outputs1m,
		Outputs2m,
		Outputs3m,
		Outputs4m,
		linkfile,
		incre
		);

	 




	return 0;
}
