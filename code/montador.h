#ifndef MONTADOR_H_INCLUDED
#define MONTADOR_H_INCLUDED

/* Tipo R de instruções: op(6) rs(5) rt(5) rd(5) sh(5) fun(6) */
/* Tipo I de instruções: op(6) rs(5) rt(5) end(16) */

/* Função responsável por contar o número de instruções presentes no arquivo */
int contaInstrucoes(FILE* arquivo);

/* Elimina resquícios da leitura do arquivo (A ',' entre os reg) */
void defineReg (char *reg);

/* Função responsável por retornar o valor, em decimal, do registrador */
int decodificaReg(char *reg);

/* Função responsável por converter numero decimal em binário */
int DecPBin(int num);

/* Transforma numeros negativos em binário */
long int ComplementoDe2 (int n);

/* Função responsavel por ler as instruções do arquivo e decodificá-las e gerar um arquivo de saída */
void traduzInstrucoes(FILE *arquivoEntrada, FILE *arquivoSaida);

#endif // MONTADOR_H_INCLUDED
