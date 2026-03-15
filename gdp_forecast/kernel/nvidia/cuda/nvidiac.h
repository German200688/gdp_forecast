


class nvidiac
{
public:
	void addobj(signed char*& dvec_a1, signed char*& dvec_b1, signed char*& dvec_c1, signed char*& vec_a23, signed char*& vec_b23, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& vec_a4, signed char*& vec_b4, int N1, int N23, int N4, int N44, signed char*& ab);
	void delobj(signed char*& dvec_a1, signed char*& dvec_b1, signed char*& dvec_c1, signed char*& vec_a23, signed char*& vec_b23, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& vec_a4, signed char*& vec_b4, signed char*& ab);
	void deltaMiddlema(int64_t& Weightslsize, signed char*& Weightsl, signed char*& delta, signed char& deltal, signed char& alpha, signed char*& Outputs, signed char*& dvec_a1, signed char*& dvec_b1, signed char*& dvec_c1);
	void deltaMiddlemam(int64_t& Weightslsize, signed char*& Weightsl, signed char*& delta, signed char& deltal, signed char& alpha, signed char*& Outputs, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);	
	void MiddleTeachM(signed char*& Weightsl, signed char& rawdata, int64_t& size, signed char*& vec_d, signed char*& vec_a);
	void deltafimanma4(signed char*& delta, signed char& delta1, int64_t& size, signed char*& Outputs, signed char*& Weightsl, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& ab);
	void deltafimanmam4(signed char*& delta, signed char& delta1, int64_t& size, signed char*& Outputs, signed char*& Weightsl, signed char*& dvec_a4, signed char*& dvec_b4, signed char*& dvec_c4, signed char*& ab);

};