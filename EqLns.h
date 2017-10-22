#ifndef EQLNS_H
#define EQLNS_H
#include "Matrix.h"

class EqLns : public Matrix 
{
public:
	EqLns(int n);
	~EqLns();
	void solve (Matrix& b, Matrix& result);
	void diagMatrix(Matrix& upper, Matrix& lower);
	
private:
	void backwardSubstitution(Matrix& z, Matrix& x, Matrix& upper);
	void forwardSubstitution(Matrix& z, Matrix& b, Matrix& lower);

};

#endif // EQLNS_H
