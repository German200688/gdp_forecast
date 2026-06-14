#include <windows.h>
#include <string>
#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iterator>
#include <regex>
#include <map>
#include <cstdint>
#include <thread>
#include <mutex>
#include "kernel/other.h"
#include "kernel/nvidia/cuda/nvidiac.h"
#include "bp3.cpp"
#include "bp4.cpp"



#pragma once

using namespace std;
mutex offlinethread;



void teachoffline(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<double>& TheoWeights, vector<vector<double>>& indicatDateInc, vector<vector<double>> Cash1, vector<double>& Weights1, vector<int64_t>& Count, vector<vector<double>> Outputs1, vector<vector<double>>& Weights2, vector<vector<double>> Outputs2, vector<vector<double>>& Weights3, vector<vector<double>> Outputs3, vector<vector<double>>& Weights4, vector<vector<double>> Outputs4, vector<vector<double>>& Weights5, double result1, double result2, double result,
	vector<double>& Weights1m,
	vector<vector<double>>& Weights2m,
	vector<vector<double>>& Weights3m,
	vector<vector<double>>& Weights4m,
	vector<vector<double>>& Weights5m,
	vector<vector<double>>& Outputs1m,
	vector<vector<double>>& Outputs2m,
	vector<vector<double>>& Outputs3m,
	vector<vector<double>>& Outputs4m,
	const double& alpha,
	const int64_t& iterationney,
	const int64_t& iteration,
	vector <vector <double>> dates,
	vector<double>& vecdate,
double& indicс,
double& theorс,
int64_t& percfff,
uint64_t& tact71,
vector<double>& incre,
const bool teach,
const int64_t& teach_count,
bool& stop,
double& stopl
)
{
	
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
	Other obj3;
	nvidiac obj1;

	double* dvec_a1 = nullptr, * dvec_b1 = nullptr, * dvec_c1 = nullptr, * vec_a23 = nullptr, * vec_b23 = nullptr, * dvec_a4 = nullptr, * dvec_b4 = nullptr, * dvec_c4 = nullptr, * vec_a4 = nullptr, * vec_b4 = nullptr, * ab = nullptr, *vec_c23 = nullptr;
	//int N1, int N23, int N4, int N44, double*& ab

	int64_t Quoter = dates[0][0];



	unsigned long long tact1 = __rdtsc();
	this_thread::sleep_for(std::chrono::seconds(1));
	unsigned long long tact2 = __rdtsc();
	unsigned long long tactraw = (tact2 - tact1) / 1000;
	std::cout << tactraw << endl;
	{
		lock_guard<mutex> lock(offlinethread);



		calcgdpteach(indicators, indicatDate, TheoWeights, indicatDateInc, Cash1, Weights1, Count, Outputs1, Weights2, Outputs2, Quoter, Weights3, Outputs3, Weights4, Outputs4, Weights5, result1, result2, result,
			Weights1m,
			Weights2m,
			Weights3m,
			Weights4m,
			Weights5m,
			Outputs1m,
			Outputs2m,
			Outputs3m,
			Outputs4m,
			incre

		);
	}
	
	




	int64_t N1 = 3;
	int64_t N23 = Weights2[0].size();
	int64_t N44 = Weights4[0].size();
	int64_t N4 = Weights5[0].size();


	obj1.addobj(dvec_a1, dvec_b1, dvec_c1, vec_a23, vec_b23, dvec_a4, dvec_b4, dvec_c4, vec_a4, vec_b4, N1, N23, N4, N44, ab, vec_c23);
	int64_t t12 = dates.size();
	int64_t percraw = iterationney * t12 * iteration;
	double percdr = 0;
	int64_t t666 = 1;




	unsigned long long tact5 = 0;

	vector<string> indicatorstemp;
	vector<vector<double>> indicatDatetemp;
	vector<double> TheoWeightstemp;
	vector<vector<double>> indicatDateInctemp;
	vector<double> Weights1temp;
	vector<int64_t> Counttemp;
	vector<double> Weights1mtemp;
	vector<vector<double>> Outputs1temp, Outputs2temp, Outputs3temp, Outputs4temp;
	vector<vector<double>> Outputs1mtemp, Outputs2mtemp, Outputs3mtemp, Outputs4mtemp;


	for (int64_t i0 = 0; i0 < iteration; i0++)
	{
		double err4 = 0;
		double err3 = 0;
		double q2 = 0;
		double q3 = 0;
		double q4 = 0;
		double q5 = 0;
		int64_t tea0 = 0;
		double q1 = stopl;
		
		for (int64_t i1 = 0; i1 < t12; i1++)
		{
			double err2 = 0;
			int64_t quot = dates[i1][0];
			int64_t resi = dates[i1][1];
			//cout << resi << endl;
			double res = static_cast<double>(resi);

//создаем временные массивы
			/*
	vector<string>& indicators, ++
		vector<vector<double>>& indicatDate, ++
		vector<double>& TheoWeights, ++
		vector<vector<double>>& indicatDateInc, ++
		vector<vector<double>>& Cash1, ++
		vector<double> Weights1, ++
		vector<int64_t>& Count, ++
		vector<vector<double>>& Outputs1, ++
		vector<vector<double>>& Weights2, -
		vector<vector<double>>& Outputs2, ++
		vector<vector<double>>& Weights3, -
		vector<vector<double>>& Outputs3, ++
		vector<vector<double>>& Weights4, -
		vector<vector<double>>& Outputs4, ++
		vector<vector<double>>& Weights5, -
		double& result1, +
		double& result2, +
		double& result,+
		vector<double>& Weights1m, ++
		vector<vector<double>>& Weights2m,-
		vector<vector<double>>& Weights3m, -
		vector<vector<double>>& Weights4m, -
		vector<vector<double>>& Weights5m,-
		vector<vector<double>>& Outputs1m, ++
		vector<vector<double>>& Outputs2m, ++
		vector<vector<double>>& Outputs3m, ++
		vector<vector<double>>& Outputs4m, ++
		*/


		
			{
				lock_guard<mutex> lock(offlinethread);
				//indicators
				indicatorstemp = indicators;

				//indicatDate
				indicatDatetemp = indicatDate;


				//TheoWeights
				TheoWeightstemp = TheoWeights;


				//indicatDateInc
				indicatDateInctemp = indicatDateInc;
				
				//Weights1
				Weights1temp = Weights1;



				//vector<int64_t>& Count
				Counttemp = Count;



				//Weights1m
				Weights1mtemp = Weights1m;



				//Outputs1
				Outputs1temp = Outputs1;

				//Outputs2
				Outputs2temp = Outputs2;


				//Outputs3
				Outputs3temp = Outputs3;


				//Outputs4
				Outputs4temp = Outputs4;

				//Outputs1m
				Outputs1mtemp = Outputs1m;

				//Outputs2m
				Outputs2mtemp = Outputs2m;

				//Outputs3m
				Outputs3mtemp = Outputs3m;

				//Outputs4m
				Outputs4mtemp = Outputs4m;

				///обнуляем
				obj3.zerodate(vecdate, indicс, theorс);
				
			}

			
			for (int64_t i2 = 0; i2 < iterationney; i2++)

			{
				unsigned long long tact3 = __rdtsc();
				calcgdpteach(indicatorstemp, indicatDatetemp, TheoWeightstemp, indicatDateInctemp, Cash1, Weights1temp, Counttemp, Outputs1temp, Weights2, Outputs2temp, quot, Weights3, Outputs3temp, Weights4, Outputs4temp, Weights5, result1, result2, result,
					Weights1m,
					Weights2m,
					Weights3m,
					Weights4m,
					Weights5m,
					Outputs1mtemp,
					Outputs2mtemp,
					Outputs3mtemp,
					Outputs4mtemp,
					incre
				);

				double err1 = (result - res) * (result - res);
				
				teachquoterm(quot, result1, result2, result, Weights5, Weights4, Weights3, Weights2, Weights1temp, Outputs4temp, Outputs3temp, Outputs2temp, Outputs1temp, alpha, res,
					Weights1mtemp,
					Weights2m,
					Weights3m,
					Weights4m,
					Weights5m,
					Outputs1mtemp,
					Outputs2mtemp,
					Outputs3mtemp,
					Outputs4mtemp,
					dvec_a1,
					dvec_b1,
					dvec_c1,
					//double*& vec_a1, 
					//double*& vec_b1, 
					//double*& vec_c1, 
					vec_a23,
					vec_b23,
					vec_c23, 
					dvec_a4,
					dvec_b4,
					dvec_c4,
					vec_a4,
					vec_b4,
					//double*& vec_c4, 
					ab,
					Cash1

				);
				/*
				percdr += 1.0;
				unsigned long long tact4 = __rdtsc();
				tact5 = (tact5 + (tact4 - tact3)) / 2;
				std::cout << tact5 << endl;
*/
				err2 += err1;
				t666++;

			}
			err4 = err4 + (err2 / iterationney);
			
			//проверяем изменилось ли что-то
			
			/*
				//i1
				double percfd = percdr / double(percraw) * 100.0;
				int64_t percf = int(percfd);

				//std::cout << " __________ Пройдено " << percf << "% __________" << endl;
				unsigned long long tact6 = tact5 * percdr / tactraw;
				unsigned long long tact7 = tact6 / percf * (100 - percf);
				*/
				/*
				unsigned long long tact8 = 0;
				if (tact7 > 7200000)
				{
					tact8 = tact7 / 3600000;
					std::cout << " __________ До завершения обучения осталось около " << tact8 << " часов __________" << endl;
				}
				else if (tact7 > 3600000 && tact7 <= 7200000)
				{
					//tact8 = tact7 / 3600000;
					std::cout << " __________ До завершения обучения осталось около " << "1" << " часа __________" << endl;
				}

				else if (tact7 > 60000 && tact7 <= 3600000)
				{
					tact8 = tact7 / 60000;
					std::cout << " __________ До завершения обучения осталось около " << tact8 << " минут __________" << endl;
				}

				else if (tact7 > 1000 && tact7 <= 60000)
				{
					tact8 = tact7 / 1000;
					std::cout << " __________ До завершения обучения осталось около " << tact8 << " секунд __________" << endl;
				}

				else
					std::cout << " __________ Рассчет почти завешен __________" << endl;
				tact8 = 0;
				*/
			bool t789 = false;
			{
				lock_guard<mutex> lock(offlinethread);
				t789 = obj3.checkdate(vecdate, quot, indicс, theorс);
			}
				if (t789) { t12--; }
				else
				{


				//	percfff = int(percfd); // надо
				//	tact71 = static_cast<uint64_t>(tact7); // надо
				/// проверка и рассчет


				//Cash1

				//Cash1 = Cash1temp;


				//Weights1
				Weights1 = Weights1temp;



				//Weights1m

				Weights1m = Weights1mtemp;

			}


		}



		err3 = err4 / t12;
		q2 = sqrt(err3);
		//cout << "Квадрат ошибки составляет " << err3 << endl;
		//cout << "Ошибка составляет " << q2 << endl;

		if (teach)
		{
			if (q2 == q3) { tea0 += 1; }
			else { tea0 = 0; }

			if (tea0 == teach_count)
			{
				cout << "Модель не обучается уже более " << teach_count << " циклов." << endl;
				break;
			}
		}

		if (stop)
		{
			if (q3 < q2 && q5 == 0.0) { q4 = q2; q5 = 1.0; }
			else if (q3 > q2 && q5 == 1.0) { q4 = 0.0; q5 = 0.0; }
			else if (q5 == 1.0 && q3 < q2 && q2 - q4 > q1) {
				cout << "Модель переобучилась после достижения ошибки равной " << q4 << endl;
				break;
			}
		}

		q3 = q2;
		q2 = 0;
		err3 = 0;

	}


	obj1.delobj(dvec_a1, dvec_b1, dvec_c1, vec_a23, vec_b23, vec_c23, dvec_a4, dvec_b4, dvec_c4, vec_a4, vec_b4, ab);
	offlineUse.store(false);
	std::cout << "Рассчет завершен" << endl << ">>> ";




		}




		void teachofflineprep(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<double>& TheoWeights, vector<vector<double>>& indicatDateInc, vector<vector<double>>& Cash1, vector<double>& Weights1, vector<int64_t>& Count, vector<vector<double>>& Outputs1, vector<vector<double>>& Weights2, vector<vector<double>>& Outputs2, vector<vector<double>>& Weights3, vector<vector<double>>& Outputs3, vector<vector<double>>& Weights4, vector<vector<double>>& Outputs4, vector<vector<double>>& Weights5, double& result1, double& result2, double& result,
			vector<double>& Weights1m,
			vector<vector<double>>& Weights2m,
			vector<vector<double>>& Weights3m,
			vector<vector<double>>& Weights4m,
			vector<vector<double>>& Weights5m,
			vector<vector<double>>& Outputs1m,
			vector<vector<double>>& Outputs2m,
			vector<vector<double>>& Outputs3m,
			vector<vector<double>>& Outputs4m,
			const double& alpha,
			const int64_t& iterationney,
			const int64_t& iteration,
			vector<double>& vecdate,
			double& indicс,
			double& theorс,
			int64_t& percf,
			uint64_t& tact71,
			vector<double>& incre,
			const bool teach,
			const int64_t& teach_count,
			bool& stop,
			double& stopl
			)
		{
			
			Other obj3;


				//Запись параметра
	//vector<string> vvodindicv;
	//string indicator = "";
				string err = "";
				//string space = " ";
				//string vvodindic;
				//char t1 = ':';
				//int64_t t2 = 0;
				//vector <vector <double>> dates;
				auto dates = std::make_shared<vector<vector<double>>>();
				double d0 = 0.0;
				vector<int64_t> index;

				bool check = obj3.checkcin();
				if (!check) { std::cout << "\033[34m Вы ничего не ввели. Введите пожалуйста данные и повторите вызов рассчета заново. \033[0m" << endl; offlineUse.store(false);  return; }



				

				//Запись квартала и значения
				string dateraw = "";

				double date2 = 0.0;
				int64_t w = 1;
				while (w < 2)
				{
					int64_t st0 = std::cin.peek();

					if (st0 == 10) { w = 2; }
					else
					{

						bool check = obj3.checkcin();
						if (check == true) { cin >> dateraw; }

						//работа с кварталом

						std::regex patQ{ R"(\d\.\d\d\d\d)" };
						if (!std::regex_match(dateraw, patQ))
						{
							std::cout << "Неверно введен квартал года или сам год " << dateraw << endl << "Пример - 4.1999 " << endl << "\033[34m Поправьте ошибку и повторите рассчет заново \033[0m" << endl;
							getline(cin, err);
							offlineUse.store(false);
							return;
						};

						////что-то делаем с годом и кварталом
						char q10 = dateraw[0];
						int64_t q0 = 0;
						char q5 = 52;
						char q6 = 49;
						if (q10 == 49)  q0 = 1;
						else if (q10 == 50)  q0 = 2;
						else if (q10 == 51)  q0 = 3;
						else if (q10 == 52)  q0 = 4;
						else { std::cout << "Неверно введен квартал года " << dateraw << endl << "Пример - 4.1999 " << endl << "\033[34m Поправьте ошибку и повторите рассчет заново \033[0m" << endl; getline(cin, err); offlineUse.store(false);  return; }
						string q1 = dateraw.substr(2, 4);
						int64_t q2 = stoi(q1);
						if (q2 < 1990) { std::cout << "Неверно введен год " << dateraw << endl << "Пример - 4.1999 " << endl << "\033[34m Поправьте ошибку и повторите рассчет заново \033[0m" << endl; getline(cin, err); offlineUse.store(false); return; }



						int64_t qy = q2 - 1990;
						qy = qy * 4;
						qy -= 1;
						qy += q0; // индекс в векторе
						qy--;
						int64_t te1 = indicatDate[0].size();
						if (qy > te1) {
							cout << "\033[34m К сожалению данные за предыдущий квартал отсутствуют и рассчет не может быть осуществлен. \033[34m Поправьте ошибку и повторите рассчет заново \033[0m" << endl; getline(cin, err); offlineUse.store(false); return;
						}
						dateraw = "";

						check = obj3.checkcin();
						if (check == true) { cin >> dateraw; }

						char t0 = dateraw.back();

						char t5 = ';';
						int64_t a = 4;

						if (t0 != t5) { std::cout << "Где-то пропущена ; или значение. Ошибка выявлена на цифре -  " << dateraw << endl << "\033[34m Поправьте ошибку и повторите рассчет заново \033[0m" << endl; getline(cin, err); offlineUse.store(false); return; }
						else
						{
							dateraw.pop_back();
							d0 = stod(dateraw); //значение в векторе

							double incr2 = d0; //x*100*10/2 - 100-Р 


							double incr3 = incr2;
							//std::cout << "incr3 = " << int(incr2) << endl;
							/*
							while (incr3 > 100)
							{
								incr3 = 100;
							}

							while (incr3 < -100)
							{
								incr3 = -100;
							}
							*/




							double incr4 = incr3;
							double incrf = incr4;

							vector <double > dates12(2);
							dates12[0] = double(qy);
							dates12[1] = incrf;
							//dates.push_back(dates12);
							dates->push_back(dates12);


						}


					}

				}


				getline(cin, err);


				




				std::cout << "\033[34m  Значения приняты оффлайн расчетом. Начинаем обучение. Для просмотрра статуса воспользуйтесь командой ???????? \033[0m " << endl;



			
				std::thread t0([&, dates, alpha, iterationney, iteration, teach, teach_count]() mutable {
					teachoffline(
						indicators, indicatDate, TheoWeights, indicatDateInc, Cash1, Weights1,
						Count, Outputs1, Weights2, Outputs2, Weights3, Outputs3, Weights4,
						Outputs4, Weights5, result1, result2, result, Weights1m, Weights2m,
						Weights3m, Weights4m, Weights5m, Outputs1m, Outputs2m, Outputs3m,
						Outputs4m, alpha, iterationney, iteration, *dates, vecdate, indicс,
						theorс, percf, tact71, incre, teach, teach_count, stop, stopl
					);
					});

				t0.detach();

/*
				thread t0(teachoffline, ref(indicators), ref(indicatDate), ref(TheoWeights), ref(indicatDateInc), Cash1, ref(Weights1), ref(Count), ref(Outputs1), ref(Weights2), ref(Outputs2), ref(Weights3), ref(Outputs3), ref(Weights4), ref(Outputs4), ref(Weights5), result1, result2, result,
					ref(Weights1m),
					ref(Weights2m),
					ref(Weights3m),
					ref(Weights4m),
					ref(Weights5m),
					ref(Outputs1m),
					ref(Outputs2m),
					ref(Outputs3m),
					ref(Outputs4m),
					ref(alpha),
					ref(iterationney),
					ref(iteration),
					dates,
					ref(vecdate),
					ref(indicс),
						ref(theorс),
					ref(percf),
					ref(tact71),
					ref(incre),
					ref(teach),
						ref(teach_count),
							ref(stop),
								ref(stopl));
				
				t0.detach();
				*/
			}



		