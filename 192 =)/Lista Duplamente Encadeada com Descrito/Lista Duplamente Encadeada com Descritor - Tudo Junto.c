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
	struct lista *prox,*ant;
};

struct desc{
	int quant;
	struct lista *ini,*fim;
};

struct desc *inicio;
int controle = 1;

main(){
	printf("[LISTA DUPLAMENTE ENCADEADA COM DESCRITO]\n\n CRIANDO A LISTA.\n\n");
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
	inicio->quant=0;
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
		aux->prox=inicio->ini;
		aux->ant=inicio->ini;
		inicio->ini=aux;
		inicio->fim=aux;
		inicio->quant++;
		scanf("%d",&valor);
		while(valor>=0){
			aux=(struct lista*)malloc(sizeof(struct lista));
			aux->valor=valor;
			aux->prox=inicio->ini;
			aux->ant=(struct lista*)NULL;
			aux->prox->ant=aux;
			inicio->ini=aux;
			inicio->quant++;
			scanf("%d",&valor);
		}
		aux=(struct lista*)NULL;
		printf("\nLISTA CRIADA COM SUCESSO.\n");
		getch();
		system("cls");
	}
}

/*void mostrar_lista(){ //usando prox
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
		aux=(struct lista*)NULL;
		getch();
		system("cls");
	}
} */

void mostrar_lista(){ //usando ant
	struct lista *aux;
	aux=inicio->fim;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		while(aux!=(struct lista*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->ant;
		}
		aux=(struct lista*)NULL;
		getch();
		system("cls");
	}
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
		printf("O menor valor da lista e: %d",m);
		getch();
		system("cls");
	}
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
		printf("O maior valor da lista e: %d",m);
		getch();
		system("cls");
	}
}

void elementos(){
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		printf("O numero de elemento da lista e: %d",inicio->quant);
		getch();
		system("cls");
	}
}

void inserir_final(){
	struct lista *aux;
	int valor;
	aux=inicio->fim;
	printf("DIGITE O VALOR PARA SER INSERIDO NO FINAL DA LISTA.\n");
	scanf("%d",&valor);
	if(aux==(struct lista*)NULL){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio->ini;
		aux->ant=inicio->ini;
		inicio->ini=aux;
		inicio->fim=aux;
		inicio->quant++;
		printf("LISTA VAZIA. VALOR INSERIDO");
	}
	else{
		aux->prox=(struct lista*)malloc(sizeof(struct lista));
		aux->prox->ant=aux;
		aux=aux->prox;
		inicio->fim=aux;
		aux->prox=(struct lista*)NULL;
		aux->valor=valor;
		inicio->quant++;
		printf("VALOR INSERIDO NO FINAL DA LISTA.\n");
		aux=(struct lista*)NULL;
		getch();
		system("cls");
	}
}

void media(){
	struct lista *aux;
	int m=0;
	aux=inicio->ini;
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		while(aux!=(struct lista*)NULL){
			m+=aux->valor;
			aux=aux->prox;
		}
		printf("A media dos elementos e: %d",m/inicio->quant);
		aux=(struct lista*)NULL;
		getch();
		system("cls");
	}
}

void remover_elemento(){
	struct lista *aux;
	int valor;
	printf("DIGITE O ELEMENTO DA LISTA ENCADEADA QUE DESEJA REMOVER.\n");
	scanf("%d",&valor);
	if(inicio->ini==(struct lista*)NULL){ //lista vazia
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio->ini->prox==(struct lista*)NULL){ //lista de 1 elemento, elemento existe
			if(inicio->ini->valor==valor){
				inicio->ini->prox=(struct lista*)NULL;
				free(inicio->ini);
				inicio->ini=(struct lista*)NULL;
				inicio->fim=(struct lista*)NULL;
				printf("ELEMENTO REMOVIDO NA LISTA DE UM ELEMENTO.\n");
				inicio->quant--;
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
			aux=inicio->ini;
			while(aux->valor!=valor&&aux->prox!=(struct lista*)NULL){
				aux=aux->prox;
			}
			if(aux->valor!=valor){ //+ de 1 elemento , não existe
				printf("ELEMENTO NAO EXISTE NA LISTA DE MAIS DE 1 ELEMENTO");
				getch();
				system("cls");
			}
			else{
				if(inicio->ini->valor==valor){ //elemento existe, inicio da lista
					inicio->ini=inicio->ini->prox;
					inicio->ini->ant->prox=(struct lista*)NULL;
					free(inicio->ini->ant);
					inicio->ini->ant=(struct lista*)NULL;
					inicio->quant--;
					printf("ELEMENTO REMOVIDO NO INICIO DA LISTA DE MAIS DE UM ELEMENTO");
					getch();
					system("cls");
				}
				else{
					if(aux->prox==(struct lista*)NULL){ //elemento existe, final da lista
						inicio->fim=inicio->fim->ant;
						aux->ant->prox=(struct lista*)NULL;
						aux->ant=(struct lista *)NULL;
						free(aux);
						aux=(struct lista*)NULL;
						inicio->quant--;
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
						inicio->quant--;
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

void inserir_elemento_ordenada(){
	struct lista *aux;
	int valor;
	printf("ENTRE COM O VALOR A SER INSERIDO NA LISTA ORDENADA.\n");
	scanf("%d",&valor);
	if(inicio->ini==(struct lista*)NULL){ //LISTA VAZIA
		inicio->ini=(struct lista*)malloc(sizeof(struct lista*));
		inicio->ini->ant=(struct lista*)NULL;
		inicio->ini->valor=valor;
		inicio->ini->prox=(struct lista*)NULL;
		inicio->fim=inicio->ini;
		inicio->quant++;
		aux=(struct lista*)NULL;
		printf("\nELEMENTO INSERIDO NA LISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		if(inicio->ini->valor>valor){ //inicio da lista
			aux=inicio->ini;
			inicio->ini=(struct lista*)malloc(sizeof(struct lista));
			inicio->ini->valor=valor;
			inicio->ini->ant=(struct lista*)NULL;
			inicio->ini->prox=aux;
			aux->ant=inicio->ini;
			aux=(struct lista*)NULL;
			inicio->quant++;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA");
			getch();
			system("cls");
		}
		else{ //no meio ou fim
			aux=inicio->ini;
			while((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
				aux=aux->prox;
			}
			if(valor>aux->valor){ //no fim
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				inicio->fim=aux;
				inicio->quant++;
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
				inicio->quant++;
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
	if(inicio->ini==(struct lista*)NULL){ //LISTA VAZIA
		inicio->ini=(struct lista*)malloc(sizeof(struct lista*));
		inicio->ini->ant=(struct lista*)NULL;
		inicio->ini->valor=valor;
		inicio->ini->prox=(struct lista*)NULL;
		inicio->fim=inicio->ini;
		inicio->quant++;
		aux=(struct lista*)NULL;
		printf("\nELEMENTO INSERIDO NA LISTA VAZIA.");
		getch();
		system("cls");
	}
	else{
		if(inicio->ini->valor>valor){ //inicio da lista
			aux=inicio->ini;
			inicio->ini=(struct lista*)malloc(sizeof(struct lista));
			inicio->ini->valor=valor;
			inicio->ini->ant=(struct lista*)NULL;
			inicio->ini->prox=aux;
			aux->ant=inicio->ini;
			aux=(struct lista*)NULL;
			inicio->quant++;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA");
			getch();
			system("cls");
		}
		else{ //no meio ou fim
			aux=inicio->ini;
			while((valor>aux->valor)&&(aux->prox!=(struct lista*)NULL)){
				aux=aux->prox;
			}
			if(valor>aux->valor){ //no fim
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				inicio->fim=aux;
				inicio->quant++;
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
				inicio->quant++;
				printf("INSERIDO NO MEIO DA LISTA");
				getch();
				system("cls");
			}
		}
	}
}
	printf("Entre com os valores para a lista ordenada. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	if(valor<0){
		inicio->ini=(struct lista*)NULL;
		inicio->fim=(struct lista*)NULL;
		inicio->quant=0;
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		while(valor>=0){
			inserir_elemento_ordenada2(valor);
			scanf("%d",&valor);
		}
		printf("LISTA CRIADA COM SUCESSO.\n");
		getch();
		system("cls");
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
		while(aux!=(struct lista*)NULL){
			inicio->ini=inicio->ini->prox;
			aux->prox=(struct lista*)NULL;
			aux->ant=aux->prox;
			free(aux);
			aux=inicio->ini;
		}
		inicio->fim=(struct lista*)NULL;
		inicio->quant=0;
		printf("LISTA APAGADA COM SUCESSO.\n");
		getch();
		system("cls");	
	}
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
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->ant=(struct lista*)NULL;
		inicio->ini->valor=valor;
		inicio->ini->prox=(struct lista*)NULL;
		inicio->fim=inicio->ini;
		printf("Entre com os valores da lista. Digite um negativo para parar.\n");
		scanf("%d",&valor);
		aux=inicio->ini;
		while(valor>=0){
			aux->prox=(struct lista*)malloc(sizeof(struct lista));
			aux->prox->ant=aux;
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=(struct lista*)NULL;
			inicio->fim=aux;
			scanf("%d",&valor);
		}
	}
	aux=(struct lista*)NULL;
	printf("\nLISTA NA ORDEM DIGITADA CRIADA COM SUCESSO");
	getch();
	system("cls");
}

void ordenar_duas_listas(){
	struct lista *aux;
	struct lista *aux2;
	int valor;
	apagar_lista();
	struct desc *inicio2;
	inicio2=(struct desc*)malloc(sizeof(struct desc));
	int aux3;
	inicio=(struct desc*)NULL;
	inicio2->ini=(struct lista*)NULL;
	inicio2->fim=(struct lista*)NULL;
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
	aux->prox=inicio2->ini;
	inicio2->ini=aux;
	inicio2->fim=aux;
	inicio2->quant++;
	aux->ant=(struct lista*)NULL;
	scanf("%d",&valor);
	while(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio2->ini;
		inicio2->ini=aux;
		aux->prox->ant=aux;
		scanf("%d",&valor);
	}
	aux->ant=(struct lista*)NULL;
	aux=(struct lista*)NULL;
	printf("\n\nLISTA CRIADA COM SUCESSO.");
	getch();
	system("cls");
}
	aux=inicio->fim;
	aux->prox=inicio2->ini;
	aux->prox->ant=aux;
	inicio->fim=inicio2->fim;
	aux=inicio->ini;
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
