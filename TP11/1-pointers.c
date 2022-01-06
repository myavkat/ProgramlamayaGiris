#include <stdio.h>
#include <stdlib.h>
#define N 5

void strcpy1(char *s1, char *s2);
void strcpy2(char *s1, char *s2);
void strcpy3(char *s1, char *s2);
void strcpy4(char *s1, char *s2);

int main(){
	
	int x = 10;
	int* p;
	p = &x;
	
	/*
	printf("x'in degerine dogrudan erisim: %d\n", x);
	printf("x'in adresine dogrudan erisim: %p\n", &x);
	printf("x'e adresi uzerinden erisim  : %d\n", *p);
	printf("Pointer ile x'in adresi      : %p\n", p);
	printf("p'nin kendi adresi (isimiz yok bu arkadasla): %p\n", &p);
	*/
	
	/*	
	int a[N] = {3,4,5,6,7}; 
	//---> a = &a[0], &a[1] = &a[0] + 1, a[1] = *(a+1)
	p = a;  // ---> p = &a[0]  			
	*/
	
	/*
	printf("a'nin ilk elemanini farkli sekillerde ekrana bastiralim: \n");
	printf("%d\n", a[0]);     // dizi indisi ile
	printf("%d\n", *p);       // pointer ile
	printf("%d\n", *a);    	  // dizi adi ile (pointer gibi kullanarak)	
	printf("%d\n", *(&a[0])); // 
	*/
		
	// "a" tipki pointer gibi bir adres gosteriyor ama POINTER DEGIL
	// hangi adresi temsil ediyor?  &a[0]
	// &a[0] sabit bir tanim dolayisiyla asagidakiler YAPILAMAZ: 
	// a = p; X
	// a++;   X
	// neler yapilabilir bir bakalim
	
	/*
	printf("a'nin elemanlarini farkli sekillerde ekrana bastiralim: \n");
	for(int i  = 0; i<N; i++){
		printf("%d ", a[i]);   // dizi indisleri ile
		printf("%d ", *(p+i)); // p pointer'ı ile 
		printf("%d ", *(a+i)); // dizi adi ile
	}
	*/
	
	//printf("\n");
	// dongu sayaci olarak p'yi kullanarak
	/*
	for (p = a; p < a+N; p++)
		printf("%d ", *p);
	*/
	
	
	//printf("\nkarakter dizilerine bir goz atalim: \n");
	/*
	char str1[] = "Hellooooo!"; //---> '\0' 
	char str2[] = "Darling!!!";
	char str3[] = "Hi!";
	*/
	
	// Asagidakileri atamalari yapabilir miyiz?
	/*
	str1 = str2; 
	str3 = "What's up?";
	*/
	
	//printf("%s %s %s\n", str1, str2, str3);
	
	// C tutor
	
	/*
	char* s1 = "Merhabaaa"; 
	char* s2 = "Tatlim!";
	char* s3 = "Hey!";  
	
	printf("Once: %s %s %s\n", s1, s2, s3);
	*/
	
	// Asagidakileri yapabilir miyiz?
	/*
	s1 = s2;
	s3 = "Naber?"; 
	*/
	
	//printf("Sonra: %s %s %s\n", s1, s2, s3);
	
	return 0;
}

// array mantigi ile kopyalama tab[i]
void strcpy1(char *s1, char *s2){ // ---> &s1[0] &s2[0]
	int i = 0; 
	while ((s1[i]=s2[i]) != '\0')
		i++;
}

//tab[i] yerine *(tab+i)
void strcpy2(char *s1, char *s2){
	int i = 0; 
	while ((*(s1+i)=*(s2+i)) != '\0') 
		i++;
}

//pointer mantigi ile
void strcpy3(char *s1, char *s2){
	while((*s1 = *s2)!= '\0'){
		s1++;
		s2++;
	}
}

//daha da kisa
void strcpy4(char *s1, char *s2){
	while(*s1++ = *s2++) // ---> (*s1) = (*s2) ---> 'H' = 'D' ---> 5 = 6 XXX
		;
}