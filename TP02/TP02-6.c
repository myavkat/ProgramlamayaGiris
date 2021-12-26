/*
 * TP02-6.c
 *
 *  Created on: 28 Eki 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

int main(){
	int userInput;
	int rowNumber = 1;
	int repetition = 0;

	printf("Entrez un entier positif: ");
	fflush(stdout);
	scanf("%d", &userInput);

	while(rowNumber<=userInput){

		while(repetition<rowNumber){
			printf("%d", rowNumber);
			repetition++;
		}

		printf("\n");
		repetition = 0;
		rowNumber++;
	}

	return 0;
}
