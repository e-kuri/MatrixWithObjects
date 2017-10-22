#include "Matrix.h"
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

int main(int argc, char **argv)
{
	Matrix mat;
	Matrix upper;
	Matrix lower;

	//fillRandomMatrix(upper);
	//fillRandomMatrix(lower);
	fill3x3Matrix(mat);
	mat.printMatrix();
	upper.printMatrix();
	lower.printMatrix();
	mat.diagMatrix(upper, lower);
	std::cout << "upper final:\n";
	upper.printMatrix();
	std::cout << "lower final:\n";
	lower.printMatrix();
}
