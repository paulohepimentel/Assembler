#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "montador.h"

int contaInstrucoes(FILE* arquivo){
    /* Contador de linhas do arquivo = Numero de instruções */
    char c;
    int numInstrucao=0;

    do{
        c = fgetc(arquivo);
        if(c == '\n'){
            numInstrucao = numInstrucao+1;
        }
    }
    while(c != EOF);
    fseek(arquivo, 0, 0); /* Retorna ao inicio do arquivo */
    //printf("O arquivo possui %d instrucoes\n\n", numInstrucao);

    return numInstrucao;
}

void defineReg (char* reg){

    int i, tam;
    tam  = strlen(reg);

    for(i=0; i<tam; i++){
        if (reg[i] == ','){
            reg[i] = '\0';
        }
    }
}

int decodificaReg(char *reg){

    defineReg(reg);

    /* Assembler temporary */
    if((strcmp(reg,"$at")) == 0)    return 1;

    /* $v0 a $v1 */
    if((strcmp(reg,"$v0")) == 0)    return 2;
    if((strcmp(reg,"$v1")) == 0)    return 3;

    /* $a0 a $a3 */
    if((strcmp(reg,"$a0")) == 0)    return 4;
    if((strcmp(reg,"$a1")) == 0)    return 5;
    if((strcmp(reg,"$a2")) == 0)    return 6;
    if((strcmp(reg,"$a3")) == 0)    return 7;

    /* $t0 a $t7 */
    if((strcmp(reg,"$t0")) == 0)    return 8;
    if((strcmp(reg,"$t1")) == 0)    return 9;
    if((strcmp(reg,"$t2")) == 0)    return 10;
    if((strcmp(reg,"$t3")) == 0)    return 11;
    if((strcmp(reg,"$t4")) == 0)    return 12;
    if((strcmp(reg,"$t5")) == 0)    return 13;
    if((strcmp(reg,"$t6")) == 0)    return 14;
    if((strcmp(reg,"$t7")) == 0)    return 15;

    /* $s0 a $s7 */
    if((strcmp(reg,"$s0")) == 0)    return 16;
    if((strcmp(reg,"$s1")) == 0)    return 17;
    if((strcmp(reg,"$s2")) == 0)    return 18;
    if((strcmp(reg,"$s3")) == 0)    return 19;
    if((strcmp(reg,"$s4")) == 0)    return 20;
    if((strcmp(reg,"$s5")) == 0)    return 21;
    if((strcmp(reg,"$s6")) == 0)    return 22;
    if((strcmp(reg,"$s7")) == 0)    return 23;

    return -1;
}

int DecPBin(int num){
    if (num == 0){
        return 0;
    }
    else{
        return (num%2) + 10 * DecPBin(num/2);
    }
}

long int ComplementoDe2 (int n){

    long int num, potencia10 = 1000000000000000; /* 10*16 */
    int i, end[16];

    num = n;

    /* Inicialização do vetor de endereço */
    for(i=0; i<16; i++){
        end[i] = 0;
    }
    /* Preenchimento do vetor endereço */
    i=0;
    while(num > 0){
        end[(15)-i] = num%10;
        num = num/10;
        i++;
    }

    /* Complemento de 1 */
    for(i=0; i<16; i++){
        if(end[i] == 0){
            end[i] = 1;
        }
        else if (end[i] == 1){
            end[i] = 0;
        }
    }
    /* Complemento de 2 */
    end[15] = end[15]+1;
    for(i=15; i>=0; i--){
        if(end[i] > 1){
            end[i] = 1;
            end[i-1] = end[i-1] +1;
        }
    }

    /* Transforma vetor em um numero */
    i=0;
    while(potencia10 > 0){
        num = num + end[i]*potencia10;
        potencia10 = potencia10/10;
        i++;
    }

    return num;
}

void traduzInstrucoes(FILE *arquivoEntrada, FILE *arquivoSaida){

    /* Arquivo de saida */
    /* Leitura do arquivo de entrada */
    int i, numInstrucoes;
    char inst[5], reg1[5], reg2[5], reg3[5];

    /* Decodificacao das instruções */
    int tpR, tpI;
    int op, rt, rs, rd, sh, funct;
    long int endereco;

    numInstrucoes = contaInstrucoes(arquivoEntrada);

    /*************************** Decodificacao das instruções ***************************/
    for(i=0; i<numInstrucoes; i++){

        tpR = 0;
        tpI = 0;
        fscanf(arquivoEntrada,"%s", inst);

        /************************************ TIPO R ************************************/
        if(strcmp(inst, "add") == 0){tpR = 1; op = 0;  sh = 0;  funct = 32;}
        else if(strcmp(inst, "sub") == 0){tpR = 1; op = 0;  sh = 0;  funct = 34;}
        else if(strcmp(inst, "and") == 0){tpR = 1; op = 0;  sh = 0;  funct = 36;}
        else if(strcmp(inst,  "or") == 0){tpR = 1; op = 0;  sh = 0;  funct = 37;}
        else if(strcmp(inst, "nor") == 0){tpR = 1; op = 0;  sh = 0;  funct = 39;}
        /* Casos especiais do tipo R - Possuem shamt */
        else if(strcmp(inst, "sll") == 0){tpR = 2; op = 0;  sh = 0;  funct = 0;}
        else if(strcmp(inst, "srl") == 0){tpR = 2; op = 0;  sh = 0;  funct = 2;}

        /************************************ TIPO I ************************************/
        else if(strcmp(inst, "addi") == 0){tpI = 1; op = 8;  endereco = 0;}
        else if(strcmp(inst, "andi") == 0){tpI = 1; op = 12;  endereco = 0;}
        else if(strcmp(inst,  "ori") == 0){tpI = 1; op = 13;  endereco = 0;}

        if(tpR == 1 || tpR == 2){

            fseek(arquivoEntrada, 1, 1);
            fscanf(arquivoEntrada,"%s", reg1);
            rd = decodificaReg(reg1);

            if(tpR == 1){

                fseek(arquivoEntrada, 1, 1);
                fscanf(arquivoEntrada,"%s", reg2);
                rs = decodificaReg(reg2);

                fseek(arquivoEntrada, 1, 1);
                fscanf(arquivoEntrada,"%s", reg3);
                rt = decodificaReg(reg3);
            }
            else if(tpR == 2){

                rs = 0;
                fseek(arquivoEntrada, 1, 1);
                fscanf(arquivoEntrada,"%s", reg2);
                rt = decodificaReg(reg2);

                fseek(arquivoEntrada, 1, 1);
                fscanf(arquivoEntrada,"%d", &sh);
            }

            fprintf(arquivoSaida, "%06d%05d%05d%05d%05d%06d\n", DecPBin(op), DecPBin(rs), DecPBin(rt), DecPBin(rd), DecPBin(sh), DecPBin(funct));
        }

        else if(tpI == 1){

            fseek(arquivoEntrada, 1, 1);
            fscanf(arquivoEntrada,"%s", reg1);
            rs = decodificaReg(reg1);

            fseek(arquivoEntrada, 1, 1);
            fscanf(arquivoEntrada,"%s", reg2);
            rt = decodificaReg(reg2);

            fseek(arquivoEntrada, 1, 1);
            fscanf(arquivoEntrada,"%ld", &endereco);
            if(endereco > 0){
                endereco = DecPBin(endereco);
            }
            else{
                endereco = endereco*(-1);
                endereco = DecPBin(endereco);
                endereco = ComplementoDe2(endereco);
            }

            fprintf(arquivoSaida, "%06d%05d%05d%016ld\n", DecPBin(op), DecPBin(rt), DecPBin(rs), endereco);

        }
    }
}
