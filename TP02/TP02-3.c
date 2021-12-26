/*
 * TP02-3.c
 *
 *  Created on: 28 Eki 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>

int main(){
	int coordX;
	int coordY;
	printf("Entrez les coordonnees cartesiennes sous le forme (X,Y): ");
	fflush(stdout);
	scanf("(%d,%d)", &coordX, &coordY);
	printf("(%d,%d) est", coordX, coordY);
	if(coordX>0){

		if(coordY>0){
			printf(" dans le premiere quadrant.");
		}
		else if(coordY<0){
			printf(" dans le quatrieme quadrant.");
		}
		else if(coordY==0){
			printf(" sur le droite Y");
		}
	}
	else if(coordX<0){

		if(coordY>0){
			printf(" dans le deuxieme quadrant.");
		}
		else if(coordY<0){
			printf(" dans le troisieme quadrant.");
		}
		else if(coordY==0){
			printf(" sur le droite Y.");
		}
	}else if(coordX==0){

		if(coordY==0){
			printf(" sur l'origine.");
		}
		else if(coordY!=0){
			printf(" sur le droite X.");
		}
	}

	return 0;
}
