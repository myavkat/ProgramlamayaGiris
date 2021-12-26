/*
 * TP04-3.c
 *
 *  Created on: 11 Kas 2021
 *      Author: Mehmet Yavuz Katrancý
 */
#include<stdio.h>

int faktoriyel(int n);
int solFaktoriyel(int n);

int main() {

	printf("   Faktöriyel           Sol Faktöriyel\n");
	printf("----------------------------------------\n");
	for (int i = 0; i <= 10; i++) {
		int fakt= faktoriyel(i),solFakt=solFaktoriyel(i);
		printf("%2d! = %8d         !%2d = %8d\n",i, fakt, i, solFakt);
	}
}

int faktoriyel(int n) {
	int result = 1;
	if (n > 0) {
		for (int i = 1; i <= n; i++) {
			result *= i;
		}
	}
	return result;
}

int solFaktoriyel(int n) {
	int result = 0;
	if (n > 0) {
		for (int i = 0; i <= n-1; i++) {
			result += faktoriyel(i);
		}
	}
	return result;
}
