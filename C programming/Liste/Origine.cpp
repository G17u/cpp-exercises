#include <stdio.h>
#include <malloc.h>
#include <random>

#define LEN_LISTA 40

struct el { int info; struct el* next; };

///////////////////////////////////////////

//Eliminazione di un elemento singolo dalla testa di lista
struct el* pop(struct el* L)
{
	struct el* temp;
	if (L == NULL) return NULL;
	temp = L;
	L = temp->next;
	temp->next = NULL;
	return (L);
}
// creazione di un elemento
struct el* creael(int v)
{
	struct el* temp;
	temp =(struct el*) malloc(sizeof(struct el));
	if (temp == NULL) return NULL;

	temp->info = v; 
	temp->next = NULL;
	return(temp);
}
//eliminazione elemento in posizione indice
struct el* ElimElementoIndice(struct el* lista, int indice) {
	int i = 0;
	struct el* temp = lista;
	struct el* inizio = lista;

	if (lista == NULL) return NULL;

	while ((lista != NULL) && (i < indice - 1)) {
		lista = lista->next;
		i++;
	}
	if (lista->next == NULL) return inizio;
	if (indice == 0) {
		temp = lista;
		inizio = lista->next;
		free(temp); temp = NULL;
		return inizio;
	}

	temp = lista->next;
	lista->next = (lista->next)->next;
	free(temp); temp = NULL;

	return inizio;
}

struct el *push(struct el *lista, struct el *NewE) {
	if (NewE == NULL) return lista;
	
	NewE->next = lista;
	lista = NewE;
	return lista;

}


// estraggo tutti gli elementi con valore n, 
// mettendoli in una nuova lista
struct el* RicercaTutti(struct el** lista, int n)
{
	struct el* NuovaLista = NULL;
	struct el* elemento = NULL;
	struct el* prec = *lista;
	struct el* temp = *lista;
	int indice = 0;

	if (*lista == NULL) return NULL;

	while (temp != NULL) {

		if (temp->info == n) {
			if (temp==*lista) {
				*lista = (*lista)->next;
				free(temp); temp = NULL;
				prec = *lista;
				indice++;
			}
			else {
				prec->next = temp->next;
				free(temp); temp = NULL;
				indice++;
			}
			temp = prec->next;
		}
		else {
			prec = temp;
			temp = temp->next;
		}
		
	}

	for (int i = 0; i < indice; i++) {
		elemento = creael(n);
		NuovaLista = push(NuovaLista, elemento);
	}
	return NuovaLista;
}

int main() {

	struct el* lista = NULL;
	struct el* elemento = NULL;
	struct el* ListaClasse = NULL;
	int n;

	srand(time(NULL));
	
	// Inizializzo lista con numeri casuali
	for (int i = 0; i < LEN_LISTA; i++) {
		elemento = creael(rand() % 10);
		lista = push(lista, elemento);
	}

	printf("Inserisci il numero da cercare: ");
	scanf("%d", &n);
	
	printf("\nLa lista era: ");
	

	struct el* temp = lista;
	while (temp != NULL) {
		printf("%d ", temp->info);
		temp = temp->next;
	}

	ListaClasse = RicercaTutti(&lista, n);

	printf("La listaClasse e': ");
	while (ListaClasse != NULL) {
		printf("%d ", ListaClasse->info);
		ListaClasse = ListaClasse->next;
	}
		
	printf("\nLa lista e' : ");
	while (lista != NULL) {
		printf("%d ", lista->info);
		lista = lista->next;
	}

	

	return 0;
}
