#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//=========================================================================
//						STRUCTS
//=========================================================================
struct no {
	int dado;
	struct no* prox;
};
typedef struct no* def_fila;

//=========================================================================
//						FUN��ES
//=========================================================================
void enfileira(def_fila *inicio, def_fila* final, int numero){
	def_fila q = (def_fila) malloc(sizeof(struct no));
	q->dado = numero;
	q->prox = NULL;
	
	if(*final != NULL) (*final)->prox = q; //*final != NULL significa que h� elementos na fila, 
	else *inicio = q; //<-aponta o primeiro	// ent�o � preciso incluir o novo n� depois do �ltimo elemento
	*final = q;								// e passar o ponteiro de final para o �ltimo elemento.
}

int desenfileira(def_fila* inicio, def_fila* final, int* numero){
	def_fila q;
	
	if(*inicio == NULL) return 0; //Se n�o h� elementos na lista, � tem o que tirar
	q = *inicio; //Recupera o primeiro elemento
	
	*inicio = (*inicio)->prox; //Aponta para o pr�ximo (segundo elemento)
	if (*inicio == NULL) *final = NULL; //Se in�cio == NULL, o elemento 'retirado' era o �ltimo, 
										// ent�o o ponteiro *final tamb�m deve apontar para NULL;
	*numero = q->dado;
	free(q);
	return 1;
}


int mostra(def_fila inicio){
	def_fila q = inicio;
	
	if(q == NULL) return 0;
	while(q){
		printf("\n\tProcesso %d.", q->dado);
		q = q->prox;
	}
	return 1;
}

int menu(){
	int op;
	
	printf("\n\n-------------------------------------------");
	do {
		printf("\n1- Incluir novo processo\n2- Retirar processo mais longo\n3- Imprimir a lista de processos\nOpcao: ");
		scanf(" %d", &op);
	} while (op < 1 && op > 3);
	return op;
}
//=========================================================================
//             						MAIN
//=========================================================================
int main(){
	def_fila inicio = NULL, final = NULL;
	int numero, op;
	
	while(1){
		op = menu();
		switch(op) {
			case 1:
				printf("\nDigite o numero de identificacao do processo: ");
				scanf(" %d", &numero);
				enfileira(&inicio, &final, numero);
				//printf("aaa");
				break;
			case 2:
				if(!desenfileira(&inicio, &final, &numero)) printf("Nao ha processos para serem retirados");
				else {
					printf("\nProcesso retirado: %d", numero);
					printf("\nProcessos restantes: ");
					if(!mostra(inicio)) printf("Nao ha processos.");
				}
				
				//mostra(inicio);
				break;
			case 3:
				if(!mostra(inicio)) printf("\nNao ha processos.");
				break;
		}
	}
}

