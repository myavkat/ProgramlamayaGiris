/*
 * TP02-2.c
 *
 *  Created on: 28 Eki 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

int main(){
	int income;
	int tax;
	printf("Entrez la base imposable: ");
	fflush(stdout);
	scanf("%d", &income);


	if(income<=0){
		printf("La base imposable est invalide.");
	}
	else if(income<24000){
		tax = 15;
	}
	else if(income<53000){
		tax = 20;
	}
	else if(income<130000){
		tax = 27;
	}
	else if(income<65000){
		tax = 35;
	}
	else{
		tax = 40;
	}

	if(tax!=0){
	printf("Taux d'imposition: %%%d", tax);
	}

	return 0;
}
