#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 250 // ornek sayisi
#define C 5	  // katsayi sayisi

// C adet katsayiyi tutmak icin bir tamsayi dizi, N adet x ve
// bunlara denk gelen y koordinatlarini tutmak icin ayri ayri iki
// double dizi ve bir de double hata alani iceren equation isimli
// bir yapi tanimlayalim
typedef struct equation
{
	int coEfficientArr[C];
	double xValues[N];
	double yValues[N];
	double MSE;
} equation;

// Fonksiyonlarin aciklamalari icin main'in altina bakiniz
equation newEquation(int c[C], double x[N]);
void computeY(equation *e);
double computeMSE(equation e1, equation e2);
// Isterseniz buraya yeni fonksiyonlar ekleyebilirsiniz
void copyEquation(equation *dest, equation *src);

int main(int argc, char *argv[])
{
	//yeterli arguman girilmemisse programı durdurur
	if (argc <= 1)
	{
		printf("Not enough of you... r arguments!");
		return -1;
	}

	//dosyayı acar yoksa programı durdurur
	FILE *data = fopen(argv[1], "r");
	if (data == NULL)
	{
		printf("File existn't");
		return -2;
	}

	//dosyadaki bilgileri tutmak icin bir equation olusturulur
	//ve ici dosyadan alınan verilerle doldurulur
	equation realEquation;
	for (int i = 0; i < N; i++)
	{
		fscanf(data, "%lf,%lf\n", &realEquation.xValues[i], &realEquation.yValues[i]);
	}

	//aldigini kontrol etmek icin degerleri ekrana bastirir
	for (int i = 0; i < N; i++)
	{
		printf("X: %lf, Y: %lf\n", realEquation.xValues[i], realEquation.yValues[i]);
	}

	//fonksiyonlarimizin calistigini test etmek icin bir equation olusturur ve y
	//degerleri ve MSEsini hesaplayıp MSEsini yazdirir
	int defaultCoEfficients[5] = {1, 1, 1, 1, 1};

	equation testCase = newEquation(defaultCoEfficients, realEquation.xValues);

	computeY(&testCase);

	testCase.MSE = computeMSE(realEquation, testCase);
	printf("\nThe MSE of the equation that we created for test: %lf\n\n", testCase.MSE);

	/*
	int c1[C] = {6, 7, 5, 8, 4};
	int c2[C] = {5, 3, 8, 7, 2};
	int c3[C] = {2, 9, 4, 7, 3};
	int c4[C] = {3, 3, 9, 8, 2};
	int c5[C] = {8, 7, 5, 1, 9};
	*/

	//dizileri for dongusunde kullanabilmek icin bir arrayin icine
	//ekledim ama iclerinde degisiklik yapmadım
	int cArray[5][C] = {{6, 7, 5, 8, 4},  // c1
						{5, 3, 8, 7, 2},  // c2
						{2, 9, 4, 7, 3},  // c3
						{3, 3, 9, 8, 2},  // c4
						{8, 7, 5, 1, 9}}; // c5

	equation eqArray[5];
	for (int i = 0; i < 5; i++)
	{
		eqArray[i] = newEquation(cArray[i], realEquation.xValues);
		computeY(&(eqArray[i]));
		eqArray[i].MSE = computeMSE(realEquation, eqArray[i]);
		printf("MSE of C%d: %lf\n", i + 1, eqArray[i].MSE); //indexleme yüzünden C'den sonraki integerın değeri i+1
	}

	double minMSE = 2170000;
	int answer = 0;
	for (int i = 0; i < 5; i++)
	{
		if (minMSE > eqArray[i].MSE)
		{
			minMSE = eqArray[i].MSE;
			answer = i + 1;
		}
	}

	printf("\nCevap: C%d \n\n", answer);

	// BONUS: Size verilen denklemin katsayilarini bulun

	//brute force deniyordu herhalde tüm değerleri denemeye
	//Katsayı aralığı küçük olduğu için kullandım, büyük aralıklar için pek efektif bir yöntem değil biliyorum ama çalışıyor :)
	equation resultEquation;
	equation testEquation = newEquation(defaultCoEfficients, realEquation.xValues);
	resultEquation.MSE = 2170000;
	for (int a = 1; a < 10; a++)
	{
		testEquation.coEfficientArr[0] = a;
		for (int b = 1; b < 10; b++)
		{
			testEquation.coEfficientArr[1] = b;
			for (int c = 1; c < 10; c++)
			{
				testEquation.coEfficientArr[2] = c;
				for (int d = 1; d < 10; d++)
				{
					testEquation.coEfficientArr[3] = d;
					for (int e = 1; e < 10; e++)
					{
						testEquation.coEfficientArr[4] = e;
						computeY(&testEquation);
						testEquation.MSE = computeMSE(realEquation, testEquation);
						if (testEquation.MSE < resultEquation.MSE)
						{
							copyEquation(&resultEquation, &testEquation);
						}
						if (resultEquation.MSE == 0)
						{
							break;
						}
					}
					if (resultEquation.MSE == 0)
					{
						break;
					}
				}
				if (resultEquation.MSE == 0)
				{
					break;
				}
			}
			if (resultEquation.MSE == 0)
			{
				break;
			}
		}
		if (resultEquation.MSE == 0)
		{
			break;
		}
	}
	for (int i = 0; i < C; i++)
	{
		printf("Coefficient %d: %d\n", i + 1, resultEquation.coEfficientArr[i]);
	}
	printf("MSE = %lf\n", resultEquation.MSE);
	printf("The equation: y = %d(x^4) + %d(x^3) + %d(x^2) + %dx + %d", resultEquation.coEfficientArr[0], 
			resultEquation.coEfficientArr[1], resultEquation.coEfficientArr[2], 
			resultEquation.coEfficientArr[3], resultEquation.coEfficientArr[4]);
	return 0;
}

//c is coefficient array that holds C coefficient
//x is the x values of equation
equation newEquation(int c[C], double x[N])
{
	equation tmpEquation;
	for (int i = 0; i < C; i++)
	{
		tmpEquation.coEfficientArr[i] = c[i];
	}
	for (int i = 0; i < N; i++)
	{
		tmpEquation.xValues[i] = x[i];
	}
	return tmpEquation;
}

//computes y values according to x and coefficient values
void computeY(equation *e)
{
	for (int i = 0; i < N; i++)
	{
		int b = C;
		(*e).yValues[i] = 0;
		for (int a = 0; a < C; a++)
		{
			b -= 1;
			(*e).yValues[i] += (*e).coEfficientArr[a] * pow((*e).xValues[i], b);
		}
	}
}

//computes and returns MSE (mean squared error) value of the equation sent (e)
double computeMSE(equation eReal, equation e)
{
	double MSE = 0;
	for (int i = 0; i < N; i++)
	{
		MSE += pow((eReal.yValues[i] - e.yValues[i]), 2);
	}
	MSE /= N;
	return MSE;
}

//copies properties of source equation to destination equation
void copyEquation(equation *dest, equation *src)
{
	for (int i = 0; i < C; i++)
	{
		(*dest).coEfficientArr[i] = (*src).coEfficientArr[i];
	}
	for (int i = 0; i < N; i++)
	{
		(*dest).yValues[i] = (*src).yValues[i];
	}
	(*dest).MSE = (*src).MSE;
	return;
}
