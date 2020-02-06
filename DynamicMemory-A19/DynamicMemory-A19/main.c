#include "functions.h"


int main()
{

	//Stack based, statically allocated double vector
	double numVector[5] = {1,2,3,4, 5}; // datatype of numVector = double*, each item of array is a double
	
	double Matrix2by2[2][2] = { {1,2},{3,4} };
	int i, j;

	//outer loop
	for (i = 0; i < 2; i++)
	{
		//inner loop -- faster progress than outer loop
		for (j = 0; j < 2; j++)
		{
			printf("%lf\t", Matrix2by2[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Base address of the static matrix: %d\n", Matrix2by2);
	printf("Base pointers of the static matrix:\n");
	for (int k = 0; k < 2; k++)
		printf("%d\t", Matrix2by2[k]);
	printf("\n");
	for (i = 0; i < 2; i++)
	{
		//inner loop -- faster progress than outer loop
		for (j = 0; j < 2; j++)
		{
			printf("%d\t", &(Matrix2by2[i][j]));
		}
		printf("\n");
	}
	printf("\n\n");
	double** pDynamicMatrix;

	pDynamicMatrix = createDynamicDoubleMatrix2D(2, 3);
	pDynamicMatrix[0][0] = 1;
	pDynamicMatrix[0][1] = 2;
	pDynamicMatrix[0][2] = 3;
	pDynamicMatrix[1][0] = 4;
	pDynamicMatrix[1][1] = 5;
	pDynamicMatrix[1][2] = 6;

	//outer loop
	for (i = 0; i < 2; i++)
	{
		//inner loop -- faster progress than outer loop
		for (j = 0; j < 3; j++)
		{
			printf("%lf\t", pDynamicMatrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Base address of the dynamic matrix: %d\n", pDynamicMatrix);
	printf("Base pointers of the dynamic matrix:\n");
	for (int k = 0; k < 2; k++)
		printf("%d\t", pDynamicMatrix[k]);
	printf("\n");

	for (i = 0; i < 2; i++)
	{
		//inner loop -- faster progress than outer loop
		for (j = 0; j < 3; j++)
		{
			printf("%d\t", &(pDynamicMatrix[i][j]));
		}
		printf("\n");
	}




	double* pDynamicDoubleVectorA;
	double* pDynamicDoubleVectorB;
	int dynArraySize;



	
	printf("Which size for your array of double elements?: ");
	scanf("%d", &dynArraySize);
	pDynamicDoubleVectorA = createDynamicDoubleArray_rtn(dynArraySize);
	if (pDynamicDoubleVectorA != NULL)
	{
		readDoubleVector_arr(pDynamicDoubleVectorA, dynArraySize);
		printDoubleVector(pDynamicDoubleVectorA, dynArraySize);

		//we're done, releasing the memory previously given by malloc
		free(pDynamicDoubleVectorA);
		pDynamicDoubleVectorA = NULL;
	}
	else
	{
		printf("Dynamic allocation has failed\n");
	}
	
	pDynamicDoubleVectorB = NULL;
	createDynamicDoubleArray_prm(&pDynamicDoubleVectorB, dynArraySize);
	if (pDynamicDoubleVectorB != NULL)
	{
		readDoubleVector_arr(pDynamicDoubleVectorB, dynArraySize);
		printDoubleVector(pDynamicDoubleVectorB, dynArraySize);

		//we're done, releasing the memory previously given by malloc
		free(pDynamicDoubleVectorB);
		pDynamicDoubleVectorA = NULL;
	}
	else
	{
		printf("Dynamic allocation has failed\n");
	}


	double a = 10.94;
	int* pA = &a;
	double b = *pA;


	//double* pNumVector[5]; //array of 5 double* --> array of pointers
	//datatype of pNumVector = double**  , each item of array is double* 





	int intVector[5];
	intVector[0] = 100;
//	readIntegerVector(intVector, 5);


	numVector[0] = 50;
	//readDoubleVector(numVector, 5);
	readDoubleVector_arr(numVector, 5);
	printDoubleVector(numVector, 5);




	return 0;
}