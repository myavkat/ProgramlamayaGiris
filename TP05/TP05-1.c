/*
 * TP05-1.c
 *
 *  Created on: Nov 17, 2021
 *      Author: Mehmet Yavuz Katrancı
 */
#include <stdio.h>
#include<limits.h>

int max(int input1, int input2);
int min(int input1, int input2);

int main() {
	int gradeList[8];
	int maxGrade = INT_MIN;
	int minGrade = INT_MAX;
	int gradeSum = 0;
	float gradeAverage;
	int sizeOfGradeList = (int) sizeof(gradeList) / (int) sizeof(gradeList[0]);

	for (int i = 0; i < sizeOfGradeList; i++) {
		printf("%d. ogrencinin notunu girin: ", i + 1);
		fflush(stdout);
		scanf("%d", &gradeList[i]);
	}

	printf("\nOgrencilerin notlari:  ");
	for (int i = 0; i < sizeOfGradeList; i++) {
		printf("%4d", gradeList[i]);
	}

	for (int i = 0; i < sizeOfGradeList; i++) {
		maxGrade = max(maxGrade, gradeList[i]);
		minGrade = min(minGrade, gradeList[i]);
		gradeSum += gradeList[i];
	}
	gradeAverage = (float) gradeSum / (float) sizeOfGradeList;
	printf("\nOrt  : %f\n", gradeAverage);
	printf("Min  : %d\n", minGrade);
	printf("Max  : %d\n", maxGrade);

	for(int i=0; i<sizeOfGradeList; i++){
		if(gradeList[i]==maxGrade){
			printf("En yuksek notu alan ogrenci no: %d\n", i+1);
		}
		else if(gradeList[i]==minGrade){
			printf("En dusuk notu alan ogrenci no : %d\n", i+1);
		}
	}

	return 0;
}

int max(int input1, int input2) {
	if (input1 > input2) {
		return input1;
	}
	return input2;
}

int min(int input1, int input2) {
	if (input1 < input2) {
		return input1;
	}
	return input2;
}
