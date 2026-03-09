


class nvidiac
{
public:
	void addobj(signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d, int N);
	void delobj(signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);
	void deltaMiddlema(int32_t& Weightslsize, signed char*& Weightsl, signed char*& delta, signed char& deltal, signed char& alpha, signed char*& Outputs, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);
	void deltaMiddlemam(int32_t& Weightslsize, signed char*& Weightsl, signed char*& delta, signed char& deltal, signed char& alpha, signed char*& Outputs, signed char*& vec_a, signed char*& vec_b, signed char*& vec_c, signed char*& vec_d);
	void MiddleTeachM(signed char*& Weightsl, int32_t& size, signed char& rawdate, signed char*& vec_d, signed char*& vec_a)
};