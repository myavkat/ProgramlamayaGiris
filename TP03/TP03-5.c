/*
 * TP03-5.c
 *
 *  Created on: 4 Kas 2021
 *      Author: Mehmet Yavuz Katrancı
 */

#include<stdio.h>

void afficheMultiple(int baseNumber, int limit);

int main(){
	int inputNumber, inputLimit;

	printf("Entrez un entier positif et un nombre limite: ");
	fflush(stdout);
	scanf("%d %d", &inputNumber, &inputLimit);

	afficheMultiple(inputNumber, inputLimit);

	return 0;
}

void afficheMultiple(int baseNumber, int limit){
	int sum = 0;

	while (sum + baseNumber < limit){
		sum += baseNumber;
		printf("%d ", sum );
	}
}
