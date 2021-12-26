/*
 * TP02-5.c
 *
 *  Created on: 28 Eki 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

int main(){
		int userInput;
		int counter;

		printf("Entrez un entier positif: ");
		fflush(stdout);
		scanf("%d", &userInput);
		counter = userInput;

		while (counter>=0){
			printf("%d ", counter);
			counter--;
		}

		printf("\n");
		counter = 0;

		while(counter<=userInput){
			printf("%d ", counter);
			counter++;
		}
		return 0;
}
