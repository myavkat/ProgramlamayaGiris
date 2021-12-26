/*
 * Odev03.c
 *
 *  Created on: 6 Ara 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>
#include<limits.h>

#define N 10

int chercheMax(int *tab, int size);
int* minAdr(int x[], int size);
void printAdrsOfArr(int *a, int size);
void printAnswers(int *p, int *a);

int main() {
	int a[N] = { 34, 78, 56, 0, 12, 89, 67, 45, 90, 23 };
	int *p;
	p = a;

	printAdrsOfArr(a,N);

	printAnswers(p,a);

	int indexOfMax = chercheMax(a, N);
	printf("------------(2)------------\n");
	printf("L’indice de max est : %d\n", indexOfMax);
	printf("La valeur max est: %d\n\n", a[indexOfMax]);

	int *adrOfMin = minAdr(a, N);

	printf("------------(3)------------\n");
	printf("Le plus petit nombre dans le tableau: %d\n", *adrOfMin);
	printf("L’adresse du plus petit nombre: 0x%x\n", adrOfMin);
	printf("L’indice du plus petit nombre : %d\n", (int)(adrOfMin-a));
	return 0;
}

int chercheMax(int *tab, int size) {
	int max = INT_MIN;
	int indexOfMax;
	for (int i = 0; i < size; i++) {
		if (tab[i] > max) {
			max = tab[i];
			indexOfMax = i;
		}
	}
	return indexOfMax;
}

int* minAdr(int x[], int size) {
	int min = INT_MAX;
	int indexOfMin;
	for (int i = 0; i < size; i++) {
		if (x[i] < min) {
			min = x[i];
			indexOfMin = i;
		}
	}
	return &x[indexOfMin];
}

void printAdrsOfArr(int *a, int size){
	printf("Adresler:\n");
	for (int i = 0; i < size; i++) {
			printf("&a[%d] = 0x%x\n",i, a+i);
		}
	printf("\n");
}

void printAnswers(int *p, int *a){
	printf("Cevaplar:\n\n");
	printf("------------(1)------------\n");
	printf("a) &p //p'nin hafýzadaki adresini verir. a'nýn adresini vermez çünkü o p deðiþkeninin içinde tutulur onlara *p ile eriþilir. (adres türünden p'nin adresi) 0x%x\n", &p);
	printf("b) *p + 5 //*p a dizisinin ilk elemanýnýn deðerini gösterir. *p+5 bu ilk elemanýn deðerinin 5 fazlasýný gösterir. (int türünden a[0]+5) %d\n", *p+5);
	printf("c) *(p + 3) //p+3 int boyutu 4 ve a bir int dizisi olduðu için a'nýn ilk elemanýnýn adresinden 3 sonraki intin adresini yani 12 byte sonraki adresi gösterir, bu da a'nýn 4. elemanýnýn adresidir <=> (&a[3]). *(p+3) a'nýn 4. elemanýnýn deðerini gösterir. (int türünden a[3]) %d\n", *(p+3));
	printf("d) &a[4] - 1 //a dizisinin 5. elemanýnýn adresinden 1 önceki intin (4 byte öncesinin) adresini gösterir. (adres türünden a[3]'ün adresi) 0x%x\n", &a[4]-1);
	printf("e) a + 2 //a dizisinin ilk elemanýndan 8 byte sonraki int elemanýnýn adresini verir. (a[2]'nin adresi) 0x%x\n", a+2);
	printf("f) &a[6] - p //p a[0]'ýn adresi olduðu için a[6]'nýn adresiyle arasýndaki fark 24 bytetýr, pointer aritmetiði dolayýsýyla bu 24 byte olarak deðil deðiþken türünün byte boyutuna bölünerek int türünden 6 dönecektir. %d\n", (int)(&a[6] - p));
	printf("g) p + (*p - 10) //(*p - 10) a'nýn ilk elemaný 34ün 10 eksiðine yani 24e eþit. p'ye 24 eklersek a'nýn ilk elemanýnýn adresinden 96 (24*4) byte sonraki adrese ulaþýrýz. (a[25]'in adresi), 0x%x\n", p+(*p-10));
	printf("h) *(p + *(p + 8) - a[7]) //p+8 a'nýn 9. elemanýna eþit. *(p+8) a'nýn 9. elemanýnýn deðeri 90'a eþit. a[7]'nin deðeri 45, p + 90 - 45 yani p + 45 a dizisinin ilk elemanýnýn adresinden (45*4) 180 byte sonraki adresi gösterir. baþýndaki yýldýz bu adresteki int cinsinden deðeri gösterttirir %d\n", *(p + *(p + 8) - a[7]));
	printf("i) p + 11 //p+11 a'nýn ilk elemanýnýn adresinden 44 (11*4) byte sonraki adresi gösterir. 0x%x\n", p + 11);
	printf("j) *(p + 11) //p+11 a dizisinin ilk elemanýnýn adresinden 44 (4*11) byte sonraki adrestir, *(p+11) bu adresteki int deðerini gösterir. %d\n\n", *(p+11));
}




















































