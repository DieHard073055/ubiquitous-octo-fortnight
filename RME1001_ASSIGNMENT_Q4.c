#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float * numbers;
int size;

void read();
float mean(float *nums);
float deviation();

int main(){
	printf("RME10001/HES1300 Robotics and mechatronics Project 1\n\n\n");
        printf("Question 2 : 2D Matrix with 2D Matrix Multiplicaton\n\n");
	read();
	printf("deviation : %f\n", deviation());
return 0;
}

void read(){
	int num_input, i=0;
	
	printf("Enter number of inputs : ");
	scanf("%d", &num_input);
	size = num_input;
	
	numbers = (float *) calloc (num_input, sizeof(float));
	
	for(i=0; i<num_input; i++){
		printf("\nPlease Enter Input %i : [float]", i);
		scanf("%g", &numbers[i]);
	}
	printf("Your numbers : \n\n");
	for(i=0; i<num_input; i++) printf("%.2lf\n" , numbers[i]);
	printf("\n");
}

float deviation(){
	float m;
	float * variance;
	int i;
	
	variance = (float *) calloc (size, sizeof(float));
	m=mean(numbers);
	for(i=0; i<size; i++) 
		variance[i] = (float)((numbers[i] - m) * (numbers[i] - m));
	
	return (float) sqrt(mean(variance));
}

float mean(float *nums){
	int i;
	float total=0;
	
	for(i=0; i<size; i++) total += nums[i];
	return (float)total/size;
}



