#include <stdio.h>
#include <random>

#define DIM_MARE 5
#define EN_MAX 5
#define N_NAVI 5

typedef struct {
	int r; // riga
	int c; // colonna
	int energia;
}s_nave;

void setup(int (*mare)[DIM_MARE][DIM_MARE], s_nave(*flotta)[N_NAVI]);
int CheckMareFlotta(int mare[DIM_MARE][DIM_MARE], s_nave nave);
void StampaMare(int mare[DIM_MARE][DIM_MARE]);
void StampaFlotta(s_nave flotta[N_NAVI]);
void Fuoco(int (*mare)[DIM_MARE][DIM_MARE], s_nave(*flotta)[N_NAVI]);
int GameOver(s_nave flotta[N_NAVI]);

int main() {

	s_nave flotta[N_NAVI];
	int mare[DIM_MARE][DIM_MARE];
	int counter = 0;
	srand(time(NULL));

	setup(&mare, &flotta);
	StampaMare(mare);
	StampaFlotta(flotta);
	printf("Partita:\n");
	
	do {
		Fuoco(&mare, &flotta);
		counter++;
	} while (GameOver(flotta) != -1);

	printf("Tutte le navi sono state affondate dopo %d colpi!", counter);

	return 0;
}

void setup(int(*mare)[DIM_MARE][DIM_MARE], s_nave(*flotta)[N_NAVI])
{
	for (int i = 0; i < DIM_MARE; i++) {
		for (int j = 0; j < DIM_MARE; j++) {
			(*mare)[i][j] = -1;
		}
	}

	for (int i = 0; i < N_NAVI; i++) {
		do {
			(*flotta)[i].c = rand() % 5;
			(*flotta)[i].r = rand() % 5;
		} while (CheckMareFlotta(*mare, (*flotta)[i]) == -1);
		(*mare)[(*flotta)[i].r][(*flotta)[i].c] = i;

		do {
			(*flotta)[i].energia = rand() % 6;
		} while ((*flotta)[i].energia == 0);
	}
	return;
}

int CheckMareFlotta(int mare[DIM_MARE][DIM_MARE], s_nave nave)
{	
	if (mare[nave.r][nave.c] != -1) {
		return -1;
	}
	else
		return 0;
}

void StampaMare(int mare[DIM_MARE][DIM_MARE])
{
	printf("Mare:\n");
	for (int i = 0; i < DIM_MARE; i++) {
		for (int j = 0; j < DIM_MARE; j++) {
			printf(" %2d", mare[i][j]);
		}
		printf("\n");
	}
}

void StampaFlotta(s_nave flotta[N_NAVI])
{
	for (int i = 0; i < N_NAVI; i++) {
		printf("Nave %d in (%d, %d): energia = %d\n", i, flotta[i].r, flotta[i].c, flotta[i].energia);
	}
}

void Fuoco(int(*mare)[DIM_MARE][DIM_MARE], s_nave(*flotta)[N_NAVI])
{
	int r = rand() % 5;
	int c = rand() % 5;
	int temp;

	printf("Fuoco in coordinate (%d, %d): ", r, c);

	if ((*mare)[r][c] != -1) {
		(*flotta)[(*mare)[r][c]].energia--;
		temp = (*flotta)[(*mare)[r][c]].energia;
		if (temp == 0)
			printf("Nave %d colpita e affondata!\n", (*mare)[r][c]);
		else if(temp<0)
			printf("Nave %d gia' affondata!\n", (*mare)[r][c]);
		else
			printf("Nave %d colpita! Energia rimanente = %d\n", (*mare)[r][c], temp);
	}
	else
		printf("Acqua!\n");
}

int GameOver(s_nave flotta[N_NAVI])
{
	for (int i = 0; i < N_NAVI; i++) {
		if (flotta[i].energia > 0)
			return 0;
	}
	return -1;
}
