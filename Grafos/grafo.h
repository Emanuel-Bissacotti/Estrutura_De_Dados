#include "fila.h"

typedef struct {
    int **matrizADJ;
    int qtdVertices;
    int qtdArestas;
} Grafo;

Grafo *inicializarGrafo(int vertices){
    Grafo *g = (Grafo *)malloc(sizeof(Grafo));

    g->qtdVertices = vertices;
    g->qtdArestas = 0;
    g->matrizADJ = malloc(sizeof(int *) * vertices);
    for (int i = 0; i < vertices; i++)
    {
        g->matrizADJ[i] =  malloc(sizeof(Grafo) * vertices);
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            g->matrizADJ[i][j] = 0;
        }      
    }
    
    return g;
}

void inserirGrafo(int origem, int destino, Grafo *g){
    if (origem < 0 || origem >= g->qtdVertices || destino < 0 ||
		destino >= g->qtdVertices || g->matrizADJ[origem][destino] != 0) {
		printf("Aresta nao cadastrada\n");
        return ;
	}

	g->matrizADJ[origem][destino] = 1;
	g->qtdArestas++;


}

void exibir(Grafo *g){
    if (!g) {
		printf("Grafo nao existe\n");
	} else {
		int i,j;
		for (i = 0; i < g->qtdVertices;i++) {
			printf("%d: ", i);
			for (j = 0; j < g->qtdVertices; j++) {
				if (g->matrizADJ[i][j] != 0)
					printf("%d   ", j);
			}
			printf("\n");
		}
	}
}

int grauVertice(int vertice, Grafo *g) {
    if (!g) return 0;
    int i;
    int conta = 0;
    for (i = 0; i < g->qtdVertices; i++) {
        if (g->matrizADJ[vertice][i] != 0) conta++;
        if (g->matrizADJ[i][vertice] != 0) conta++;
    }
    return conta;
}

int ehSimetrico(Grafo *g) {
    if (!g) return -27;
    int i, j;

    for (i = 0; i < g->qtdVertices; i++) {
        for (j = i; j < g->qtdVertices; j++) {
            if (g->matrizADJ[i][j] != g->matrizADJ[j][i])
                return 0;
        }
    }
    return 1;
}

void mostraCaminhoAmplitude(int origem, Grafo *g){
    int i, no;
	Fila fila;
	inicializarFila(&fila);

	int *visitados;
	visitados = malloc(sizeof(int) * g->qtdVertices);
	for (i = 0; i < g->qtdVertices; i++){
		visitados[i] = 0;
	}
	visitados[origem] = 1;
	no = origem;
	do {
		printf("%d\t", no);

		for (i = 0; i < g->qtdVertices; i++) {
			if (g->matrizADJ[no][i] != 0 && !visitados[i]) {
				visitados[i] = 1;
				inserirFila(i, &fila);
			}
		}
		no = removerFila(&fila);

	} while (no != -1);
	
    
}