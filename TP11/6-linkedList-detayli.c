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

// daha sonra yazacagimiz fonksiyonlar
struct dugum* ucElemanliListe();
int uzunluk(struct dugum* baslangic_dugumu);
void dataBastir(struct dugum *baslangic_dugumu);


int main(int argc, char*argv[]) {

	// simdi ilk basta dugum yapisinda bir degisken tanimlayalim = tek elemanli bir liste yaratalim
	struct dugum *ilk = NULL;
	
	// 1 - dugum yapisi icin bellekte gerekli yeri ayiriyoruz
	ilk = malloc(sizeof(struct dugum));
	
	// 2 - malloc isini duzgun yapmis mi kontrol edelim
	if(ilk == NULL){
		exit(1);
	}
	
	// 3 - dugumun "data" isimli alanina deger atiyorum
	ilk->data = 7;
	// 4 - bu arkadas simdilik boslugu gostersin (tek bir elemanimiz var)
	ilk->sonraki = NULL;
	
	
	// tek elemanli listemizde tuttugumuz veriyi bastiralim
	printf(" Bagli listemizde bulunan tek elemanin tuttugu veri ve sonrakinin adresi: \n");
	printf(" %d\n", ilk->data);
	printf(" %p\n", ilk->sonraki);
	
	// listemize yeni bir eleman eklemek icin gerekli hazirliklari yapalim
	struct dugum *ikinci = NULL;
	
	// 1 - dugum yapisi icin bellekte gerekli yeri ayiriyoruz
	ikinci = malloc(sizeof(struct dugum));
	
	// 2 - malloc isini duzgun yapmis mi kontrol edelim
	if(ikinci == NULL){
		exit(1);
	}
	
	// 3 - dugumun "data" isimli alanina deger atiyorum
	ikinci->data = 89;
	// 4 - bu arkadas simdilik boslugu gostersin (tek bir elemanimiz var)
	ikinci->sonraki = NULL;
	
	// 5 - iki elemani birbirine baglayip listeyi olusturalim 
	ilk->sonraki = ikinci;
	
	// iki elemanli listemizin ilk elemaninin alanlarini bastiralim 
	printf(" Iki elemanli listenin ilk elemani: \n");
	printf(" data  : %d\n", ilk->data);
	printf(" sonraki elemanin adresi : %p\n", &ikinci->data);
	printf(" sonraki elemanin adresi : %p\n", &((ilk->sonraki)->data));
	printf(" sonraki elemanin adresi : %p\n", ilk->sonraki);
	
	// iki elemanli listemizin ikinci elemaninin alanlarini bastiralim 
	printf(" Iki elemanli listenin ikinci elemani: \n");
	printf(" data  : %d\n", (ilk->sonraki)->data);
	printf(" sonraki elemanin adresi : %p\n", (ilk->sonraki)->sonraki);
	
	
	// listemizin uzunluğunu hesaplayalim
	
	// listeyi dolasmak icin "yedek" isimli gecici bir degisken tanimlayalim ve "ilk" dugumunden baslatalim
	struct dugum* yedek = ilk;
	// eleman sayisini bir "sayac" degiskeninde tutalim
	int sayac = 0;
	// eger liste bossa, zaten pointer NULL gosteriyordur, dolayisiyla while dongusu icine girilmez, sayac 0 olarak kalir
	while (yedek != NULL) {
		// eger pointer NULL degerini gostermiyorsa sayac bir arttirilir
		sayac++;
		// listede dolasabilmek icin "yedek" degiskenine bir sonraki dugumu atayarak donguye devam edelim
		yedek = yedek->sonraki;
	}
	printf(" Listedeki eleman sayisi : %d\n", sayac);
	
	// ayni mantigi kullanarak listenin elemanlarini ekrana bastiralim 
	
	// yine listeyi dolasmak icin "yedek" degiskenimizi kullanalim
	yedek = ilk;
	printf(" Listede yer alan elemanlar: ");
	while (yedek != NULL) {
		printf(" %d ", yedek->data);
		yedek = yedek->sonraki;
	}
	printf("\n");
	
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
	yedek = ilk;
	printf(" Listede yer alan elemanlar: ");
	while (yedek != NULL) {
		printf(" %d ", yedek->data);
		yedek = yedek->sonraki;
	}
	printf("\n");
	
	// Yazdigimiz fonksiyonlari kullanalim:
	
	// 3 elemanli bir liste olusturalim, once boslugu gosteren bir dugum tanimlayalim
	struct dugum *liste = NULL;
	
	// 3 elemanli liste fonksiyonumuzu cagirarak listeyi dolduralim
	liste = ucElemanliListe();
	
	// uzunlugunu ekrana bastiralim
	printf(" Uzunluk: %d\n", uzunluk(liste));
	
	// listenin elemanlarini ekrana bastiralim
	dataBastir(liste);
	
	// bu listeyi diger listemizin basina ekleyelim
	liste->sonraki->sonraki->sonraki = ilk; // tabii ki bunun icin de tanimli fonksiyonlar mevcut bkz push pop
	
	// uzunlugunu ekrana bastiralim
	printf(" Uzunluk: %d\n", uzunluk(liste));
	
	// listenin elemanlarini ekrana bastiralim
	dataBastir(liste);
	
	
	return 0;
}


// parametre olarak listenin ilk dugumunu gosteren bir pointer alan ve listeyi pointer'lar uzerinden dolasarak listenin kac elemanli oldugunu hesaplayip donduren fonksiyon
int uzunluk(struct dugum* baslangic_dugumu) {
	
	// listeyi dolasmak icin "yedek" isimli gecici bir degisken tanimlanir, ve listenin ilk elemanini gosteren pointer ilk deger olarak bu degiskene atanir
	struct dugum* yedek = baslangic_dugumu;
	// eleman sayisi bir "sayac" degiskeni tarafindan tutulur
	int sayac = 0;
	// eger liste bossa, zaten pointer NULL gosteriyordur, dolayisiyla while dongusu icine girilmez, sayac 0 olarak kalir
	while (yedek != NULL) {
		// eger pointer NULL degerini gostermiyorsa sayac bir arttirilir
		sayac++;
		// listede dolasabilmek icin "yedek" degiskenine bir sonraki dugum atanir
		yedek = yedek->sonraki;
	}
	// uzunluk geri dondurulur
	return sayac;

}

// parametre olarak listenin ilk dugumunu gosteren bir pointer alan ve listeyi pointer'lar uzerinden dolasarak listedeki elemanlarin tuttuklari datalari ekrana bastiran fonksiyon, calisma mantigi yukaridaki ile ayni
void dataBastir(struct dugum *baslangic_dugumu) {
	struct dugum* yedek = baslangic_dugumu;
	printf(" Listede yer alan elemanlar: ");
	while (yedek != NULL) {
		printf("%d ", yedek->data);
		yedek = yedek->sonraki;
	}
	printf("\n");
}

// 3 elemanli (dugumlu) bagli liste olusturmak icin basit bir fonksiyon, listenin ilk elemanini dondurur
struct dugum* ucElemanliListe() {
	// struct dugum tipinde 3 pointer tanimlanir
	struct dugum* baslangic_dugumu = NULL;
	struct dugum* ikinci_dugum = NULL;
	struct dugum* ucuncu_dugum = NULL;

	// her biri icin bellekte gerekli yer acilir
	baslangic_dugumu = malloc(sizeof(struct dugum));
	ikinci_dugum = malloc(sizeof(struct dugum));
	ucuncu_dugum = malloc(sizeof(struct dugum));

	// ilk elemanin tuttugu dataya ilk deger atamasi yapilir
	baslangic_dugumu->data = 1;
	// ilk elemanin ikinci elemani gostermesini saglayan pointer'a ilk deger atamasi yapilir
	baslangic_dugumu->sonraki = ikinci_dugum;

	// ilk eleman icin yapilan islemler asagida ikinci ve ucuncu eleman icin de yapilir
	ikinci_dugum->data = 2;
	ikinci_dugum->sonraki = ucuncu_dugum;

	ucuncu_dugum->data = 3;
	// ucuncu eleman listenin son elemani oldugundan, onun pointer'i NULL degerini gosterir
	ucuncu_dugum->sonraki = NULL;

	// liste yaratildiktan sonra listeye ulasmak icin kullanacagimiz pointer dondurulur
	return baslangic_dugumu;
	
}

