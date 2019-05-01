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
	criar_lista(0);
	opcoes();
	while(controle!=0){
		if(controle==1){
			mostrar_lista(inicio->ini,0);
		}
		if(controle==2){
			menor(inicio->ini,0);
		}
		if(controle==3){
			maior(inicio->ini,0);
		}
		if(controle==4){
			elementos();
		}
		if(controle==5){
			inserir_final(inicio->ini,0,0);
		}
		if(controle==6){
			media(inicio->ini,0,0);
		}
		if(controle==7){
			remover_elemento(inicio->ini,inicio->ini,0,0);
		}
		if(controle==8){
			inserir_elemento_ordenada(inicio->ini,inicio->ini,0,0);
		}
		if(controle==9){
			gerar_lista_crescente();
		}
		if(controle==10){
			apagar_lista(inicio->ini);
		}
		if(controle==11){
			lista_ordem_correta(inicio->ini,0,0);
		}
		if(controle==12){
			ordenar_duas_listas((struct lista*)NULL,(struct lista*)NULL,(struct desc*)NULL,0,0,0,1);
		}
		opcoes();
	}
}


void opcoes(){
	printf("\n\nO que deve ser feito?\n\n1 - Mostrar lista.\n2 - Menor elemento da lista.\n3 - Maior elemento da lista.\n4 - Numero de elementos da lista.\n5 - Inserir elemento no final da lista.\n6 - Media dos elementos da lista.\n7 - Remover elemento da lista.\n8 - Inserir elemento na lista ordenada.\n9 - Gerar lista em ordem crescente.\n10 - Apagar lista toda.\n11 - Gerar lista na ordem correta dos elementos.\n12 - Criar duas listas em e por em ordem crescente");
	scanf("%d",&controle);
	system("cls");
}

void criar_lista(int cont){
	struct lista *aux;
	int valor;
	if(cont==0){
	inicio=(struct desc*)malloc(sizeof(struct desc));
	inicio->ini=(struct lista*)NULL;
	inicio->fim=(struct lista*)NULL;
	inicio->nos=0;
	cont++;
	printf("Digite valores para a lista encadeada com descritor. Digite um valor menor que 0 para parar.\n");
}
	scanf("%d",&valor);
	if(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio->ini;
		inicio->ini=aux;
		inicio->nos++;
		if(aux->prox==(struct lista*)NULL){
			inicio->fim=aux;
		}
		criar_lista(cont);
	}
	else{
	if(inicio->nos==0){
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		printf("LISTA CRIADA COM SUCESSO.\n");
		getch();
		system("cls");
	}
}
	aux=(struct lista*)NULL;
}

void mostrar_lista(struct lista *aux, int cont){
	if(cont==0){
	aux=inicio->ini;
	cont++;
}
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(aux!=(struct lista*)NULL){
			printf("%d\t",aux->valor);
			aux=aux->prox;
			mostrar_lista(aux,cont);
		}
	}
	aux=(struct lista*)NULL;
	getch();
	system("cls");
}

void menor(struct lista *aux, int m){
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
		
	}
	else{
		if(aux==inicio->ini){
		m=aux->valor;
	}
		if(aux!=(struct lista*)NULL){
			if(aux->valor<m){
				m=aux->valor;
			}
			aux=aux->prox;
			menor(aux,m);
		}
		else{
			printf("O menor valor da lista e: %d",m);
			getch();
			system("cls");
		}
	}
	aux=(struct lista*)NULL;
}

void maior(struct lista *aux, int m){
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
		
	}
	else{
		if(aux==inicio->ini){
		m=aux->valor;
	}
		if(aux!=(struct lista*)NULL){
			if(aux->valor>m){
				m=aux->valor;
			}
			aux=aux->prox;
			maior(aux,m);
		}
		else{
			printf("O maior valor da lista e: %d",m);
			getch();
			system("cls");
		}
	}
	aux=(struct lista*)NULL;
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

void inserir_final(struct lista *aux, int cont, int valor){
	if(cont==0){
	printf("Digite o valor para ser inserido no final da lista.\n");
	scanf("%d",&valor);
	cont++;
}
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
		if(aux->prox!=(struct lista*)NULL){
			aux=aux->prox;
			inserir_final(aux,cont,valor);
		}
		else{
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
}

void media(struct lista *aux, int m, int cont){
	if(inicio->ini==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
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
		printf("A MEDIA DOS ELEMENTOS E: %d",m/cont);
		getch();
		system("cls");
		}
	}
}

void remover_elemento(struct lista *aux, struct lista *aux2, int valor,int cont){
	if(aux==(struct lista*)NULL){ //lista vazia
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(cont==0){
			printf("Entre com o elemento da lista para ser removido.\n");
			scanf("%d",&valor);
			cont++;
		}
		if(inicio->ini->prox==(struct lista*)NULL){ //lista de 1 elemento
			if(aux->valor!=valor){ // nao existe
				printf("ELEMENTO NAO EXISTE NA LISTA DE 1 ELEMENTO.\n");
				aux=(struct lista*)NULL;
				getch();
				system("cls");
			}
			else{ //existe
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
			if(inicio->ini->valor==valor){ //elemento no inicio
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
				if(aux->valor!=valor&&aux->prox!=(struct lista*)NULL){
					aux2=aux;
					aux=aux->prox;
					remover_elemento(aux,aux2,valor,cont);
				}
				else{
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
	aux=(struct lista*)NULL;
	aux2=aux;
}

void inserir_elemento_ordenada(struct lista *aux, struct lista *ant, int valor, int cont){
	if(cont==0){
	printf("ENTRE COM O VALOR QUE DESEJA INSERIR NA LISTA CRESCENTE.");
	scanf("%d",&valor);
	aux=inicio->ini;
	cont++;
}
	if(inicio->ini==(struct lista*)NULL){ //lista vazia
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
			if(valor>aux->valor&&aux->prox!=(struct lista*)NULL){
				ant=aux;
				aux=aux->prox;
				inserir_elemento_ordenada(aux,ant,valor,cont);
			}
			else{
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
				else{ //no meio
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
}

void gerar_lista_crescente(){
	int valor;
	void inserir_elemento_ordenada2(struct lista *aux, struct lista *ant, int valor, int cont){
	if(cont==0){
	aux=inicio->ini;
	cont++;
}
	if(inicio->ini==(struct lista*)NULL){ //lista vazia
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
			if(valor>aux->valor&&aux->prox!=(struct lista*)NULL){
				ant=aux;
				aux=aux->prox;
				inserir_elemento_ordenada(aux,ant,valor,cont);
			}
			else{
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
				else{ //no meio
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
}
	printf("ENTRE COM O VALOR PARA SER INSERIDO NA LISTA CRESCENTE.\n");
	scanf("%d",&valor);
	if(valor<0){
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		if(valor>=0){
			inserir_elemento_ordenada2(inicio->ini,inicio->ini,valor,0);
			gerar_lista_crescente();
		}
	}
}

void apagar_lista(struct lista *aux){
	if(aux==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio->ini!=(struct lista*)NULL){
			inicio->ini=aux->prox;
			aux->prox=(struct lista*)NULL;
			free(aux);
			aux=inicio->ini;
			apagar_lista(aux);
		}
		inicio->fim=(struct lista*)NULL;
		inicio->nos=0;
		aux=(struct lista*)NULL;
		printf("LISTA APAGADA COM SUCESSO.\n");
		getch();
		system("cls");
	}
}

void lista_ordem_correta(struct lista *aux, int valor, int cont){
	if(cont==0){
	apagar_lista(inicio->ini);
	inicio->ini=(struct lista*)NULL;
	inicio->fim=inicio->ini;
	printf("ENTRE COM OS VALORES PARA A LISTA NA ORDEM CORRETA. DIGITE UM VALOR MENOR QUE 0 PARA PARAR.\n");
	scanf("%d",&valor);
	cont++;
	if(valor>=0){
		inicio->ini=(struct lista*)malloc(sizeof(struct lista));
		inicio->ini->valor=valor;
		inicio->ini->prox=(struct lista*)NULL;
		inicio->nos++;
		aux=inicio->ini;
}	
	lista_ordem_correta(aux,valor,cont);
}
else{
		scanf("%d",&valor);
		if(valor>=0){
			aux->prox=(struct lista*)malloc(sizeof(struct lista));
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=(struct lista*)NULL;
			inicio->fim=aux;
			inicio->nos++;
			lista_ordem_correta(aux,valor,cont);
		}
		system("cls");
		printf("LISTA CRIADA COM SUCESSO.\n");
	}
	if(inicio->nos==0){
		printf("LISTA VAZIA CRIADA.\n");
		aux=(struct lista*)NULL;
		getch();
		system("cls");
	}


}


/*void ordenar_duas_listas(struct lista *aux, struct lista *aux2, struct desc *inicio2, int cont,int valor, int aux3, int aux4){
	if(cont==0){
	inicio2=(struct desc*)malloc(sizeof(struct desc));
	apagar_lista(inicio->ini);
	inicio->ini=(struct lista*)NULL;
	inicio->fim=(struct lista*)NULL;
	inicio2->ini=(struct lista*)NULL;
	inicio2->fim=(struct lista*)NULL;
	inicio2->nos=0;
	criar_lista(0);
	cont++;
	printf("Digite valores para a segunda lista encadeada. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	ordenar_duas_listas(aux,aux2,inicio2,cont,valor,aux3,aux4);
}
else{
	if(valor>=0&&cont==1){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio2->ini;
		inicio2->ini=aux;
		inicio2->nos++;
		scanf("%d",&valor);
		if(valor<0){
			cont++;
		}
		ordenar_duas_listas(aux,aux2,inicio2,cont,valor,aux3,aux4);
	}
	else{
	if(cont==2){
		aux=inicio->ini;
		cont++;
	}
	if(cont==3){
	if(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
		ordenar_duas_listas(aux,aux2,inicio2,cont,valor,aux3,aux4);
	}
}
	else{
	if(cont==3){
		cont++;
	}
	
	if(cont==4){
	aux->prox=inicio2->ini;
	inicio->nos+=inicio2->nos;
	aux2=(struct lista*)NULL;
	aux=inicio->ini;
	cont++;
}
	if(aux!=(struct lista*)NULL&&cont==5){
		if(aux4==1){
		aux2=aux;
		aux2=aux2->prox;
		aux4=0;
	}
		if(aux2!=(struct lista*)NULL){
			if(aux->valor>aux2->valor){
				aux3=aux->valor;
				aux->valor=aux2->valor;
				aux2->valor=aux3;
			}
			aux2=aux2->prox;
			ordenar_duas_listas(aux,aux2,inicio2,cont,valor,aux3,aux4);
		}
		aux=aux->prox;
		aux4=1;
		if(aux==(struct lista*)NULL){
			cont++;
		}
		ordenar_duas_listas(aux,aux2,inicio2,cont,valor,aux3,aux4);
	}
	else{
	printf("to aqui bb :)\n");
	aux=inicio->ini;
	if(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
		ordenar_duas_listas(aux,aux2,inicio2,cont,valor, aux3,aux4);
	}
	else{
	inicio->fim=aux;
	printf("LISTA CRIADA COM SUCESSO.\n");
	getch();
	system("cls");
}
}
}
}
}
}
*/
