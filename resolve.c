//
// Created by Rafael_Yoshinaga on 18/04/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "resolve.h"

// PercorreEntrada() percorre a string de entrada e monta a pilha ignorando os espaços e encontrando números de mais de 1 dígito
Pilha *PercorreEntrada(char *entrada, int *cont){
    int k = 0, contador = 0;
    *cont = 0;
    char *buffer = (char *) malloc(201 * sizeof(char));
    Pilha *pilha = (Pilha *) malloc(sizeof(Pilha));
    FPVazia(pilha);
    while(entrada[k] != '\0') { // Verifica se a string chegou ao fim
        while (!isspace(entrada[k])) { // Encontra números com mais de 1 dígito
            if (entrada[k] == '?') {
                *cont = *cont + 1;
            }
            buffer[contador] = entrada[k]; // Monta o buffer com o número de dígitos da entrada
            k++;
            contador++;
        }
        Empilha((buffer), pilha);
        memset(&buffer[0], 0, 201 * sizeof(char)); // Zera o buffer
        contador = 0;
        k++;
    }
    free(buffer);
    return pilha;
}

// SomaBinario() soma 1 binário no vetor binário
void SomaBinario(int *vetorBinario, int tamanho){
    int i = tamanho - 1;
    if (vetorBinario[i] == 0){
        vetorBinario[i] = 1;
    }
    else{
        vetorBinario[i] = 0;
        if (i > 0) {
            SomaBinario(vetorBinario, tamanho - 1);
        }
    }
    return;
}
 // ComparaVetor() verifica se o vetor só tem 1's
int ComparaVetor(int *vetorBinario, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        if(vetorBinario[i] == 0){
            return 0;
        }
    }
    return 1;
}