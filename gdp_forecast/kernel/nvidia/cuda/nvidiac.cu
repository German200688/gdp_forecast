
#include <iostream>
#include <device_launch_parameters.h>
#include <cuda_runtime.h>
#include "nvidiac.h"

__constant__ signed char p12 = 120;
__constant__ signed char p11 = 110;
__constant__ signed char p10 = 100;
__constant__ signed char p9 = 90;
__constant__ signed char p8 = 80;
__constant__ signed char p7 = 70;
__constant__ signed char p6 = 60;
__constant__ signed char p5 = 50;
__constant__ signed char p4 = 40;
__constant__ signed char p3 = 30;
__constant__ signed char p2 = 20;
__constant__ signed char p1 = 10;
__constant__ signed char p0 = 10;
__constant__ signed char n12 = -120;
__constant__ signed char n11 = -110;
__constant__ signed char n10 = -100;
__constant__ signed char n9 = -90;
__constant__ signed char n8 = -80;
__constant__ signed char n7 = -70;
__constant__ signed char n6 = -60;
__constant__ signed char n5 = -50;
__constant__ signed char n4 = -40;
__constant__ signed char n3 = -30;
__constant__ signed char n2 = -20;
__constant__ signed char n1 = -10;



__global__ void plusssm(signed char*& ap, signed char*& bp, signed char*& d2, int N)
{
	
	int th0 = threadIdx.x;
	if (th0 > N - 1) return;
	
	if (ap[th0] > 60 && bp[th0] > 60 || ap[th0] > 50 && bp[th0] > 70 || ap[th0] > 40 && bp[th0] > 80 || ap[th0] > 30 && bp[th0] > 90 || ap[th0] > 20 && bp[th0] > 100 || ap[th0] > 10 && bp[th0] > 110 || ap[th0] > 0 && bp[th0] > 120 || bp[th0] > 50 && ap[th0] > 70 || bp[th0] > 40 && ap[th0] > 80 || bp[th0] > 30 && ap[th0] > 30 || bp[th0] > 20 && ap[th0] > 100 || bp[th0] > 10 && ap[th0] > 110 || bp[th0] > 0 && ap[th0] > 120) d2[th0] = 120;
	else if (ap[th0] < -60 && bp[th0] < -60 || ap[th0] < -50 && bp[th0] < -70 || ap[th0] < -40 && bp[th0] < -80 || ap[th0] < -30 && bp[th0] < -90 || ap[th0] < -20 && bp[th0] < -100 || ap[th0] < -10 && bp[th0] < -110 || ap[th0] < -0 && bp[th0] < -120 || bp[th0] < -50 && ap[th0] < -70 || bp[th0] < -40 && ap[th0] < -80 || bp[th0] < -30 && ap[th0] < -90 || bp[th0] < -20 && ap[th0] < -100 || bp[th0] < -10 && ap[th0] < -110 || bp < -0 && ap[th0] < -120) d2[th0] = 120;
	else
	{
		signed char d1 = ap[th0] + bp[th0];
		if (d1 >= 120) d2[th0] = 120;
		else if  (d1 <= -120) d2[th0] = -120;
		else d2[th0] = d1;
		
		
		


	}

}


__global__ void minusssm(signed char*& am, signed char*& bm, signed char*& e2, int N)
{
	int th0 = threadIdx.x;
	if (th0 > N - 1) return;
	signed char bm1 = -bm[th0];
	
	if (am[th0] == bm1) e2[th0] = 0;


	if (am[th0] > 60 && bm1 > 60 || am[th0] > 50 && bm1 > 70 || am[th0] > 40 && bm1 > 80 || am[th0] > 30 && bm1 > 90 || am[th0] > 20 && bm1 > 100 || am[th0] > 10 && bm1 > 110 || am[th0] > 0 && bm1 > 120 || bm1 > 50 && am[th0] > 70 || bm1 > 40 && am[th0] > 80 || bm1 > 30 && am[th0] > 30 || bm1 > 20 && am[th0] > 100 || bm1 > 10 && am[th0] > 110 || bm1 > 0 && am[th0] > 120) e2[th0] = 120;
	else if (am[th0] < -60 && bm1 < -60 || am[th0] < -50 && bm1 < -70 || am[th0] < -40 && bm1 < -80 || am[th0] < -30 && bm1 < -90 || am[th0] < -20 && bm1 < -100 || am[th0] < -10 && bm1 < -110 || am[th0] < -0 && bm1 < -120 || bm1 < -50 && am[th0] < -70 || bm1 < -40 && am[th0] < -80 || bm1 < -30 && am[th0] < -90 || bm1 < -20 && am[th0] < -100 || bm1 < -10 && am[th0] < -110 || bm < -0 && am[th0] < -120) e2[th0] = 120;
	else
	{
		signed char e1 = am[th0] + bm1;
		if (e1 >= 120) e2[th0] = 120;
		else if (e1 <= -120) e2[th0] = -120;
		else e2[th0] = e1;





	}
}

__global__ void multttm(signed char*& amul, signed char*& bmul, signed char*& m4, int N)
{
	
	int th0 = threadIdx.x;
	if (th0 > N - 1) return;
	
	int m1 = amul[th0];
	int m2 = bmul[th0];
	int m3 = m1 * m2;
	m3 = m3 / 100;
	if (m3 > 120) m3 = 120;
	if (m3 < -120) m3 = -120;
	m4[th0] = signed char(m3);
	

}


void nvidiac::addobj(int*& vec_a, int*& vec_b, int*& vec_c, int N)
{


#ifdef _DEBUG
	unsigned __int64 t1, t2, t3, t4, t5, t6, t7;
	t1 = __rdtsc();
#endif
	cudaMalloc((void**)&vec_a, N * sizeof(int));
	cudaMalloc((void**)&vec_b, N * sizeof(int));
	cudaMalloc((void**)&vec_c, N * sizeof(int));
#ifdef _DEBUG	
	t2 = __rdtsc();
	t3 = t2 - t1;
	printf("time cuda6 %i \n", t3);
#endif






}


void nvidiac::delobj(int*& vec_a, int*& vec_b, int*& vec_c)
{
	cudaFree(vec_a);
	cudaFree(vec_b);
	cudaFree(vec_c);

}