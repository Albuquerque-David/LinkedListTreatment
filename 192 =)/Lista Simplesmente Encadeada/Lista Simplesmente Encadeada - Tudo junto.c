#include <stdio.h>
#include <stdlib.h>

void criar_lista();
void mostrar_lista();
void menor();
void maior();
void elementos();
void opcoes();
void inserir_final();
void media();
void remover_elemento();
void inserir_elemento_ordenada();
void gerar_lista_crescente();
void apagar_lista();
void lista_ordem_correta();
void ordenar_duas_listas();



int controle = 1;

struct lista{
	int valor;
	struct lista *prox;
};

struct lista *inicio;

main(){
	printf("[LISTA SIMPLESMENTE ENCADEADA]\n\n CRIANDO A LISTA.\n\n");
	criar_lista();
	opcoes();
	while(controle!=0){
		if(controle==1){
			mostrar_lista();
		}
		if(controle==2){
			menor();
		}
		if(controle==3){
			maior();
		}
		if(controle==4){
			elementos();
		}
		if(controle==5){
			inserir_final();
		}
		if(controle==6){
			media();
		}
		if(controle==7){
			remover_elemento();
		}
		if(controle==8){
			inserir_elemento_ordenada();
		}
		if(controle==9){
			gerar_lista_crescente();
		}
		if(controle==10){
			apagar_lista();
		}
		if(controle==11){
			lista_ordem_correta();
		}
		if(controle==12){
			ordenar_duas_listas();
		}
		opcoes();
	}
}

void criar_lista(){
	struct lista *aux;
	int valor;
	inicio = (struct lista*)NULL;
	printf("Digite valores para a lista encadeada. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	while(valor>=0){
		aux = (struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		scanf("%d",&valor);
	}
	aux = (struct lista*)NULL;
}

void mostrar_lista(){
	struct lista *aux;
	aux=inicio;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n\n");
	}
	else{
	while(aux!=(struct lista*)NULL){
		printf("%d\t",aux->valor);
		aux=aux->prox;
	}
}
	aux = (struct lista*)NULL;
	getch();
	system("cls");
}

void opcoes(){
	printf("\n\nO que deve ser feito?\n\n1 - Mostrar lista.\n2 - Menor elemento da lista.\n3 - Maior elemento da lista.\n4 - Numero de elementos da lista.\n5 - Inserir elemento no final da lista.\n6 - Media dos elementos da lista.\n7 - Remover elemento da lista.\n8 - Inserir elemento na lista ordenada.\n9 - Gerar lista em ordem crescente.\n10 - Apagar lista toda.\n11 - Gerar lista na ordem correta dos elementos.\n12 - Criar duas listas em e por em ordem crescente");
	scanf("%d",&controle);
	system("cls");
}

void menor(){
	struct lista *aux;
	int *menor;
	menor = (int *)malloc(sizeof(int));
	aux=inicio;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n\n");
	}
	else{
	*menor = aux->valor;
	while(aux!=(struct lista*)NULL){
		if(aux->valor<*menor){
			*menor=aux->valor;
		}
		aux=aux->prox;
	}	
	printf("\nO menor numero da lista e %d.",*menor);
}
	free(menor);
	menor = (int *)NULL;
	getch();
	system("cls");
}


void maior(){
	struct lista *aux;
	int *maior;
	maior = (int *)malloc(sizeof(int));
	aux=inicio;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n\n");
	}
	else{
	*maior = aux->valor;
	while(aux!=(struct lista*)NULL){
		if(aux->valor>*maior){
			*maior=aux->valor;
		}
		aux=aux->prox;
	}	
	printf("\nO maior numero da lista e %d.",*maior);
}
	free(maior);
	maior = (int *)NULL;
	getch();
	system("cls");
}

void elementos(){
	struct lista *aux;
	int *cont;
	cont = (int *)malloc(sizeof(int));
	*cont=0;
	aux=inicio;
	if(aux==(struct lista *)NULL){
		printf("LISTA VAZIA.\n");
	}
	else{
		while(aux!=(struct lista *)NULL){
			*cont+=1;
			aux=aux->prox;
		}
		printf("\nA lista possui %d elementos",*cont);
	}
	free(cont);
	cont=(int *)NULL;
	getch();
	system("cls");
}

void inserir_final(){
	struct lista *aux;
	aux=inicio;
	int valor;
	printf("Entre com um valor pra ser inserido no final da lista encadeada.\n");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
	}
	else{
	while(aux->prox!=(struct lista *)NULL){
		aux=aux->prox;
	}
	aux->prox=(struct lista *)malloc(sizeof(struct lista));
	aux=aux->prox;
	aux->valor=valor;
	aux->prox=(struct lista *)NULL;
	aux=(struct lista *)NULL;
	printf("\nELEMENTO INSERIDO NO FINAL DA LISTA.");
	getch();
	system("cls");
}
}

void media(){
	struct lista *aux;
	int media=0,cont=0;
	aux=inicio;
	while(aux!=(struct lista*)NULL){
		media=media+aux->valor;
		cont++;
		aux=aux->prox;
	}
	media=media/cont;
	printf("\nA media dos elementos e: %d",media);
	getch();
	system("cls");
}

void remover_elemento(){
	struct lista *aux;
	struct lista *aux2;
	int valor;
	aux=inicio;
	if(aux==(struct lista*)NULL){ //lista vazia
		printf("NAO HA ELEMENTOS PARA SEREM REMOVIDOS. LISTA VAZIA.\n");
		aux=(struct lista*)NULL;
		getch();
		system("cls");
	}
	else{
		printf("Entre com o numero a ser removido.\n");
		scanf("%d",&valor);
		if(aux->prox==(struct lista*)NULL){ //lista de 1 elemento
			if(valor!=aux->valor){ //elemento nao existe
			 	printf("\nO ELEMENTO NAO EXISTE NESTA LISTA DE 1 ELEMENTO.\n");
			 	aux=(struct lista*)NULL;
				getch();
			 	system("cls");
		}
		else{  //elemento existe
			inicio->prox=(struct lista*)NULL;
			free(aux);
			inicio=(struct lista*)NULL;
			printf("LISTA DE 1 ELEMENTO. REMOVIDO COM SUCESSO.\n");
			aux=(struct lista*)NULL;
			getch();
			system("cls");
		}
	}
	else{  //lista de +1 elemento
		if(aux->valor==valor){ //elemento no inicio
			aux=aux->prox;
			free(inicio);
			inicio=aux;
			aux=(struct lista*)NULL;
			printf("\nLISTA DE MAIS DE 1 ELEMENTO. ELEMENTO NO INICIO DA LISTA. REMOVIDO COM SUCESSO.\n");
			getch();
			system("cls");
		}
		else{
			while(aux->valor!=valor&&aux->prox!=(struct lista*)NULL){
			aux2=aux;
			aux=aux->prox;
		}
		if(aux->valor!=valor){ //não existe
			printf("LISTA DE MAIS DE 1 ELEMENTO. ELEMENTO NAO EXISTE NA LISTA!\n");
			getch();
			system("cls");
		}
		else{
			if(aux->prox==(struct lista*)NULL){ //final da lista
			aux2->prox=(struct lista*)NULL;
			aux->prox=(struct lista*)NULL;
			free(aux);
			aux=(struct lista*)NULL;
			aux2=(struct lista*)NULL;
			printf("\nLISTA DE MAIS DE UM ELEMENTO. ELEMENTO NO FINAL DA LISTA. REMOVIDO COM SUCESSO.\n");
			getch();
			system("cls");
		}
		else{ //meio da lista
			aux=aux->prox;
			free(aux2->prox);
			aux2->prox=aux;
			aux=(struct lista*)NULL;
			aux2=(struct lista*)NULL;
			printf("\nLISTA DE MAIS DE UM ELEMENTO. ELEMENTO NO MEIO DA LISTA. REMOVIDO COM SUCESSO.\n");
			getch();
			system("cls");
		}
		}
	}
}
}
}

void inserir_elemento_ordenada(){
	struct lista *aux,*ant;
	int valor;
	printf("Entre com o valor a ser inserido");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){ //lista vazia
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		printf("LISTA VAZIA. Valor inserido.\n");
		getch();
		system("cls");
	}
	else{ // inicio
		aux=inicio;
		if(valor<inicio->valor){ //inicio->valor menor que o valor digitado
			inicio=(struct lista*)malloc(sizeof(struct lista));
			inicio->valor=valor;
			inicio->prox=aux;
			aux=(struct lista*)NULL;
			printf("Alocado antes do primeiro elemento\n");
			getch();
			system("cls");
		}
		else{
			 //no meio ou no fim
				while((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
					ant=aux;
					aux=aux->prox;
				}
				if(valor>aux->valor){ //final da lista
					aux->prox=(struct lista*)malloc(sizeof(struct lista));
					aux=aux->prox;
					aux->valor=valor;
					aux->prox=(struct lista*)NULL;
					aux=(struct lista*)NULL;
					printf("Alocado no final da lista.\n");
				}
				else{  //no meio da lista
					ant->prox=(struct lista*)malloc(sizeof(struct lista));
					ant=ant->prox;
					ant->valor=valor;
					ant->prox=aux;
					aux=(struct lista*)NULL;
					ant=aux;
					printf("Alocado no meio da lista.\n");
				}
			}
		}
}

void gerar_lista_crescente(){
	int valor;
	apagar_lista();
	void inserir_elemento_ordenada2(int valor){
		struct lista *aux,*ant;
		if(inicio==(struct lista*)NULL){ //lista vazia
			inicio=(struct lista*)malloc(sizeof(struct lista));
			inicio->valor=valor;
			inicio->prox=(struct lista*)NULL;
			printf("LISTA VAZIA. Valor inserido.\n");
			getch();
			system("cls");
		}
		else{ // inicio
			aux=inicio;
			if(valor<inicio->valor){ //inicio->valor menor que o valor digitado
				inicio=(struct lista*)malloc(sizeof(struct lista));
				inicio->valor=valor;
				inicio->prox=aux;
				aux=(struct lista*)NULL;
				printf("Alocado antes do primeiro elemento\n");
				getch();
				system("cls");
			}
			else{
				 //no meio ou no fim
					while((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
						ant=aux;
						aux=aux->prox;
					}
					if(valor>aux->valor){ //final da lista
						aux->prox=(struct lista*)malloc(sizeof(struct lista));
						aux=aux->prox;
						aux->valor=valor;
						aux->prox=(struct lista*)NULL;
						aux=(struct lista*)NULL;
						printf("Alocado no final da lista.\n");
					}
					else{  //no meio da lista
						ant->prox=(struct lista*)malloc(sizeof(struct lista));
						ant=ant->prox;
						ant->valor=valor;
						ant->prox=aux;
						aux=(struct lista*)NULL;
						ant=aux;
						printf("Alocado no meio da lista.\n");
					}
				}
			}
		}
		printf("Digite valores para a lista encadeada. Digite um valor menor que 0 para parar.\n");
		scanf("%d",&valor);
		inicio=(struct lista*)NULL;
		while(valor>=0){
			inserir_elemento_ordenada2(valor);
			scanf("%d",&valor);
		}
}

void lista_ordem_correta(){
	apagar_lista();
	struct lista *aux;
	int valor;
	inicio=(struct lista*)NULL;
	printf("Digite valores para a lista encadeada. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	if(valor>=0){
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		scanf("%d",&valor);
		aux=inicio;
	while(valor>=0){
		aux->prox=(struct lista*)malloc(sizeof(struct lista));
		aux=aux->prox;
		aux->valor=valor;
		aux->prox=(struct lista*)NULL;
		scanf("%d",&valor);
	}
		printf("\nLISTA CRIADA COM SUCESSO.");
}
	else{
		printf("LISTA VAZIA CRIADA.");
	}
	aux=(struct lista*)NULL;
	getch();
	system("cls");

}

void apagar_lista(){
	struct lista *aux;
	aux=inicio;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		while(inicio!=(struct lista*)NULL){
		inicio=aux->prox;
		aux->prox=(struct lista*)NULL;
		free(aux);
		aux=inicio;
		}
	}
	printf("\nLISTA APAGADA COM SUCESSO.");
	getch();
	system("cls");
}


