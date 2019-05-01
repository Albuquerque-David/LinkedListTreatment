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

struct lista{
	int valor;
	struct lista *ant,*prox;
};

struct lista *inicio;
int controle = 1;

main(){
	printf("[LISTA DUPLAMENTE ENCADEADA]\n\n CRIANDO A LISTA.\n\n");
	criar_lista(0,inicio);
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
			remover_elemento(inicio,0,0);
		}
		if(controle==8){
			inserir_elemento_ordenada(inicio,0,0);
		}
		if(controle==9){
			gerar_lista_crescente(0,0);
		}
		if(controle==10){
			apagar_lista(inicio,0);
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


void opcoes(){
	printf("\n\nO que deve ser feito?\n\n1 - Mostrar lista.\n2 - Menor elemento da lista.\n3 - Maior elemento da lista.\n4 - Numero de elementos da lista.\n5 - Inserir elemento no final da lista.\n6 - Media dos elementos da lista.\n7 - Remover elemento da lista.\n8 - Inserir elemento na lista ordenada.\n9 - Gerar lista em ordem crescente.\n10 - Apagar lista toda.\n11 - Gerar lista na ordem correta dos elementos.\n12 - Criar duas listas em e por em ordem crescente");
	scanf("%d",&controle);
	system("cls");
}

void criar_lista(int cont, struct lista *aux){
	int valor;
	scanf("%d",&valor);
	if(cont==0){
	if(valor<0){
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		aux->ant=(struct lista*)NULL;
		cont++;
		criar_lista(cont,aux);
	}
}
	else{
		if(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		aux->prox->ant=aux;
		criar_lista(cont,aux);
	}
}
	if(valor<0&&cont==1){
	aux->ant=(struct lista*)NULL;
	aux=(struct lista*)NULL;
	printf("\n\nLISTA CRIADA COM SUCESSO.");
	cont++;
	getch();
	system("cls");
	}
}

void mostrar_lista(struct lista *aux){ 
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(aux!=(struct lista*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
			mostrar_lista(aux);
		}
	}
	aux=(struct lista*)NULL;
	getch();
	system("cls");
}

/*void mostrar_lista(){
	struct lista *aux;
	aux=inicio;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		while(aux->prox!=(struct lista*)NULL){
			aux=aux->prox;
		}
		while(aux!=(struct lista*)NULL){
			printf("[%d]\t",aux->valor);
			aux=aux->ant;
		}
	}
	aux=(struct lista*)NULL;
	getch();
	system("cls");
}*/

void menor(struct lista *aux, int m){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(aux==inicio){
		m=aux->valor;
		}
		
		if(aux->valor<m)
			m=aux->valor;
		aux=aux->prox;
		if(aux!=(struct lista*)NULL){
				menor(aux,m);
			}
		else{
			printf("\nO MENOR VALOR E %d\n",m);
			getch();
			system("cls");
		}
}
}

void maior(struct lista *aux, int m){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(aux==inicio){
		m=aux->valor;
		}
		
		if(aux->valor>m)
			m=aux->valor;
		aux=aux->prox;
		if(aux!=(struct lista*)NULL){
				maior(aux,m);
			}
		else{
			printf("\nO MAIOR VALOR E %d\n",m);
			getch();
			system("cls");
		}
	}
}

void elementos(struct lista *aux, int cont){
	if(inicio==(struct lista*)NULL){
		printf("\nLISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		if(aux!=(struct lista*)NULL){
			cont++;
			aux=aux->prox;
			elementos(aux,cont);
		}
		else{
			printf("\nA LISTA POSSUI %d ELEMENTOS.",cont);
			getch();
			system("cls");
		}
	}
	aux=(struct lista*)NULL;
}

void media(struct lista *aux, int m, int cont){
	if(inicio==(struct lista*)NULL){
		printf("\nLISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		if(aux!=(struct lista*)NULL){
			m+=aux->valor;
			cont++;
			aux=aux->prox;
			media(aux,m,cont);
		}
		else{
			m=m/cont;
			printf("\nA MEDIA DOS ELEMENTOS E %d",m);
			getch();
			system("cls");
		}
	}
}

void inserir_final(struct lista *aux, int valor, int cont){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	if(cont==0){
		printf("ENTRE COM O NOVO VALOR A SER INSERIDO.\n");
		scanf("%d",&valor);
		cont++;
		inserir_final(aux,valor,cont);
	}
	else{
		if(aux->prox!=(struct lista*)NULL){
			aux=aux->prox;
			inserir_final(aux,valor,cont);
		}
		else{
		aux->prox=(struct lista*)malloc(sizeof(struct lista));
		aux->prox->ant=aux;
		aux=aux->prox;
		aux->valor=valor;
		aux->prox=(struct lista*)NULL;
		printf("\nINSERIDO COM SUCESSO.");
		getch();
		system("cls");
		}
	}
}

void inserir_elemento_ordenada(struct lista *aux, int valor, int cont){
	if(cont==0){
	printf("ENTRE COM O VALOR A SER INSERIDO NA LISTA ORDENADA.\n");
	scanf("%d",&valor);
	cont++;
	inserir_elemento_ordenada(aux,valor,cont);
	}
	else{
	if(inicio==(struct lista*)NULL){ //LISTA VAZIA
		inicio=(struct lista*)malloc(sizeof(struct lista*));
		inicio->ant=(struct lista*)NULL;
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		aux=(struct lista*)NULL;
		printf("\nELEMENTO INSERIDO NA LISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		if(inicio->valor>valor){ //inicio da lista
			aux=inicio;
			inicio=(struct lista*)malloc(sizeof(struct lista));
			inicio->valor=valor;
			inicio->ant=(struct lista*)NULL;
			inicio->prox=aux;
			aux->ant=inicio;
			aux=(struct lista*)NULL;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA");
			getch();
			system("cls");
			cont++;
		}
		else{ //no meio ou fim
			if((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
				aux=aux->prox;
				inserir_elemento_ordenada(aux,valor,cont);
			}
			else{
			if(valor>aux->valor){ //no fim
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct lista*)NULL;
				aux=(struct lista*)NULL;
				printf("INSERIDO NO FINAL DA LISTA.\n");
				getch();
				system("cls");
			}
			else{
				if(valor<aux->valor){ //no meio
				aux->ant->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->ant->prox->prox=aux;
				aux->ant->prox->ant=aux->ant;
				aux->ant->prox->valor=valor;
				aux=(struct lista*)NULL;
				printf("INSERIDO NO MEIO DA LISTA");
				getch();
				system("cls");
			}
			}
		}
	}
	}
}
}

void gerar_lista_crescente(int valor, int cont){
	void inserir_elemento_ordenada2(struct lista *aux, int valor, int cont){
	if(cont==0){
	cont++;
	inserir_elemento_ordenada(aux,valor,cont);
	}
	else{
	if(inicio==(struct lista*)NULL){ //LISTA VAZIA
		inicio=(struct lista*)malloc(sizeof(struct lista*));
		inicio->ant=(struct lista*)NULL;
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		aux=(struct lista*)NULL;
		printf("\nELEMENTO INSERIDO NA LISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		if(inicio->valor>valor){ //inicio da lista
			aux=inicio;
			inicio=(struct lista*)malloc(sizeof(struct lista));
			inicio->valor=valor;
			inicio->ant=(struct lista*)NULL;
			inicio->prox=aux;
			aux->ant=inicio;
			aux=(struct lista*)NULL;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA");
			getch();
			system("cls");
			cont++;
		}
		else{ //no meio ou fim
			if((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
				aux=aux->prox;
				inserir_elemento_ordenada(aux,valor,cont);
			}
			else{
			if(valor>aux->valor){ //no fim
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct lista*)NULL;
				aux=(struct lista*)NULL;
				printf("INSERIDO NO FINAL DA LISTA.\n");
				getch();
				system("cls");
			}
			else{
				if(valor<aux->valor){ //no meio
				aux->ant->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->ant->prox->prox=aux;
				aux->ant->prox->ant=aux->ant;
				aux->ant->prox->valor=valor;
				aux=(struct lista*)NULL;
				printf("INSERIDO NO MEIO DA LISTA");
				getch();
				system("cls");
			}
			}
		}
	}
	}
}
}
	if(cont==0){
	printf("Entre com os valores da lista. Digite um negativo para parar.\n");
}
	scanf("%d",&valor);
	if(valor<0&&cont==0){
		printf("\nCRIADA LISTA VAZIA.");
		cont++;
		getch();
		system("cls");
	}
	else{
	if(valor>=0){
		cont++;
		inserir_elemento_ordenada2(inicio,valor,0);
		gerar_lista_crescente(valor, cont);
		}
	else{
		printf("\n\nLISTA ORDENADA CRIADA COM SUCESSO");
		getch();
		system("cls");
	}
	}

}

void apagar_lista(struct lista *aux, int cont){
	if(inicio==(struct lista*)NULL&&cont==0){
		printf("LISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		if(aux!=(struct lista*)NULL){
			inicio=aux->prox;
			aux->prox=(struct lista*)NULL;
			aux->ant=(struct lista*)NULL;
			free(aux);
			aux=inicio;
			cont++;
			apagar_lista(aux,cont);
		}
		printf("\nLISTA ESVAZIADA COM SUCESSO.");
		getch();
		system("cls");
	}
}

void lista_ordem_correta(struct lista *aux, int valor, int cont){
	if(cont==0){
	printf("Entre com os valores da lista. Digite um negativo para parar.\n");
	scanf("%d",&valor);
	if(valor<0){
		inicio=(struct lista *)NULL;
		printf("LISTA VAZIA CRIADA.");
		getch();
		system("cls");
		cont++;
	}
	else{
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->ant=(struct lista*)NULL;
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		cont++;
		scanf("%d",&valor);
		lista_ordem_correta(inicio,valor,cont);
	}
}
else{
		if(valor>=0){
			aux->prox=(struct lista*)malloc(sizeof(struct lista));
			aux->prox->ant=aux;
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=(struct lista*)NULL;
			scanf("%d",&valor);
			lista_ordem_correta(aux,valor,cont);
		}
		else{
			aux=(struct lista*)NULL;
			printf("\nLISTA NA ORDEM DIGITADA CRIADA COM SUCESSO");
			getch();
			system("cls");
		}
	}
}


void remover_elemento(struct lista *aux, int valor, int cont){
	if(cont==0){
	printf("DIGITE O ELEMENTO DA LISTA ENCADEADA QUE DESEJA REMOVER.\n");
	scanf("%d",&valor);
	cont++;
}
	if(inicio==(struct lista*)NULL){ //lista vazia
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio->prox==(struct lista*)NULL){ //lista de 1 elemento, elemento existe
			if(inicio->valor==valor){
				inicio->prox=(struct lista*)NULL;
				free(inicio);
				inicio=(struct lista*)NULL;
				printf("ELEMENTO REMOVIDO NA LISTA DE UM ELEMENTO.\n");
				getch();
				system("cls");
			}
			else{
				printf("ELEMENTO NAO EXISTE NA LISTA DE 1 ELEMENTO"); //lista de 1 elemento, elemento não existe
				getch();
				system("cls");
			}
		}
		else{
			if(aux->valor!=valor&&aux->prox!=(struct lista*)NULL){
				aux=aux->prox;
				remover_elemento(aux,valor,cont);
			}
			else{
			if(aux->valor!=valor){ //+ de 1 elemento , não existe
				printf("ELEMENTO NAO EXISTE NA LISTA DE MAIS DE 1 ELEMENTO");
				getch();
				system("cls");
			}
			else{
				if(inicio->valor==valor){ //elemento existe, inicio da lista
					inicio=inicio->prox;
					inicio->ant->prox=(struct lista*)NULL;
					free(inicio->ant);
					inicio->ant=(struct lista*)NULL;
					printf("ELEMENTO REMOVIDO NO INICIO DA LISTA DE MAIS DE UM ELEMENTO");
					getch();
					system("cls");
				}
				else{
					if(aux->prox==(struct lista*)NULL){ //elemento existe, final da lista
						aux->ant->prox=(struct lista*)NULL;
						aux->ant=(struct lista *)NULL;
						free(aux);
						aux=(struct lista*)NULL;
						printf("ELEMENTO REMOVIDO NO FINAL DA LISTA DE MAIS DE UM ELEMENTO");
						getch();
						system("cls");
					}
					else{
						aux->ant->prox=aux->prox;
						aux->prox->ant=aux->ant;
						aux->prox=(struct lista*)NULL;
						aux->ant=(struct lista*)NULL;
						free(aux);
						aux=(struct lista*)NULL;
						printf("ELEMENTO REMOVIDO NO MEIO DA LISTA DE MAIS DE UM ELEMENTO");
						getch();
						system("cls");
					}
				}
			}
		}
	}
	}
	aux=(struct lista*)NULL;
}

void ordenar_duas_listas(){
	struct lista *aux;
	struct lista *aux2;
	int valor;
	apagar_lista(inicio,0);
	struct lista *inicio2;
	int aux3;
	inicio=(struct lista*)NULL;
	inicio2=(struct lista*)NULL;
	criar_lista(0,inicio);
	printf("Entre com os valores da segunda lista. Digite um negativo para parar.\n");
	scanf("%d",&valor);
	if(valor<0){
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
	aux=(struct lista*)malloc(sizeof(struct lista));
	aux->valor=valor;
	aux->prox=inicio2;
	inicio2=aux;
	aux->ant=(struct lista*)NULL;
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio2;
		inicio2=aux;
		aux->prox->ant=aux;
		scanf("%d",&valor);
	}
	aux->ant=(struct lista*)NULL;
	aux=(struct lista*)NULL;
	printf("\n\nLISTA CRIADA COM SUCESSO.");
	getch();
	system("cls");
}
	aux=inicio;
	while(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
	}
	aux->prox=inicio2;
	aux->prox->ant=aux;
	aux=inicio;
	while(aux!=(struct lista*)NULL){
		aux2=aux->prox;
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
