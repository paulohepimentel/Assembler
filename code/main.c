#include <stdio.h>
#include <stdlib.h>
#include "montador.h"

int main()
{

    FILE *arqEntrada, *arqSaida;

    arqEntrada = fopen("Entrada.asm", "r");
    arqSaida = fopen("Saida.txt", "w");

    if(arqEntrada == NULL){
        printf("Erro, nao foi possivel abrir o arquivo\n");
    }
    else{
        traduzInstrucoes(arqEntrada, arqSaida);
    }

    printf("\nO arquivo de saida foi gerado com sucesso!\n");

    fclose(arqEntrada);
    fclose(arqSaida);

    return 0;

}

