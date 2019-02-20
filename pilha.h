#ifndef TP02017_PILHA_H
#define TP02017_PILHA_H

struct Celula;

typedef struct Celula *Apontador;

typedef struct Celula{
    int conteudo;
    Apontador prox;
}Celula;

typedef struct {
    Apontador Fundo, Topo;
    int tamanho;
}Pilha;

void FPVazia(Pilha *);
int Vazia(Pilha);
void Empilha(char *, Pilha *);
int Tamanho(Pilha);

#endif //TP02017_PILHA_H
