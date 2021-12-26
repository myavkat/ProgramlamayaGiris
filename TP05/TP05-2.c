/*
 * TP05-2.c
 *
 *  Created on: 18 Kas 2021
 *      Author: Mehmet Yavuz Katrancı
 */
#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>

#define gradeListLength 100

int max(int number1, int number2);
int min(int number1, int number2);
int maxNote(int gradeList[]);
int minNote(int gradeList[]);
float moyen(int gradeList[]);

int main() {
	int gradeList[100];
	srand(time(0));

	for (int i = 0; i < gradeListLength; i++) {
		gradeList[i] = rand() % 101;
	}

	printf("Ogrencilerin notlari:\n");
	for (int i = 0; i < gradeListLength; i++) {
		printf("%3d. ogrencinin notu: %3d\n", i + 1, gradeList[i]);
	}

	int minGrade = minNote(gradeList);
	int maxGrade = maxNote(gradeList);
	float averageGrade = moyen(gradeList);
	printf("\nOrt  : %.2f\n", averageGrade);
	printf("Min  : %d\n", minGrade);
	printf("Max  : %d\n", maxGrade);

	for (int i = 0; i < gradeListLength; i++) {
		if (gradeList[i] == maxGrade) {
			printf("En yuksek notu alan ogrenci no: %d\n", i + 1);
		} else if (gradeList[i] == minGrade) {
			printf("En dusuk notu alan ogrenci no : %d\n", i + 1);
		}
	}

	return 0;
}

int max(int number1, int number2) {
	if (number1 > number2) {
		return number1;
	}
	return number2;
}

int min(int number1, int number2) {
	if (number1 < number2) {
		return number1;
	}
	return number2;
}

int maxNote(int gradeList[]) {
	int maxGrade = INT_MIN;
	for (int i = 0; i < gradeListLength; i++) {
		maxGrade = max(maxGrade, gradeList[i]);
	}
	return maxGrade;
}

int minNote(int gradeList[]) {
	int minGrade = INT_MAX;
	for (int i = 0; i < gradeListLength; i++) {
		minGrade = min(minGrade, gradeList[i]);
	}
	return minGrade;
}

float moyen(int gradeList[]) {
	float sum = 0;
	for (int i = 0; i < gradeListLength; i++) {
		sum += (float) gradeList[i];
	}
	return (sum / (float) gradeListLength);
}

