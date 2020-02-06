#include "functions.h"

double* createDynamicDoubleArray_rtn(int arraySize)
{
	double* pDoubleVector;
	//(double*) in front of the malloc: recast of the return type --> recast (void*) into (double*)
	//Explicit recast here
	//recasting can be implicit (don't write it)
	pDoubleVector = (double*)malloc(sizeof(double) * arraySize);
	//if malloc succeeds, pDoubleVector will point at the beginning of the allocated memory
	//in THE HEAP

	//This could return the NULL pointer: if the OS cannot allocate memory: malloc failling
	return pDoubleVector;
}

void createDynamicDoubleArray_prm(double** pDoubleVector, int arraySize)
{
	//pDoubleVector is pointer, so modifying it should be ok, no need for a function, with return
	*pDoubleVector = (double*)malloc(sizeof(double) * arraySize);
}

double** createDynamicDoubleMatrix2D(int nbRows, int nbColumns)
{
	double** pDynMatrix;
	int j;
	//Base array, of pointers on double*
	pDynMatrix = (double**)malloc(sizeof(double*)* nbRows);
	for (j = 0; j < nbRows; j++)
	{
		//datatype of pDynMatrix[j] = double*
		//Allocation of each sub array
		pDynMatrix[j] = (double*)malloc(sizeof(double) * nbColumns);
	}

	return pDynMatrix;
}



void readDoubleVector(double* pNumArray, int arraySize)
{
	int i;
	printf("Interactive input of a double array of %d elements\n", arraySize);
	for (i = 0; i < arraySize; i++)
	{
		printf("Please type the %d element (%d index): ", i + 1, i);
		scanf("%lf", pNumArray+i);
	}
}

void readDoubleVector_arr(double aNumbers[], int arraySize)
{
	int i;
	printf("Interactive input of a double array of %d elements\n", arraySize);
	for (i = 0; i < arraySize; i++)
	{
		printf("Please type the %d element (%d index): ", i + 1, i);
		scanf("%lf", &(aNumbers[i]));
	}
}

void printDoubleVector(double* pNumArray, int arraySize)
{
	int i;
	printf("Interactive out of a double array of %d elements\n", arraySize);
	for (i = 0; i < arraySize; i++)
	{
		printf("Element %d at index %d: %f\n", i + 1, i, pNumArray[i]);
	}
}


void readIntegerVector(int* pNumArray, int arraySize)
{
	int i;
	printf("Interactive input of a double array of %d elements\n", arraySize);
	for (i = 0; i < arraySize; i++)
	{
		printf("Please type the %d element (%d index): ", i + 1, i);
		scanf("%d", (pNumArray + i));
	}
}