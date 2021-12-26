/*
 * TP03-3.c
 *
 *  Created on: 4 Kas 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>
#include <math.h>

float leMax(float a, float b, float c);
float leMin(float a, float b, float c);

int main(){

	float input1, input2, input3, outputMax, outputMin, difference;

	printf("Entrez 3 entiers reels: ");
	fflush(stdout);
	scanf("%f %f %f", &input1, &input2, &input3);

	outputMax = leMax(input1, input2, input3);
	outputMin = leMin(input1, input2, input3);
	difference = outputMax - outputMin;

	printf("Max: %lf\nMin: %lf\nDifference: %lf", outputMax, outputMin, difference);

	return 0;
}
/*bu soruda math.h'ý kullanmamamýz ile ilgili bir yönerge bulunmuyor
ve de 2 yerine 3 input aldýðý için direk fmax ve fmin ile ayný da deðil*/
float leMax(float a, float b, float c){
	return fmax(fmax(a, b), c);
}

float leMin(float a, float b, float c){
	return fmin(fmin(a, b), c);
}
