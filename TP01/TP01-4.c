/*
 * TP01-4.c
 *
 *  Created on: 21 Eki 2021
 *      Author: Mehmet Yavuz Katranc�
 */
#include <stdio.h>

int main(){
	int gunSayisi = 0;
	printf("Gun sayisini giriniz: ");
	fflush(stdout);
	scanf("%i", &gunSayisi);
	int yil = gunSayisi/365;
	int hafta = (gunSayisi%365)/7;
	int gun = ((gunSayisi%365)%7);
	printf("\nYil  : %d\n"
			"Hafta: %d\n"
			"Gun  : %d\n"
			"Karar: ", yil, hafta, gun);
	if(yil>=5){
		printf("Bu belge 5 ya��ndan b�y�k oldu�u i�in n�fusu gen� tutma yasas� do�rultusunda belgenin infaz�na karar verilmi�tir.");
	}
	else{
		printf("Gen�leri koruma yasas� kapsam�nda belgenin infaz� belge 5 ya��ndan k���k oldu�u i�in reddedilmi�tir.");
	}
}
