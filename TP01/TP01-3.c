/*
 * TP01-3.c
 *
 *  Created on: 21 Eki 2021
 *      Author: Mehmet Yavuz Katrancý
 *      a+c, f+c, d+f, ((int)d)+l, a+f, s+b, l+b, s+c, l+c, l+u
 */
#include <stdio.h>
int main(){
	int a = 100, b = 10000;
	long l = 1234567890;
	short s = 2021;
	float f = 2.13459;
	double d = 1.1415927;
	char c = 'P';
	unsigned long u = 2541567890;

	printf("a+c = %i \n"
			"f+c = %lf \n"
			"d+f = %lf \n"
			"((int)d)+1 = %i \n"
			"a+f = %lf \n"
			"s+b = %i \n"
			"l+b = %li \n"
			"s+c = %i \n"
			"l+c = %li \n"
			"l+u = %lu \n",
			a+c, f+c, d+f, ((int)d)+1, a+f, s+b, l+b, s+c, l+c, l+u );

	return 0;
}

