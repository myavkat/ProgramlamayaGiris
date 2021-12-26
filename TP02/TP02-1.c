/*
 * TP02-1.c
 *
 *  Created on: 28 Eki 2021
 *      Author: Mehmet Yavuz Katrancı
 */

#include<stdio.h>

int main(){
	int number;
	printf("Entrez un nombre entier: ");
	fflush(stdout);
	scanf("%d", &number);
	if(number<0){
		printf("%d est negatif\n", number);
	}
	else if(number>0){
		printf("%d est positif\n", number);
	}else{
		printf("0 n'est pas positif ni negatif\n");
	}

	if(number%2==1){
		printf("%d est impair\n", number);
	}else if(number%2==0){
		printf("%d est pair\n", number);
	}

	return 0;
}
