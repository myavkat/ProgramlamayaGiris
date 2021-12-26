/*
 * TP08-2.c
 *
 *  Created on: 17 Ara 2021
 *      Author: mehme
 */

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main(int argc, char* argv[]){
	int randArr[25];
	srand(time(0));
	printf("Before: \n");
	for (int i = 0; i < 25; ++i) {
		randArr[i]= rand()%50;
		printf("%d ", randArr[i]);
	}
	printf("\nAfter: \n");
	for (int i = 0; i < 25; ++i) {
		randArr[i] += atoi(argv[1]);
		printf("%d ", randArr[i]);
	}
}
