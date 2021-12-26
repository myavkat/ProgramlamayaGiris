/*
 * exercise02.c
 *
 *  Created on: Oct 20, 2021
 *      Author: Mehmet Yavuz Katrancı
 *      Description:
 *      Yarı ̧cap (r = 5cm)  ve  yukseklik (h = 10cm)  bilgisini  kullanarak  bir  silindirin  sırasıyla
 *      taban alanını, yanal yuzey alanını, toplam y ̈uzey alanını ve hacmini hesaplayıp ekrana bastıran
 *      programın C kodunu yazın. ̈Ornek ekran ̧cıktısı asagıda verilmistir.
 *      La surface de la base : 50.265482
 *      La surface laterale   : 251.327412
 *      La surface totale     : 351.858377
 *      Le volume             : 502.654825
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


