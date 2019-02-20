//
// Created by Rafael_Yoshinaga on 18/04/2017.
//
#include "pilha.h"

#ifndef TP02017_RESOLVE_H
#define TP02017_RESOLVE_H

typedef struct Bloco{
    int a, b, resultado, operacao;
}Bloco;

Pilha *PercorreEntrada(char *, int *);
void Desempilha(Pilha *, Pilha *, int * ,int *, int, int *);
void SomaBinario(int *, int);
int ComparaVetor(int *  , int);

#endif //TP02017_RESOLVE_H
