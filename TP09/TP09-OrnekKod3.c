/*
 * #include <stdio.h>

int main(){

int x = 1;
FILE* f = fopen("toto.txt", "w");
if (!f) {
printf("Oh la la! Probleme! Pas de fichier!\n");
return 1;
}
int a = fprintf(f, "%d * 2 = %d\n", x, x*2);
printf("fprintf donus degeri: %d\n", a);
for (x = 1; x <= 100; x++){
fprintf(f, "%d * 2 = %d\n", x, x*2);
}
fclose(f);
return 0;

}
*/
