#include <stdio.h>
#define TXTL 20

typedef struct s_data {
	int anno;
	int mese;
	int giorno;
};
typedef struct s_bollettino {
	s_data data;
	char meteo[TXTL];
};
int gg_mese[12]= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int anno_bisestile(int anno);
int verifica_data(s_data data);
int giorni_da_capodanno(s_data data);
void ins_bollettino(s_bollettino* bollettino);
void stampa_bollettino(s_bollettino bollettino);

int main() {

	s_bollettino bollettino;

	ins_bollettino(&bollettino);
	stampa_bollettino(bollettino);

	return 0;
}

int anno_bisestile(int anno) {

	if ((anno % 4 == 0) && (anno % 100 != 0 || anno % 400 == 0)) return 1;
	else return 0;
}

int verifica_data(s_data data) {

	if (data.anno >= 2000) {
		if (data.mese >= 1 && data.mese <= 12) {
			if (anno_bisestile(data.anno) == 1)
				gg_mese[2] = gg_mese[2] + 1;
			
			if (data.giorno >= 1 && (data.giorno <= gg_mese[data.mese])) return 1;
		}
	}
	return 0;
}

int giorni_da_capodanno(s_data data) {
	int sommagiorni = 0;
	
	if (anno_bisestile(data.anno) == 1)
		gg_mese[2] = 29;


	for (int i = 1; i < data.mese; i++) {
		sommagiorni += gg_mese[i];
	}
	sommagiorni += data.giorno;
	return sommagiorni;
}

void ins_bollettino(s_bollettino* bollettino) {

	do {
		printf("Inserire l'anno: ");
		scanf("%d", &(bollettino->data).anno);
		
		printf("Inserire il mese: ");
		scanf("%d", &(bollettino->data).mese);
		
		printf("Inserire il giorno: ");
		scanf("%d", &(bollettino->data).giorno);
		
	} while (verifica_data(bollettino->data) == 0);
	
	printf("Inserire il meteo in questa data: ");
	scanf("%s", &bollettino->meteo);

}

void stampa_bollettino(s_bollettino bollettino) {
	
	printf("Il bollettino meteorologico in data %d/%d/%d e': %s\n", bollettino.data.giorno, bollettino.data.mese, bollettino.data.anno, bollettino.meteo);
	printf("Dall'inizio dell'anno sono passati %d giorni\n", giorni_da_capodanno(bollettino.data));
	if (anno_bisestile(bollettino.data.anno) == 1)
		printf("L'anno %d e' bisestile", bollettino.data.anno);
	else
		printf("L'anno %d non e' bisestile", bollettino.data.anno);

}