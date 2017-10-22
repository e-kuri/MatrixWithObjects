#include "Matrix.h"
#include <stdlib.h> 
#include <iostream>

using namespace std;

Matrix::Matrix()
{
	buildMatrix(3,3);
}

Matrix:: Matrix (int n, int m)
{
	buildMatrix(n,m);
}

Matrix::~Matrix()
{
	free(_matrix);
}

void Matrix::buildMatrix (int n, int m) {
    _n=n;
    _m=m;

    if ((_matrix = (float**)malloc( n*sizeof(float*))) == NULL)
    {
        std::cout << "Error al alojar la memoria de n";
    }

    for (int i=0; i<n; i++){
      if ((_matrix[i]=(float*)malloc(m*sizeof(float)))==NULL)
      {
          cout << "Error al alojar la memoria de m";
      }
    }
}


void Matrix::printMatrix (){
    int i,j;
    for (i=0; i<_n; i++){
            cout << "\n";
        for (j=0; j<_m; j++){
            cout << _matrix[i][j];
            cout << "\t";
        }
    }
	cout << "\n\n";
}

int Matrix::getN ()
{
	return _n;
}

int Matrix::getM ()
{
	return _m;
}

float& Matrix::getValue(int i, int j)
{
	return _matrix[i][j];
}

float Matrix::getDiagVal(Matrix& lower, Matrix& upper, int i, int j, int n, bool isUpper){
    float sum = _matrix[i][j];
    float div;
        if (isUpper) {
            for (int k = 0; k < n; k++) {
                if(k != i){
                    sum -= lower.getValue(i,k) * upper.getValue(k,j);
                }else{
                    div = lower.getValue(i,k);
                }
            }
        }
        else {
            for (int k = 0; k < n; k++) {
                if (k != j) {
                    sum -= lower.getValue(i,k) * upper.getValue(k,j);
                }else{
                    div = upper.getValue(k,j);
                }
            }
        }
    return sum / div;
}

void Matrix::diagMatrix(Matrix& upper, Matrix& lower){
    if(_m != _n){
        cout << "La matriz debe ser cuadrada para ser diagonalizable";
        return;
    }

    //Inicializamos la matriz triangular superior
    for (int i = 0; i<_n; i++) {
        for (int j = 0; j<i; j++) {
            upper.getValue(i,j) = 0;
        }
    }

    //Inicializamos la matriz triangular inferior
    for (int i = 0; i<_n; i++) {
        for (int j = i; j<_m; j++) {
            if (i == j) {
                lower.getValue(i,j) = 1;
            }
            else {
                lower.getValue(i,j) = 0;
            }

        }
    }

    int j = 0;
    while (j < _m) {
        for (int i = 0; i<_n; i++) {
            if (j >= i) {
                upper.getValue(i,j) = getDiagVal(lower, upper, i, j, _n, true);
            }
            else {
                lower.getValue(i,j) = getDiagVal(lower, upper, i, j, _n, false);
            }
        }
        j++;
    }
}