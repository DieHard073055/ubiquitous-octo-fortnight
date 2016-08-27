#include <stdio.h>
#define SIZE 6

int A[SIZE][SIZE] = {
	{1, 2, 3, 4, 5, 6},
	{2, 3, 4, 5, 6, 7},
	{3, 4, 5, 6, 7, 8},
	{4, 5, 6, 7, 8, 9},
	{5, 6, 7, 8, 9, 10},
	{6, 7, 8, 9, 10, 11}
};
int X[SIZE] = { -2, -5, 6, 3, 2, 7 };
int Y[SIZE][SIZE];

int main(){
	
	int i=0, j=0;

	printf("RME10001/HES1300 Robotics and mechatronics Project 1\n\n\n");
	printf("Question 1 : 2D Matrix with 1D Matrix Multiplicaton\n\n");
	printf("Matrix A : \n\n");
	
	for(i=0; i<(SIZE); i++){
		for(j=0; j<(SIZE); j++){
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	printf("\n\nMatrix X : \n\n");
	
	for(i=0; i<SIZE; i++){
		printf("%d\n", X[i]);
	}
	printf("\n");

	for(i=0; i<SIZE; i++){
		for(j=0; j<SIZE; j++){
			Y[i][j] = A[i][j] * X[j];			
		}
	}	

	printf("\n\nMatrix Y : \n\n");
	
	for(i=0; i<(SIZE); i++){
                for(j=0; j<(SIZE); j++){
                        printf("%d ", Y[i][j]);
                }
                printf("\n");
        }

	return 0;
}
