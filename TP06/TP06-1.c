/*
 * TP06-1.c
 *
 *  Created on: Dec 1, 2021
 *      Author: Mehmet Yavuz Katrancı
 */

#include<stdio.h>
int main() {
	int a = 10;
	int b;
	int* x;
	x = &a;

	printf("la valeur de a = %d\n", a);
	printf("&a est l'adresse de a = 0x%x\n", &a);
	printf("&b est l'adresse de b = 0x%x\n", &b);
	printf("&x est l'adresse de x = 0x%x\n", &x);
	printf("x pointe sur l'adresse de a = 0x%x\n", x);
	printf("*x contient la valeur de a = %d\n", *x);
	printf("la taille de x = %d\n", sizeof(x));
	printf("la taille de *x = %d\n", sizeof(*x));
}
