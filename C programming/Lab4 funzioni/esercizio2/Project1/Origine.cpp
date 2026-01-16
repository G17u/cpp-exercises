#include <stdio.h>
#include <random>

void genera_matrice(int matrice[2][2], int *det, int *sum) {

	srand(time(NULL));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			matrice[i][j] = rand() % 10;
		}
	}
	*det = (matrice[0][0] * matrice[1][1]) - (matrice[1][0] * matrice[0][1]);
	*sum= matrice[0][0] + matrice[1][1] + matrice[1][0] + matrice[0][1];
}


int main() {

	int det = 0, sum = 0;
	int matrice[2][2];

	genera_matrice(matrice, &det, &sum);

	printf("Matrice 2x2: \n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", matrice[i][j]);
		}
		printf("\n");
	}
	printf("Determinante: %d", det);
	printf("Somma: %d", sum);

	return 0;
}