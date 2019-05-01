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


void opcoes(){
	printf("\n\nO que deve ser feito?\n\n1 - Mostrar lista.\n2 - Menor elemento da lista.\n3 - Maior elemento da lista.\n4 - Numero de elementos da lista.\n5 - Inserir elemento no final da lista.\n6 - Media dos elementos da lista.\n7 - Remover elemento da lista.\n8 - Inserir elemento na lista ordenada.\n9 - Gerar lista em ordem crescente.\n10 - Apagar lista toda.\n11 - Gerar lista na ordem correta dos elementos.\n12 - Criar duas listas em e por em ordem crescente");
	scanf("%d",&controle);
	system("cls");
}

void criar_lista(){
	struct lista *aux;
	inicio=(struct lista*)NULL;
	int valor;
	printf("Entre com os valores da lista. Digite um negativo para parar.\n");
	scanf("%d",&valor);
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
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		aux->prox->ant=aux;
		scanf("%d",&valor);
	}
	aux->ant=(struct lista*)NULL;
	aux=(struct lista*)NULL;
	printf("\n\nLISTA CRIADA COM SUCESSO.");
	getch();
	system("cls");
}
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
		while(aux!=(struct lista*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}
	}
	aux=(struct lista*)NULL;
	getch();
	system("cls");
} */

void mostrar_lista(){
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
}

void menor(){
	struct lista *aux;
	int menor;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		menor=aux->valor;
		while(aux!=(struct lista*)NULL){
			if(aux->valor<menor)
				menor=aux->valor;
			aux=aux->prox;
		}
	}
	printf("\nO MENOR VALOR E %d\n",menor);
	getch();
	system("cls");
}

void maior(){
	struct lista *aux;
	int valor;
	int maior;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		maior=aux->valor;
		while(aux!=(struct lista*)NULL){
			if(aux->valor>maior)
				maior=aux->valor;
			aux=aux->prox;
		}
	}
	aux=(struct lista*)NULL;
	printf("\nO MAIOR ELEMENTO E %d",maior);
	getch();
	system("cls");
}

void elementos(){
	struct lista *aux;
	int cont=0;
	if(inicio==(struct lista*)NULL){
		printf("\nLISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		while(aux!=(struct lista*)NULL){
			cont++;
			aux=aux->prox;
		}
	}
	aux=(struct lista*)NULL;
	printf("\nA LISTA POSSUI %d ELEMENTOS.",cont);
	getch();
	system("cls");
}

void media(){
	struct lista *aux;
	int media=0;
	int cont=0;
	if(inicio==(struct lista*)NULL){
		printf("\nLISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		while(aux!=(struct lista*)NULL){
			media+=aux->valor;
			cont++;
			aux=aux->prox;
		}
	}
	media=media/cont;
	printf("\nA MEDIA DOS ELEMENTOS E %d",media);
	getch();
	system("cls");
}

void inserir_final(){
	struct lista *aux;
	int valor;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		printf("ENTRE COM O NOVO VALOR A SER INSERIDO.\n");
		scanf("%d",&valor);
		aux=inicio;
		while(aux->prox!=(struct lista*)NULL){
			aux=aux->prox;
		}
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

void inserir_elemento_ordenada(){
	struct lista *aux;
	int valor;
	printf("ENTRE COM O VALOR A SER INSERIDO NA LISTA ORDENADA.\n");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){ //LISTA VAZIA
		inicio=(struct lista*)malloc(sizeof(struct lista));
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
		}
		else{ //no meio ou fim
			aux=inicio;
			while((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
				aux=aux->prox;
			}
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
			else{ //no meio
				aux->ant->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->ant->prox->prox=aux;
				aux->ant->prox->ant=aux->ant;
				aux->ant->prox->valor=valor;
				aux->ant=aux->ant->prox;
				aux=(struct lista*)NULL;
				printf("INSERIDO NO MEIO DA LISTA");
				getch();
				system("cls");
			}
		}
	}
}

void gerar_lista_crescente(){
	int valor;
	void inserir_elemento_ordenada2(int valor){
	struct lista *aux;
	if(inicio==(struct lista*)NULL){ //LISTA VAZIA
		inicio=(struct lista*)malloc(sizeof(struct lista));
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
		}
		else{ //no meio ou fim
			aux=inicio;
			while((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
				aux=aux->prox;
			}
			if(aux->prox==(struct lista*)NULL){ //no fim
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
			else{ //no meio
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
	printf("Entre com os valores da lista. Digite um negativo para parar.\n");
	scanf("%d",&valor);
	if(valor<0){
		printf("\nCRIADA LISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
	while(valor>=0){
		inserir_elemento_ordenada2(valor);
		printf("Entre com os valores da lista. Digite um negativo para parar.\n");
		scanf("%d",&valor);
		}
	}
	printf("\n\nLISTA ORDENADA CRIADA COM SUCESSO");
	getch();
	system("cls");
}

void apagar_lista(){
	struct lista *aux;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA;");
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		while(aux!=(struct lista*)NULL){
			inicio=aux->prox;
			aux->prox=(struct lista*)NULL;
			aux->ant=(struct lista*)NULL;
			free(aux);
			aux=inicio;
		}
		printf("\nLISTA ESVAZIADA COM SUCESSO.");
		getch();
		system("cls");
	}
	getch();
	system("cls");
}

void lista_ordem_correta(){
	struct lista *aux;
	int valor;
	printf("Entre com os valores da lista. Digite um negativo para parar.\n");
	scanf("%d",&valor);
	if(valor<0){
		printf("LISTA VAZIA CRIADA.");
		getch();
		system("cls");
	}
	else{
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->ant=(struct lista*)NULL;
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		printf("Entre com os valores da lista. Digite um negativo para parar.\n");
		scanf("%d",&valor);
		aux=inicio;
		while(valor>=0){
			aux->prox=(struct lista*)malloc(sizeof(struct lista));
			aux->prox->ant=aux;
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=(struct lista*)NULL;
			scanf("%d",&valor);
		}
	}
	aux=(struct lista*)NULL;
	printf("\nLISTA NA ORDEM DIGITADA CRIADA COM SUCESSO");
	getch();
	system("cls");
}

void remover_elemento(){
	struct lista *aux;
	int valor;
	printf("DIGITE O ELEMENTO DA LISTA ENCADEADA QUE DESEJA REMOVER.\n");
	scanf("%d",&valor);
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
			aux=inicio;
			while(aux->valor!=valor&&aux->prox!=(struct lista*)NULL){
				aux=aux->prox;
			}
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
	aux=(struct lista*)NULL;
}

void ordenar_duas_listas(){
	struct lista *aux;
	struct lista *aux2;
	int valor;
	apagar_lista();
	struct lista *inicio2;
	int aux3;
	inicio=(struct lista*)NULL;
	inicio2=(struct lista*)NULL;
	criar_lista();
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
