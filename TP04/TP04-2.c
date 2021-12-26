/*
 * TP04-2.c
 *
 *  Created on: 11 Kas 2021
 *      Author: Mehmet Yavuz Katrancý
 */
#include<stdio.h>

int fahrenheit(int cel);
int celcius(int fahr);

int main() {
	//Celcius to Fahrenheit Printer (0-100)
	printf("Celcius -----> Fahrenheit:\n");
	printf("   C           F\n");
	printf("-------------------\n");

	for (int cel = 0; cel <= 100; cel += 10) {
		int fahr = fahrenheit(cel);
		printf(" %3d          %3d\n", cel, fahr);
	}

	//Fahrenheit to Celcius Printer (32-212)
	printf("\nFahrenheit -----> Celcius:\n");
	printf("   F           C\n");
	printf("-------------------\n");

	for (int fahr = 32; fahr <= 212; fahr += 20) {
		int cel = celcius(fahr);
		printf(" %3d          %3d\n", fahr, cel);
	}
}

int fahrenheit(int cel) {
	int fahr = (int) (((float) cel * 1.8) + (float) 32);
	return fahr;
}

int celcius(int fahr) {
	int cel = (int) (((float) fahr - (float) 32) / 1.8);
	return cel;
}
