#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void echo(const char* fname){
FILE* f = fopen(fname, "r");
if (f) {
while (1) {
int c = getc(f);
if (c == EOF) {
if (ferror(f)) perror("getc");
fclose(f); return;
}
printf("%c", c);
}
}
else printf("echec de open ( %s ): Erreur no %d --> %s \n",
fname, errno, strerror(errno));
//else perror("Hata Mesaji");
}

int main(){
echo("toti.txt");
return 0;
}
