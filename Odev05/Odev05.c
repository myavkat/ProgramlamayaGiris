/*
 * Odev05.c
 *
 *  Created on: 20 Ara 2021
 *      Author: mehme
 */

#include<stdio.h>
#include<ctype.h>
#include<string.h>

void strToUpper(char *src, char *dest);
void strToLower(char *src, char *dest);
void strToSentenceCase(char *src, char *dest);

int main(int argc, char *argv[]) {
	if (argc < 3) {
		printf("Eksik arguman girdiniz!");
	} else if (argc >= 3) {
		if (argc > 3) {
			printf(
					"Fazla arguman girdiniz ama olsun, hizmet icin buradayiz...\n");
		}
		int argv2Len = strlen(argv[2]);
		int argv1Len = strlen(argv[1]);
		char inputStr[argv2Len];
		char optionParam[argv1Len];
		strcpy(inputStr, argv[2]);
		strcpy(optionParam, argv[1]);

		if (!strcmp(optionParam, "-d")) {
			printf("Girdiginiz karakter dizisi: %s", inputStr);
		} else if (!strcmp(optionParam, "-u")) {
			char upperCased[argv2Len];
			strToUpper(inputStr, upperCased);
			printf("%s", upperCased);
		} else if (!strcmp(optionParam, "-l")) {
			char lowerCased[argv2Len];
			strToLower(inputStr, lowerCased);
			printf("%s", lowerCased);
		} else if (!strcmp(optionParam, "-s")) {
			char sentenceCased[argv2Len];
			strToSentenceCase(inputStr, sentenceCased);
			printf("%s", sentenceCased);
		} else {
			printf("Oyle bir opsiyon yok canim. Bye!");
			return 1;
		}
	}
	return 0;
}

void strToUpper(char *src, char *dest) {
	for (int i = 0; i < strlen(src); i++) {
		dest[i] = toupper(src[i]);
	}
	return;
}

void strToLower(char *src, char *dest) {
	for (int i = 0; i < strlen(src); i++) {
		dest[i] = tolower(src[i]);
	}
	return;
}

void strToSentenceCase(char *src, char *dest) {
	strToLower(src, dest);
	dest[0] = toupper(src[0]);
	return;
}
