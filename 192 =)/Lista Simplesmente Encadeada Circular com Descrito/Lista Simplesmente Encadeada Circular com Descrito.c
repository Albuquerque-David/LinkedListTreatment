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
	struct lista *prox;
};

struct desc{
	int quant;
	struct lista *ini,*fim;
};

struct desc *inicio;
int controle = 1;

main(){
	printf("[LISTA SIMPLESMENTE ENCADEADA CIRCULAR COM DESCRITO]\n\n CRIANDO A LISTA.\n\n");
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
			//lista_ordem_correta();
		}
		if(controle==12){
			//ordenar_duas_listas();
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
	int valor;
	inicio=(struct desc*)malloc(sizeof(struct lista));
	inicio->ini=(struct lista*)malloc(sizeof(struct lista));
	inicio->fim=(struct lista*)malloc(sizeof(struct lista));
	inicio->ini=(struct lista*)NULL;
	inicio->fim=(struct lista*)NULL;
	inicio->quant=0;
	printf("Entre com os valores para preencher a lista encadeada. Digite um menor que 0 para parar.\n");
	scanf("%d",&valor);
	if(valor>=0){
	while(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio->ini;
		inicio->ini=aux;
		inicio->quant++;
		scanf("%d",&valor);
	}
	aux=inicio->ini;
	while(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
	}
	inicio->fim=aux;
	aux->prox=inicio->ini;
	aux=(struct lista*)NULL;
	printf("LISTA CRIADA COM SUCESSO.\n");
	getch();
	system("cls");
}
}

void mostrar_lista(){
	struct lista *aux;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
	}
	else{
		do{
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}while(aux!=inicio->ini);
		printf("\n\nPrimeiro elemento da lista: %d\n",inicio->ini->valor);
		printf("Ultimo elemento da lista: %d\n",inicio->fim->valor);
		printf("Elemento circular: %d",inicio->fim->prox->valor);
		getch();
		system("cls");
	}
}

void menor(){
	struct lista *aux;
	int m;
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio->ini;
		m=aux->valor;
		while(aux!=inicio->fim){
			aux=aux->prox;
			if(aux->valor<m){
				m=aux->valor;
			}
		}
		printf("O MENOR ELEMENTO DA LISTA E: %d.\n",m);
		getch();
		system("cls");
	}
}

void maior(){
	struct lista *aux;
	int m;
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio->ini;
		m=aux->valor;
		while(aux!=inicio->fim){
			aux=aux->prox;
			if(aux->valor>m){
				m=aux->valor;
			}
		}
		printf("O MAIOR ELEMENTO DA LISTA E: %d.\n",m);
		getch();
		system("cls");
	}
}

void elementos(){
	if(inicio->quant==0){
		printf("LISTA VAZIA.\n");
	}
	else{
		printf("A LISTA POSSUI %d ELEMENTOS.",inicio->quant);
	}
}

void inserir_final(){
	struct lista *aux;
	int valor;
	printf("Entre com o valor para ser inserido no final da lista.\n");
	scanf("%d",&valor);
	if(inicio->ini==(struct lista*)NULL){
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->valor=valor;
		inicio->ini->prox=inicio->ini;
		inicio->fim=inicio->ini;
		inicio->quant++;
		printf("VALOR INSERIDO NA LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio->fim;
		aux->prox=(struct lista*)malloc(sizeof(struct lista));
		aux=aux->prox;
		aux->valor=valor;
		aux->prox=inicio->ini;
		inicio->fim=aux;
		inicio->quant++;
		printf("VALOR ALOCADO NO FINAL DA LISTA.\n");
		getch();
		system("cls");
	}
}

void media(){
	struct lista *aux;
	int m=0;
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio->ini;
		do{
			m+=aux->valor;
			aux=aux->prox;
		}while(aux!=inicio->ini);
		printf("A MEDIA DOS ELEMENTOS DA LISTA E: %d",m/inicio->quant);
		getch();
		system("cls");
	}
}

void remover_elemento(){
	struct lista *aux,*ant;
	int valor;
	printf("ENTRE COM O ELEMENTO PARA SER REMOVIDO DA LISTA.\n");
	scanf("%d",&valor);
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio->ini->prox==inicio->ini){ //lista de 1 elemento
			if(inicio->ini->valor==valor){
				inicio->ini->prox=(struct lista*)NULL;
				free(inicio->ini);
				inicio->ini=(struct lista*)NULL;
				inicio->fim=(struct lista*)NULL;
				inicio->quant--;
				printf("ELEMENTO REMOVIDA DA LISTA DE 1 ELEMENTO.");
				getch();
				system("cls");
			}
			else{
				printf("ELEMENTO NAO EXISTE NA LISTA DE 1 ELEMENTO.\n");
				getch();
				system("cls");
			}
		}
		else{
			if(inicio->ini->valor==valor){ //inicio da lista
				inicio->ini=inicio->ini->prox;
				inicio->fim->prox->prox=(struct lista*)NULL;
				free(inicio->fim->prox);
				inicio->fim->prox=inicio->ini;
				inicio->quant--;
				printf("ELEMENTO REMOVIDO DO INICIO DA LISTA.\n");
			}
			else{
			aux=inicio->ini;
			while(aux->valor!=valor&&aux->prox!=inicio->ini){ //+ de 1 elemento
				ant=aux;
				aux=aux->prox;
			}
			if(aux->valor!=valor){ //nao existe
				printf("ELEMENTO NAO EXISTE NA LISTA DE MAIS DE 1 ELEMENTO.\n");
				getch();
				system("cls");
			}
			else{
				if(aux->prox==inicio->ini){ //final da lista
					aux->prox=(struct lista*)NULL;
					free(aux);
					ant->prox=inicio->ini;
					inicio->fim=ant;
					inicio->quant--;
					printf("ELEMENTO REMOVIDO DO FINAL DA LISTA.\n");
					getch();
					system("cls");
				}
				else{ //no meio
					ant->prox=aux->prox;
					aux->prox=(struct lista*)NULL;
					free(aux);
					inicio->quant--;
					printf("ELEMENTO REMOVIDO DO MEIO DA LISTA.\n");
					getch();
					system("cls");
				}
			}
		}
		}
	}
	aux=(struct lista*)NULL;
	ant=aux;
}

void inserir_elemento_ordenada(){
	struct lista *aux,*ant;
	int valor;
	aux=inicio->ini;
	printf("ENTRE COM O NUMERO QUE DESEJA INSERIR NA LISTA ORDENADA.\n");
	scanf("%d",&valor);
	if(inicio->ini==(struct lista*)NULL){
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->prox=inicio->ini;
		inicio->fim=inicio->ini;
		inicio->ini->valor=valor;
		inicio->quant++;
		printf("Elemento inserido na lista vazia.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio->ini->valor>valor){
			inicio->ini=(struct lista*)malloc(sizeof(struct lista));
			inicio->ini->valor=valor;
			inicio->ini->prox=aux;
			inicio->fim->prox=inicio->ini;
			inicio->quant++;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA.\n");
			getch();
			system("cls");
		}
		else{
			while(aux->valor<valor&&aux->prox!=inicio->ini){
				ant=aux;
				aux=aux->prox;
			}
			if(valor>aux->valor){
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux=aux->prox;
				aux->valor=valor;
				inicio->fim=aux;
				aux->prox=inicio->ini;
				inicio->quant++;
				printf("ELEMENTO INSERIDO NO FINAL DA LISTA.\n");
				getch();
				system("cls");
			}
			else{
				ant->prox=(struct lista*)malloc(sizeof(struct lista));
				ant=ant->prox;
				ant->valor=valor;
				ant->prox=aux;
				inicio->quant++;
				printf("ELEMENTO INSERIDO NO MEIO DA LISTA.\n");
				getch();
				system("cls");
			}
		}
	}
	aux=(struct lista*)NULL;
	ant=aux;
}

void gerar_lista_crescente(){
	int valor;
	void inserir_elemento_ordenada2(int valor){
	struct lista *aux,*ant;
	aux=inicio->ini;
	if(inicio->ini==(struct lista*)NULL){
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->prox=inicio->ini;
		inicio->fim=inicio->ini;
		inicio->ini->valor=valor;
		inicio->quant++;
		printf("Elemento inserido na lista vazia.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio->ini->valor>valor){
			inicio->ini=(struct lista*)malloc(sizeof(struct lista));
			inicio->ini->valor=valor;
			inicio->ini->prox=aux;
			inicio->fim->prox=inicio->ini;
			inicio->quant++;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA.\n");
			getch();
			system("cls");
		}
		else{
			while(aux->valor<valor&&aux->prox!=inicio->ini){
				ant=aux;
				aux=aux->prox;
			}
			if(valor>aux->valor){
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux=aux->prox;
				aux->valor=valor;
				inicio->fim=aux;
				aux->prox=inicio->ini;
				inicio->quant++;
				printf("ELEMENTO INSERIDO NO FINAL DA LISTA.\n");
				getch();
				system("cls");
			}
			else{
				ant->prox=(struct lista*)malloc(sizeof(struct lista));
				ant=ant->prox;
				ant->valor=valor;
				ant->prox=aux;
				inicio->quant++;
				printf("ELEMENTO INSERIDO NO MEIO DA LISTA.\n");
				getch();
				system("cls");
			}
		}
	}
	aux=(struct lista*)NULL;
	ant=aux;
}
	printf("ENTRE COM O NUMERO QUE DESEJA INSERIR NA LISTA ORDENADA.\n");
	scanf("%d",&valor);
	while(valor>=0){
		inserir_elemento_ordenada2(valor);
		scanf("%d",&valor);
	}
	printf("LISTA CRIADA.\n");
	getch();
	system("cls");
}

void apagar_lista(){
	struct lista *aux;
	aux=inicio->ini;
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		inicio->fim->prox=(struct lista*)NULL;
		while(inicio->ini!=(struct lista*)NULL){
			aux=inicio->ini;
			inicio->ini=inicio->ini->prox;
			aux->prox=(struct lista*)NULL;
			free(aux);
		}
		inicio->fim=(struct lista*)NULL;
		aux=(struct lista*)NULL;
		printf("LISTA APAGADA.\n");
		getch();
		system("cls");
	}
}
