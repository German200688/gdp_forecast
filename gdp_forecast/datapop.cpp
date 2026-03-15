#include <string>
#include <chrono>
#include <cstdint>
#include <iostream>
#include "kernel/file.hpp"




void beginmatrix1sc(int64_t count1, int64_t vectcount1, vector<vector<signed char>>& date1, string& filename, const string& linkfile) //размер основного вектора, размер вложенного вектора, матрица 2мерная, корень файла
{
	
	Filework<signed char> obj2;
	Filework<string> obj1;

	for (int64_t i = 0; i < count1; i++)
	{
		vector<signed char> indicatDate1{};
		
		string i1 = to_string(i);
		i1 = filename + i1;


		int64_t i2 = obj1.checkfile(i1, linkfile);

		if (i2 == 0)
		{
			int64_t i3 = 0;
			for (int64_t i3 = 0; i3 < vectcount1; i3++)
			{
				signed char a = 0;
				indicatDate1.push_back(a);

			}


		}
		else

		{
			indicatDate1 = obj2.myfileread(i1, indicatDate1, linkfile);


			int64_t i4 = indicatDate1.size();

			if (i4 != vectcount1)
			{

				while (i4 < vectcount1)
				{
					signed char a = 0;
					indicatDate1.push_back(a);
					i4++;
				}
				while (i4 > vectcount1)
				{
					indicatDate1.pop_back();
					i4--;

				}



			}

		}
		date1.push_back(indicatDate1);
		int64_t a2 = 0;
	}

}

void beginmatrix2sc(vector<vector<signed char>>& WWW, string& filename, int64_t& count, const string& linkfile)

{
	Filework<signed char> obj2;

	vector<signed char> W;
	W = obj2.myfileread(filename, W, linkfile);
	int64_t count12 = 0;
	if (W.size() == 0) {}
	else { count12 = W.size() / count; }
	int64_t i0 = 0;
	while (i0 < count12)
	{
		int64_t i1 = i0 * count;
		for (int64_t i2 = 0; i2 < count; i2++)
		{
			int64_t i3 = i1 + i2;
			signed char a = W[i3];
			WWW[i0].push_back(a);

		}
		i0++;
	}

	int64_t count13 = count12 * count;
	int64_t count14 = W.size();
	if (count13 != count14)
	{
		int64_t count15 = count14 - count13;
		int64_t i3 = i0 * count;
		int64_t i4 = 0;
		while (i4 < count15)
		{
			i3 = i3 + i4;
			signed char a = W[i3];
			WWW[i0].push_back(a);
			i4++;
		}

		while (i4 < count)
		{
			signed char a1 = 0;
			WWW[i0].push_back(a1);
			i4++;
		}


	}


}




void beginmatrix3sc(int64_t count1, int64_t vectcount1, vector<vector<double>>& date1, string& filename, const string& linkfile) //размер основного вектора, размер вложенного вектора, матрица 2мерная, корень файла
{

	Filework<double> obj2;
	Filework<string> obj1;

	for (int64_t i = 0; i < count1; i++)
	{
		vector<double> indicatDate1{};

		string i1 = to_string(i);
		i1 = filename + i1;


		int64_t i2 = obj1.checkfile(i1, linkfile);

		if (i2 == 0)
		{
			int64_t i3 = 0;
			for (int64_t i3 = 0; i3 < vectcount1; i3++)
			{
				double a = 0.0;
				indicatDate1.push_back(a);

			}


		}
		else

		{
			indicatDate1 = obj2.myfileread(i1, indicatDate1, linkfile);


			int64_t i4 = indicatDate1.size();

			if (i4 != vectcount1)
			{

				while (i4 < vectcount1)
				{
					double a = 0.0;
					indicatDate1.push_back(a);
					i4++;
				}
				while (i4 > vectcount1)
				{
					indicatDate1.pop_back();
					i4--;

				}



			}

		}
		date1.push_back(indicatDate1);
		int64_t a2 = 0;
	}

}

void beginmatrix4sc(int64_t count1, int64_t vectcount1, vector<vector<signed char>>& date1, string& filename, const string& linkfile) //размер основного вектора, размер вложенного вектора, матрица 2мерная, корень файла
{


	Filework<string> obj1;
	Filework<signed char> obj3;

	for (int64_t i = 0; i < count1; i++)
	{
		vector<signed char> Date1{};

		string i1 = to_string(i);
		i1 = filename + i1;


		int64_t i2 = obj1.checkfile(i1, linkfile);

		if (i2 == 0)
		{
			int64_t i3 = 0;
			for (int64_t i3 = 0; i3 < vectcount1; i3++)
			{
				signed char a = 0;
				Date1.push_back(a);

			}


		}
		else

		{
			Date1 = obj3.myfileread(i1, Date1, linkfile);


			int64_t i4 = Date1.size();

			if (i4 != vectcount1)
			{

				while (i4 < vectcount1)
				{
					signed char a = 0;
					Date1.push_back(a);
					i4++;
				}
				while (i4 > vectcount1)
				{
					Date1.pop_back();
					i4--;

				}



			}

		}
		date1.push_back(Date1);
		int64_t a2 = 0;
	}

}




void beginmatrix5sc(int64_t count1, int64_t vectcount1, vector<vector<signed char>>& date1, string& filename, const string& linkfile) //размер основного вектора, размер вложенного вектора, матрица 2мерная, корень файла
{


	Filework<string> obj1;
	Filework<signed char> obj3;

	for (int64_t i = 0; i < count1; i++)
	{
		vector<signed char> Date1{};

		string i1 = to_string(i);
		i1 = filename + i1;


		int64_t i2 = obj1.checkfile(i1, linkfile);

		if (i2 == 0)
		{
			int64_t i3 = 0;
			for (int64_t i3 = 0; i3 < vectcount1; i3++)
			{
				signed char a = 0;
				Date1.push_back(a);

			}


		}
		else

		{
			Date1 = obj3.myfileread(i1, Date1, linkfile);


			int64_t i4 = Date1.size();

			if (i4 != vectcount1)
			{

				while (i4 < vectcount1)
				{
					signed char a = 0;
					Date1.push_back(a);
					i4++;
				}
				while (i4 > vectcount1)
				{
					Date1.pop_back();
					i4--;

				}



			}

		}
		date1.push_back(Date1);
		int64_t a2 = 0;
	}

}


void endmatrix1sc(vector<vector<signed char>>& date1, string& filename, const string& linkfile) //2мерная матрица, корень файла
{
	Filework<signed char> obj2;
	int64_t i5 = date1.size();
	int64_t i6 = 0;

	while (i6 < i5)
	{

		string i7 = to_string(i6);
		i7 = filename + i7;

		vector<signed char> weightdw{};
		weightdw = date1[i6];
		obj2.myfilerewtite(i7, weightdw, linkfile);
		i6++;

	}
}



void endmatrix2sc(vector<vector<double>>& date1, string& filename, const string& linkfile) //2мерная матрица, корень файла
{
	Filework<double> obj3;
	int64_t i5 = date1.size();
	int64_t i6 = 0;

	while (i6 < i5)
	{

		string i7 = to_string(i6);
		i7 = filename + i7;

		vector<double> weightdw{};
		weightdw = date1[i6];
		obj3.myfilerewtite(i7, weightdw, linkfile);
		i6++;

	}
}



void beginfile(vector<string>& indicators, vector<signed char>& TheoWeights, vector<vector<double>>& indicatDate, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<int64_t>& Count,
	vector<signed char>& Weights1,
	vector<vector<signed char>>& Outputs1,
vector<vector<signed char>>& Weights2,
vector<vector<signed char>>& Outputs2,
vector<vector<signed char>>& Outputs3,
vector<vector<signed char>>& Outputs4,
vector<vector<signed char>>& Weights3,
vector<vector<signed char>>& Weights4,
vector<vector<signed char>>& Weights5,
vector<signed char>& Weights1m,
vector<vector<signed char>>& Weights2m,
vector<vector<signed char>>& Weights3m,
vector<vector<signed char>>& Weights4m,
vector<vector<signed char>>& Weights5m,
vector<vector<signed char>>& Outputs1m,
vector<vector<signed char>>& Outputs2m,
vector<vector<signed char>>& Outputs3m,
vector<vector<signed char>>& Outputs4m,
string linkfile

)
{
	Filework<string> obj1;
	Filework<signed char> obj2;
	Filework<int64_t> obj3;

	
	string filename1 = "indicators";
	indicators = obj1.myfileread(filename1, indicators, linkfile);

	string filename2 = "teoweights";
	TheoWeights = obj2.myfileread(filename2, TheoWeights, linkfile);

	string filename3 = "count";
	Count = obj3.myfileread(filename3, Count, linkfile);
	
	int64_t vectcounti = indicators.size();
	int64_t vectcountT = TheoWeights.size();

	if (vectcountT != vectcounti)
	{

		while (vectcountT < vectcounti)
		{
			signed char a = 0;
			TheoWeights.push_back(a);
			vectcountT++;
		}
		while (vectcountT > vectcounti)
		{
			TheoWeights.pop_back();
			vectcountT--;

		}

	}
	int64_t countQuoter = 0;
	if (!Count.empty()) countQuoter = Count[0]+1;
	string filename4 = "idate";
	beginmatrix3sc(vectcounti, countQuoter, indicatDate, filename4, linkfile);
	string filename5 = "idinc";
	beginmatrix1sc(vectcounti, countQuoter, indicatDateInc, filename5, linkfile);
	string filename6 = "cash1";
	beginmatrix1sc(vectcounti, countQuoter, Cash1, filename6, linkfile);

	int64_t countConvol1 = 0;

	
	
	int64_t size = Count.size();
	//слой1
	int64_t countWeight1 = 0;
	if (size < 2) ;
	else { countWeight1 = Count[1]; }
	string fileWeights1 = "Weights1";
	Weights1 = obj2.myfileread(fileWeights1, Weights1, linkfile);
	
	
	int64_t countOutputs1 = 0;
	if (size < 3);
	else { countOutputs1 = Count[2]; }
	string fileOutputs1 = "Outputs1";
	beginmatrix4sc(countQuoter, countOutputs1, Outputs1, fileOutputs1, linkfile);


	int64_t countWeight1m = 0;
	if (size < 2);
	else { countWeight1m = Count[1]; }
	string fileWeights1m = "Weights1m";
	Weights1m = obj2.myfileread(fileWeights1m, Weights1m, linkfile);


	int64_t countOutputs1m = 0;
	if (size < 3);
	else { countOutputs1m = Count[2]; }
	string fileOutputs1m = "Outputs1m";
	beginmatrix4sc(countQuoter, countOutputs1m, Outputs1m, fileOutputs1m, linkfile);




	//слой2
	
	int64_t countWeight2 = 0;
	if (size < 3);
	else { countWeight2 = Count[2]; }
	string fileWeights2 = "Weights2";
	beginmatrix5sc(countWeight2, countWeight2, Weights2, fileWeights2, linkfile);

	int64_t countOutputs2 = 0;
	if (size < 3);
	else { countOutputs2 = Count[2]; }
	string fileOutputs2 = "Outputs2";
	beginmatrix4sc(countQuoter, countOutputs2, Outputs2, fileOutputs2, linkfile);


	int64_t countWeight2m = 0;
	if (size < 3);
	else { countWeight2m = Count[2]; }
	string fileWeights2m = "Weights2m";
	beginmatrix5sc(countWeight2m, countWeight2m, Weights2m, fileWeights2m, linkfile);

	int64_t countOutputs2m = 0;
	if (size < 3);
	else { countOutputs2m = Count[2]; }
	string fileOutputs2m = "Outputs2m";
	beginmatrix4sc(countQuoter, countOutputs2m, Outputs2m, fileOutputs2m, linkfile);




	//слой3

	int64_t countWeight3 = 0;
	if (size < 3);
	else { countWeight3 = Count[2]; }
	string fileWeights3 = "Weights3";
	beginmatrix5sc(countWeight3, countWeight3, Weights3, fileWeights3, linkfile);

	int64_t countOutputs3 = 0;
	if (size < 3);
	else { countOutputs3 = Count[2]; }
	string fileOutputs3 = "Outputs3";
	beginmatrix4sc(countQuoter, countOutputs3, Outputs3, fileOutputs3, linkfile);

	int64_t countWeight3m = 0;
	if (size < 3);
	else { countWeight3m = Count[2]; }
	string fileWeights3m = "Weights3m";
	beginmatrix5sc(countWeight3m, countWeight3m, Weights3m, fileWeights3m, linkfile);

	int64_t countOutputs3m = 0;
	if (size < 3);
	else { countOutputs3m = Count[2]; }
	string fileOutputs3m = "Outputs3m";
	beginmatrix4sc(countQuoter, countOutputs3m, Outputs3m, fileOutputs3m, linkfile);





	//слой 4
	int64_t countOutputs4 = 0;
	if (size < 3);
	else { countOutputs4 = Count[2]; }
	string fileOutputs4 = "Outputs4";
	beginmatrix4sc(countQuoter, countOutputs4, Outputs4, fileOutputs4, linkfile);

	int64_t countWeight4 = 0;
	if (size < 3);
	else { countWeight4 = Count[2]; }
	string fileWeights4 = "Weights4";
	beginmatrix5sc(countWeight4, countWeight4, Weights4, fileWeights4, linkfile);

	int64_t countOutputs4m = 0;
	if (size < 3);
	else { countOutputs4m = Count[2]; }
	string fileOutputs4m = "Outputs4m";
	beginmatrix4sc(countQuoter, countOutputs4m, Outputs4m, fileOutputs4m, linkfile);

	int64_t countWeight4m = 0;
	if (size < 3);
	else { countWeight4m = Count[2]; }
	string fileWeights4m = "Weights4m";
	beginmatrix5sc(countWeight4m, countWeight4m, Weights4m, fileWeights4m, linkfile);



	//слой 5
	int64_t countWeight5 = 0;
	if (size < 3);
	else { countWeight5 = Count[2]; }
	string fileWeights5 = "Weights5";
	beginmatrix5sc(countWeight5, countWeight5, Weights5, fileWeights5, linkfile);

	int64_t countWeight5m = 0;
	if (size < 3);
	else { countWeight5m = Count[2]; }
	string fileWeights5m = "Weights5m";
	beginmatrix5sc(countWeight5m, countWeight5m, Weights5m, fileWeights5m, linkfile);

	


}


void endfile(vector<string>& indicators, vector<signed char>& TheoWeights, vector<vector<double>>& indicatDate, vector<vector<signed char>>& indicatDateInc, vector<vector<signed char>>& Cash1, vector<int64_t>& Count,
	vector<signed char>& Weights1,
	vector<vector<signed char>>& Outputs1,
	vector < vector<signed char>>& Weights2,
	vector<vector<signed char>>& Outputs2,
	vector<vector<signed char>>& Outputs3,
	vector < vector<signed char>>& Weights3,
	vector<vector<signed char>>& Outputs4,
	vector < vector<signed char>>& Weights4,
	vector < vector<signed char>>& Weights5,
	vector<signed char>& Weights1m,
	vector<vector<signed char>>& Weights2m,
	vector<vector<signed char>>& Weights3m,
	vector<vector<signed char>>& Weights4m,
	vector<vector<signed char>>& Weights5m,
	vector<vector<signed char>>& Outputs1m,
	vector<vector<signed char>>& Outputs2m,
	vector<vector<signed char>>& Outputs3m,
	vector<vector<signed char>>& Outputs4m,
	string linkfile
	

)
{
Filework<string> obj1;
Filework<signed char> obj2;
Filework<int64_t> obj3;

cout << "Идет сохранение обновленных данных..." << endl;
	
	string filename6 = "indicators";
	obj1.myfilerewtite(filename6, indicators, linkfile);


	filename6 = "teoweights";
	obj2.myfilerewtite(filename6, TheoWeights, linkfile);

	filename6 = "count";
	obj3.myfilerewtite(filename6, Count, linkfile);
	
	string filename7 = "idate";
	endmatrix2sc(indicatDate, filename7, linkfile);

	string filename8 = "idinc";
	endmatrix1sc(indicatDateInc, filename8, linkfile);
	////
	string filename9 = "cash1";
	endmatrix1sc(Cash1, filename9, linkfile);


	cout << "Идет сохранение весов 1-го слоя нейронов..." << endl;
	//первый слой
		
	string fileWeights10 = "Weights1";
	obj2.myfilerewtite(fileWeights10, Weights1, linkfile);

	string fileWeights10m = "Weights1m";
	obj2.myfilerewtite(fileWeights10m, Weights1m, linkfile);

	string fileOutputs10 = "Outputs1";
	endmatrix1sc(Outputs1, fileOutputs10, linkfile);

	string fileOutputs10m = "Outputs1m";
	endmatrix1sc(Outputs1m, fileOutputs10m, linkfile);

	
	cout << "Идет сохранение весов 2-го слоя нейронов..." << endl;

	string fileWeights12 = "Weights2";
	endmatrix1sc(Weights2, fileWeights12, linkfile);

	string fileWeights12m = "Weights2m";
	endmatrix1sc(Weights2m, fileWeights12m, linkfile);

	string fileOutputs12 = "Outputs2";
	endmatrix1sc(Outputs2, fileOutputs12, linkfile);

	string fileOutputs12m = "Outputs2m";
	endmatrix1sc(Outputs2m, fileOutputs12m, linkfile);

	cout << "Идет сохранение весов 3-го слоя нейронов..." << endl;

	string fileWeights13 = "Weights3";
	endmatrix1sc(Weights3, fileWeights13, linkfile);

	string fileOutputs13 = "Outputs3";
	endmatrix1sc(Outputs3, fileOutputs13, linkfile);

	string fileWeights13m = "Weights3m";
	endmatrix1sc(Weights3m, fileWeights13m, linkfile);

	string fileOutputs13m = "Outputs3m";
	endmatrix1sc(Outputs3m, fileOutputs13m, linkfile);

	cout << "Идет сохранение весов 4-го слоя нейронов..." << endl;

	string fileWeights14 = "Weights4";
	endmatrix1sc(Weights4, fileWeights14, linkfile);

	string fileOutputs14 = "Outputs4";
	endmatrix1sc(Outputs4, fileOutputs14, linkfile);

	string fileWeights14m = "Weights4m";
	endmatrix1sc(Weights4m, fileWeights14m, linkfile);

	string fileOutputs14m = "Outputs4m";
	endmatrix1sc(Outputs4m, fileOutputs14m, linkfile);

	cout << "Идет сохранение весов 5-го слоя нейронов..." << endl;

	string fileWeights15m = "Weights5m";
	endmatrix1sc(Weights5m, fileWeights15m, linkfile);
	string fileWeights15 = "Weights5";
	endmatrix1sc(Weights5, fileWeights15, linkfile);



}
