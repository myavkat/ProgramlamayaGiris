/*

#include <stdio.h>
#include <stdlib.h>

int main(){

int x = -9999, y = -9999, z = -9999;
FILE* f = fopen("toto.txt", "w"); // ouverture
if (f==NULL) { // verification
printf("Oh la la! Probleme! Pas de fichier!\n");
return 1;
}
x = fputs("coucou\n", f); // ecriture
y = fputc('p', f);
z = putc('u', f);
fclose(f); // fermeture
printf("Valeur de retour:\n");
printf("fputs: %d\t fputc: %d\t putc: %d\n", x, y, z);
return 0;

}
*/
