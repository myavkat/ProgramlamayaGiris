#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct{
	int a;
	double b;
	char c[N];
}canimstruct;

int main(){
	
	// bir yapi tanimlayalim, ilk deger atamasi yapalim
	canimstruct x = {3, 8.988743, "lala"};
	
	// ekrana bastiralim
	printf("%d %lf %s\n", x.a, x.b, x.c);
	
	// bir pointer yapi tanilayalim
	canimstruct *y;
	
	// kimin adresini gosterecegini soyleyelim
	y = &x;
	
	// ekrana bastiralim
	printf("%d %lf %s\n", y->a, y->b, y->c);
	
	// kullanicidan yeni deger alarak x'in degerini guncelleyelim
	printf("x struct'inin degerlerini guncelleyelim: ");
	scanf("%d%lf%s", &x.a, &x.b, x.c);
	
	// ekrana bastiralim
	printf("%d %lf %s\n", x.a, x.b, x.c);
	
	// ayni islemi pointer kullanarak yapalim
	printf("x struct'inin degerlerini y ile guncelleyelim: ");
	scanf("%d%lf%s", &y->a, &y->b, y->c);
	
	// ekrana bastiralim
	printf("%d %lf %s\n", x.a, x.b, x.c);
	
	// adresleri hem x uzerinden hem de y uzerinden ekrana bastiralim
	printf("x'in adresi: %p\n", &x);
	printf("x.a'nin adresi: %p\n", &x.a);
	printf("x.b'nin adresi: %p\n", &x.b);
	printf("x.c'nin adresi: %p\n", x.c);
	
	printf("x'in adresi: %p\n", y);
	printf("x.a'nin adresi: %p\n", &((*y).a));
	printf("x.b'nin adresi: %p\n", &y->b);
	printf("x.c'nin adresi: %p\n", y->c);

	return 0;
}