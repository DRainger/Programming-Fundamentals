#include "CMatrixFun.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>



CMatrixFun::CMatrixFun() :row(1), col(1)
{
	*matrix = new double[row];
	*matrix[0] = 1;
}

CMatrixFun::CMatrixFun(int r, int c) : row(r), col(c)
{
	matrix = new double*[row];
	for (int i = 0; i < col; i++) 
		matrix[i] = new double[col];
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			matrix[r][c] = Generate();

}

CMatrixFun::CMatrixFun(const CMatrixFun & source) : row(source.row), col(source.col)
{
	matrix = new double*[row];
	for (int i = 0; i < col; i++)
		matrix[i] = new double[col];
	for (int r = 0; r < row; r++)
		for (int c = 0; c < col; c++)
			matrix[r][c] = source.matrix[r][c];
}

void CMatrixFun::Print() const
{
	for (int r = 0; r < row; r++) {
		for (int c = 0; c < col; c++)
			cout << matrix[r][c] << " ";
		cout << endl;
	}

}


CMatrixFun::~CMatrixFun()
{
}

double Generate()
{
	return rand() % 31;
}
