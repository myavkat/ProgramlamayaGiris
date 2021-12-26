/*
 * TP07-2.c
 *
 *  Created on: Dec 8, 2021
 *      Author: Mehmet Yavuz Katranc�
 */

#include<stdio.h>

char enMajuscule(char ch);
char enMinuscule(char ch);
int main() {
	char ch;
	printf("Entrez un caractere en miniscule: ");
	fflush(stdout);
	scanf("%c", &ch);
	getchar();
	printf("En majuscule: %c\n", enMajuscule(ch));
	printf("Entrez un caractere: ");
	fflush(stdout);
	scanf("%c", &ch);
	getchar();
	printf("En minuscule: %c", enMinuscule(ch));
}

char enMajuscule(char ch) {
	if (ch > 96 && ch < 123)
		return ch - 32;
	return '?';
}

char enMinuscule(char ch) {
	if (ch < 91 && ch > 64)
		return ch + 32;
	else if(ch > 96 && ch < 123)
		return ch;
	return '?';
}
