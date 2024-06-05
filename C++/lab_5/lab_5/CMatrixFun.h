#pragma once
#ifndef _CMATRIXFUN_H
#define _CMATRIXFUN_H
using namespace std;

class CMatrixFun
{
	double **matrix;
	int row, col;

public:
	CMatrixFun();
	CMatrixFun(int row, int col);
	CMatrixFun(const CMatrixFun&);
	void Print()const;

	~CMatrixFun();
};
double Generate();
#endif //_CMATRIXFUN_H

