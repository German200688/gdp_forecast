
#include "OB1.h"
#include "neyron.h"
#include <chrono>
#include <iostream>
#include <cstdint>
#include "relu.hpp"


using namespace std;









 signed char Neyron::valueneyTwoOne(vector<signed char>& neyronin, vector<signed char>& weight)

{
	
	 Signch obj;
	if (neyronin.empty() || weight.empty()) return (0);
	
	vector<signed char> vzveshney = {};

	int32_t i = 0;
		if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
		else i = weight.size() - 1;
	
		while (i >= 0)
	{
			
			signed char t3 = neyronin[i];
			signed char t4 = weight[i];
			signed char t1 = obj.multtt(t3, t4);
		vzveshney.push_back(t1);
		i--;

		
}
		signed char t2 = 0;
		
		i = vzveshney.size() -1;


		while (i >= 0)
		{
		
			signed char t5 = neyronin[i];
			signed char t6 = weight[i];
			t2 = obj.plusss(t2, vzveshney[i]);
			i--;

		
		}
		
		return (t2);


}

 vector<signed char> Neyron::valueneyOneTwo(vector<signed char>& neyronin, vector<signed char>& weight)

 {

	 Signch obj;
	 vector<signed char> vzveshney = {};
	 if (neyronin.empty() || weight.empty()) return (vzveshney);

	 

	 int32_t i1 = 0;
	 if (weight.size() > neyronin.size()) i1 = neyronin.size() - 1;
	 else i1 = weight.size() - 1;

	 for (int32_t i = 0; i <= i1; i++)
	 {

		 signed char t3 = neyronin[i];
		 signed char t4 = weight[i];
		 signed char t1 = obj.multtt(t3, t4);
		 vzveshney.push_back(t1);

	 }
	 


	 return (vzveshney);


 }

 vector <signed char> Neyron::teacherOneTwo(vector <signed char> weight1, signed char input, int32_t ig, int32_t ip)
 {
	 
	 Signch obj;

	 signed char igres;
	 signed char ipres;
	 signed char alpha = 100;

	 igres = weight1[ig];
	 ipres = weight1[ip];

	 signed char delta = obj.minusss(ipres, igres);

	 signed char weightDelta = obj.multtt(input, delta);
	 ipres -= obj.multtt(alpha, delta);
	 weight1[ip] = ipres;

	 return weight1;

 }



 signed char Neyron::valueneyTwoOner(vector<signed char>& neyronin, vector<signed char>& weight)

 {

	 Signch obj;
	 Relu obj4;
	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<signed char> vzveshney = {};

	 int32_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 signed char t3 = neyronin[i];
		 signed char t4 = weight[i];
		 signed char t1 = obj.multtt(t3, t4);
		 signed char t10 = obj4.relup(t1);

		 vzveshney.push_back(t10);
		 i--;


	 }
	 signed char t2 = 0;

	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 signed char t5 = neyronin[i];
		 signed char t6 = weight[i];
		 t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }

	 return (t2);


 }


 signed char Neyron::valueneyTwoOnerm(vector<signed char>& neyronin, vector<signed char>& weight)

 {

	 Signch obj;
	 Relu obj4;
	 if (neyronin.empty() || weight.empty()) return (0);

	 vector<signed char> vzveshney = {};

	 int32_t i = 0;
	 if (weight.size() > neyronin.size()) i = neyronin.size() - 1;
	 else i = weight.size() - 1;

	 while (i >= 0)
	 {

		 signed char t3 = neyronin[i];
		 signed char t4 = weight[i];
		 signed char t1 = obj.multtt(t3, t4);
		 signed char t10 = obj4.relum(t1);

		 vzveshney.push_back(t10);
		 i--;


	 }
	 signed char t2 = 0;

	 i = vzveshney.size() - 1;


	 while (i >= 0)
	 {

		 signed char t5 = neyronin[i];
		 signed char t6 = weight[i];
		 t2 = obj.plusss(t2, vzveshney[i]);
		 i--;


	 }

	 return (t2);


 }





 vector<signed char> Neyron::valueneyOneTwor(vector<signed char>& neyronin, vector<signed char>& weight)

 {

	 Signch obj;
	 Relu obj4;

	 vector<signed char> vzveshney = {};
	 if (neyronin.empty() || weight.empty()) return (vzveshney);



	 int32_t i1 = 0;
	 if (weight.size() > neyronin.size()) i1 = neyronin.size() - 1;
	 else i1 = weight.size() - 1;

	 for (int32_t i = 0; i <= i1; i++)
	 {

		 signed char t3 = neyronin[i];
		 signed char t4 = weight[i];
		 signed char t1 = obj.multtt(t3, t4);
		 signed char t10 = obj4.relup(t1);

		 vzveshney.push_back(t10);

	 }



	 return (vzveshney);


 }




 vector<signed char> Neyron::valueneyOneTworm(vector<signed char>& neyronin, vector<signed char>& weight)

 {

	 Signch obj;
	 Relu obj4;

	 vector<signed char> vzveshney = {};
	 if (neyronin.empty() || weight.empty()) return (vzveshney);



	 int32_t i1 = 0;
	 if (weight.size() > neyronin.size()) i1 = neyronin.size() - 1;
	 else i1 = weight.size() - 1;

	 for (int32_t i = 0; i <= i1; i++)
	 {

		 signed char t3 = neyronin[i];
		 signed char t4 = weight[i];
		 signed char t1 = obj.multtt(t3, t4);
		 signed char t10 = obj4.relum(t1);

		 vzveshney.push_back(t10);

	 }



	 return (vzveshney);


 }


 vector<signed char > Neyron::deltaout(vector<signed char >& delta, const signed char& neyrontest, const signed char& neyrontestres)

 {
	 Signch obj;

	 int32_t t0 = delta.size();

	 while (t0 > 0)

	 {
		 delta.pop_back();
		 t0 = delta.size();
	 }

	 signed char t1 = obj.minusss(neyrontest, neyrontestres);
	 delta.push_back(t1);

	 return delta;

 }


 void Neyron::dellayerlast(vector<vector<signed char>>& Weights3, int32_t Quoter, vector<vector<signed char>>& Outputs2, const signed char& delta)

 {
	 Signch obj;

	 int32_t t1 = Outputs2[Quoter].size();
	 int32_t t10 = Outputs2.size();

	 signed char alpha3 = 100;

	 for (int32_t i = 0; i < t1; i++)
	 {
		 signed char t2 = obj.multtt(Outputs2[Quoter][i], delta);
		 signed char t3 = obj.multtt(t2, alpha3);
		 Weights3[0][i] = obj.minusss(Weights3[0][i], t2);

	 }


 }


 signed char Neyron::deltaMiddle(int32_t Weightslsize, vector<signed char >& Weights, vector<signed char >& delta, signed char& alpha, signed char& Outputs)
 {
	 Relu obj;
	 Signch obj1;
	 signed char deltaraw = 0;
	 if (obj.reludivp(Outputs) == 0) { return 0; }
	 else
	 {
		 
		 for (int32_t i6 = 0; i6 < Weightslsize; i6++)
		 {
			 
			 signed char sdeltaraw = obj1.multtt(Weights[i6], delta[i6]);
			 deltaraw = obj1.plusss(deltaraw, sdeltaraw);
			 if (deltaraw == 120 || deltaraw == -120) break;

		 }

		 return deltaraw;
	 }
	 
	 
 }


 signed char Neyron::deltafin(int32_t Weightslsize, signed char & Weight, signed char& delta, signed char& alpha, signed char& Outputs)
 {
	 Relu obj;
	 Signch obj1;
	 signed char deltaraw = 0;
	 if (obj.reludivp(Outputs) == 0) { return 0; }
	 else
	 {

		 

			 signed char sdeltaraw = obj1.multtt(Weight, delta);
			 deltaraw = obj1.plusss(deltaraw, sdeltaraw);
			 if (deltaraw == 120 || deltaraw == -120) 

		 

		 return deltaraw;
	 }


 }



 signed char Neyron::deltaMiddlem(int32_t Weightslsize, vector<signed char >& Weights, vector<signed char >& delta, signed char& alpha, signed char& Outputs)
 {
	 Relu obj;
	 Signch obj1;
	 signed char deltaraw = 0;
	 if (obj.reludivm(Outputs) == 0) { return 0; }
	 else
	 {

		 for (int32_t i6 = 0; i6 < Weightslsize; i6++)
		 {

			 signed char sdeltaraw = obj1.multtt(Weights[i6], delta[i6]);
			 deltaraw = obj1.plusss(deltaraw, sdeltaraw);
			 if (deltaraw == 120 || deltaraw == -120) break;

		 }

		 return deltaraw;
	 }
 }

 signed char Neyron::deltafinm(int32_t Weightslsize, signed char& Weight, signed char& delta, signed char& alpha, signed char& Outputs)
 {
	 Relu obj;
	 Signch obj1;
	 signed char deltaraw = 0;
	 if (obj.reludivp(Outputs) == 0) { return 0; }
	 else
	 {



		 signed char sdeltaraw = obj1.multtt(Weight, delta);
		 deltaraw = obj1.plusss(deltaraw, sdeltaraw);
		 if (deltaraw == 120 || deltaraw == -120)



			 return deltaraw;
	 }


 }


 vector<signed char > Neyron::MiddleTeach(vector<signed char >& Weights, signed char& Output, signed char& delta, int32_t& size, signed char& alpha)
 {
	 Relu obj;
	 Signch obj1;

	 for (int32_t i1 = 0; i1 < size; i1++)
	 {
		
		 signed char t1 = obj1.multtt(Output, delta);
		 signed char t2 = obj1.multtt(t1, alpha);
		 Weights[i1] = obj1.minusss(Weights[i1], t1);
		// Weights[i1] = obj1.multtt(Weights[i1], alpha);

			

	 }
	 return Weights;
 }