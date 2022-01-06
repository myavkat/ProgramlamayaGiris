#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 30

int main(int argc, char* argv[]){
	
	// 1) Komut satirindan aldigimiz argumanlari ekrana bastiralim
	// 2) Programa isim verip tekrar bastiralim
	for (int i = 0; i< argc; i++){
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	
	// 3) Girilen herhangi bir arguman belirli bir string'e esit mi diye bakalim
	char str[N] = "Teoman";
	for (int i = 0; i< argc; i++){
		if (strcmp(argv[i],str) == 0)
			printf("Ay ben %s Hoca'yi cok seviyorum!\n", str);
	}
	
	// 4) Girilen argumani alip program icinde kullanalim
	// Once string olarak:
	for (int i = 0; i<(int)strlen(argv[3]);i++){
		argv[3][i] = toupper(argv[3][i]); 
	}
	printf("%s\n", argv[3]);
	// Pinar'in Notu: argv'nin degerini baska bir string'e kopyalayip kopya uzerinde calismak daha iyi bir uygulama ornegi
	
	// Simdi bir de string'i sayiya cevirip kullanalim
	int a = atoi(argv[1]);
	float b = atof(argv[2]);
	
	printf("%d x 2 = %d\n", a, a*2);
	printf("%.2f x 2 = %.2f\n", b, b*2);
	
	return 0;
	
}