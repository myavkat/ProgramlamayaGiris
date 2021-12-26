/*
 * TP03-4.c
 *
 *  Created on: 4 Kas 2021
 *      Author: Mehmet Yavuz Katrancý
 */

#include<stdio.h>
#include<math.h>

float nouveauCapital(int capital, float taux, int n);

int main(){
	int capital, year;
	float tax, newCapital, totalRevenue;

	printf("Entrez le capital initiali le taux d'interet et le nombre d'annees: ");
	fflush(stdout);
	scanf("%d %f %d", &capital, &tax, &year);

	newCapital = nouveauCapital(capital, tax, year);
	totalRevenue = newCapital - capital;
	printf("Le nouveau capital est %.3f\n", newCapital);
	printf("Le revenu total est %.3f pour %d annees", totalRevenue, year);

	return 0;
}

float nouveauCapital(int capital, float taux, int n){
	float result = capital* pow(1+taux, n);
	return result;
}
