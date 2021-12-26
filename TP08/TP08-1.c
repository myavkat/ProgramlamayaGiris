/*
 * TP08-1.c
 *
 *  Created on: 16 Ara 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

int main(int argc, char* argv[]){

	printf("Komut satýrýndan aldýðý parametre sayýsý: %d", argc);
	printf("\nProgramýn adý: %s", argv[0]);

	for(int i=1;i<argc;i++){
		if(i==1)printf("\nParametreler:");
		printf("\n%s", argv[i]);
	}
	return 0;
}
