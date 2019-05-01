#include <stdio.h>
#include <stdlib.h>
void cria_lista_inv();
void mostra_lista();
void soma_elementos();
void conta();
void media();

struct ptr{
	int valor;
	struct ptr *prox;
};
struct ptr *inicio;

main(){
	//funções aqui
}

void cria_lista_inv(){
	struct ptr *aux;
	int valor;
	inicio = (struct ptr *)NULL;
	printf("Entre com um elemento.\n\n");
	scanf("%d",&valor);
	while(valor>=0){
		aux = (struct ptr *)malloc(sizeof(struct ptr));
		aux->valor=valor;
		aux->prox=inicio;
		inicio = aux;
		printf("Entre com o valor:\n\n");
		scanf("%d",&valor);
	}
	aux = (struct ptr*)NULL;
}

void mostra_lista(){
	struct ptr *aux;
	aux=inicio;
	if(inicio==(struct ptr *)NULL)
		printf("\nLISTA VAZIA");
	else{
		while(aux!=(struct ptr *)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
	}
}

void soma_elementos(){
	struct ptr*aux;
	int cont;
	cont=0;
	aux=inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLISTA VAZIA");
	else{
		while(aux!=(struct ptr*)NULL){
			cont += aux->valor;
			aux = aux->prox;
		}
	}
	printf("\n\nA soma dos elementos e %d",cont);
}

void conta(){
	struct ptr*aux;
	int cont;
	cont=0;
	aux=inicio;
		while(aux!=(struct ptr *)NULL){
			cont++;
			aux = aux->prox;
		}
	printf("\n\nA lista possui %d elementos",cont);
}

void media(){
	struct ptr*aux;
	float m;
	int cont;
	cont=0;
	m=0;
	aux = inicio;
	while(aux!=(struct ptr *)NULL){
		cont++;
		m += aux->valor;
		aux= aux->prox;
	}
	if(cont!=0)
		printf("\n\nA media dos elementos da lista e %f",m/cont);
	else
		printf("\n\nMedia = 0");
}

void maiormenor(){
	struct ptr*aux;
	int maior,menor;
	aux = inicio;
	if(inicio==(struct ptr*)NULL)
		printf("\nLISTA VAZIA");
	else{
		maior = aux->valor;
		menor = aux->valor;
		while(aux!=(struct ptr*)NULL){
			if(aux->valor>maior)
				maior=aux->valor;
			if(aux->valor<menor)
				menor=aux->menor;
			aux = aux->prox;		
		}
			
	}
	printf("\nO maior elementos e %d\n",maior);
	printf("\n O menor elementos e %d\n",menor);
}

void inserir_final(){
	struct ptr*aux;
	int n;
	printf("\nentre com o novo valor");
	scanf("%d",&n);
	aux = inicio;
	if(inicio==(struct ptr*)NULL){
		inicio=(struct ptr*)malloc(sizeof(struct ptr));
		inicio -> valor = n;
		inicio->prox=(struct ptr*)NULL;
	}
	else{
	while(aux->prox!=(struct ptr*)NULL){
		aux = aux->prox;
	}
	aux->prox = (struct ptr *)malloc(sizeof(struct ptr));
	aux=aux->prox;
	aux->valor=n;
	aux->prox=(struct ptr*)NULL;
	aux=(struct ptr*)NULL;
 }
}

void inserir_ordenado(int valor){
	//Situações possiveis: - Lista vazia
	//- Lista não vazia: Inserir no inicio, no meio ou no fim.
	struct ptr*aux,*ant;
	if(inicio==(struct ptr*)NULL){ //lista vazia
		inicio = (struct ptr*)malloc(sizeof(struct ptr));
		inicio->valor=valor;
		inicio->prox=(struct ptr*)NULL;
	}
	else{
		aux = inicio;
		if(inicio->valor>valor){ 
			inicio=(struct ptr*)malloc(sizeof(struct ptr));
			inicio -> valor = valor;
			inicio->prox=aux;
			aux=(struct ptr*)NULL;
		}
		else{
			while((valor>aux->valor)&&(aux->prox!=(struct ptr*)NULL)){
				ant = aux;
				aux = aux->prox;
			}
		}
		if(valor>aux->valor){ //final
			aux->prox = (struct ptr*)malloc(sizeof(struct ptr));
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=(struct ptr*)NULL;
			aux=(struct ptr*)NULL;
			ant = aux;
		}
		else{
			ant->prox=(struct ptr*)malloc(sizeof(struct ptr));
			ant = ant->prox;
			ant->valor=valor;
			ant->prox=aux;
			ant=(struct ptr*)NULL;
			aux=ant; //igual a linha acima
		}
	}
}

void criar_lista_ordenada(){
	void inserir_ordenado(int valor);
	int valor;
	printf("\nEntre com o valor:");
	scanf("%d",&valor);
	inicio=(struct ptr*)NULL;
	while(valor>=0){
		inserir_ordenado(int valor);
		printf("Entre com o valor:\n");
		scanf("%d",&valor);
	}
}

void remover(){
	struct ptr*aux,*ant;
	int valor;
	printf("Entre com o valor a ser removido:");
	scanf("%d",&valor);
	if(inicio==(struct ptr*)NULL)
		printf("\ n\nLISTA VAZIA");
	else{
		if(inicio->prox==(struct ptr*)NULL){
			if(inicio->valor!=valor)
				printf("\nO valor nao existe!");
			else{
				free(inicio);
				inicio=(struct ptr*)NULL;
			}
		}
		else{
			if(inicio->valor=valor){
				aux=inicio;
				inicio=inicio->prox;
				aux->prox=(struct ptr*)NULL;
				free(aux);
				aux=(struct ptr*)NULL;
			}
			else{
				aux=inicio;
				while((valor!=aux->valor)&&(aux->prox!=(struct ptr*)NULL)){
					ant=aux;
					aux=aux->prox;
				}
				if(aux->valor!=valor)
					printf("\nVALOR NAO EXISTE");
				else{
					if(aux->prox==(struct ptr*)NULL){
						ant->prox=(struct ptr*)NULL;
						free(aux);
						aux=(struct ptr*)NULL;
						ant = aux;
					}
					else{
						ant->prox=aux->prox;
						aux->prox=(struct ptr*)NULL;
						free(aux);
						aux=(struct ptr*)NULL;
						aut=aux;
					}
				}
			}
		}
	}
}
