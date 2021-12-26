/*
 * Odev03.c
 *
 *  Created on: 6 Ara 2021
 *      Author: Mehmet Yavuz Katranc�
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
	printf("L�indice de max est : %d\n", indexOfMax);
	printf("La valeur max est: %d\n\n", a[indexOfMax]);

	int *adrOfMin = minAdr(a, N);

	printf("------------(3)------------\n");
	printf("Le plus petit nombre dans le tableau: %d\n", *adrOfMin);
	printf("L�adresse du plus petit nombre: 0x%x\n", adrOfMin);
	printf("L�indice du plus petit nombre : %d\n", (int)(adrOfMin-a));
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
	printf("a) &p //p'nin haf�zadaki adresini verir. a'n�n adresini vermez ��nk� o p de�i�keninin i�inde tutulur onlara *p ile eri�ilir. (adres t�r�nden p'nin adresi) 0x%x\n", &p);
	printf("b) *p + 5 //*p a dizisinin ilk eleman�n�n de�erini g�sterir. *p+5 bu ilk eleman�n de�erinin 5 fazlas�n� g�sterir. (int t�r�nden a[0]+5) %d\n", *p+5);
	printf("c) *(p + 3) //p+3 int boyutu 4 ve a bir int dizisi oldu�u i�in a'n�n ilk eleman�n�n adresinden 3 sonraki intin adresini yani 12 byte sonraki adresi g�sterir, bu da a'n�n 4. eleman�n�n adresidir <=> (&a[3]). *(p+3) a'n�n 4. eleman�n�n de�erini g�sterir. (int t�r�nden a[3]) %d\n", *(p+3));
	printf("d) &a[4] - 1 //a dizisinin 5. eleman�n�n adresinden 1 �nceki intin (4 byte �ncesinin) adresini g�sterir. (adres t�r�nden a[3]'�n adresi) 0x%x\n", &a[4]-1);
	printf("e) a + 2 //a dizisinin ilk eleman�ndan 8 byte sonraki int eleman�n�n adresini verir. (a[2]'nin adresi) 0x%x\n", a+2);
	printf("f) &a[6] - p //p a[0]'�n adresi oldu�u i�in a[6]'n�n adresiyle aras�ndaki fark 24 bytet�r, pointer aritmeti�i dolay�s�yla bu 24 byte olarak de�il de�i�ken t�r�n�n byte boyutuna b�l�nerek int t�r�nden 6 d�necektir. %d\n", (int)(&a[6] - p));
	printf("g) p + (*p - 10) //(*p - 10) a'n�n ilk eleman� 34�n 10 eksi�ine yani 24e e�it. p'ye 24 eklersek a'n�n ilk eleman�n�n adresinden 96 (24*4) byte sonraki adrese ula��r�z. (a[25]'in adresi), 0x%x\n", p+(*p-10));
	printf("h) *(p + *(p + 8) - a[7]) //p+8 a'n�n 9. eleman�na e�it. *(p+8) a'n�n 9. eleman�n�n de�eri 90'a e�it. a[7]'nin de�eri 45, p + 90 - 45 yani p + 45 a dizisinin ilk eleman�n�n adresinden (45*4) 180 byte sonraki adresi g�sterir. ba��ndaki y�ld�z bu adresteki int cinsinden de�eri g�sterttirir %d\n", *(p + *(p + 8) - a[7]));
	printf("i) p + 11 //p+11 a'n�n ilk eleman�n�n adresinden 44 (11*4) byte sonraki adresi g�sterir. 0x%x\n", p + 11);
	printf("j) *(p + 11) //p+11 a dizisinin ilk eleman�n�n adresinden 44 (4*11) byte sonraki adrestir, *(p+11) bu adresteki int de�erini g�sterir. %d\n\n", *(p+11));
}




















































