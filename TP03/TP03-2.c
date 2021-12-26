/*
 * TP03-2.c
 *
 *  Created on: 4 Kas 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

int myPower(int a, int b);

int main(){

	int inputBase;
	int inputPower;
	int output;

	printf("Entrez la base et l'exposant: ");
	fflush(stdout);
	scanf("%d %d", &inputBase, &inputPower);

	output = myPower(inputBase, inputPower);
	printf("Resultat: %d", output);
	return 0;
}

int myPower(int a, int b){
	int result = 1;

	for(int i = 0; i < b; i++){
		result *= a;
	}
	return result;
}
