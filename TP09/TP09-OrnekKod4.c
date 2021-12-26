/*
 #include <stdio.h>

void copie(const char *src, const char *dst) {
	FILE *s = fopen(src, "r");
	FILE *d = fopen(dst, "w");
	if (!s || !d) {
		printf("Erreur!Pas de fichier!\n");
		exit(1);
	}
	while (1) {
		int x = getc(s);
		if (x == EOF)
			break;
		if (putc(x, d) == EOF) {
			printf("Erreur de putc!\n");
			break;
		}
	}
	fclose(s);
	fclose(d);
}

int main() {
	copie("toto.txt", "tata.txt");
	return 0;
}
*/
