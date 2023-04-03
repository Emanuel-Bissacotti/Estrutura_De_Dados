typedef struct no {
    struct no *ant;
    int dado;
    struct no *prox;
} Celula;

void showList(Celula *listD){
    if(!listD){
        printf("Nao exite lista\n");
        return ;
    }
    Celula *p = NULL;
    printf("exibindo lista\n");
    for(p = listD; p; p = p->prox){
        printf("%d\t", p->dado);
    }
    return ;
}

Celula *insert(int valor, Celula *listD){
    Celula *novo; 
    Celula *pR, *p;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->dado = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    if (!listD) { //cria lista
        return novo;
    }

    for (pR = NULL, p = listD; p ; pR = p, p = p->prox){
        if (valor < p->dado) {
            break;
        }
    }
    if (!pR){ //inicio
        novo->prox = p; 
        p->ant = novo;
        return novo;
    }
    else if (!p){ //ultima
        pR->prox = novo;
        novo->ant = pR;
    }
    else{ //meio
        pR->prox = novo;
        novo->ant = pR;
        novo->prox = p;
        p->ant = novo;
    }	
	return listD;
}

Celula *delete(int valor, Celula *listD){
    Celula *p, *pR;

    if(!listD) {
        printf("não exite lista\n");
        return listD;
    }
    for (pR = NULL, p = listD; p ; pR = p, p = p->prox) {
        if (valor == p->dado) {
            printf("Valor encontrado\n");
            break;
        }
    }

    if(!p){
        printf("Nao exite esse valor na lista\n");
        return listD;
    }

    if (!pR) {
        listD = listD->prox;
        listD->ant = NULL;
    } else if (!p->prox) {
        pR->prox = NULL;
    } else {
        pR->prox = p->prox;
        p->prox->ant = pR;
    }
    free(p);
    return listD;
}

int counter(Celula *listD){
    Celula *p;
    int counter = 0;
    for (p = listD; p; counter++, p = p->prox);
    
    return counter;
}