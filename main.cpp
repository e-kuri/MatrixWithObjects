#include "EqLns.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>


void fillRandomMatrix (Matrix& matrix)
{
	srand((unsigned)time(NULL));
	
	for (int i=0; i<matrix.getN(); i++){
		for (int j=0; j<matrix.getM(); j++){
			matrix.getValue(i,j) = rand()%10;			
		}
	}
		
}

void fill3x3Matrix(Matrix& matrix)
{
	matrix.getValue(0,0) = 2;
	matrix.getValue(0,1) = 0;
	matrix.getValue(0,2) = 0;
	matrix.getValue(1,0) = 3;
	matrix.getValue(1,1) = 4;
	matrix.getValue(1,2) = 0;
	matrix.getValue(2,0) = 2;
	matrix.getValue(2,1) = 1;
	matrix.getValue(2,2) = 5;
}

void fill4x4Matrix(Matrix& matrix)
{
	matrix.getValue(0,0) = 1;
	matrix.getValue(0,1) = 2;
	matrix.getValue(0,2) = 1;
	matrix.getValue(0,3) = 6;
	matrix.getValue(1,0) = 2;
	matrix.getValue(1,1) = 8;
	matrix.getValue(1,2) = 2;
	matrix.getValue(1,3) = 6;
	matrix.getValue(2,0) = 1;
	matrix.getValue(2,1) = 2;
	matrix.getValue(2,2) = 7;
	matrix.getValue(2,3) = 9;
	matrix.getValue(3,0) = 2;
	matrix.getValue(3,1) = 7;
	matrix.getValue(3,2) = 5;
	matrix.getValue(3,3) = 4;
}

int main(int argc, char **argv)
{
	EqLns matrix = EqLns(4);
	Matrix b = Matrix(4, 1);
	b.getValue(0,0) = 32;
	b.getValue(1,0) = 48;
	b.getValue(2,0) = 62;
	b.getValue(3,0) = 47;
	b.printMatrix();
	Matrix x = Matrix(4, 1);
	fill4x4Matrix(matrix);
	std::cout << "matrix:\n";
	matrix.printMatrix();
	matrix.solve(b, x);
	std::cout << "x:\n";
	x.printMatrix();
}
