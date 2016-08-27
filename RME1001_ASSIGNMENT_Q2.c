#include <stdio.h>

#define AC 5
#define AR 3
#define BC 4
#define BR 5


float A[AR][AC]={
	{2, (float)-1/3, 0, (float)2/3, 4},
	{(float)1/2, (float)3/2, 4, -2, 1},
	{0, 3, (float)-9/7, (float)6/7, (float)4/3}
};
float B[BR][BC]={
	{(float)6/5, 0, -2, (float)1/3},
	{5, (float)7/2, (float)3/4, (float)-3/2},
	{0, -1, 1, 0},
	{(float)9/2, (float)3/7, -3, 3},
	{4, (float)-1/2, 0, (float)3/4}
};
float C[AC][BR];

int main(){
	int i=0, j=0;
	
	
	printf("RME10001/HES1300 Robotics and mechatronics Project 1\n\n\n");
        printf("Question 2 : 2D Matrix with 2D Matrix Multiplicaton\n\n");
        printf("Matrix A : \n\n");


	for(i=0; i<AR; i++){
		for(j=0; j<AC; j++){
			C[i][i] = A[i][j];
			printf("%lf ", A[i][j]);
		}printf("\n");
	}
	
	printf("\n\n MATRIX B : \n\n");

	for(i=0; i<BR; i++){
		for(j=0; j<BC; j++){
			C[i][i] = A[i][j];
			printf("%lf ",B[i][j]);
		}printf("\n");
	}
	
	printf("\n\n MATRIX C : \n\n");
	
	for(i=0; i<AC; i++){
		for(j=0; j<BR; j++){
			C[j][i] = A[i][j] * B[j][i];
			printf("%.3lf ", C[i][j]);	
		}printf("\n");
	}	
	
	return 0;
}
