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



void teachoffline(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<signed char>& TheoWeights, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>> Cash1, vector<signed char>& Weights1, vector<int64_t>& Count, vector<vector<signed char>> Outputs1, vector<vector<signed char>>& Weights2, vector<vector<signed char>> Outputs2, vector<vector<signed char>>& Weights3, vector<vector<signed char>> Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>> Outputs4, vector<vector<signed char>>& Weights5, signed char result1, signed char result2, signed char result,
	vector<signed char>& Weights1m,
	vector<vector<signed char>>& Weights2m,
	vector<vector<signed char>>& Weights3m,
	vector<vector<signed char>>& Weights4m,
	vector<vector<signed char>>& Weights5m,
	vector<vector<signed char>>& Outputs1m,
	vector<vector<signed char>>& Outputs2m,
	vector<vector<signed char>>& Outputs3m,
	vector<vector<signed char>>& Outputs4m,
	const signed char& alpha,
	const int64_t& iterationney,
	const int64_t& iteration,
	vector <vector <int64_t>> dates,
	vector<unsigned char>& vecdate,
unsigned char& indicс,
unsigned char& theorс,
int64_t& percfff,
uint64_t& tact71
)
{
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
	Other obj3;
	nvidiac obj1;

	signed char* dvec_a1, * dvec_b1, * dvec_c1, * vec_a23, * vec_b23, * dvec_a4, * dvec_b4, * dvec_c4, * vec_a4, * vec_b4, * ab;
	//int N1, int N23, int N4, int N44, signed char*& ab

	int64_t Quoter = dates[0][0];



	unsigned long long tact1 = __rdtsc();
	this_thread::sleep_for(std::chrono::seconds(1));
	unsigned long long tact2 = __rdtsc();
	unsigned long long tactraw = (tact2 - tact1) / 1000;
	std::cout << tactraw << endl;

	//lock_guard<mutex> lock(offlinethread);
	offlinethread.lock();
	

	calcgdpteach(indicators, indicatDate, TheoWeights, indicatDateInc, Cash1, Weights1, Count, Outputs1, Weights2, Outputs2, Quoter, Weights3, Outputs3, Weights4, Outputs4, Weights5, result1, result2, result,
		Weights1m,
		Weights2m,
		Weights3m,
		Weights4m,
		Weights5m,
		Outputs1m,
		Outputs2m,
		Outputs3m,
		Outputs4m
		
	);
	offlinethread.unlock();
	
	




	int64_t N1 = 3;
	int64_t N23 = Weights2[0].size();
	int64_t N44 = Weights4[0].size();
	int64_t N4 = Weights5[0].size();


	obj1.addobj(dvec_a1, dvec_b1, dvec_c1, vec_a23, vec_b23, dvec_a4, dvec_b4, dvec_c4, vec_a4, vec_b4, N1, N23, N4, N44, ab);
	int t12 = dates.size();
	int percraw = iterationney * t12 * iteration;
	double percdr = 0;
	int t666 = 1;
	unsigned long long tact5 = 0;
	for (int64_t i0 = 0; i0 < iteration; i0++)
	{
		for (int64_t i1 = 0; i1 < t12; i1++)
		{
			int64_t quot = dates[i1][0];
			int64_t resi = dates[i1][1];
			//cout << resi << endl;
			signed char res = static_cast<signed char>(resi);

//создаем временные массивы
			/*
	vector<string>& indicators, ++
		vector<vector<double>>& indicatDate, ++
		vector<signed char>& TheoWeights, ++
		vector<vector<signed char>>& indicatDateInc, ++
		vector<vector<signed char>>& Cash1, ++
		vector<signed char> Weights1, ++
		vector<int64_t>& Count, ++
		vector<vector<signed char>>& Outputs1, ++
		vector<vector<signed char>>& Weights2, -
		vector<vector<signed char>>& Outputs2, ++
		vector<vector<signed char>>& Weights3, -
		vector<vector<signed char>>& Outputs3, ++
		vector<vector<signed char>>& Weights4, -
		vector<vector<signed char>>& Outputs4, ++
		vector<vector<signed char>>& Weights5, -
		signed char& result1, +
		signed char& result2, +
		signed char& result,+
		vector<signed char>& Weights1m, ++
		vector<vector<signed char>>& Weights2m,-
		vector<vector<signed char>>& Weights3m, -
		vector<vector<signed char>>& Weights4m, -
		vector<vector<signed char>>& Weights5m,-
		vector<vector<signed char>>& Outputs1m, ++
		vector<vector<signed char>>& Outputs2m, ++
		vector<vector<signed char>>& Outputs3m, ++
		vector<vector<signed char>>& Outputs4m, ++
		*/
			offlinethread.lock();
		//indicators
			int64_t s1 = indicators.size();
			vector<string> indicatorstemp(s1);
			indicatorstemp = indicators;

			//indicatDate
			int64_t s2 = indicatDate.size();
			int s2_0 = indicatDate[0].size();
			vector<vector<double>> indicatDatetemp(s2, vector<double>(s2_0));
			indicatDatetemp = indicatDate;
			

			//TheoWeights
			int64_t s3 = TheoWeights.size();
			vector<signed char> TheoWeightstemp(s3);
			TheoWeightstemp = TheoWeights;


			//indicatDateInc
			int64_t s4 = indicatDateInc.size();
			int64_t s4_0 = indicatDateInc[0].size();
			vector<vector<signed char>> indicatDateInctemp(s4, vector<signed char> (s4_0));


			//Weights1
			int64_t s16 = Weights1.size();
			vector<signed char> Weights1temp(s16);
			Weights1temp = Weights1;



			//vector<int64_t>& Count
			int64_t s6 = Count.size();
			vector<int64_t> Counttemp(s6);
			Counttemp = Count;



			//Weights1m
			int64_t s11 = Weights1m.size();
			vector<signed char> Weights1mtemp(s11);
			Weights1mtemp = Weights1m;



			//Outputs1
			int64_t s12 = Outputs1.size();
			int64_t s12_0 = Outputs1[0].size();
			vector<vector<signed char>> Outputs1temp(s12, vector<signed char>(s4_0));
			Outputs1temp = Outputs1;

			//Outputs2
			int64_t s13 = Outputs2.size();
			int64_t s13_0 = Outputs2[0].size();
			vector<vector<signed char>> Outputs2temp(s13, vector<signed char> (s13_0));
			Outputs2temp = Outputs2;


			//Outputs3
			int64_t s14 = Outputs3.size();
			int64_t s14_0 = Outputs3[0].size();
			vector<vector<signed char>> Outputs3temp(s14, vector<signed char> (s14_0));
			Outputs3temp = Outputs3;


			//Outputs4
			int64_t s15 = Outputs4.size();
			int64_t s15_0 = Outputs4[0].size();
			vector<vector<signed char>> Outputs4temp(s15, vector<signed char> (s15_0));
			Outputs4temp = Outputs4;

			//Outputs1m
			int64_t s22 = Outputs1m.size();
			int64_t s22_0 = Outputs1m[0].size();
			vector<vector<signed char>> Outputs1mtemp(s22, vector<signed char> (s22_0));
			Outputs1mtemp = Outputs1m;

			//Outputs2m
			int64_t s23 = Outputs2m.size();
			int64_t s23_0 = Outputs2m[0].size();
			vector<vector<signed char>> Outputs2mtemp(s23, vector<signed char> (s23_0));
			Outputs2mtemp = Outputs2m;

			//Outputs3m
			int64_t s24 = Outputs3m.size();
			int64_t s24_0 = Outputs3m[0].size();
			vector<vector<signed char>> Outputs3mtemp(s24, vector<signed char> (s24_0));
			Outputs3mtemp = Outputs3m;

			//Outputs4m
			int64_t s25 = Outputs4m.size();
			int64_t s25_0 = Outputs4m[0].size();
			vector<vector<signed char>> Outputs4mtemp(s25, vector<signed char> (s25_0));
			Outputs4mtemp = Outputs4m;

			///обнуляем
			obj3.zerodate(vecdate, indicс, theorс);
			offlinethread.unlock();
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
					Outputs4mtemp
				);



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
					//signed char*& vec_a1, 
					//signed char*& vec_b1, 
					//signed char*& vec_c1, 
					vec_a23,
					vec_b23,
					//signed char*& vec_c23, 
					dvec_a4,
					dvec_b4,
					dvec_c4,
					vec_a4,
					vec_b4,
					//signed char*& vec_c4, 
					ab

				);
				percdr += 1.0;
				unsigned long long tact4 = __rdtsc();
				tact5 = (tact5 + (tact4 - tact3)) / 2;
				std::cout << tact5 << endl;

				t666++;

			}
			//проверяем изменилось ли что-то
			

				//i1
				double percfd = percdr / double(percraw) * 100.0;
				int64_t percf = int(percfd);

				//std::cout << " __________ Пройдено " << percf << "% __________" << endl;
				unsigned long long tact6 = tact5 * percdr / tactraw;
				unsigned long long tact7 = tact6 / percf * (100 - percf);
				
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

				lock_guard<mutex> lock(offlinethread);
				bool t789 = obj3.checkdate(vecdate, quot, indicс, theorс);

				if (t789) { t12--; }
				else
				{


					percfff = int(percfd); // надо
					tact71 = static_cast<uint64_t>(tact7); // надо
				/// проверка и рассчет


				//Cash1

				//Cash1 = Cash1temp;


				//Weights1
				Weights1 = Weights1temp;



				//Weights1m

				Weights1m = Weights1mtemp;

			}


		}





	}


	obj1.delobj(dvec_a1, dvec_b1, dvec_c1, vec_a23, vec_b23, dvec_a4, dvec_b4, dvec_c4, vec_a4, vec_b4, ab);
	offlineUse.store(false);
	std::cout << "Рассчет завершен" << endl << ">>> ";;




		}




		void teachofflineprep(vector<string>& indicators, vector<vector<double>>& indicatDate, vector<signed char>& TheoWeights, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<signed char>& Weights1, vector<int64_t>& Count, vector<vector<signed char>>& Outputs1, vector<vector<signed char>>& Weights2, vector<vector<signed char>>& Outputs2, vector<vector<signed char>>& Weights3, vector<vector<signed char>>& Outputs3, vector<vector<signed char>>& Weights4, vector<vector<signed char>>& Outputs4, vector<vector<signed char>>& Weights5, signed char& result1, signed char& result2, signed char& result,
			vector<signed char>& Weights1m,
			vector<vector<signed char>>& Weights2m,
			vector<vector<signed char>>& Weights3m,
			vector<vector<signed char>>& Weights4m,
			vector<vector<signed char>>& Weights5m,
			vector<vector<signed char>>& Outputs1m,
			vector<vector<signed char>>& Outputs2m,
			vector<vector<signed char>>& Outputs3m,
			vector<vector<signed char>>& Outputs4m,
			const signed char& alpha,
			const int64_t& iterationney,
			const int64_t& iteration,
			vector<unsigned char>& vecdate,
			unsigned char& indicс,
			unsigned char& theorс,
			int64_t& percf,
			uint64_t& tact71
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
				vector <vector <int64_t>> dates;
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

							double incr2 = d0 * 5; //x*100*10/2 - 100-Р 


							int64_t incr3 = int64_t(incr2);
							//std::cout << "incr3 = " << int(incr2) << endl;

							while (incr3 > 100)
							{
								incr3 = 100;
							}

							while (incr3 < -100)
							{
								incr3 = -100;
							}

							signed char incr4 = static_cast<signed char>(incr3);
							int64_t incrf = int(incr4);

							vector <int64_t > dates12(2);
							dates12[0] = qy;
							dates12[1] = incrf;
							dates.push_back(dates12);


						}


					}

				}


				getline(cin, err);







				std::cout << "\033[34m  Значения приняты оффлайн расчетом. Начинаем обучение. Для просмотрра статуса воспользуйтесь командой ???????? \033[0m " << endl;




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
					ref(tact71));
				t0.detach();
			}



		