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

struct desc{
	int nos;
	struct lista *ini,*fim;
};

struct desc *inicio;

main(){
	printf("[LISTA SIMPLESMENTE ENCADEADA COM DESCRITO]\n\n CRIANDO A LISTA.\n\n");
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
	int valor;
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct lista*)NULL;
	inicio->fim=(struct lista*)NULL;
	inicio->nos=0;
	printf("Digite valores para a lista encadeada com descritor. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio->ini;
		inicio->ini=aux;
		inicio->nos++;
		scanf("%d",&valor);
	}
	if(inicio->nos==0){
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio->ini;
		while(aux->prox!=(struct lista*)NULL){
			aux=aux->prox;
		}
		inicio->fim=aux;
		printf("LISTA CRIADA COM SUCESSO.\n");
		getch();
		system("cls");
	}
	aux=(struct lista*)NULL;
}

void mostrar_lista(){
	struct lista *aux;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){
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
	printf("\n%d",inicio->fim->valor);
	aux=(struct lista*)NULL;
	getch();
	system("cls");
}

void menor(){
	struct lista *aux;
	int m;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
		
	}
	else{
		m=aux->valor;
		while(aux!=(struct lista*)NULL){
			if(aux->valor<m){
				m=aux->valor;
			}
			aux=aux->prox;
		}
	}
	printf("O menor valor da lista e: %d",m);
	getch();
	system("cls");
}

void maior(){
	struct lista *aux;
	int m;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
		
	}
	else{
		m=aux->valor;
		while(aux!=(struct lista*)NULL){
			if(aux->valor>m){
				m=aux->valor;
			}
			aux=aux->prox;
		}
	}
	printf("O maior valor da lista e: %d",m);
	getch();
	system("cls");
}

void elementos(){
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
	}
	else{
		printf("A lista possui %d elementos.",inicio->nos);
	}
	getch();
	system("cls");
}

void inserir_final(){
	struct lista *aux;
	int valor;
	aux=inicio->ini;
	printf("Digite o valor para ser inserido no final da lista.\n");
	scanf("%d",&valor);
	if(aux==(struct lista*)NULL){
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->valor=valor;
		inicio->ini->prox=(struct lista*)NULL;
		inicio->fim=inicio->ini;
		printf("ELEMENTO INSERIDO NA LISTA VAZIA COM SUCESSO.\n");
		getch();
		system("cls");
		inicio->nos++;
	}
	else{
		while(aux->prox!=(struct lista*)NULL){
			aux=aux->prox;
		}
		aux->prox=(struct lista*)malloc(sizeof(struct lista));
		aux=aux->prox;
		aux->valor=valor;
		aux->prox=(struct lista*)NULL;
		inicio->fim=aux;
		printf("ELEMENTO INSERIDO NO FINAL DA LISTA COM SUCESSO.\n");
		getch();
		system("cls");
		inicio->nos++;
	}	
}

void media(){
	struct lista *aux;
	int m=0;
	int cont=0;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		while(aux!=(struct lista*)NULL){
			m+=aux->valor;
			cont++;
			aux=aux->prox;
		}
		printf("A MEDIA DOS ELEMENTOS E: %d",m/cont);
		getch();
		system("cls");
	}
}

void remover_elemento(){
	struct lista *aux;
	struct lista *aux2;
	int valor;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){ //lista vazia
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		printf("Entre com o elemento da lista para ser removido.\n");
		scanf("%d",&valor);
		if(aux->prox==(struct lista*)NULL){ //lista de 1 elemento
			if(aux->valor!=valor){ //existe
				printf("ELEMENTO NAO EXISTE NA LISTA DE 1 ELEMENTO.\n");
				aux=(struct lista*)NULL;
				getch();
				system("cls");
			}
			else{ //nao existe
				free(aux);
				inicio->ini=(struct lista*)NULL;
				inicio->fim=inicio->ini;
				aux=inicio->fim;
				printf("ELEMENTO REMOVIDO DA LISTA DE 1 ELEMENTO.\n");
				getch();
				system("cls");
				inicio->nos--;
			}
		}
		else{ //lista de + de 1 elemento
			if(aux->valor==valor){ //elemento no inicio
				inicio->ini=aux->prox;
				aux->prox=(struct lista*)NULL;
				free(aux);
				aux=(struct lista*)NULL;
				printf("ELEMENTO REMOVIDO DO INICIO DA LISTA DE MAIS DE 1 ELEMENTO.\n");
				getch();
				system("cls");	
				inicio->nos--;
			}
			else{ //meio ou fim
				while(aux->valor!=valor&&aux->prox!=(struct lista*)NULL){
					aux2=aux;
					aux=aux->prox;
				}
				if(aux->valor!=valor){ //nao existe
					aux2=(struct lista*)NULL;
					aux=aux2;
					printf("ELEMENTO NAO EXISTE NA LISTA DE MAIS DE 1 ELEMENTO.\n");
				}
				else{ //meio ou fim
					if(aux->prox==(struct lista*)NULL){ //fim da lista
						free(aux);
						aux2->prox=(struct lista*)NULL;
						inicio->fim=aux2;
						aux2=(struct lista*)NULL;
						aux=aux2;
						printf("ELEMENTO REMOVIDO DO FIM DA LISTA DE MAIS DE 1 ELEMENTO.");
						getch();
						system("cls");
						inicio->nos--;
					}
					else{ // no meio
						aux2->prox=aux->prox;
						aux->prox=(struct lista*)NULL;
						free(aux);
						aux2=(struct lista*)NULL;
						aux=aux2;
						printf("ELEMENTO REMOVIDO DO MEIO DA LISTA DE MAIS DE 1 ELEMENTO");
						getch();
						system("cls");
						inicio->nos--;
					}
				}
			}
		}
	}
}

void inserir_elemento_ordenada(){
	struct lista *aux;
	struct lista *ant;
	int valor;
	printf("ENTRE COM O VALOR QUE DESEJA INSERIR NA LISTA CRESCENTE.");
	scanf("%d",&valor);
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){ //lista vazia
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->valor=valor;
		inicio->ini->prox=(struct lista*)NULL;
		inicio->fim=inicio->ini;
		aux=(struct lista*)NULL;
		ant=aux;
		printf("ELEMENTO INSERIDO NA LISTA VAZIA.\n");
		getch();
		system("cls");
		inicio->nos++;
	}
	else{
		if(valor<inicio->ini->valor){ //inicio da lista
			inicio->ini=(struct lista*)malloc(sizeof(struct lista));
			inicio->ini->valor=valor;
			inicio->ini->prox=aux;
			aux=(struct lista*)NULL;
			ant=aux;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA.\n");
			getch();
			system("cls");
			inicio->nos++;
		}
		else{
			while(valor>aux->valor&&aux->prox!=(struct lista*)NULL){
				ant=aux;
				aux=aux->prox;
			}
			if(valor>aux->valor){ //no final da lista
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct lista*)NULL;
				inicio->fim=aux;
				aux=(struct lista*)NULL;
				ant=aux;
				printf("ELEMENTO INSERIDO NO FINAL DA LISTA.\n");
				getch();
				system("cls");
				inicio->nos++;
			}
			else{
				ant->prox=(struct lista*)malloc(sizeof(struct lista));
				ant=ant->prox;
				ant->valor=valor;
				ant->prox=aux;
				ant=(struct lista*)NULL;
				aux=ant;
				printf("ELEMENTO INSERIDO NO MEIO DA LISTA.\n");
				getch();
				system("cls");
				inicio->nos++;
			}
		}
	}
}

void gerar_lista_crescente(){
	int valor;
	void inserir_elemento_ordenada2(int valor){
	struct lista *aux;
	struct lista *ant;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){ //lista vazia
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->valor=valor;
		inicio->ini->prox=(struct lista*)NULL;
		inicio->fim=inicio->ini;
		aux=(struct lista*)NULL;
		ant=aux;
		printf("ELEMENTO INSERIDO NA LISTA VAZIA.\n");
		getch();
		system("cls");
		inicio->nos++;
	}
	else{
		if(valor<inicio->ini->valor){ //inicio da lista
			inicio->ini=(struct lista*)malloc(sizeof(struct lista));
			inicio->ini->valor=valor;
			inicio->ini->prox=aux;
			aux=(struct lista*)NULL;
			ant=aux;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA.\n");
			getch();
			system("cls");
			inicio->nos++;
		}
		else{
			while(valor>aux->valor&&aux->prox!=(struct lista*)NULL){
				ant=aux;
				aux=aux->prox;
			}
			if(valor>aux->valor){ //no final da lista
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=(struct lista*)NULL;
				inicio->fim=aux;
				aux=(struct lista*)NULL;
				ant=aux;
				printf("ELEMENTO INSERIDO NO FINAL DA LISTA.\n");
				getch();
				system("cls");
				inicio->nos++;
			}
			else{
				ant->prox=(struct lista*)malloc(sizeof(struct lista));
				ant=ant->prox;
				ant->valor=valor;
				ant->prox=aux;
				ant=(struct lista*)NULL;
				aux=ant;
				printf("ELEMENTO INSERIDO NO MEIO DA LISTA.\n");
				getch();
				system("cls");
				inicio->nos++;
			}
		}
	}
}
	printf("ENTRE COM O VALOR PARA SER INSERIDO NA LISTA CRESCENTE.\n");
	scanf("%d",&valor);
	if(valor<0){
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		while(valor>=0){
			inserir_elemento_ordenada2(valor);
			scanf("%d",&valor);
		}
	}
}

void apagar_lista(){
	struct lista *aux;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		while(inicio->ini!=(struct lista*)NULL){
			inicio->ini=aux->prox;
			aux->prox=(struct lista*)NULL;
			free(aux);
			aux=inicio->ini;
		}
		inicio->fim=(struct lista*)NULL;
		inicio->nos=0;
		printf("LISTA APAGADA COM SUCESSO.\n");
		getch();
		system("cls");
	}
}

void lista_ordem_correta(){
	struct lista *aux;
	apagar_lista();
	inicio->ini=(struct lista*)NULL;
	inicio->fim=inicio->ini;
	int valor;
	printf("ENTRE COM OS VALORES PARA A LISTA NA ORDEM CORRETA. DIGITE UM VALOR MENOR QUE 0 PARA PARAR.\n");
	scanf("%d",&valor);
	if(valor>=0){
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->valor=valor;
		inicio->ini->prox=(struct lista*)NULL;
		inicio->nos++;
		scanf("%d",&valor);
		aux=inicio->ini;
		while(valor>=0){
			aux->prox=(struct lista*)malloc(sizeof(struct lista));
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=(struct lista*)NULL;
			inicio->fim=aux;
			inicio->nos++;
			scanf("%d",&valor);
		}
		printf("LISTA CRIADA COM SUCESSO.\n");
	}
	else{
		printf("LISTA VAZIA CRIADA.\n");
		aux=(struct lista*)NULL;
		getch();
		system("cls");
	}
}

void ordenar_duas_listas(){
	struct lista *aux,*aux2;
	struct desc *inicio2;
	inicio2=(struct desc*)malloc(sizeof(struct desc));
	int valor;
	int aux3;
	apagar_lista();
	inicio->ini=(struct lista*)NULL;
	inicio->fim=(struct lista*)NULL;
	inicio2->ini=(struct lista*)NULL;
	inicio2->fim=(struct lista*)NULL;
	inicio2->nos=0;
	criar_lista();
	printf("Digite valores para a segunda lista encadeada. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio2->ini;
		inicio2->ini=aux;
		inicio2->nos++;
		scanf("%d",&valor);
	}
	aux=inicio->ini;
	while(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
	}
	aux->prox=inicio2->ini;
	inicio->nos+=inicio2->nos;
	aux2=(struct lista*)NULL;
	aux=inicio->ini;
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
	aux=inicio->ini;
	while(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
	}
	inicio->fim=aux;
	printf("LISTA CRIADA COM SUCESSO.\n");
	getch();
	system("cls");
}
