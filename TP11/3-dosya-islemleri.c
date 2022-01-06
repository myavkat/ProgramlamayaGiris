#include <stdio.h>
#include <stdlib.h>
#define N 50

int main(){
	FILE *fpr = fopen("metin1.txt", "r");
	FILE *fpw = fopen("metin2.txt", "w");
	if(fpr == NULL || fpw == NULL){
		perror("Hata!");
	}
	
	// 1. yontem: fgetc
	char x = fgetc(fpr);
	while( x != EOF ){
		fputc(x,fpw);	  // dosyaya yaziyorum	
		printf("%c", x);  // ekrana yaziyorum
		x = fgetc(fpr);
	}
	printf("\t1.yontem ok\n");
	
	rewind(fpr); //fseek(fpr, 0, SEEK_SET); // fclose(fpr); fpr = fopen(...);
	// 2. yontem: fgets
	char s[N];
	while(fgets(s, N, fpr) != NULL){
		fputs(s, fpw);    // dosyaya yaziyorum
		printf("%s", s);  // ekrana yaziyorum
	}
	printf("\t2.yontem ok\n");
	
	rewind(fpr);
	// 3. yontem: fscanf
	char s1[N], s2[N], s3[N];
	while(fscanf(fpr,"%s %s %s\n", s1, s2, s3) != EOF){
		;
		fprintf(fpw,"%s %s %s\n", s1, s2, s3);
		printf("%s %s %s\n", s1, s2, s3);
	}
	printf("\t3.yontem ok\n");
	
	fclose(fpr);
	fclose(fpw);
	
	return 0;
}