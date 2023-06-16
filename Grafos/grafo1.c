#include <stdio.h>
#include <stdlib.h>

#include "grafo.h"

int main(){
    Grafo *grafo1 = inicializarGrafo(5);

    inserirGrafo(0, 1, grafo1);
    inserirGrafo(0, 2, grafo1);
    inserirGrafo(1, 0, grafo1);
    inserirGrafo(1, 2, grafo1);
    inserirGrafo(1, 4, grafo1);
    inserirGrafo(2, 3, grafo1);
    inserirGrafo(2, 4, grafo1);
    inserirGrafo(3, 2, grafo1);
    inserirGrafo(4, 3, grafo1);
    
    exibir(grafo1);

    mostraCaminhoAmplitude(0, grafo1);
    return 0;
}