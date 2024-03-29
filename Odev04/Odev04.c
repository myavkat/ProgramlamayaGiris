/*
 * Odev04.c
 *
 *  Created on: 14 Ara 2021
 *      Author: Mehmet Yavuz Katranc�
 */

#include<stdio.h>
#define arrSize 50

void toUpper(char src[], char dest[]);
char findMax(char *s);
char findMin(char *s);
void crypto(char src[], char dest[], int key);
int main() {

	char inputStr[arrSize], upperCase[arrSize], cryptoed[arrSize],
			maxLetterOfInput, minLetterOfInput;

	printf("Sifrelenecek karakter dizisini girin: ");
	fflush(stdout);
	fgets(inputStr, arrSize, stdin);
	printf("\nSifrelenecek karakter dizisi: %s", inputStr);

	toUpper(inputStr, upperCase);
	printf("\nBuyuk harfe cevrilmis dizi : %s", upperCase);

	maxLetterOfInput = findMax(upperCase);
	minLetterOfInput = findMin(upperCase);
	printf("\nMax degerli karakter : %c (%d)", maxLetterOfInput,
			maxLetterOfInput);
	printf("\nMin degerli karakter : %c (%d)", minLetterOfInput,
			minLetterOfInput);

	int passwordKey = maxLetterOfInput - minLetterOfInput;
	printf("\nSifre anahtari: %d", passwordKey);

	crypto(upperCase, cryptoed, passwordKey);
	printf("\nSifrelenmis dizi: %s", cryptoed);
	return 0;
}

void toUpper(char src[], char dest[]) {
	for (int i = 0; i < arrSize; i++) {
		dest[i] = src[i];
		if (src[i] >= 97 && src[i] <= 122) {
			dest[i] -= 32;
		}
	}
	return;

}

char findMax(char *s) {
	char max = 65;
	for (int i = 0; i < arrSize; i++) {
		if (s[i] <= 90 && s[i] >= 65) {
			if (s[i] > max) {
				max = s[i];
			}
		}
	}
	return max;
}

char findMin(char *s) {
	char min = 90;
	for (int i = 0; i < arrSize; i++) {
		if (s[i] <= 90 && s[i] >= 65) {
			if (s[i] < min) {
				min = s[i];
			}
		}
	}
	return min;
}

//before using this function on a string, use toUpper function for staying in
//between the ASCII boundaries
void crypto(char src[], char dest[], int key) {
	for (int i = 0; i < arrSize; ++i) {
		dest[i] = src[i];
		if ((src[i] <= 90 && src[i] >= 65) || (src[i] <= 122 && src[i] >= 97)
				|| (src[i] <= 57 && src[i] >= 48)) {
			dest[i] += key;
		}
	}
}

