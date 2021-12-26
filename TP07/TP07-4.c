/*
 * TP07-4.c
 *
 *  Created on: 9 Ara 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>
#include<limits.h>

int strLen(char str[]);
int main(){
	char x[] = "introduction to C programming";
	int strSize= strLen(x);
	for(int i=0;i<strSize;i++){
		if(x[i]==' '){
			printf("space");
		}
		else{
			printf("%c", x[i]);
		}
		printf(" ");
	}
}

int strLen(char str[]){
	for(int i=0;i<INT_MAX;i++){
		if(str[i]=='\0')
			return i;
	}
	return 0;
}
