/*
 * TP08-1.c
 *
 *  Created on: 16 Ara 2021
 *      Author: Mehmet Yavuz Katranc�
 */

#include<stdio.h>

int main(int argc, char* argv[]){

	printf("Komut sat�r�ndan ald��� parametre say�s�: %d", argc);
	printf("\nProgram�n ad�: %s", argv[0]);

	for(int i=1;i<argc;i++){
		if(i==1)printf("\nParametreler:");
		printf("\n%s", argv[i]);
	}
	return 0;
}
