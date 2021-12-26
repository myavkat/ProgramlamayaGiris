/*
 * TP03-0.c
 *
 *  Created on: 4 Kas 2021
 *      Author: Mehmet Yavuz Katrancı
 */

#include<stdio.h>

double g(double r);

int main(){
	double input, output;

	printf("Entrez un entier reel: ");
	fflush(stdout);
	scanf("%lf", &input);

	output = g(input);

	printf(">>g(%.2lf) = %.2lf", input, output);

	return 0;
}

double g(double r){
	double result;
	result = r*r*r + 25*r*r + 10*r + 7;
	return result;
}
