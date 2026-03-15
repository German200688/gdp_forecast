
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
	/*
	HANDLE Thread0 = GetCurrentThread();
	DWORD_PTR MyThread0 = 0x02;
	DWORD_PTR previousMask = SetThreadAffinityMask(Thread0, MyThread0);
	*/
	//setlocale(LC_ALL, "RU");
	locale::global(locale("ru_RU.UTF-8"));
	system("chcp 65001");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	
	Config obj1;
	nvidia obj4;

	vector<string> indicators = {}; //параметры
	vector<signed char> TheoWeights = {}; //весы индикаторов
	vector<vector<double>> indicatDate = {}; //данные индикатора
	vector<vector<signed char>> indicatDateInc = {}; //прирост за квартал
	vector<int64_t> Count = {}; //служебный
	vector<vector<signed char>> Cash1; //драфтовые параметры
	vector<signed char> Weights1; //слой
	vector<vector<signed char>> Weights2; //слой
	vector<vector<signed char>> Weights3; //слой
	vector<vector<signed char>> Weights4; //слой
	vector<vector<signed char>> Weights5; //слой
	vector<vector<signed char>> Outputs1; // исходы
	vector<vector<signed char>> Outputs2; // исходы
	vector<vector<signed char>> Outputs3; // исходы
	vector<vector<signed char>> Outputs4; // исходы

	vector<signed char> Weights1m; //слой
	vector<vector<signed char>> Weights2m; //слой
	vector<vector<signed char>> Weights3m; //слой
	vector<vector<signed char>> Weights4m; //слой
	vector<vector<signed char>> Weights5m; //слой
	vector<vector<signed char>> Outputs1m; // исходы
	vector<vector<signed char>> Outputs2m; // исходы
	vector<vector<signed char>> Outputs3m; // исходы
	vector<vector<signed char>> Outputs4m; // исходы

	string linkfile = "";
	signed char alpha = 100;
	int64_t iterationney = 1;
	int64_t iteration = 1;

	map<string, string> configf;

	configf = obj1.configread();
	linkfile = configf["linkfile:"];
	string alphas = configf["alpha:"];
	int64_t alphai = stoi(alphas);
	alpha = static_cast<signed char>(alphai);
	string iterationneys = configf["iterationney:"];
	iterationney = stoi(iterationneys);
	string iterationst = configf["iteration:"];
	iteration = stoi(iterationst);

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
		linkfile
		);
#ifdef _DEBUG
	
	obj4.nvidiadata();
#endif

	cout << "\033[31m      WELCOME TO" << endl;
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
		iteration
		
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
		linkfile
		);

	 




	return 0;
}
