#include <stdio.h>
#include <malloc.h>
#include <random>

#define LenNome 20
#define DIM 10
#define PATH_LEN 30

typedef struct s_elem {
	char codice;
	int quantita;
	s_elem* next;
};
typedef enum {txt, bin} t_file;

void StampaLista(s_elem* lista, const char nomelista[LenNome]) {
	printf("%s: ", nomelista);
	while (lista != NULL) {
		printf("[%c, %d]->", lista->codice, lista->quantita);
		lista = lista->next;
	}
	printf("NULL\n");
}

s_elem* CreaElem(char codice, int quantita) {
	s_elem* elemento;
	elemento = (s_elem*)malloc(sizeof(s_elem));
	if (elemento == NULL)
		return NULL;

	elemento->next = NULL;
	elemento->codice = codice;
	elemento->quantita = quantita;
	return elemento;
}

s_elem* InserisciTesta(s_elem* lista, s_elem* elemento) {
	
	if (elemento == NULL)
		return NULL;
	elemento->next = lista;
	lista = elemento;
	return lista;
}

s_elem* InserisciCoda(s_elem* lista, s_elem* elemento) {
	s_elem* temp = lista;
	
	if (lista == NULL) {
		lista = elemento;
		return lista;
	}
	else {
		while (lista->next != NULL) {
			lista = lista->next;
		}		
		lista->next = elemento;
		return temp;
	}
}

s_elem* CercaElem(s_elem* lista, char codice) {
	while (lista != NULL) {
		if (lista->codice == codice)
			return lista;
		lista = lista->next;
	}
	return lista;
}

s_elem* Raggruppa(s_elem* lista) {

	s_elem* NewLista = NULL;
	s_elem* temp;
	s_elem* elemento;


	while (lista != NULL) {
		temp = CercaElem(NewLista, lista->codice);
		
		if ( temp != NULL) {
			temp->quantita = lista->quantita + temp->quantita;
		}
		else {
			elemento = CreaElem(lista->codice, lista->quantita);
			NewLista = InserisciCoda(NewLista, elemento);
		}

		lista = lista->next;
	}


	return NewLista;
}

s_elem* FiltraLista(s_elem* lista, char codice) {

	s_elem* temp = lista;
	s_elem* prec = NULL;

	while (temp != NULL) {
		if (temp->codice == codice) {
			
			if (prec == NULL) {
				lista = lista->next;
				free(temp);
				temp = lista;
			}
			else {
				prec->next = temp->next;
				free(temp);
				temp = prec->next;
			}
			
		}
		else {
			prec = temp;
			temp = temp->next;
		}
			
	}
	return lista;
}

void DividiLista(s_elem** listaInput, s_elem** listaPari, s_elem** listaDispari) {

	int counterP = 0;
	int counterD = 0;
	s_elem* tempPari = NULL;
	s_elem* tempDispari = NULL;

	while (*listaInput != NULL) {
		if (((*listaInput)->quantita % 2 == 0) && ((*listaInput)->quantita % 5 != 0)) {
			if (counterP == 0) {
				*listaPari = *listaInput;
				*listaInput = (*listaInput)->next;
				tempPari = *listaPari;
				tempPari->next = NULL;
				counterP++;
			}
			else {
				tempPari->next = *listaInput;
				*listaInput = (*listaInput)->next;
				tempPari = tempPari->next;
				tempPari->next = NULL;
			}
			
		}
		else if (((*listaInput)->quantita % 2 == 1) && ((*listaInput)->quantita % 5 != 0)) {
			if (counterD == 0) {
				*listaDispari = *listaInput;
				*listaInput = (*listaInput)->next;
				tempDispari = *listaDispari;
				tempDispari->next = NULL;
				counterD++;
			}
			else {
				tempDispari->next = *listaInput;
				*listaInput = (*listaInput)->next;
				tempDispari = tempDispari->next;
				tempDispari->next = NULL;
			}
		}
		else {
			*listaInput = (*listaInput)->next;
		}
	}

}

int SalvaLista(s_elem* lista, const char nomeFile[PATH_LEN], t_file tipoFile) {

	FILE* fileptr;
	int ris;

	if (tipoFile == txt) {
		fileptr = fopen(nomeFile, "w");
		if (fileptr == NULL) {
			printf("Errore durante l'apertura\n");
			return -1;
		}
			
		while (lista != NULL) {
			ris = fprintf(fileptr, "%c %d\n", lista->codice, lista->quantita);
			if (ris == 0) {
				printf("Errore durante la scrittura testuale della lista nel file \"%s\".\n", nomeFile);
				return -1;
			}
			lista = lista->next;
		}
		fclose(fileptr);
		return 0;
	}
	else {
		fileptr = fopen(nomeFile, "wb");
		if (fileptr == NULL) {
			printf("Errore durante l'apertura\n");
			return -1;
		}
		while (lista != NULL) {
			ris = fwrite(lista, sizeof(lista), 1, fileptr);
			if (ris == 0) {
				printf("Errore durante la scrittura binaria della lista nel file \"%s\".\n", nomeFile);
				return -1;
			}
			lista = lista->next;
		}
		fclose(fileptr);
		return 0;
	}
	

}

int CaricaLista(s_elem** lista, const char nomeFile[PATH_LEN], t_file tipoFile) {

	FILE* fileptr;
	s_elem* elemento;
	char codice;
	int quantita;

	if (tipoFile == txt) {
		fileptr = fopen(nomeFile, "r");
		if (fileptr == NULL) {
			printf("Errore durante l'apertura\n");
			return -1;
		}
		
		

		while (fscanf(fileptr, "%c %d\n", &codice, &quantita) == 2) {
			elemento = CreaElem(codice, quantita);
			*lista = InserisciCoda(*lista, elemento);
		}
		if (ferror(fileptr)) {
			printf("Errore durante la lettura testuale della lista dal file\"%s\".\n", nomeFile);
			return -1;
		}
		fclose(fileptr);
	}
	else {
		fileptr = fopen(nomeFile, "rb");
		if (fileptr == NULL) {
			printf("Errore durante l'apertura\n");
			return -1;
		}
		elemento = CreaElem('1', 1);
		while (fread(elemento, sizeof(elemento), 1, fileptr) > 0 ) {
			*lista = InserisciCoda(*lista, elemento);
			elemento = CreaElem('1', 1);
		}
		if (ferror(fileptr)) {
			printf("Errore durante la lettura binaria della lista dal file\"%s\".\n", nomeFile);
			return -1;
		}
		fclose(fileptr);
	}
	return 0;
}

int main() {

	s_elem* lista1 = NULL; s_elem* lista2 = NULL; s_elem* lista3 = NULL;
	s_elem* listaDispari = NULL;; s_elem* listaPari = NULL;
	s_elem* listaDispariVecchia = NULL;; s_elem* listaPariVecchia = NULL;
	s_elem* elemento = NULL;
	char codice;
	int quantita;
	srand(time(NULL));

	//lista inserita dalla testa
	for (int i = 0; i < DIM; i++) {
		codice = 'A' + rand() % ('Z' - 'A' + 1);
		quantita = rand() % 10;
		elemento = CreaElem(codice, quantita);
		lista1 = InserisciTesta(lista1, elemento);
		printf("[%c, %d] ", elemento->codice, elemento->quantita);
	}
	printf("\n");
	StampaLista(lista1, "Lista1");
	printf("\n");

	//lista inserita dalla coda
	for (int i = 0; i < DIM; i++) {
		codice = 'A' + rand() % ('Z' - 'A' + 1);
		quantita = rand() % 10;
		elemento = CreaElem(codice, quantita);
		lista2 = InserisciCoda(lista2, elemento);
		printf("[%c, %d] ", elemento->codice, elemento->quantita);
	}
	printf("\n");
	StampaLista(lista2, "Lista2");

	//lista che raggruppa elementi della lista1
	lista3 = Raggruppa(lista1);
	printf("\n");
	StampaLista(lista3, "Lista3");

	//eliminazione elementi dalla lista1
	printf("\n"); 
	printf("Quale codice va eliminato? "); 
	scanf("%c", &codice); 
	lista1 = FiltraLista(lista1, codice); 
	printf("\n"); 
	StampaLista(lista1, "Lista1");
	

	//dividiLista sulla lista3
	DividiLista(&lista3, &listaPari, &listaDispari);
	printf("\n");
	StampaLista(lista3, "Lista3");
	printf("\n");
	StampaLista(listaPari, "ListaPari");
	printf("\n");
	StampaLista(listaDispari, "ListaDispari");

	CaricaLista(&listaPariVecchia, "ListaPari", txt);
	CaricaLista(&listaDispariVecchia, "ListaDispari", bin);

	printf("\n");
	StampaLista(listaPariVecchia, "listaPariVecchia");
	printf("\n");
	StampaLista(listaDispariVecchia, "listaDispariVecchia");

	printf("\n");
	SalvaLista(listaPari, "ListaPari", txt);
	SalvaLista(listaDispari, "ListaDispari", bin);

	return 0;
}