/*
#include <stdio.h>
#include <stdlib.h>

void copie(const char *src, const char *dst) {
	FILE *s = fopen(src, "r");
	FILE *d = fopen(dst, "w");
	if (!s || !d) {
		printf("Erreur!Pas de fichier!\n");
		exit(1);
	}
	int x, y, z;
	while (!(feof(s))) {
		fscanf(s, "%d * %d = %d\n", &x, &y, &z);
		fprintf(d, "%d * %d = %d\n", x, y, z);
	}
	fclose(s);
	fclose(d);
}
int main() {
	copie("tata.txt", "titi.txt");
	return 0;
}
*/
