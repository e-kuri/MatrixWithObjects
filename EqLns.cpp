#include "EqLns.h"
#include <iostream>

using namespace std;

EqLns::EqLns(int n):Matrix(n, n)
{
	
}

EqLns::~EqLns()
{
}

/*
void EqLns::backwardSubstitution(Matrix& z, Matrix& x, Matrix& upper){
	for(int i=x.getN() - 2; i>=0; i--)
	{
		float acc = 0.0;
		for(int j=i+1; j<x.getN(); j++ )
		{
			acc += upper.getValue(i, j) * x.getValue(j,0);
		}
		acc += z.getValue(i, 0);
		x.getValue(i, 0) = acc / upper.getValue(i,i);
	}
}
*/

void EqLns::backwardSubstitution(Matrix& z, Matrix& x, Matrix& upper){
	for(int i=x.getN() - 1; i>=0; i--)
	{
		float acc = 0.0;
		for(int j=i+1; j<x.getN(); j++)
		{
			acc += upper.getValue(i,j)*x.getValue(j,0);
		}
		acc = z.getValue(i,0) - acc;
		x.getValue(i,0) = acc / upper.getValue(i,i);
	}
}

void EqLns::forwardSubstitution(Matrix& z, Matrix& b, Matrix& lower){
	for(int i=0; i<z.getN(); i++){
		float result = 0.0;
		for(int j=0; j<i; j++)
		{
			result += lower.getValue(i,j) * z.getValue(j,0);
		}
		result = b.getValue(i, 0) - result;
		z.getValue(i, 0) = result / lower.getValue(i, i);
	}
}

void EqLns::solve (Matrix& b, Matrix& result){
	
	if(b.getM() != 1 || b.getN() != getN())
	{
		cout << "El vector b debe ser de Nx1";
	}
	Matrix upper = Matrix(getN(), getM());
	Matrix lower = Matrix(getN(), getM());
	diagMatrix(upper, lower);
	cout << "upper:\n";
	upper.printMatrix();
	cout << "lower:\n";
	lower.printMatrix();
	Matrix z = Matrix(getN(), 1);
	forwardSubstitution(z, b, lower);
	cout << "z:\n";
	z.printMatrix();
	backwardSubstitution(z, result, upper);
}

void EqLns::diagMatrix(Matrix& upper, Matrix& lower){
	Matrix::diagMatrix(upper, lower);
}