/*
 * TP03-1.c
 *
 *  Created on: 4 Kas 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

int laSomme(int n);

int main(){

	int input, output;

	printf("Entrez un entier positif: ");
	fflush(stdout);
	scanf("%d", &input);

	output = laSomme(input);

	printf("La somme est %d", output);

	return 0;
}

int laSomme(int n){
	int total = 0;

	for(int i = 1; i<=n ; i++){
		total += i;
	}

	return total;
}
