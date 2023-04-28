#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **matrizalocada(int n){
    int **matriz = malloc (n * sizeof (int *));
    for (int i = 0; i < n; i++)
        matriz[i] = malloc (n * sizeof (int));

    //inicializar a matriz criada
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            matriz[i][j] = 0;
    
    return matriz;
}


void exibir(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
}

void gerarDiagonalPrincipal(int **matriz, int n) {
    // diagonal principal
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        matriz[i][i] = (rand() % 10) + 1;
    }
}

void gerarDiagonalSecundaria(int **matriz, int n) {
    // diagonal principal
    srand(time(NULL));
    for (int lin = 0, col = n - 1; lin < n; lin++, col--){
        matriz[lin][col] = (rand() % 10) + 1;
    }
}

void gerarTriangularSuperiorPrincial(int **matriz, int n){
    srand(time(NULL));
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++){
            matriz[i][j] = (rand() % 10) + 1;
        }   
}

void gerarTriangularPrincipalInferior(int **matriz, int n){
    srand(time(NULL));
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++){
            matriz[i][j] = (rand() % 10) + 1;
        }
}

void gerarTrinagularDiagonalSecundaria(int **matriz, int n){
    srand(time(NULL));
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++){
			matriz[i][j] = rand() % 100;
        }
}

void gerarTriangularInferiorSecundaria(int **matriz, int n){
	srand(time(NULL));
	for (int i = 1; i < n; i++)
		for (int j = n - i; j < n; j++){
			matriz[i][j] = rand() % 100;
        }
}

int main(){
    int n;
    int **matriz;
    printf("Digite o n: ");
    scanf("%d", &n);
    
    printf("Diagonal Principal\n");
    matriz = matrizalocada(n);
    gerarDiagonalPrincipal(matriz, n);
    exibir(matriz, n);
    free(matriz);

    printf("Diagonal Secundario\n");
    matriz = matrizalocada(n);
    gerarDiagonalSecundaria(matriz, n);
    exibir(matriz, n);
    free(matriz);

    printf("Tringular Superior Principal\n");
    matriz = matrizalocada(n);
    gerarTriangularSuperiorPrincial(matriz, n);
    exibir(matriz, n);
    free(matriz);

    printf("Tringular Principal Inferior\n");
    matriz = matrizalocada(n);
    gerarTriangularPrincipalInferior(matriz, n);
    exibir(matriz, n);
    free(matriz);
    
    printf("Triangular Superior Secundaria\n");
    matriz = matrizalocada(n);
    gerarTrinagularDiagonalSecundaria(matriz, n);
    exibir(matriz, n);
    free(matriz);

    printf("Triangular Inferior Secundaria\n");
    matriz = matrizalocada(n);
    gerarTriangularInferiorSecundaria(matriz, n);
    exibir(matriz, n);
    free(matriz);

    return 0;
}