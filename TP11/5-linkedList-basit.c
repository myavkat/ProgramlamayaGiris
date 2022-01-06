/*
 * linkedList.c
 *
 *  Created on: 12 Oca 2021
 *      Author: Pinpin
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// https://cs50.harvard.edu/college/2019/fall/notes/5/#:~:text=typedef%20struct%20node{%20%20%20%20int%20n;%20%20%20%20struct%20node%20*next;}node;
// https://www.w3resource.com/c-programming-exercises/linked_list/c-linked_list-exercise-1.php

// bagli listenin her bir dugumunu ifade eden yapi tanimlanir
struct dugum {
	int data;
	struct dugum *sonraki;
};


int main(int argc, char*argv[]) {

	// simdi ilk basta dugum yapisinda bir degisken tanimlayalim = tek elemanli bir liste yaratalim
	struct dugum *ilk; 
	
	// 1 - dugum yapisi icin bellekte gerekli yeri ayiralim
	ilk = malloc(sizeof(struct dugum));
	
	// 2 - malloc isini duzgun yapmis mi kontrol edelim
	if(ilk == NULL){
		exit(1);
	}
	
	// 3 - dugumun "data" isimli alanina ilk deger atayalim
	ilk->data = 7;
	// 4 - bu arkadas simdilik boslugu gosterecek (cunku kendisi tek bir elemanli bir liste)
	ilk->sonraki = NULL;
	
	// tek elemanli listemizde tuttugumuz veriyi bastiralim
	printf(" Bagli listemizde bulunan tek elemanin tuttugu veri ve sonrakinin adresi: \n");
	printf(" %d\n", ilk->data);
	printf(" %p\n", ilk->sonraki);
	
	// listemize yeni bir eleman eklemek icin gerekli hazirliklari yapalim
	struct dugum *ikinci = NULL;
	
	// 1 - dugum yapisi icin bellekte gerekli yeri ayiralim
	ikinci = malloc(sizeof(struct dugum));
	
	// 2 - malloc isini duzgun yapmis mi kontrol edelim
	if(ikinci == NULL){
		exit(1);
	}
	
	// 3 - dugumun "data" isimli alanina ilk deger atayalim
	ikinci->data = 89;
	// 4 - sonraki olmadigindan boslugu gosterecek (cunku simdilik tek elemanimiz)
	ikinci->sonraki = NULL;
	
	// 5 - iki elemani birbirine baglayalim ve listeyi olusturalim 
	ilk->sonraki = ikinci;
	
	// iki elemanli listemizin ilk elemaninin alanlarini bastiralim 
	printf(" Iki elemanli listenin ilk elemani: \n");
	printf(" data  : %d\n", ilk->data);
	printf(" sonraki elemanin adresi : %p\n", &ikinci->data);
	printf(" sonraki elemanin adresi : %p\n", &((ilk->sonraki)->data));
	printf(" sonraki elemanin adresi : %p\n", ilk->sonraki);
	
	// iki elemanli listemizin ikinci elemaninin alanlarini bastiralim 
	printf(" Iki elemanli listenin ikinci elemani: \n");
	printf(" data  : %d\n", (ikinci->data));
	printf(" data  : %d\n", (ilk->sonraki)->data);
	printf(" sonraki elemanin adresi : %p\n", (ikinci->sonraki));
	printf(" sonraki elemanin adresi : %p\n", (ilk->sonraki)->sonraki);
	
	// ilk ve ikinci arasina yeni bir dugum ekleyelim
	struct dugum *yeni = NULL;
	yeni = malloc(sizeof(struct dugum));
	if(yeni == NULL){
		exit(1);
	}
	
	yeni->data = 54;
	
	// bu yeni elemani "ilk" ve "ikinci" dugumlerin arasina ekleyecegiz
	// once ilk'ten sonraya yerlestirelim
	ilk->sonraki = yeni;
	
	// sonra "ikinci" ile baglayalim
	yeni->sonraki = ikinci;
	
	// elemanlarini guncelledigimiz listeyi ekrana bastiralim
	
	struct dugum *yedek = NULL;
	yedek = ilk;
	printf(" Listede yer alan elemanlar: ");
	while (yedek != NULL) {
		printf(" %d ", yedek->data);
		yedek = yedek->sonraki;
	}
	printf("\n");
	
	// ikinci elemani listeden cikaralim
	yeni->sonraki = NULL;
	
	// ikinci eleman icin ayrilan bellek hucrelerini bosaltalim
	free(ikinci);

	printf(" Guncellenmis listede yer alan elemanlar: ");
	yedek = ilk;
	while (yedek != NULL) {
		printf(" %d ", yedek->data);
		yedek = yedek->sonraki;
	}
	printf("\n");
	
	return 0;
}

