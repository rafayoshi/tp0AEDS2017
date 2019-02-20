#include <stdlib.h>
#include <stdio.h>

#include "pilha.h"
#include "resolve.h"

int Vazia(Pilha pilha){
    return(pilha.Topo == pilha.Fundo);
}

void FPVazia(Pilha *pilha){
    pilha->Topo = (Apontador) malloc(sizeof(Celula));
    pilha->Fundo = pilha->Topo;
    pilha->Topo->prox = NULL;
    pilha->tamanho = 0;
}

//Empilha() empilha novos valores na pilha e transoforma a ? em 0 para executar operações int
void Empilha(char *conteudo, Pilha *pilha){
    int conteudoInt;
    if(*conteudo == '?')
        conteudoInt = 0;
    else
        conteudoInt = atoi(conteudo);
    Apontador aux;
    aux = (Apontador) malloc(sizeof(Celula));
    pilha->Topo->conteudo = conteudoInt;
    aux->prox = pilha->Topo;
    pilha->Topo = aux;
    pilha->tamanho++;
}


//reverteReversa() reverte a pilha reversa e empilha na pilha principal para ordená-la
void reverteReversa(Pilha *pilha, Pilha *pilhaReversa){
    Apontador q;
    char *buffer = (char *) malloc(201 * (sizeof(char)));
    while(!Vazia(*pilhaReversa)) {
        q = pilhaReversa->Topo;
        sprintf(buffer, "%d", q->prox->conteudo);
        Empilha((buffer), pilha);
        pilhaReversa->Topo = q->prox;
        free(q);
    }
    free(buffer);
}

//Desempilha() desempilha valores da pilha principal e executa as operações ao entrar um bloco (op/num/num)
void Desempilha(Pilha *pilha, Pilha *pilhaReversa, int *vetor, int *vetorCompara, int tamanho, int *resultado) {
    Apontador q;
    char *buffer = (char *) malloc(201 * (sizeof(char)));
    Bloco bloco; // Bloco (op/num/num)
    int cont = 0; // Contador do número de operações empilhadas na pilha reversa
    if(Tamanho(*pilha) > 1) {
        while (!Vazia(*pilha)) {
            q = pilha->Topo;
            if (q->prox->conteudo == 0) {
                while(vetorCompara[tamanho - cont - 1] == 2){ // Verifica se a operação em questão já foi executada
                    cont++;
                }
                    if (q->prox->prox->conteudo != 0) {
                    if (q->prox->prox->prox->conteudo != 0) {
                        bloco.operacao = vetor[tamanho - cont - 1]; // Verifica qual a operação a ser executada
                        vetorCompara[tamanho - cont - 1] = 2; // Inviabiliza uma nova execução de uma operação já executada
                        bloco.a = q->prox->prox->conteudo;
                        bloco.b = q->prox->prox->prox->conteudo;
                        if (bloco.operacao == 0) { // Se a operação é 0 no vetor, executa soma
                            bloco.resultado = (char) bloco.a + bloco.b;
                        } else { // Se a operação e 1 no vetor, executa multiplicação
                            bloco.resultado = (char) bloco.a * bloco.b;
                        }
                        q->prox->prox->prox->conteudo = bloco.resultado; // Resultado vai para a posição ideal na pilha
                        pilha->Topo = q->prox->prox->prox;
                        q->prox = pilha->Topo;
                        sprintf(buffer, "%d", q->prox->conteudo);
                        Empilha(buffer, pilhaReversa); // Empilha o resultado na pilha reversa
                        free(q);
                        pilha->tamanho = pilha->tamanho - 3;
                        *resultado = bloco.resultado;  // Resultado vai para um ponteiro externo à função
                        cont++;
                    }
                    else { // Caso não seja encontrado um bloco (op/num/num) mas seja encontrada uma ?
                        pilha->Topo = q->prox;
                        sprintf(buffer, "%d", q->prox->conteudo);
                        Empilha(buffer, pilhaReversa);
                        free(q);
                        cont++;
                        pilha->tamanho--;
                    }
                }
                else { // Caso não seja encontrado um bloco (op/num/num) mas seja encontrada uma ?
                    pilha->Topo = q->prox;
                    sprintf(buffer, "%d", q->prox->conteudo);
                    Empilha(buffer, pilhaReversa);
                    cont++;
                    free(q);
                    pilha->tamanho--;
                }
            }
            else{ // Caso não seja encontrado um bloco (op/num/num) mas seja encontrado um número
                pilha->Topo = q->prox;
                sprintf(buffer, "%d", q->prox->conteudo);
                Empilha(buffer, pilhaReversa);
                free(q);
                pilha->tamanho--;
            }
        }
        reverteReversa(pilha, pilhaReversa);
        Desempilha(pilha, pilhaReversa, vetor, vetorCompara, tamanho, resultado); // Desempilha novamente a pilha, com novos valores
    }
    free(buffer);
}

int Tamanho(Pilha pilha){
    return(pilha.tamanho);
}