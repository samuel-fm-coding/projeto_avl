#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

struct No {
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
};

int altura(struct No *n) {
    if (n == NULL)
        return 0;
    return n->altura;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

struct No* novoNo(int valor) {
    struct No* nodo = (struct No*)malloc(sizeof(struct No));
    nodo->valor = valor;
    nodo->esq = NULL;
    nodo->dir = NULL;
    nodo->altura = 1; // novo nó é inicialmente adicionado na folha
    return nodo;
}

struct No* rotacionarDireita(struct No *y) {
    struct No *x = y->esq;
    struct No *T2 = x->dir;

    // Realiza a rotação
    x->dir = y;
    y->esq = T2;

    // Atualiza as alturas
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;

    return x; // nova raiz
}

struct No* rotacionarEsquerda(struct No *x) {
    struct No *y = x->dir;
    struct No *T2 = y->esq;

    // Realiza a rotação
    y->esq = x;
    x->dir = T2;

    // Atualiza as alturas
    x->altura = max(altura(x->esq), altura(x->dir)) + 1;
    y->altura = max(altura(y->esq), altura(y->dir)) + 1;

    return y; // nova raiz
}

int fatorBalanceamento(struct No *n) {
    if (n == NULL)
        return 0;
    return altura(n->esq) - altura(n->dir);
}

struct No* inserirNo(struct No* nodo, int valor) {
    if (nodo == NULL)
        return novoNo(valor);

    if (valor < nodo->valor)
        nodo->esq = inserirNo(nodo->esq, valor);
    else if (valor > nodo->valor)
        nodo->dir = inserirNo(nodo->dir, valor);
    else // valores duplicados não são permitidos
        return nodo;

    // Atualiza a altura deste nó
    nodo->altura = max(altura(nodo->esq), altura(nodo->dir)) + 1;

    // Obtém o fator de balanceamento
    int balance = fatorBalanceamento(nodo);

    //ROTAÇÕES

    //Esquerda-Esquerda
    if (balance > 1 && valor < nodo->esq->valor)
        return rotacionarDireita(nodo);

    //Direita-Direita
    if (balance < -1 && valor > nodo->dir->valor)
        return rotacionarEsquerda(nodo);

    //Esquerda-Direita
    if (balance > 1 && valor > nodo->esq->valor) {
        nodo->esq = rotacionarEsquerda(nodo->esq);
        return rotacionarDireita(nodo);
    }

    //Direita-Esquerda
    if (balance < -1 && valor < nodo->dir->valor) {
        nodo->dir = rotacionarDireita(nodo->dir);
        return rotacionarEsquerda(nodo);
    }

    return nodo; // retorna o ponteiro do nó (inalterado)
}

void preOrdem(struct No *raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

void menu(struct No **raiz) {
    system("cls");
    int opcao = 0;

    printf("----- Árvore AVL -----\n\n");
    printf("1 - Inserir nó \n");
    printf("2 - Ver Árvore (Pré-Ordem) \n");
    printf("3 - Sair \n");
    scanf("%d", &opcao);
    
    switch (opcao) {
        case 1: {
            int numero;
            printf("Digite um número: ");
            scanf("%d", &numero);
            *raiz = inserirNo(*raiz, numero);
            break;
        }
        case 2:
            printf("Árvore em Pré-Ordem: ");
            preOrdem(*raiz);
            printf("\n");
            getch();
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("Opção inválida!\n");
            getch(); 
            break;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct No *raiz = NULL;

    while (1) {
        menu(&raiz);
    }
    
    return 0;
}
