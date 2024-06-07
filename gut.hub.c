#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



void bubbleSort(char (*V)[30], int Fim) {
    int i, j;
    char temp[30];

    for(i = 0; i < Fim; i++) {
        for(j = 0; j < Fim - 1 - i; j++) {
            if(strcmp(V[j], V[j + 1]) > 0) {
                strcpy(temp, V[j]);
                strcpy(V[j], V[j + 1]);
                strcpy(V[j + 1], temp);
            }
        }
    }
}

int main() {
	setlocale(LC_ALL,"Portuguese");
    int Fim, i;

    printf("\nQuantas pessoas deseja cadastrar? ");
    scanf("%i", &Fim);
    char (*V)[30] = malloc(Fim * sizeof(char[30])); 

    if(V == NULL) {
        printf("Erro de alocação de memória.\n");
        return 1;
    }

    for(i = 0; i < Fim; i++) {
        printf("\n----------------------------------------");
        printf("\nDigite o nome da %iª pessoa: ", i + 1);
        scanf("%s", V[i]);
    }

    bubbleSort(V, Fim);

    printf("\n---------- Organizado de Forma Alfabética ----------");
    for(i = 0; i < Fim; i++) {
        printf("\n%s", V[i]);
    }

    free(V); 
    return 0;
}

