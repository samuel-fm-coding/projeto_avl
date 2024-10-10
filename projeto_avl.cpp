/*		PROJETO AVL		*/
/* Échelly Paiva */
/* Samuel Fernandes */

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>


struct no{
	int valor;
	int altura;
	struct no *esq;
	struct no *dir;
};








void menu(){
	system("cls");
	
	int option = 0;
	
	printf("----- Árvore AVL -----\n\n");
	printf("1 - Inserir nó \n\n");
	printf("2 - Remover Nó \n\n");
	printf("3 - Ver Árvore \n\n");
	printf("4 - Sair \n\n");
	scanf("%d", &option);
	switch(option){
		case 1:
			inserirNo();
			break;
		case 2:
			removerNo();
			break;
		case 3:
			verArvore();
			break;
		case 4: 
			exit(0);
			break;
	}
	
}

void inserirNo(){
	
}

void main(){
	
}
