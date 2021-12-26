/*
 * TP02-4.c
 *
 *  Created on: 28 Eki 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

int main(){
	int userInput;
	int number = 0;
	int sum = 0;

	printf("Entrez un entier positif: ");
	fflush(stdout);
	scanf("%d", &userInput);

	while(number<=userInput){
		printf("%d ", number);
		sum += number;
		number++;
	}
	printf("\n");
	printf("La somme est %d", sum);

	return 0;
}
