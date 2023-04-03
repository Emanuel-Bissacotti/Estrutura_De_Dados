#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main(){
    Celula *listD = NULL;
    for (int i = 0; i < 10; i++){
        listD = insert(rand() % 100, listD);
    }
    showList(listD);
    printf("\nNumero para excluir: ");
    int value;
    scanf("%d", &value);
    listD = delete(value, listD);
    showList(listD);
    printf("Lista tem %d numeros\n", counter(listD));
}