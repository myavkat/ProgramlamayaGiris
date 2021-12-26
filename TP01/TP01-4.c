/*
 * TP01-4.c
 *
 *  Created on: 21 Eki 2021
 *      Author: Mehmet Yavuz Katrancý
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
		printf("Bu belge 5 yaþýndan büyük olduðu için nüfusu genç tutma yasasý doðrultusunda belgenin infazýna karar verilmiþtir.");
	}
	else{
		printf("Gençleri koruma yasasý kapsamýnda belgenin infazý belge 5 yaþýndan küçük olduðu için reddedilmiþtir.");
	}
}
