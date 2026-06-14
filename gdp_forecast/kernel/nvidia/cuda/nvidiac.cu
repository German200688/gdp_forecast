
#include <iostream>
#include <device_launch_parameters.h>
#include <cuda_runtime.h>
#include "nvidiac.h"

__constant__ double p12 = 120;
__constant__ double p11 = 110;
__constant__ double p10 = 100;
__constant__ double p9 = 90;
__constant__ double p8 = 80;
__constant__ double p7 = 70;
__constant__ double p6 = 60;
__constant__ double p5 = 50;
__constant__ double p4 = 40;
__constant__ double p3 = 30;
__constant__ double p2 = 20;
__constant__ double p1 = 10;
__constant__ double p0 = 10;
__constant__ double n12 = -120;
__constant__ double n11 = -110;
__constant__ double n10 = -100;
__constant__ double n9 = -90;
__constant__ double n8 = -80;
__constant__ double n7 = -70;
__constant__ double n6 = -60;
__constant__ double n5 = -50;
__constant__ double n4 = -40;
__constant__ double n3 = -30;
__constant__ double n2 = -20;
__constant__ double n1 = -10;



__global__ void finplussdelm(double ab, double* dvec_a4, double* dvec_b4, int size, double* dvec_c4, double alpha)

{


	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > size - 1) return;

	//if (dvec_a4[th0] >= 0) { return; } //релу
	//else {
		double m1 = ab;
		double m2 = dvec_b4[th0];
		double m3 = m1 * m2 * alpha;
		//m3 = m3 / 100;
		//if (m3 > 120) m3 = 120;
		//if (m3 < -120) m3 = -120;
		dvec_c4[th0] = m3;
	//}
	//printf("dHello from GPU threa %d!\n", threadIdx.x);
}


__global__ void finplussdel(double ab, double* dvec_a4, double* dvec_b4, int size, double* dvec_c4, double alpha)

{


	int th0 = blockIdx.x * blockDim.x + threadIdx.x;


	if (th0 > size - 1) return;

	if (size <= 0) { dvec_c4[th0] = 1; return; }
	else {
		double m1 = ab;
		double m2 = dvec_b4[th0];
		double m3 = m1 * m2 * alpha;
	//m3 = m3 / 100;
	//if (m3 > 120) m3 = 120;
	//if (m3 < -120) m3 = -120;

	double m4 = m3;
	dvec_c4[th0] = m4;
	
	}

	/*
	int a1 = int(dvec_a4[th0]);
	printf("dHello1111 from GPU threa %d!\n", a1);

	if (size <= 0) { dvec_c4[th0] = 0; return; }
	else {
		printf("dHello from GPU threa %d!\n", threadIdx.x);
		*/
		/*
				int m1 = ab;
				int m2 = dvec_b4[th0];
				int m3 = m1 * m2;
				m3 = m3 / 100;
				if (m3 > 120) m3 = 120;
				if (m3 < -120) m3 = -120;
				dvec_c4[th0] = double(m3);
				printf("dHello from GPU threa %d!\n", threadIdx.x);
				//printf("H1 %d!\n", dvec_c4[th0]);
	*/			

//	}

}


__global__ void plusssm(double* ap, double* bp, double* d2, int N)
{
	
	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > N - 1) return;
	
	if (ap[th0] > 60 && bp[th0] > 60 || ap[th0] > 50 && bp[th0] > 70 || ap[th0] > 40 && bp[th0] > 80 || ap[th0] > 30 && bp[th0] > 90 || ap[th0] > 20 && bp[th0] > 100 || ap[th0] > 10 && bp[th0] > 110 || ap[th0] > 0 && bp[th0] > 120 || bp[th0] > 50 && ap[th0] > 70 || bp[th0] > 40 && ap[th0] > 80 || bp[th0] > 30 && ap[th0] > 30 || bp[th0] > 20 && ap[th0] > 100 || bp[th0] > 10 && ap[th0] > 110 || bp[th0] > 0 && ap[th0] > 120) d2[th0] = 120;
	else if (ap[th0] < -60 && bp[th0] < -60 || ap[th0] < -50 && bp[th0] < -70 || ap[th0] < -40 && bp[th0] < -80 || ap[th0] < -30 && bp[th0] < -90 || ap[th0] < -20 && bp[th0] < -100 || ap[th0] < -10 && bp[th0] < -110 || ap[th0] < -0 && bp[th0] < -120 || bp[th0] < -50 && ap[th0] < -70 || bp[th0] < -40 && ap[th0] < -80 || bp[th0] < -30 && ap[th0] < -90 || bp[th0] < -20 && ap[th0] < -100 || bp[th0] < -10 && ap[th0] < -110 || bp < -0 && ap[th0] < -120) d2[th0] = 120;
	else
	{
		double d1 = ap[th0] + bp[th0];
		if (d1 >= 120) d2[th0] = 120;
		else if  (d1 <= -120) d2[th0] = -120;
		else d2[th0] = d1;
		
		
		


	}

}


__global__ void minusssm(double* am, double* bm, double* e2, int N)
{
	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > N - 1) return;
	double bm1 = -bm[th0];
	
	if (am[th0] == bm1) e2[th0] = 0;


	if (am[th0] > 60 && bm1 > 60 || am[th0] > 50 && bm1 > 70 || am[th0] > 40 && bm1 > 80 || am[th0] > 30 && bm1 > 90 || am[th0] > 20 && bm1 > 100 || am[th0] > 10 && bm1 > 110 || am[th0] > 0 && bm1 > 120 || bm1 > 50 && am[th0] > 70 || bm1 > 40 && am[th0] > 80 || bm1 > 30 && am[th0] > 30 || bm1 > 20 && am[th0] > 100 || bm1 > 10 && am[th0] > 110 || bm1 > 0 && am[th0] > 120) e2[th0] = 120;
	else if (am[th0] < -60 && bm1 < -60 || am[th0] < -50 && bm1 < -70 || am[th0] < -40 && bm1 < -80 || am[th0] < -30 && bm1 < -90 || am[th0] < -20 && bm1 < -100 || am[th0] < -10 && bm1 < -110 || am[th0] < -0 && bm1 < -120 || bm1 < -50 && am[th0] < -70 || bm1 < -40 && am[th0] < -80 || bm1 < -30 && am[th0] < -90 || bm1 < -20 && am[th0] < -100 || bm1 < -10 && am[th0] < -110 || bm < -0 && am[th0] < -120) e2[th0] = 120;
	else
	{
		double e1 = am[th0] + bm1;
		if (e1 >= 120) e2[th0] = 120;
		else if (e1 <= -120) e2[th0] = -120;
		else e2[th0] = e1;





	}
}


__global__ void minussspm(double* am, double bm, double* e2, int N, double* amm, double alpha)
//minussspm << < t_block, t_thread >> > (vec_d, delt, vec_a, size, vec_b);
{
	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > N - 1) return;
	double bm1 = bm;

	//if (am[th0] == bm1) e2[th0] = 0;


	//if (am[th0] > 60 && bm1 > 60 || am[th0] > 50 && bm1 > 70 || am[th0] > 40 && bm1 > 80 || am[th0] > 30 && bm1 > 90 || am[th0] > 20 && bm1 > 100 || am[th0] > 10 && bm1 > 110 || am[th0] > 0 && bm1 > 120 || bm1 > 50 && am[th0] > 70 || bm1 > 40 && am[th0] > 80 || bm1 > 30 && am[th0] > 30 || bm1 > 20 && am[th0] > 100 || bm1 > 10 && am[th0] > 110 || bm1 > 0 && am[th0] > 120) e2[th0] = 120;
	//else if (am[th0] < -60 && bm1 < -60 || am[th0] < -50 && bm1 < -70 || am[th0] < -40 && bm1 < -80 || am[th0] < -30 && bm1 < -90 || am[th0] < -20 && bm1 < -100 || am[th0] < -10 && bm1 < -110 || am[th0] < -0 && bm1 < -120 || bm1 < -50 && am[th0] < -70 || bm1 < -40 && am[th0] < -80 || bm1 < -30 && am[th0] < -90 || bm1 < -20 && am[th0] < -100 || bm1 < -10 && am[th0] < -110 || bm < -0 && am[th0] < -120) e2[th0] = 120;
	//else
	{
		
		double e1 = am[th0] - amm[th0] * bm1 * alpha;
		if (e1 == 0) { e1 = 0.01; }
		//if (e1 >= 120) e2[th0] = 120;
		//else if (e1 <= -120) e2[th0] = -120;
		//else 
		//if (e1 == 0) e2[th0] = 1;
		//else 
		e2[th0] = e1;





	}
}



__global__ void multttmrelp(double amul, double* bmul, double* rel, double* m4, int N, double alpha)
{
	
	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > N - 1) return;
	//if (rel <= 0) { m4[th0] = 1;  return;}
	//else {
		double m1 = amul;
		double m2 = bmul[th0];
		double m3 = m1 * m2 * alpha;
		m3 = m3;
		//if (m3 > 120) m3 = 120;
		//if (m3 < -120) m3 = -120;
		m4[th0] = m3;
	//}

}


__global__ void multttmrelm1(double amul, double* bmul, double* rel, double* m4, int N)
{

	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > N - 1) return;
	//if (rel[th0] <= 0) m4[th0] = 1;
//	else {
		double m1 = amul;
		double m2 = bmul[th0];
		double m3 = m1 * m2;
		m3 = m3; // 100;
		//if (m3 > 120) m3 = 120;
		//if (m3 < -120) m3 = -120;
		m4[th0] = m3;
//	}

}


/*
__global__ void multttmrelm(double* vec_d, double Output, double delta, int N, double alpha, double* vec_a)

{

	int th0 = blockIdx.x * blockDim.x + threadIdx.x;
	if (th0 > N - 1) return;
	else {
		int m1 = int(Output);
		int m2 = int(delta);
		int m5 = int(alpha);
		int m3 = m1 * m2;
		m3 = m3 / 100;
		if (m3 > 120) m3 = 120;
		if (m3 < -120) m3 = -120;
		vec_a[th0] = double(m3);

		m4[th0] = double(m3);


		Relu obj;
		Signch obj1;

		for (int64_t i1 = 0; i1 < size; i1++)
		{

			//	double t1 = obj1.multtt(Output, delta);
				//double t2 = obj1.multtt(t1, alpha);
			Weights[i1] = obj1.minusss(Weights[i1], t1);
			// Weights[i1] = obj1.multtt(Weights[i1], alpha);



		}
		return Weights;



	}

}
*/

void nvidiac::addobj(double*& dvec_a1, double*& dvec_b1, double*& dvec_c1, double*& vec_a23, double*& vec_b23, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& vec_a4, double*& vec_b4, int N1, int N23, int N4, int N44, double*& ab, double*& vec_c23)
{


#ifdef _DEBUG
	unsigned __int64 t1, t2, t3, t4, t5, t6, t7;
	t1 = __rdtsc();
#endif
	cudaMalloc((void**)&dvec_a1, N1 * sizeof(double)); //3 нейрона
	cudaMalloc((void**)&dvec_b1, N1 * sizeof(double)); //3 нейрона
	cudaMalloc((void**)&dvec_c1, N1 * sizeof(double)); //3 нейрона
	//cudaMalloc((void**)&vec_a1, N1 * sizeof(double)); //3 нейрона
	//cudaMalloc((void**)&vec_b1, N1 * sizeof(double)); //3 нейрона
	//cudaMalloc((void**)&vec_c1, N1 * sizeof(double)); //3 нейрона

	cudaMalloc((void**)&vec_a23, N23 * sizeof(double)); //10 нейрона
	cudaMalloc((void**)&vec_b23, N23 * sizeof(double)); //10 нейрона
	cudaMalloc((void**)&vec_c23, N23 * sizeof(double)); //10 нейрона
	cudaMalloc((void**)&dvec_a4, N4 * sizeof(double)); //6 нейрона
	cudaMalloc((void**)&dvec_b4, N4 * sizeof(double)); //6 нейрона
	cudaMalloc((void**)&dvec_c4, N4 * sizeof(double)); //6 нейрона
	cudaMalloc((void**)&vec_a4, N44 * sizeof(double)); //6 нейрона
	cudaMalloc((void**)&vec_b4, N44 * sizeof(double)); //6 нейрона
	//cudaMalloc((void**)&vec_c4, N44 * sizeof(double)); //6 нейрона
	cudaMalloc((void**)&ab, sizeof(double)); //6 нейрона
#ifdef _DEBUG	
	t2 = __rdtsc();
	t3 = t2 - t1;
	printf("time cuda6 %i \n", t3);
#endif


	//double*& vec_a1, 
		//double*& vec_b1, 
		//double*& vec_c1, 
	//double*& vec_c23, 
	//double*& vec_c4, 



}


void nvidiac::delobj(double*& dvec_a1, double*& dvec_b1, double*& dvec_c1, double*& vec_a23, double*& vec_b23, double*& vec_c23, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& vec_a4, double*& vec_b4, double*& ab)
{
	cudaFree(dvec_a1);
	cudaFree(dvec_b1);
	cudaFree(dvec_c1);
	//cudaFree(vec_a1);
	//cudaFree(vec_b1);
	//cudaFree(vec_c1);
	
	cudaFree(vec_a23);
	cudaFree(vec_b23);
	cudaFree(vec_c23);
	cudaFree(dvec_a4);
	cudaFree(dvec_b4);
	cudaFree(dvec_c4);
	cudaFree(vec_a4);
	cudaFree(vec_b4);
	//cudaFree(vec_c4);
	cudaFree(ab);
	

}


void nvidiac::deltaMiddlema(int64_t& Weightslsize, double*& Weightsl, double*& delta, double& deltal, double& alpha, double*& Outputs, double*& dvec_a1, double*& dvec_b1, double*& dvec_c1)
{
	int64_t t_block = 1;
	int64_t t_thread = 512;
	double alpha1 = alpha;
	//double alpha1 = 0.21;
	// определяю блоки Weightslsize - не более 1 500 000 
	if (Weightslsize < 512) { t_block = 1;}
	else
	{
		int64_t t0 = Weightslsize / 512;
		int64_t t1 = Weightslsize % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}

	// копирую
	
	
	cudaMemcpy(dvec_a1, Weightsl, Weightslsize * sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(dvec_b1, Outputs, Weightslsize * sizeof(double), cudaMemcpyHostToDevice);

	multttmrelp << < t_block, t_thread >> > (deltal, dvec_a1, dvec_b1, dvec_c1, Weightslsize, alpha1);

	cudaMemcpy(delta, dvec_c1, Weightslsize * sizeof(double), cudaMemcpyDeviceToHost);

}



void nvidiac::deltaMiddlemam(int64_t& Weightslsize, double*& Weightsl, double*& delta, double& deltal, double& alpha, double*& Outputs, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d)
{
	int64_t t_block = 1;
	int64_t t_thread = 512;
	// определяю блоки Weightslsize - не более 1 500 000 
	if (Weightslsize < 512) { t_block = 1; }
	else
	{
		int64_t t0 = Weightslsize / 512;
		int64_t t1 = Weightslsize % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}

	// копирую

	//cudaMemcpy(vec_a, deltal, Weightslsize * sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(vec_b, Weightsl, Weightslsize * sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(vec_c, Outputs, Weightslsize * sizeof(double), cudaMemcpyHostToDevice);

	multttmrelm1 << < t_block, t_thread >> > (deltal, vec_b, vec_c, vec_d, Weightslsize);
	
	
	cudaMemcpy(delta, vec_d, Weightslsize * sizeof(double), cudaMemcpyDeviceToHost);

}


void nvidiac::MiddleTeachM(double*& Weightsl, double*& rawdata, double& delt, int64_t& size, double*& vec_d, double*& vec_a, double*& vec_b, double alpha)
//// obj2.MiddleTeachM(Weightsl, Outputs, t01, t1, vec_d, vec_a, vec_b);
{
	
	//double alpha = 0.21;
	int64_t t_block = 1;
	int64_t t_thread = 512;
	// определяю блоки Weightslsize - не более 1 500 000 
	if (size < 512) { t_block = 1; }
	else
	{
		int64_t t0 = size / 512;
		int64_t t1 = size % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}
	
	
	cudaMemcpy(vec_d, Weightsl, size * sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(vec_b, rawdata, size * sizeof(double), cudaMemcpyHostToDevice);

	minussspm << < t_block, t_thread >> > (vec_d, delt, vec_a, size, vec_b, alpha);
	

	cudaMemcpy(Weightsl, vec_a, size * sizeof(double), cudaMemcpyDeviceToHost);


	


}




void nvidiac::deltafimanma4(double*& delta, double& delta1, int64_t& size, double*& Outputs, double*& Weightsl, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& ab, double alpha3)
{
	
	
	
	int64_t t_block = 1;
	int64_t t_thread = 512;
	

	//
	// double alpha3 = 0.21;
	// определяю блоки size - не более 1 500 000 
	if (size < 512) { t_block = 1; }
	else
	{
		int64_t t0 = size / 512;
		int64_t t1 = size % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}

	cudaMemcpy(dvec_b4, Weightsl, size * sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(dvec_a4, Outputs, size * sizeof(double), cudaMemcpyHostToDevice);
	//cudaMemcpy(ab, &delta1, sizeof(double), cudaMemcpyHostToDevice);

	finplussdel << < t_block, t_thread >> > (delta1, dvec_a4, dvec_b4, size, dvec_c4, alpha3);


	cudaMemcpy(delta, dvec_c4, size * sizeof(double), cudaMemcpyDeviceToHost);



}



void nvidiac::deltafimanmam4(double*& delta, double& delta1, int64_t& size, double*& Outputs, double*& Weightsl, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& ab, double alpha3)
{

	
	int64_t t_block = 1;
	int64_t t_thread = 512;
	//double alpha3 = 0.21;
	// определяю блоки size - не более 1 500 000 
	if (size < 512) { t_block = 1; }
	else
	{
		int64_t t0 = size / 512;
		int64_t t1 = size % 512;

		if (t1 == 0) { t_block = t0; }
		else { t_block = t0 + 1; }

	}

	cudaMemcpy(dvec_b4, Weightsl, size * sizeof(double), cudaMemcpyHostToDevice);
	cudaMemcpy(dvec_a4, Outputs, size * sizeof(double), cudaMemcpyHostToDevice);
	//cudaMemcpy(ab, &delta1, sizeof(double), cudaMemcpyHostToDevice);

	finplussdelm << < t_block, t_thread >> > (delta1, dvec_a4, dvec_b4, size, dvec_c4, alpha3);


	cudaMemcpy(delta, dvec_c4, size * sizeof(double), cudaMemcpyDeviceToHost);



}





