#include <stdio.h>
#include <string.h>
#define MAXC 50


void estrazione(char orig[], char carat, char risult[]);

int main() {

	char orig[MAXC];
	char carat;
	char risult[MAXC];

	

	printf("String in ingresso: ");
	scanf("%s", orig);
	getchar();

	printf("Carattere delimitatore: ");
	scanf("%c", &carat);

	estrazione(orig, carat, risult);

	printf("%s", risult);

	return 0;
}

void estrazione(char orig[], char carat, char risult[]) {

	int check = 0;
	int i;
	int counter = 0;
	for (i = 0; i < strlen(orig); i++) {
		if (orig[i] == carat) {
			check += 1;
			risult[counter] = orig[i];
			counter++;
		}
		else if (check % 2 == 1) {
			risult[counter] = orig[i];
			counter++;
		}
	}
	risult[counter] = '\0';

}
