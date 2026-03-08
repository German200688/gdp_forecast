// OB1.cpp: определяет точку входа для приложения.
//

#include "OB1.h"
#include <chrono>
#include <cstdint>

using namespace std;








signed char Signch::scale(signed char draft) {
	if (draft >= 120) return 120;
	if (draft <= -120) return -120;
	return draft;
}


signed char Signch::plusss(signed char ap, signed char bp)
{
	if (ap > 60 && bp > 60 || ap > 50 && bp > 70 || ap > 40 && bp > 80 || ap > 30 && bp > 90 || ap > 20 && bp > 100 || ap > 10 && bp > 110 || ap > 0 && bp > 120 || bp > 50 && ap > 70 || bp > 40 && ap > 80 || bp > 30 && ap > 90 || bp > 20 && ap > 100 || bp > 10 && ap > 110 || bp > 0 && ap > 120) return 100;
	else if (ap < -60 && bp < -60 || ap < -50 && bp < -70 || ap < -40 && bp < -80 || ap < -30 && bp < -90 || ap < -20 && bp < -100 || ap < -10 && bp < -110 || ap < -0 && bp < -120 || bp < -50 && ap < -70 || bp < -40 && ap < -80 || bp < -30 && ap < -90 || bp < -20 && ap < -100 || bp < -10 && ap < -110 || bp < -0 && ap < -120) return -100;
	else
	{
		signed char d1 = ap + bp;
		signed char d2 = scale(d1);
		return d2;
		

	}	

}


signed char Signch::minusss(signed char am, signed char bm)
{
	bm = -bm; 
	if (am == bm) return 0;
	signed char e2  = Signch::plusss(am, bm);
	return e2;
}


signed char Signch::multtt(signed char amul, signed char bmul)
{
	int32_t m1 = amul;
	int32_t m2 = bmul;
	int32_t m3 = m1 * m2;
	m3 = m3 / 100;
	if (m3 > 120) m3 = 120;
	if (m3 < - 120) m3 = - 120;
	signed char m4;
	m4  = signed char(m3);
	return m4;

}


int32_t Signch::maxWeight(const vector<signed char>& neyronout)
{
	
	
	signed char maxWeight = neyronout[0];
	int32_t t0 = 0;

	for (size_t i = 1; i < neyronout.size(); ++i) {
		if (neyronout[i] > maxWeight) {
			maxWeight = neyronout[i];
			t0 = i;
		}
	}

	return t0;

	
}
