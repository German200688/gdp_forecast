

#include <iostream>
#include <chrono>
#include <string>
#include <type_traits>
#include <fstream> 
#include <clocale>
#include <cstdint>


#pragma once



using namespace std;

template <typename T>


class Filework
{


public:
	vector<T> myfileread(const string& filename, vector<T>& datumr, const string& filelink);
	void myfilerewtite(const string& filename, vector<T>& datumw, const string& filelink);
	int32_t checkfile(string filename, const string& filelink);

};


template <typename T>

vector<T> Filework<T>::myfileread(const string& filename, vector<T>& datumr, const string& filelink)
{
	
	setlocale(LC_ALL, "Russian");
	
	static_assert(is_same_v<T, signed char> || is_same_v<T, string> || is_same_v<T, double> || is_same_v<T, int32_t>);

	string filelinc = filelink; /////"C:\\Users\\Legion\\Documents\\testney\\";
	string txt = ".txt";
	filelinc = filelinc + filename + txt;
	ifstream file(filelinc);

	if (!file.is_open()) {
#ifdef _DEBUG 
		std::cerr << "ERROR: Cannot open: " << filelinc  << std::endl;
#endif
		return datumr;
	}

	string line;

	if constexpr (is_same_v<T, string>) {
		while (getline(file, line)) {

			datumr.push_back(line);


		};
	}
	if constexpr (is_same_v<T, signed char>)
	{
		while (getline(file, line)) {

			int32_t t0 = stoi(line);
			if (t0 > 100) t0 = 100;
			if (t0 < -100) t0 = -100;
			signed char t1 = (signed char)t0;

			datumr.push_back(t1);


		};
	}

		if constexpr (is_same_v<T, int32_t>)
		{
			while (getline(file, line)) {

				int32_t t0 = stoi(line);
				if (t0 > 100) t0 = 100;
				if (t0 < -100) t0 = -100;

				datumr.push_back(t0);


			};
	}

	if constexpr (is_same_v<T, double>) {
		while (getline(file, line)) {

			double t9 = stod(line);
			datumr.push_back(t9);


		};

	};



	file.close();

	return datumr;
}

template <typename T1>
void Filework<T1>::myfilerewtite(const string& filename, vector<T1>& datumw, const string& filelink)
{
	setlocale(LC_ALL, "Russian");
	
	static_assert(is_same_v<T1, signed char> || is_same_v<T1, string> || is_same_v<T1, double> || is_same_v<T1, int32_t>);

	if (datumw.size() > 0)
	{
		string filelinc = filelink;
	// //"C:\\Users\\Legion\\Documents\\testney\\";
		string txt = ".txt";
		filelinc = filelinc + filename + txt;

		int32_t c0 = datumw.size();
		std::string content;
		int32_t i = 0;
		while (i < c0) {
			std::string c1;
			std::string c2;
			double c3 = 0.0;

			if constexpr (is_same_v<T1, string>) c1 = datumw[i];
			if constexpr (is_same_v<T1, double>) { c3 = datumw[i]; c1 = to_string(c3); }
			if constexpr (is_same_v<T1, int32_t>) { c3 = datumw[i]; c1 = to_string(c3); }
			if constexpr (is_same_v<T1, signed char>) {
signed char t0 = datumw[i];

int32_t t1 = int32_t(t0);
c1 = to_string(t1);


			}

			c2 = "\n";
			content = content + c1 +c2;
			i++;
		}

		ofstream outFile(filelinc, std::ios::out | std::ios::trunc);

		if (outFile.is_open()) {
			outFile << content;
			outFile.close();

		}
		else {
#ifdef _DEBUG 
			std::cerr << "ERROR: Cannot open or create file" << filelinc << "!" << std::endl; 
#endif		
			return;
		}

	}

}

int32_t Filework<string>::checkfile(string filename, const string& filelink)
{
	string filelinc = filelink; //"C:\\Users\\Legion\\Documents\\testney\\";
	string txt = ".txt";
	filelinc = filelinc + filename + txt;
	ifstream file(filelinc);
	if (!file.is_open()) {
#ifdef _DEBUG 
		std::cerr << "ERROR: Cannot open: " << filelinc << std::endl;
#endif
		return 0;

	}
	else
	{
		file.close();
		return 1;
	}
}




