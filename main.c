#include <stdio.h>
#include <stdlib.h>

#include "resolve.h"
#include "pilha.h"

int main() {
    char *entrada;
    entrada = (char *) malloc(201 * sizeof(char)); // Recebe a string da entrada
    int resultado, i, resultadoEquacao;
    fgets(entrada, 201, stdin);
    scanf("%d", &resultado); // Recebe o resultado da operação
    int contOperacoes;
    Pilha *pilha = PercorreEntrada(entrada, &contOperacoes);  // Pilha recebe os valores da entrada em formato int
    int *vetor, *vetorCompara;
    vetor = (int *) calloc(sizeof(int), (size_t)contOperacoes);  // Vetor de 0's e 1's que guarda as operações
    vetorCompara = (int *) calloc(sizeof(int), (size_t)contOperacoes); // Vetor que verifica qual operação foi executada
    Pilha *pilhaReversa = (Pilha *) malloc(sizeof(Pilha)); // Recebe o desempilhamento da pilha principal
    FPVazia(pilhaReversa);
    int v;
    while(ComparaVetor(vetor, contOperacoes) != 1){ // Loop que executa enquanto o vetor não esta preenchido apenas com 1's
        v = 0;
        Desempilha(pilha, pilhaReversa, vetor, vetorCompara, contOperacoes, &resultadoEquacao); // Desempilha e realiza as operações
        if(resultado == resultadoEquacao) { // Verifica se o resultado encontrado em Desempilha() é o resultado esperado
                for (i = 0; i < contOperacoes; i++) {  // Imprime +'s e *'s de acordo com o resultado
                    if (vetor[i] == 0)
                        printf("%c", '+');
                    else
                        printf("%c", '*');
                }
            printf("\n");
            resultadoEquacao = 0;
        }
        SomaBinario(vetor, contOperacoes);  // Soma binária dos valores do vetor, para verificar todas as combinações possíveis
        pilha = PercorreEntrada(entrada, &contOperacoes); // Lê a pilha novamente para executar com novas operações
        while(v < contOperacoes){
            vetorCompara[v] = 0; // Zera o vetorCompara para novas operações serem executadas
            v++;
        }
    }
    pilha = PercorreEntrada(entrada, &contOperacoes); // Última iteração para testar o resultado quando todas as operações são *
    Desempilha(pilha, pilhaReversa, vetor, vetorCompara, contOperacoes, &resultadoEquacao);
    if(resultado == resultadoEquacao) {
        for (i = 0; i < contOperacoes; i++) {
            if (vetor[i] == 0)
                printf("%c", '+');
            else
                printf("%c", '*');
        }
        printf("\n");
    }
    free(pilha);
    free(pilhaReversa);
    free(entrada);
    free(vetor);
    free(vetorCompara);
    return 0;
}