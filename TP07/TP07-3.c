/*
 * TP07-3.c
 *
 *  Created on: 9 Ara 2021
 *      Author: Mehmet Yavuz Katrancý
 */
#include<stdio.h>
#include<limits.h>

int strLen(char str[]);
int main(){
	printf("Entrez une chaine de caractere: ");
	char str[500];
	fflush(stdout);
	gets(str);
	int lengthOfString = strLen(str);
	printf(">> La longueur de la chaine \"%s\" est %d.", str, lengthOfString);
	return 0;
}

int strLen(char str[]){
	for(int i=0;i<INT_MAX;i++){
		if(str[i]=='\0')
			return i;
	}
	return 0;
}
