#pragma once
#include "Tools.h"

//This provides a function allocating the memory space of an array
double* createDynamicDoubleArray_rtn(int);
void createDynamicDoubleArray_prm(double**, int);

double** createDynamicDoubleMatrix2D(int, int);

//araySize (second parameter) is the actual number of elements of the array
void readDoubleVector(double*, int);
void readDoubleVector_arr(double[], int);
void printDoubleVector(double*, int);

void readIntegerVector(int*, int);