#include <stdio.h>
#include <stdlib.h>

//tipo para a celula, como em pilhas e listas simples
typedef struct nodo {
	int conteudo;
	struct nodo *prox;
} Celula;

//tipo para armazenar os dois ponteiros da fila
typedef struct {
	Celula *cabeca; //operacao de remocao
	Celula *cauda;  //operacao de insercao
} Fila;

/*
metodo que incializa a fila
*/
void inicializacao(Fila *f) {
	f->cabeca = NULL;
	f->cauda = NULL;
}

/*
metodo que insere um elemento na cauda da fila
*/
void inserirFila(int valor, Fila *f) {
	Celula *novo;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->conteudo = valor;
	novo->prox = NULL;

	//eh a primeira vez?
	if (!f->cauda) {
		f->cauda = novo;
		f->cabeca = novo;
	} else {
		f->cauda->prox = novo;
		f->cauda = novo;
	}
}

/*
metodo que remove elemento da cabeca da fila
*/
int removerFila(Fila *f) {
	Celula *lixo;
    int ficha;
	//fila existe?
	if (f->cabeca) {
		ficha = f->cabeca->conteudo;
		lixo = f->cabeca;
		f->cabeca = f->cabeca->prox;
		free(lixo);

		//caso apague o ultimo elemento
		if (!f->cabeca) {
			f->cauda = NULL;
		}
		return ficha;
	} 
	return -27;
}

int contarFila(Fila f) {
	int quantidade = 0;
	if (!f.cabeca) return quantidade;

	Celula *p;
	for (p = f.cabeca; p ; p = p->prox) {
		quantidade++;
	}

	return quantidade;
}

// Construir programa em C que simule os processos de geração/retirada de 
// senha em atendimento (normal ou prioritário) e a chamada da senha 
// (a cada 3 atendimentos normais, chamar um prioritário).

// Sugere-se um menu:

// 1 - Gerar Ficha Normal - (1 a 999)
// 2 - Gerar Ficha Prioritária (1000 - 1999)
// 3 - Atender
// 4 - Sair

// Regra do negócio: a cada 3 fichas normais atendidas, chamar um ficha Prioritária
// DICA: usar duas filas, uma para normal (1  a 999) outra para Prioritária (1000 a 2000)

int main() {

	Fila normal;
	Fila prioritaria;

	inicializacao(&normal);
	inicializacao(&prioritaria);

    int acao = 0;
    int fichap = 1000;
    int fichan = 1;
    int contador = 0;
    int verdade = 1;

    while(verdade){
        printf("\n\n1-prioritario\n2-normal\n3-atender\n4-sair\n\n");
        scanf("%d", &acao);

        switch (acao){
        case 1:
            inserirFila(fichap, &prioritaria);
            fichap++;
            break;
        case 2:
            inserirFila(fichan, &normal);
            fichan++;
            break;
        case 3:
            if(contarFila(normal) != 0 && contador%3 != 0){
                printf("Ficha numero %d", removerFila(&normal));
                contador++;
            }
            else if(contarFila(prioritaria) != 0 && contador%3 == 0){
                printf("Ficha numero %d", removerFila(&prioritaria));
                contador++;
            }
            else{ 
                printf("Não possui fila\n");
            }
            break;
        case 4:
            printf("saindo....");
            verdade = 0;
            break;
        default:
            printf("numero errado\n");
            break;
        }
    }
	return 1;
}