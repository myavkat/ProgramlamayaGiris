/*
 * Odev02-1.c
 *
 *  Created on: 4 Kas 2021
 *      Author: Mehmet Yavuz Katrancý
 */
#include<stdio.h>
#include<math.h>

int intLength(int number){
	int length=1;
	while(number>10){
		number/=10;
		length++;
	}
	return length;
}

//aaaaaaaaa
int sommeChiffres(int number){
	int tenPowerDigitCount;
	int sum = 0;
	while(number>=1){
		tenPowerDigitCount = (int)pow(10, (double)(intLength(number)-1));
		sum+=number/tenPowerDigitCount;
		number%=tenPowerDigitCount;
	}
	return sum;
}

//bbbbbbbbbbbbb
int harshad(int number){
	if(number % sommeChiffres(number) == 0){
		return 1;
	}
	else{
		return 0;
	}
}

//cccccccccccccc
void afficheHarshad(int limit){
	int numberToTry = 1;
	int harshadCount = 0;

	while(harshadCount<limit){
		if(harshad(numberToTry)){
			printf("%5d ", numberToTry);
			harshadCount++;
			if(harshadCount%10==0){
				printf("\n");
			}
		}
		numberToTry++;
	}
	return;
}

//dddddddddddddd
int main(){
	int input;
	printf("Entrez un entier positif: ");
	fflush(stdout);
	scanf("%d", &input);
	afficheHarshad(input);
	return 0;
}
