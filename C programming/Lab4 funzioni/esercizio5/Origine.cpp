#include <stdio.h>
#define DIM 5

typedef float t_matrice[DIM][DIM];
void calcola(t_matrice, int[DIM][DIM]);
int dentro(int, int);
float media(int[DIM][DIM], int, int);

int main() {
	
	int matr_orig[DIM][DIM] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{1,2,3,4,5},{6,7,8,9,10} };
	t_matrice matr_media;

	calcola(matr_media, matr_orig);

	printf("Matrice iniziale:\n");
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			printf("%3d ", matr_orig[i][j]);
		}
		printf("\n");
	}
	printf("Matrice media:\n");
	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {
			printf("%3.2f ", matr_media[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void calcola(t_matrice matr_media, int matr_orig[DIM][DIM]) {

	for (int i = 0; i < DIM; i++) {
		for (int j = 0; j < DIM; j++) {

			matr_media[i][j] = media(matr_orig, i, j);

		}
	}

}

float media(int matr_orig[DIM][DIM], int i, int j) {
	
	int media = 0;
	int contatore = 0;

	for (int h = -1; h <= 1; h++) {
		for (int k = -1; k <= 1; k++) {
			if (dentro(i+h, j+k) && ((i+h != i) || (j+k != j))) {
				media += matr_orig[i+h][j+k];
				contatore++;
			}
		}
	}

	return (float)media/contatore;
}

int dentro(int r, int c) {

	if ((r < DIM) && (r >= 0) && (c < DIM) && (c >= 0)) {
		return 1;
	}
	return 0;
}