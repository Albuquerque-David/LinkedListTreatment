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
	printf("Digite valores para a lista encadeada. Digite um valor menor que 0 para parar.\n\n");
	criar_lista(0);
	opcoes();
	while(controle!=0){
		if(controle==1){
			mostrar_lista(inicio);
		}
		if(controle==2){
			menor(inicio,0);
		}
		if(controle==3){
			maior(inicio,0);
		}
		if(controle==4){
			elementos(inicio,0);
		}
		if(controle==5){
			inserir_final(inicio,0,0);
		}
		if(controle==6){
			media(inicio,0,0);
		}
		if(controle==7){
			remover_elemento(inicio,inicio,0,0);
		}
		if(controle==8){
			inserir_elemento_ordenada(inicio,inicio,0,0);
		}
		if(controle==9){
			gerar_lista_crescente(0);
		}
		if(controle==10){
			apagar_lista(inicio);
		}
		if(controle==11){
			lista_ordem_correta(inicio,0,0);
		}
		if(controle==12){
			ordenar_duas_listas();
		}
		opcoes();
	}
}

void criar_lista(int cont){
	struct lista *aux;
	int valor;
	scanf("%d",&valor);
		if(valor>=0){
			aux = (struct lista*)malloc(sizeof(struct lista));
			aux->valor=valor;
			aux->prox=inicio;
			inicio=aux;
			criar_lista(cont);
		}		
	aux = (struct lista*)NULL;
}

void mostrar_lista(struct lista *aux){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n\n");
	}
	else{
		if(aux!=(struct lista*)NULL){
		printf("%d\t",aux->valor);
		mostrar_lista(aux->prox);
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

void menor(struct lista *aux,int m){
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n\n");
	}
	else{
		if(aux==inicio){
			m=aux->valor;
		}
			if(aux->valor<m){
				m=aux->valor;
			}
			aux=aux->prox;
			if(aux!=(struct lista*)NULL){
				menor(aux,m);
			}
			else{
		printf("\nO menor numero da lista e %d.",m);
		getch();
		system("cls");
	}	
}
}


void maior(struct lista *aux,int m){
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n\n");
	}
	else{
		if(aux==inicio){
			m=aux->valor;
		}
			if(aux->valor>m){
				m=aux->valor;
			}
			aux=aux->prox;
			if(aux!=(struct lista*)NULL){
				maior(aux,m);
			}
			else{
		printf("\nO maior numero da lista e %d.",m);
	}

	getch();
	system("cls");
}
}

void elementos(struct lista *aux, int cont){
	if(aux==(struct lista *)NULL){
		printf("LISTA VAZIA.\n");
	}
	else{
			cont+=1;
			aux=aux->prox;
		if(aux!=(struct lista*)NULL){
			elementos(aux,cont);
		}
		else{
		printf("\nA lista possui %d elementos",cont);
	}
	getch();
	system("cls");
}
}

void inserir_final(struct lista *aux, int valor, int cont){
	if(cont==0){
	printf("Entre com um valor pra ser inserido no final da lista encadeada.\n");
	scanf("%d",&valor);
	cont++;
}
	if(inicio==(struct lista*)NULL){
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
	}
	else{
	if(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
		inserir_final(aux,valor,cont);
	}
	else{
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
}

void media(struct lista *aux, int med, int cont){
	if(aux!=(struct lista*)NULL){
		med=med+aux->valor;
		cont++;
		aux=aux->prox;
		media(aux,med,cont);
	}
	else{
	med=med/cont;
	printf("\nA media dos elementos e: %d",med);
	getch();
	system("cls");
	}
}

void remover_elemento(struct lista *aux, struct lista *aux2, int valor, int cont){
	if(inicio==(struct lista*)NULL){ //lista vazia
		printf("NAO HA ELEMENTOS PARA SEREM REMOVIDOS. LISTA VAZIA.\n");
		aux=(struct lista*)NULL;
		getch();
		system("cls");
	}
	else{
		if(cont==0){
		printf("Entre com o numero a ser removido.\n");
		scanf("%d",&valor);
		cont++;
		}
		if(inicio->prox==(struct lista*)NULL){ //lista de 1 elemento
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
		if(inicio->valor==valor){ //elemento no inicio
			aux=aux->prox;
			free(inicio);
			inicio=aux;
			aux=(struct lista*)NULL;
			printf("\nLISTA DE MAIS DE 1 ELEMENTO. ELEMENTO NO INICIO DA LISTA. REMOVIDO COM SUCESSO.\n");
			getch();
			system("cls");
		}
		else{
			if(aux->valor!=valor&&aux->prox!=(struct lista*)NULL){
			aux2=aux;
			aux=aux->prox;
			remover_elemento(aux,aux2,valor,cont);
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

void inserir_elemento_ordenada(struct lista *aux, struct lista *ant, int valor, int cont){
	if(cont==0){
	printf("Entre com o valor a ser inserido");
	scanf("%d",&valor);
	cont++;
	}
	if(inicio==(struct lista*)NULL){ //lista vazia
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		printf("LISTA VAZIA. Valor inserido.\n");
		getch();
		system("cls");
	}
	else{ // inicio
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
				if((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
					ant=aux;
					aux=aux->prox;
					inserir_elemento_ordenada(aux,ant,valor,cont);
				}
				else{
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
}

void gerar_lista_crescente(int valor){
	void inserir_elemento_ordenada2(struct lista *aux, struct lista *ant, int valor, int cont){
	if(cont==0){
		cont++;
	}
	if(inicio==(struct lista*)NULL){ //lista vazia
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		printf("LISTA VAZIA. Valor inserido.\n");
		getch();
		system("cls");
	}
	else{ // inicio
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
				if((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
					ant=aux;
					aux=aux->prox;
					inserir_elemento_ordenada(aux,ant,valor,cont);
				}
				else{
				if(valor>aux->valor){ //final da lista
					aux->prox=(struct lista*)malloc(sizeof(struct lista));
					aux=aux->prox;
					aux->valor=valor;
					aux->prox=(struct lista*)NULL;
					aux=(struct lista*)NULL;
					printf("Alocado no final da lista.\n");
					cont++;
					
				}
				else{  //no meio da lista
					ant->prox=(struct lista*)malloc(sizeof(struct lista));
					ant=ant->prox;
					ant->valor=valor;
					ant->prox=aux;
					aux=(struct lista*)NULL;
					ant=aux;
					printf("Alocado no meio da lista.\n");
					cont++;
				}
			}
			}
		}
}
		printf("Digite valores para a lista encadeada. Digite um valor menor que 0 para parar.\n");
		scanf("%d",&valor);
		if(valor>=0){
			inserir_elemento_ordenada2(inicio,inicio,valor,0);
			gerar_lista_crescente(valor);
		}
}

void lista_ordem_correta(struct lista *aux, int valor,int cont){
	if(cont==0){
	apagar_lista();
	inicio=(struct lista*)NULL;
	cont++;
	printf("Digite valores para a lista encadeada. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	if(valor>=0){
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
	printf("Digite valores para a lista encadeada. Digite um valor menor que 0 para parar.\n");
	aux=inicio;
	lista_ordem_correta(aux,valor,cont);
}
}
	else{
	scanf("%d",&valor);
	if(valor>=0){
		aux->prox=(struct lista*)malloc(sizeof(struct lista));
		aux=aux->prox;
		aux->valor=valor;
		aux->prox=(struct lista*)NULL;
		printf("Digite valores para a lista encadeada. Digite um valor menor que 0 para parar.\n");
		lista_ordem_correta(aux,valor,cont);
	}
	else{
	aux=(struct lista*)NULL;
	printf("\nLISTA CRIADA COM SUCESSO.");
	getch();
	system("cls");
	}
}
}

void apagar_lista(struct lista *aux){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio!=(struct lista*)NULL){
		inicio=aux->prox;
		aux->prox=(struct lista*)NULL;
		free(aux);
		aux=inicio;
		apagar_lista(aux);
		}
	}
	printf("\nLISTA APAGADA COM SUCESSO.");
	getch();
	system("cls");
}

void ordenar_duas_listas(){
	struct lista *aux2;
	int aux3,valor;
	apagar_lista(inicio);
	struct lista *inicio2;
	struct lista *aux;
	inicio2=(struct lista*)NULL;
	criar_lista(0);
	printf("Digite valores para a segunda lista encadeada. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	while(valor>=0){ //cria lista 2
		aux = (struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio2;
		inicio2=aux;
		scanf("%d",&valor);
	}
	aux = (struct lista*)NULL;
	aux=inicio;
	while(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
	}
	aux->prox=inicio2;
	aux=inicio;
	while(aux!=(struct lista*)NULL){
		aux2=aux;
		aux2=aux2->prox;
		while(aux2!=(struct lista*)NULL){
			if(aux->valor>aux2->valor){
				aux3=aux->valor;
				aux->valor=aux2->valor;
				aux2->valor=aux3;
			}
			aux2=aux2->prox;
		}
		aux=aux->prox;
	}
	aux=(struct lista*)NULL;
	aux2=(struct lista*)NULL;
}
