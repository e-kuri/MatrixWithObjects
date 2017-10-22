#ifndef EQLNS_H
#define EQLNS_H
#include "Matrix.h"

class EqLns : public Matrix 
{
public:
	EqLns(int n);
	~EqLns();
	//void solve (Matrix& b, Matrix& result);

};

#endif // EQLNS_H
