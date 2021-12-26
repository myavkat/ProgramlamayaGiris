#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){
	setvbuf(stdout, NULL, _IONBF, 0); //disables the stdout's buffer
	
	if(argc<=1){
		printf("Yetersiz sayıda arguman");
		return 1;
	}
	FILE* f = fopen(argv[1], "w");
	if(f==NULL){
		printf("Pas de fichier!");
		return 1;
	}
	int devam = 1;
	char nameInput[20];
	char gradeInput[20];
	char continueInput[5] = "1";
	char *p;
	while(!strcmp(continueInput,"1")){
		printf("Entrez le prenom: ");
		fflush(stdout);
		if(fgets(nameInput, 20, stdin)!=NULL){
			if( (p = strchr(nameInput, '\n')) != NULL)
				*p='\0';
		}

		printf("Entrez la note: ");
		fflush(stdout);
		if(fgets(gradeInput, 20, stdin)!=NULL){
			if( (p = strchr(gradeInput, '\n')) != NULL)
				*p='\0';
		}

		fprintf(f, "%s %s\n", nameInput, gradeInput);

		printf("Pour continuer [1], pour terminer [0]: ");
		fflush(stdout);
		if(fgets(continueInput, 5, stdin)!=NULL){
			if( (p = strchr(continueInput, '\n')) != NULL)
				*p='\0';
		}
	}
	printf("Bye bye...\n");
	return 0;
}
