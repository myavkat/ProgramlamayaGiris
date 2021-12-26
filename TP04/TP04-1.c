/*
 * TP04-1.c
 *
 *  Created on: 11 Kas 2021
 *      Author: Mehmet Yavuz Katrancý
 */
#include<stdio.h>

int main(){
	int i = 1, toplam = 0, n = 100;
	while(i<=n){
		toplam = toplam + i;
		i++;
	}
	printf("While result: %d\n", toplam);

	toplam = 0, n = 100;
	for(i=1;i<=n;i++){
		toplam = toplam + i;
	}
	printf("For result: %d\n", toplam);

	i=1,toplam=0,n=100;
	do{
		toplam = toplam + i;
		i++;
	}while(i<=n);
	printf("Do-While result: %d\n", toplam);
}
