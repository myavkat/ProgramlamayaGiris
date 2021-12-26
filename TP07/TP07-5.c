/*
 * TP07-5.c
 *
 *  Created on: 9 Ara 2021
 *      Author: Mehmet Yavuz Katrancý
 */
#include<stdio.h>
#include<limits.h>

int strLen(char str[]);
int main(){
	char x[] = "Wdqulp#qh#ndgdu#gd#vdkdqh#elu#ghuv$";
	int sizeOfX = strLen(x);
	char y[sizeOfX];
	for(int i = 0; i<sizeOfX;i++){
		y[i]=x[i]-3;
	}
	printf(y); //gerçekten de öyle ^_^
}

int strLen(char str[]){
	for(int i=0;i<INT_MAX;i++){
		if(str[i]=='\0')
			return i;
	}
	return 0;
}
