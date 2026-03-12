
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



__global__ void finplussdelm(signed char& ab, signed char*& dvec_a4, signed char*& dvec_b4, int size, signed char*& dvec_c4)

{


	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > size - 1) return;

	if (dvec_a4[th0] >= 0) { return; }
	else {
		int m1 = ab;
		int m2 = dvec_b4[th0];
		int m3 = m1 * m2;
		m3 = m3 / 100;
		if (m3 > 120) m3 = 120;
		if (m3 < -120) m3 = -120;
		dvec_c4[th0] = signed char(m3);
	}
}


__global__ void finplussdel(signed char& ab, signed char*& dvec_a4, signed char*& dvec_b4, int size, signed char*& dvec_c4)

{
	
	
	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > size - 1) return;
	
	if (dvec_a4[th0] <= 0) { return; }
	else {
		int m1 = ab;
		int m2 = dvec_b4[th0];
		int m3 = m1 * m2;
		m3 = m3 / 100;
		if (m3 > 120) m3 = 120;
		if (m3 < -120) m3 = -120;
		dvec_c4[th0] = signed char(m3);
	}
}


__global__ void plusssm(signed char*& ap, signed char*& bp, signed char*& d2, int N)
{
	
	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
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
	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
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

__global__ void multttmrelp(signed char& amul, signed char*& bmul, signed char*& rel, signed char*& m4, int N)
{
	
	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > N - 1) return;
	if (rel <= 0) { m4[th0] = 0;  return;}
	else {
		int m1 = amul;
		int m2 = bmul[th0];
		int m3 = m1 * m2;
		m3 = m3 / 100;
		if (m3 > 120) m3 = 120;
		if (m3 < -120) m3 = -120;
		m4[th0] = signed char(m3);
	}

}



__global__ void multttmrelm(signed char& amul, signed char*& bmul, signed char*& rel, signed char*& m4, int N)
{

	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > N - 1) return;
	if (rel >= 0) { m4[th0] = 0;  return; }
	else {
		int m1 = amul;
		int m2 = bmul[th0];
		int m3 = m1 * m2;
		m3 = m3 / 100;
		if (m3 > 120) m3 = 120;
		if (m3 < -120) m3 = -120;
		m4[th0] = signed char(m3);
	}

}


void nvidiac::addobj(signed char*& dvec_a1, signed char*& dvec_b1, signed char*& dvec_c1, signed char*& vec_a23, signed char*& vec_b23, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& vec_a4, signed char*& vec_b4, int N1, int N23, int N4, int N44, signed char*& ab)
{


#ifdef _DEBUG
	unsigned __int64 t1, t2, t3, t4, t5, t6, t7;
	t1 = __rdtsc();
#endif
	cudaMalloc((void**)&dvec_a1, N1 * sizeof(signed char)); //3 нейрона
	cudaMalloc((void**)&dvec_b1, N1 * sizeof(signed char)); //3 нейрона
	cudaMalloc((void**)&dvec_c1, N1 * sizeof(signed char)); //3 нейрона
	//cudaMalloc((void**)&vec_a1, N1 * sizeof(signed char)); //3 нейрона
	//cudaMalloc((void**)&vec_b1, N1 * sizeof(signed char)); //3 нейрона
	//cudaMalloc((void**)&vec_c1, N1 * sizeof(signed char)); //3 нейрона

	cudaMalloc((void**)&vec_a23, N23 * sizeof(signed char)); //10 нейрона
	cudaMalloc((void**)&vec_b23, N23 * sizeof(signed char)); //10 нейрона
	//cudaMalloc((void**)&vec_c23, N23 * sizeof(signed char)); //10 нейрона
	cudaMalloc((void**)&dvec_a4, N4 * sizeof(signed char)); //6 нейрона
	cudaMalloc((void**)&dvec_b4, N4 * sizeof(signed char)); //6 нейрона
	cudaMalloc((void**)&dvec_c4, N4 * sizeof(signed char)); //6 нейрона
	cudaMalloc((void**)&vec_a4, N44 * sizeof(signed char)); //6 нейрона
	cudaMalloc((void**)&vec_b4, N44 * sizeof(signed char)); //6 нейрона
	//cudaMalloc((void**)&vec_c4, N44 * sizeof(signed char)); //6 нейрона
	cudaMalloc((void**)&ab, sizeof(signed char)); //6 нейрона
#ifdef _DEBUG	
	t2 = __rdtsc();
	t3 = t2 - t1;
	printf("time cuda6 %i \n", t3);
#endif


	//signed char*& vec_a1, 
		//signed char*& vec_b1, 
		//signed char*& vec_c1, 
	//signed char*& vec_c23, 
	//signed char*& vec_c4, 



}


void nvidiac::delobj(signed char*& dvec_a1, signed char*& dvec_b1, signed char*& dvec_c1, signed char*& vec_a23, signed char*& vec_b23, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& vec_a4, signed char*& vec_b4, signed char*& ab)
{
	cudaFree(dvec_a1);
	cudaFree(dvec_b1);
	cudaFree(dvec_c1);
	//cudaFree(vec_a1);
	//cudaFree(vec_b1);
	//cudaFree(vec_c1);
	
	cudaFree(vec_a23);
	cudaFree(vec_b23);
	//cudaFree(vec_c23);
	cudaFree(dvec_a4);
	cudaFree(dvec_b4);
	cudaFree(dvec_c4);
	cudaFree(vec_a4);
	cudaFree(vec_b4);
	//cudaFree(vec_c4);
	cudaFree(ab);
	

}


void nvidiac::deltaMiddlema(int32_t& Weightslsize, signed char*& Weightsl, signed char*& delta, signed char& deltal, signed char& alpha, signed char*& Outputs, signed char*& dvec_a1, signed char*& dvec_b1, signed char*& dvec_c1)
{
	int32_t t_block = 1;
	int32_t t_thread = 512;
	// определяю блоки Weightslsize - не более 1 500 000 
	if (Weightslsize < 512) { t_block = 1;}
	else
	{
		int32_t t0 = Weightslsize / 512;
		int32_t t1 = Weightslsize % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}

	// копирую
	
	
	cudaMemcpy(dvec_a1, Weightsl, Weightslsize * sizeof(signed char), cudaMemcpyHostToDevice);
	cudaMemcpy(dvec_b1, Outputs, Weightslsize * sizeof(signed char), cudaMemcpyHostToDevice);

	multttmrelp << < t_block, t_thread >> > (deltal, dvec_a1, dvec_b1, dvec_c1, Weightslsize);

	cudaMemcpy(delta, dvec_c1, Weightslsize * sizeof(signed char), cudaMemcpyDeviceToHost);

}



void nvidiac::deltaMiddlemam(int32_t& Weightslsize, signed char*& Weightsl, signed char*& delta, signed char& deltal, signed char& alpha, signed char*& Outputs, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d)
{
	int32_t t_block = 1;
	int32_t t_thread = 512;
	// определяю блоки Weightslsize - не более 1 500 000 
	if (Weightslsize < 512) { t_block = 1; }
	else
	{
		int32_t t0 = Weightslsize / 512;
		int32_t t1 = Weightslsize % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}

	// копирую

	//cudaMemcpy(vec_a, deltal, Weightslsize * sizeof(signed char), cudaMemcpyHostToDevice);
	cudaMemcpy(vec_b, Weightsl, Weightslsize * sizeof(signed char), cudaMemcpyHostToDevice);
	cudaMemcpy(vec_c, Outputs, Weightslsize * sizeof(signed char), cudaMemcpyHostToDevice);

	multttmrelm << < t_block, t_thread >> > (deltal, vec_b, vec_c, vec_d, Weightslsize);
	

	cudaMemcpy(delta, vec_d, Weightslsize * sizeof(signed char), cudaMemcpyDeviceToHost);

}


void nvidiac::MiddleTeachM(signed char*& Weightsl, int32_t& size, signed char& rawdate, signed char*& vec_d, signed char*& vec_a)
{
	
	int32_t t_block = 1;
	int32_t t_thread = 512;
	// определяю блоки Weightslsize - не более 1 500 000 
	if (size < 512) { t_block = 1; }
	else
	{
		int32_t t0 = size / 512;
		int32_t t1 = size % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}
	
	
	//cudaMemcpy(vec_d, Weightsl, size * sizeof(signed char), cudaMemcpyHostToDevice);

	//multttmrelm << < t_block, t_thread >> > (rawdate, vec_d, size);
	

	//cudaMemcpy(Weightsl, vec_d, size * sizeof(signed char), cudaMemcpyDeviceToHost);


}




void nvidiac::deltafimanma4(signed char*& delta, signed char& delta1, int32_t& size, signed char*& Outputs, signed char*& Weightsl, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& ab)
{
	
	
	
	int32_t t_block = 1;
	int32_t t_thread = 512;
	// определяю блоки size - не более 1 500 000 
	if (size < 512) { t_block = 1; }
	else
	{
		int32_t t0 = size / 512;
		int32_t t1 = size % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}

	cudaMemcpy(dvec_b4, Weightsl, size * sizeof(signed char), cudaMemcpyHostToDevice);
	cudaMemcpy(dvec_a4, Outputs, size * sizeof(signed char), cudaMemcpyHostToDevice);
	//cudaMemcpy(ab, &delta1, sizeof(signed char), cudaMemcpyHostToDevice);

	finplussdel << < t_block, t_thread >> > (delta1, dvec_a4, dvec_b4, size, dvec_c4);


	cudaMemcpy(delta, dvec_c4, size * sizeof(signed char), cudaMemcpyDeviceToHost);



}



void nvidiac::deltafimanmam4(signed char*& delta, signed char& delta1, int32_t& size, signed char*& Outputs, signed char*& Weightsl, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& ab)
{



	int32_t t_block = 1;
	int32_t t_thread = 512;
	// определяю блоки size - не более 1 500 000 
	if (size < 512) { t_block = 1; }
	else
	{
		int32_t t0 = size / 512;
		int32_t t1 = size % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}

	cudaMemcpy(dvec_b4, Weightsl, size * sizeof(signed char), cudaMemcpyHostToDevice);
	cudaMemcpy(dvec_a4, Outputs, size * sizeof(signed char), cudaMemcpyHostToDevice);
	//cudaMemcpy(ab, &delta1, sizeof(signed char), cudaMemcpyHostToDevice);

	finplussdelm << < t_block, t_thread >> > (delta1, dvec_a4, dvec_b4, size, dvec_c4);


	cudaMemcpy(delta, dvec_c4, size * sizeof(signed char), cudaMemcpyDeviceToHost);



}





