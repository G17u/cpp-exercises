#include <stdio.h>

int es1() {

    char stagione;
    float temp;

    printf("Inserire la stagione: ");
    scanf("%c", &stagione);
    printf("Inserire la temperatura: ");
    scanf("%f", &temp);

    if (stagione == 'e') {
        if (temp < 32.5 && temp>27.5) printf("Stagione estiva compresa nella media stagionale");
        else printf("Stagione estiva NON compresa nella media stagionale");
    }
    else if (stagione == 'i') {
        if (temp < 7.5 && temp>2.5) printf("Stagione invernale compresa nella media stagionale");
        else printf("Stagione invernale NON compresa nella media stagionale");
    }

    return 0;
}

int es3() {

    int a, b;
    float calcolo;
    char op;

    printf("Inserire a: ");
    scanf("%d", &a);
    
    getchar();
    printf("Inserire b: ");
    scanf("%d", &b);
    
    getchar();
    printf("Inserire op: ");
    scanf("%c", &op);

    if (op == '+') calcolo = a + b;
    else if (op == '-') calcolo = a - b;
    else if (op == '*') calcolo = a * b;
    else if (op == '/') calcolo = (float)a / b;
    else if (op == 'M') {
        if (a > b) calcolo = a;
        else calcolo = b;
    }
    else if (op == 'm') {
        if (a > b) calcolo = b;
        else calcolo = a;
    }
    else printf("E' stato inserito un operatore invalido");

    printf("\n Il risultato e': %g", calcolo);

    return 0;
}

int es4() {

    int a, div, resto;


    printf("Inserire un numero intero da convertire in binario: ");
    scanf("%d", &a);

    div = a;

    do {

        div = a / 2;
        resto = a % 2;

        printf("%d / 2 = %d resto %d\n", a, div, resto);
        a = div;

    } while (div != 0);

    return 0;
}

int es5() {

    return 0;
}

int main()
{
    return es4();
}
