#include <stdio.h>
#include <random>
#define C_LEN 10
#define P_MAX 15

int enqueue(int (*coda)[C_LEN], int* n, unsigned int elem);
int dequeue(int (*coda)[C_LEN], int* n);
void stampa_coda(int coda[C_LEN], int n);

int main() {

	int counter;
	int coda[C_LEN];
	int n = 0;
	int check;
	srand(time(NULL));

	for (int i = 0; i < P_MAX; i++) {
		counter = rand() % 2;
		printf("Passo %d di %d. ", i+1, P_MAX);
		
		switch (counter) {
		case 0:
			printf("USCITA ->");
			check = dequeue(&coda, &n);
			if (check == -1)
				printf(" Coda vuota, nessuna uscita. ");
			else
				printf("Uscita di %d avvenuta. ", check);
			stampa_coda(coda, n);
			break;
		case 1:
			printf("ENTRATA ->");
			int num = rand() % 10;
			check = enqueue(&coda, &n, num);
			if (check == -1)
				printf(" Coda piena, nessuna entrata. ");
			else
				printf("Entrata di %d avvenuta. ", num);
			stampa_coda(coda, n);
			break;
		}
	}

	return 0;
}

int enqueue(int (*coda)[C_LEN], int* n, unsigned int elem) {

	if (*n < C_LEN) {
		(*coda)[*n] = elem;
		(*n)++;
		return 1;
	}
	else
		return -1;

}
int dequeue(int (*coda)[C_LEN], int* n) {
	int temp;

	if (*n > 0) {
		temp = (*coda)[0];
		
		if (*n == 1) {
			(*n)--;
			return temp;
		}
		else {
			for (int i = 1; i < *n; i++) {
				(*coda)[i - 1] = (*coda)[i];
			}
			(*n)--;
			return temp;
		}
	}
	else
		return -1;
}
void stampa_coda(int coda[C_LEN], int n) {

	printf("Coda: ");

	if (n == 0) {
		printf("<vuota>\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		printf(" %d", coda[i]);
	}

	if (n == C_LEN) {
		printf(" <piena>\n");
		return;
	}
	printf("\n");
	return;
}