/*
 * TP06-3.c
 *
 *  Created on: Dec 1, 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

void swap1(int a, int b);
void swap2(int *a, int *b);
int main() {
	int a, b;
	printf("Entrez 2 entiers a et b: ");
	fflush(stdout);
	scanf("%d %d", &a, &b);
	printf(" Avant swap : a=%d b=%d\n", a, b);
	swap1(a, b);
	printf(" Apres swap1: a=%d b=%d\n", a, b);
	swap2(&a, &b);
	printf(" Apres swap2: a=%d b=%d\n", a, b);
}

void swap1(int a, int b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
	return;
}

void swap2(int *a, int *b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}
