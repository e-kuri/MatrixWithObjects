#ifndef MATRIX_H
#define MATRIX_H

class Matrix
{
private:
	float ** _matrix;
	int _n;
	int _m;
	void buildMatrix (int n, int m);
	float getDiagVal(Matrix& lower, Matrix& upper, int i, int j, int n, bool isUpper);	
	
public:
	//Constructor por defecto que genera una matriz de 3x3
	Matrix();
	
	//Constructor en donde se establecen en n’umero de renglones (n) y columnas (m).
	Matrix(int n,int m);
	
	//Destructor (libera la memoria reservada din’amicamente).
	~Matrix();
	
	void printMatrix ();
	
	int getN ();
	int getM ();
	
	//Regresa la i,j-es’ima localidad de la matriz
	float& getValue(int i, int j);
	
	//Contruye la matriz diagonal superior (ceros debajo de la diagonal).
	void diagMatrix(Matrix& upper, Matrix& lower);

};

#endif // MATRIX_H
