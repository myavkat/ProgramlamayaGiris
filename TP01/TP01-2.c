/*
 * TP01-2.c
 *
 *  Created on: 21 Eki 2021
 *      Author: Mehmet Yavuz Katrancý
 */
#include <stdio.h>

int main(){

	float r=5;
	float h=10;
	float tabanAlan = 3.14*r*r;
	float tabanCevre = 2*3.14*r;
	float yanalAlan = tabanCevre*h;
	float hacim = tabanAlan*h;
	float toplamYuzey = tabanAlan*2+yanalAlan;

	printf("La surface de la base : %f\n"
			"La surface laterale   : %f\n"
			"La surface totale     : %f\n"
			"Le volume             : %f\n",
			tabanAlan, yanalAlan, toplamYuzey, hacim);
}

