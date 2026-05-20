
//#include "OB1.h"
#include "neyron.h"
#include <chrono>
#include <iostream>
#include <cstdint>
#include "activat.h"
#include "other.h"

#pragma once

using namespace std;









double Neyron::valueneyTwoOne(vector<double>& neyronin, vector<double>& weight)

{
	
	// Signch obj;
	if (neyronin.empty() || weight.empty()) return (0);
	
	vector<double> vzveshney = {};

	int64_t i = 0;
		if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
		else i = weight.size() - 1;
	
		while (i >= 0)
	{
			
			double t3 = neyronin[i];
			double t4 = weight[i];
			double t1 = t3 * t4; //obj.multtt(t3, t4);
		vzveshney.push_back(t1);
		i--;

		
}
		double t2 = 0;
		
		i = vzveshney.size() -1;


		while (i >= 0)
		{
		
			double t5 = neyronin[i];
			double t6 = weight[i];
			t2 = t2 + vzveshney[i];
				//obj.plusss(t2, vzveshney[i]);
			i--;

		
		}
		
		return (t2);


}

 vector<double> Neyron::valueneyOneTwo(vector<double>& neyronin, vector<double>& weight)

 {

	 // Signch obj;
	 vector<double> vzveshney = {};
	 if (neyronin.empty() || weight.empty()) return (vzveshney);

	 

	 int64_t i1 = 0;
	 if (weight.size() > neyronin.size()) i1 = neyronin.size() - 1;
	 else i1 = weight.size() - 1;

	 for (int64_t i = 0; i <= i1; i++)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4;
			 //obj.multtt(t3, t4);
		 vzveshney.push_back(t1);

	 }
	 


	 return (vzveshney);


 }

 vector <double> Neyron::teacherOneTwo(vector <double> weight1, double input, int64_t ig, int64_t ip, double alpha)
 {
	 
	 //Signch obj;

	 double igres;
	 double ipres;
	 //double alpha = 0.21;

	 igres = weight1[ig];
	 ipres = weight1[ip];

	 double delta = ipres - igres;
	//	 obj.minusss(ipres, igres);

	 double weightDelta = input * delta;
		 //obj.multtt(input, delta);
	 ipres = ipres - alpha * delta;
		 //obj.multtt(alpha, delta);
	 weight1[ip] = ipres;

	 return weight1;

 }

 double Neyron::valueneyTwoOnerD(vector<double>& neyronin, vector<double>& weight)

 {

	 // Signch obj;
	 //Relu obj4;
	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<double> vzveshney = {};

	 int64_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4;
		 //obj.multtt(t3, t4);
		 double t10 = t1;
		 //obj4.relup(t1);

		 vzveshney.push_back(t10);
		 i--;


	 }
	 double t2 = 0;
	 double t2i = 0;
	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 double t5 = neyronin[i];
		 double t6 = weight[i];
		 t2i = t2i + vzveshney[i];
		 //t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }
	 i = vzveshney.size();
	 double  t21i = t2i;
	 t2 = t21i;

	 return (t2);


 }


 double Neyron::valueneyTwoOner(vector<double>& neyronin, vector<double>& weight)

 {

	 // Signch obj;
	 //Relu obj4;
	 //Other Other;
	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<double> vzveshney = {};

	 int64_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4; /////////////////////маленькое число
		 //obj.multtt(t3, t4);
//////////////////////////////////////////////////////////////////////////////////	 
		 //double t10 = Other.ssign(t1);
		 //t10 = t1 * t10;
		 //obj4.relup(t1);
//////////////////////////////////////////////////////////////////////////////////
		 vzveshney.push_back(t1);
		 i--;


	 }
	 double t2 = 0;
	 double t2i = 0;
	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 double t5 = neyronin[i];
		 double t6 = weight[i];
		 t2i = t2i + vzveshney[i];
		 //t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }
	 i = vzveshney.size();
	 double  t21i = t2i;
	 t2 = t21i;

	 return (t2);


 }



 double Neyron::valueneyTwoOner2(vector<double>& neyronin, vector<double>& weight)

 {

	// Signch obj;
	 //Relu obj4;
	 Activat Activat;
	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<double> vzveshney = {};

	 int64_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4; /////////////////////маленькое число
			 //obj.multtt(t3, t4);
	//////////////////////////////////////////////////////////////////////////////////	 
		 double t10 = Activat.ssign(t1);
		 t10 = t1 * t10;
			 //obj4.relup(t1);
//////////////////////////////////////////////////////////////////////////////////
		 vzveshney.push_back(t10);
		 i--;


	 }
	 double t2 = 0;
	 double t2i = 0;
	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 double t5 = neyronin[i];
		 double t6 = weight[i];
		 t2i = t2i + vzveshney[i];
		 //t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }
	 i = vzveshney.size();
	 double  t21i = t2i;
	 t2 = t21i;

	 return (t2);


 }



 double Neyron::valueneyTwoOner3(vector<double>& neyronin, vector<double>& weight)

 {

	 // Signch obj;
	// Relu obj4;
	 Activat Activat;
	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<double> vzveshney = {};

	 int64_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4; /////////////////////маленькое число
		 //obj.multtt(t3, t4);
//////////////////////////////////////////////////////////////////////////////////	 
		 double t10 = Activat.tanh(t1);
		 t10 = t1 * t10;
		 //obj4.relup(t1);
//////////////////////////////////////////////////////////////////////////////////
		 vzveshney.push_back(t10);
		 i--;


	 }
	 double t2 = 0;
	 double t2i = 0;
	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 double t5 = neyronin[i];
		 double t6 = weight[i];
		 t2i = t2i + vzveshney[i];
		 //t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }
	 i = vzveshney.size();
	 double  t21i = t2i;
	 t2 = t21i;

	 return (t2);


 }



 double Neyron::valueneyTwoOner4(vector<double>& neyronin, vector<double>& weight)

 {

	 // Signch obj;
	// Relu obj4;
	 Activat Activat;
	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<double> vzveshney = {};

	 int64_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4; /////////////////////маленькое число
		 //obj.multtt(t3, t4);
//////////////////////////////////////////////////////////////////////////////////	 
		 double t10 = Activat.swish(t1);
		// 
		 //double t10 = Activat.ssign(t1);
		// double t10 = Activat.tanh(t1);
		// double t10 = 1;
		 t10 = t1 * t10;
		 //obj4.relup(t1);
//////////////////////////////////////////////////////////////////////////////////
		 vzveshney.push_back(t10);
		 i--;


	 }
	 double t2 = 0;
	 double t2i = 0;
	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 double t5 = neyronin[i];
		 double t6 = weight[i];
		 t2i = t2i + vzveshney[i];
		 //t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }
	 i = vzveshney.size();
	 double  t21i = t2i;
	 t2 = t21i;

	 return (t2);


 }

 double Neyron::valueneyTwoOner4m(vector<double>& neyronin, vector<double>& weight)

 {

	 // Signch obj;
	// Relu obj4;
	 Activat Activat;
	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<double> vzveshney = {};

	 int64_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4; /////////////////////маленькое число
		 //obj.multtt(t3, t4);
//////////////////////////////////////////////////////////////////////////////////	 
		 double t10 = Activat.gswish(t1);
		 // 
		  //double t10 = Activat.ssign(t1);
		 // double t10 = Activat.tanh(t1);
		// double t10 = 1;
		 t10 = t1 * t10;
		 //obj4.relup(t1);
//////////////////////////////////////////////////////////////////////////////////
		 vzveshney.push_back(t10);
		 i--;


	 }
	 double t2 = 0;
	 double t2i = 0;
	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 double t5 = neyronin[i];
		 double t6 = weight[i];
		 t2i = t2i + vzveshney[i];
		 //t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }
	 i = vzveshney.size();
	 double  t21i = t2i;
	 t2 = t21i;

	 return (t2);


 }

 double Neyron::valueneyTwoOnerm(vector<double>& neyronin, vector<double>& weight)

 {

	 //Signch obj;
	 //Relu obj4;
	 Activat Activat;

	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<double> vzveshney = {};

	 int64_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4;
			 //obj.multtt(t3, t4);
		 /////////////////////////////////////////
		 double t10 = t1 * Activat.ssign(t1);;
			 //obj4.relum(t1);
		 /////////////////////////////////////////////////////

		 vzveshney.push_back(t10);
		 i--;


	 }
	 double t2 = 0;
	 double t2i = 0;
	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 double t5 = neyronin[i];
		 double t6 = weight[i];
		 t2i = t2i + vzveshney[i];
		// t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }
	 i = weight.size();
	 double  t21i = t2i;
	 t2 = t21i;

	 return (t2);


 }




 /// <summary>
 /// //////////////////////////////////ГДЕ ИСПОЛЬЗУЕТСЯ!!!
 /// </summary>
 /// <param name="neyronin"></param>
 /// <param name="weight"></param>
 /// <returns></returns>
 vector<double> Neyron::valueneyOneTwor(vector<double>& neyronin, vector<double>& weight, double a)

 {

	// Signch obj;
	 Activat obj4;

	 vector<double> vzveshney = {};
	 if (neyronin.empty() || weight.empty()) return (vzveshney);



	 int64_t i1 = 0;
	 if (weight.size() > neyronin.size()) i1 = neyronin.size() - 1;
	 else i1 = weight.size() - 1;

	 for (int64_t i = 0; i <= i1; i++)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4;
			// obj.multtt(t3, t4);
		// double t10 = obj4.relup(t1);
		 double t10 = t1;

		 vzveshney.push_back(t10);

	 }



	 return (vzveshney);


 }


 
 vector<double> Neyron::valueneyOneTworm(vector<double>& neyronin, vector<double>& weight)

 {

	// Signch obj;
	 Activat obj4;

	 vector<double> vzveshney = {};
	 if (neyronin.empty() || weight.empty()) return (vzveshney);



	 int64_t i1 = 0;
	 if (weight.size() > neyronin.size()) i1 = neyronin.size() - 1;
	 else i1 = weight.size() - 1;

	 for (int64_t i = 0; i <= i1; i++)
	 {

		 double t3 = neyronin[i];
		 double t4 = weight[i];
		 double t1 = t3 * t4;
			 //obj.multtt(t3, t4);
		 //double t10 = obj4.relum(t1);
		 double t10 = t1;
		 vzveshney.push_back(t10);

	 }



	 return (vzveshney);


 }


 vector<double > Neyron::deltaout(vector<double >& delta, const double& neyrontest, const double& neyrontestres)

 {
	// Signch obj;

	 int64_t t0 = delta.size();

	 while (t0 > 0)

	 {
		 delta.pop_back();
		 t0 = delta.size();
	 }
	 //double t1 = neyrontestres - neyrontest;
	 double t1 = neyrontest - neyrontestres;
		 //obj.minusss(neyrontest, neyrontestres);
	 delta.push_back(t1);

	 return delta;

 }


 void Neyron::dellayerlast(vector<vector<double>>& Weights3, int64_t Quoter, vector<vector<double>>& Outputs2, const double& delta, double alpha)

 {
	// Signch obj;

	 int64_t t1 = Outputs2[Quoter].size();
	 int64_t t10 = Outputs2.size();
	 double alpha3 = alpha;
	 //double alpha3 = 0.21;

	 for (int64_t i = 0; i < t1; i++)
	 {
		 double t2 = Outputs2[Quoter][i] * delta;
			 //obj.multtt(Outputs2[Quoter][i], delta);
		 double t3 = t2 * alpha3;
			// obj.multtt(t2, alpha3);
		 double t11 = Weights3[0][i] - t3;
			 //obj.minusss(Weights3[0][i], t3);
		 if (t11 == 0) {
			 t11 = 1;
		 }
		 Weights3[0][i] = t11;

	 }


 }


 double Neyron::deltaMiddle(int64_t Weightslsize, vector<double >& Weights, vector<double >& delta, double& alpha, double& Outputs, double& OutputD4f)
 {
	 //Relu obj;
	// Signch obj1;
	 double deltaraw = 0;
	 double deltaraw1 = 0;
	 double deltaraw2 = 0;
	 double alpha3 = alpha;
	 //double alpha3 = 0.21;

	 //if (obj.reludivp(Outputs) == 0) { return 0; }
	 //else
	 {
		 
		 for (int64_t i6 = 0; i6 < Weightslsize; i6++)
		 {
			 
			 double sdeltaraw = Weights[i6] * delta[i6];
				 //obj1.multtt(Weights[i6], delta[i6]);
			 deltaraw = deltaraw * sdeltaraw;
				 //obj1.plusss(deltaraw, sdeltaraw);
			// if (deltaraw == 120 || deltaraw == -120) break;

		 }
		 deltaraw2 = deltaraw * OutputD4f;
		 return deltaraw;
	 }
	 
	 
 }


 double Neyron::deltafin(int64_t Weightslsize, double& Weight, double& delta, double& alpha, double& Outputs)
 {
	 //Relu obj;
	 //Signch obj1;
	 double deltaraw = 0;
	 //if (obj.reludivp(Outputs) == 0) { return 0; }
	 //else
	 {

		 

		 double sdeltaraw = Weight * delta;
				 //obj1.multtt(Weight, delta);
		 deltaraw = deltaraw + sdeltaraw;
				 //obj1.plusss(deltaraw, sdeltaraw);
			// if (deltaraw == 120 || deltaraw == -120) 

		 

		 return deltaraw;
	 }


 }



 double Neyron::deltaMiddlem(int64_t Weightslsize, vector<double >& Weights, vector<double >& delta, double& alpha, double& Outputs)
 {
	 Activat obj;
	// Signch obj1;
	 double deltaraw = 0;
	 //if (obj.reludivm(Outputs) == 0) { return 0; }
	 //else
	 {

		 for (int64_t i6 = 0; i6 < Weightslsize; i6++)
		 {

			 double sdeltaraw = Weights[i6] * delta[i6];
				 //obj1.multtt(Weights[i6], delta[i6]);
			 deltaraw = deltaraw + sdeltaraw;
				 //obj1.plusss(deltaraw, sdeltaraw);
			// if (deltaraw == 120 || deltaraw == -120) break;

		 }

		 return deltaraw;
	 }
 }



 double Neyron::deltafinm(int64_t Weightslsize, double& Weight, double& delta, double& alpha, double& Outputs)
 {
	 Activat obj;
	// Signch obj1;
	 double deltaraw = 0;
	 //if (obj.reludivp(Outputs) == 0) { return 0; }
	 //else
	 {



		 double sdeltaraw = Weight * delta;
			 //obj1.multtt(Weight, delta);
		 deltaraw = deltaraw + sdeltaraw;
			 //obj1.plusss(deltaraw, sdeltaraw);
		// if (deltaraw == 120 || deltaraw == -120)



			 return deltaraw;
	 }


 }


 vector<double > Neyron::MiddleTeach(vector<double >& Weights, vector<double >& Output, double& delta, int64_t& size, double& alpha1)
 {
	// Relu obj;
	// Signch obj1;
	 double alpha = alpha1;
	 
	 //double alpha = 0.21;

	 for (int64_t i1 = 0; i1 < size; i1++)
	 {
		
		 double t1 = Output[i1] * delta;
			 //obj1.multtt(Output, delta);
		 double t2 = t1 * alpha;
			 //obj1.multtt(t1, alpha);
		 //if (t2 == 0) { t2 = 1; }
		 double t20 = Weights[i1] - t2;
			 //obj1.minusss(Weights[i1], t2);
		 if (t20 == 0) { Weights[i1] = 0.01; }
		 else Weights[i1] = t20;

			

	 }
	 return Weights;
 }