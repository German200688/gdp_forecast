


#pragma once
class nvidiac
{
public:
	void addobj(double*& dvec_a1, double*& dvec_b1, double*& dvec_c1, double*& vec_a23, double*& vec_b23, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& vec_a4, double*& vec_b4, int N1, int N23, int N4, int N44, double*& ab);
	void delobj(double*& dvec_a1, double*& dvec_b1, double*& dvec_c1, double*& vec_a23, double*& vec_b23, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& vec_a4, double*& vec_b4, double*& ab);
	void deltaMiddlema(int64_t& Weightslsize, double*& Weightsl, double*& delta, double& deltal, double& alpha, double*& Outputs, double*& dvec_a1, double*& dvec_b1, double*& dvec_c1);
	void deltaMiddlemam(int64_t& Weightslsize, double*& Weightsl, double*& delta, double& deltal, double& alpha, double*& Outputs, double*& vec_a, double*& vec_b, double*& vec_c, double*& vec_d);	
	void MiddleTeachM(double*& Weightsl, double& rawdata, int64_t& size, double*& vec_d, double*& vec_a);
	void deltafimanma4(double*& delta, double& delta1, int64_t& size, double*& Outputs, double*& Weightsl, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& ab);
	void deltafimanmam4(double*& delta, double& delta1, int64_t& size, double*& Outputs, double*& Weightsl, double*& dvec_a4, double*& dvec_b4, double*& dvec_c4, double*& ab);

};