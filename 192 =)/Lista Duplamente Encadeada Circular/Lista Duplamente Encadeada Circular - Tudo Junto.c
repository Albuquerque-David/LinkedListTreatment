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
	printf("[LISTA DUPLAMENTE ENCADEADA CIRCULAR]\n\n CRIANDO A LISTA.\n\n");
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
	inicio=(struct lista*)NULL;
	printf("Entre com os valores da lista. Digite um negativo para parar.\n");
	scanf("%d",&valor);
	if(valor<0){
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
		inicio->ant=(struct lista*)NULL;
		scanf("%d",&valor);
		while(valor>=0){
			aux=(struct lista*)malloc(sizeof(struct lista));
			aux->prox=inicio;
			aux->prox->ant=aux;
			aux->valor=valor;
			inicio=aux;
			scanf("%d",&valor);
		}
		aux=inicio;
		while(aux->prox!=(struct lista*)NULL){
			aux=aux->prox;
		}
		aux->prox=inicio;
		inicio->ant=aux;
		aux=(struct lista*)NULL;
	}
}

void mostrar_lista(){  //usando prox
	struct lista *aux;
	aux=inicio;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		do{
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}while(aux!=inicio);
	}
	aux=(struct lista*)NULL;
	printf("inicio ant %d\n\n",inicio->ant->valor);
	printf("inicio ant prox %d\n\n",inicio->ant->prox->valor);
	getch();
	system("cls");
} 

/*void mostrar_lista(){ //usando ant
	struct lista *aux;
	aux=inicio;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		while(aux->prox!=inicio){
			aux=aux->prox;
		}
		do{
			printf("[%d]\t",aux->valor);
			aux=aux->ant;
		}while(aux!=inicio->ant);
	}
	aux=(struct lista*)NULL;
	getch();
	system("cls");
} */

void menor(){
	struct lista *aux;
	int m;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio->prox;
		m=inicio->valor;
		while(aux!=inicio){
			if(aux->valor<m){
				m=aux->valor;
			}
			aux=aux->prox;
		}
		printf("O MENOR ELEMENTO DA LISTA E: %d",m);
		getch();
		system("cls");
	}
}

void maior(){
	struct lista *aux;
	int m;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio->prox;
		m=inicio->valor;
		while(aux!=inicio){
			if(aux->valor>m){
				m=aux->valor;
			}
			aux=aux->prox;
		}
		printf("O MAIOR ELEMENTO DA LISTA E: %d",m);
		getch();
		system("cls");
	}
}

void elementos(){
	struct lista *aux;
	int cont=0;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		do{
			cont++;
			aux=aux->prox;
		}while(aux!=inicio);
	printf("O NUMERO DE ELEMENTOS DA LISTA E: %d",cont);
	getch();
	system("cls");
	}
}

void inserir_final(){
	struct lista *aux;
	int valor;
	printf("DIGITE O VALOR QUE DESEJA INSERIR NO FINAL DA LISTA.\n");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){ //lista vazia
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->ant=inicio;
		inicio->prox=inicio;
		getch();
		system("cls");
	}
	else{
		aux=inicio->ant;
		aux->prox=(struct lista*)malloc(sizeof(struct lista));
		aux->prox->ant=aux;
		aux=aux->prox;
		aux->valor=valor;
		aux->prox=inicio;
		inicio->ant=aux;
		printf("VALOR INSERIDO NO FINAL DA LISTA COM SUCESSO.\n");
		getch();
		system("cls");
	}
}

void media(){
	struct lista *aux;
	int m=0;
	int cont=0;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		do{
			m+=aux->valor;
			cont++;
			aux=aux->prox;
		}while(aux!=inicio);
		printf("A MEDIA DOS ELEMENTOS DA LISTA E: %d",m/cont);
		getch();
		system("cls");
		
	}
}

void remover_elemento(){
	struct lista *aux;
	int valor;
	printf("ENTRE COM O VALOR PARA SER REMOVIDO DA LISTA.\n");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio->prox==inicio){ //lista de 1 elemento
			if(inicio->valor==valor){ //existe
				inicio->prox=(struct lista*)NULL;
				inicio->ant=(struct lista*)NULL;
				free(inicio);
				inicio=(struct lista*)NULL;
				printf("ELEMENTO REMOVIDO DA LISTA DE 1 ELEMENTO.\n");
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
			aux=inicio;
			while(aux->valor!=valor&&aux->prox!=inicio){ //+ de 1 elemento
				aux=aux->prox;
			}
			if(aux->valor!=valor){ //nao existe
				printf("ELEMENTO NAO EXISTE NA LISTA DE + DE 1 ELEMENTO.\n");
				getch();
				system("cls");
			}
			else{
				if(inicio->valor==valor){ //inicio da lista
					aux=inicio;
					inicio->ant->prox=inicio->prox;
					inicio->prox->ant=inicio->ant;
					inicio=inicio->prox;
					aux->ant=(struct lista*)NULL;
					aux->prox=(struct lista*)NULL;
					free(aux);
					printf("VALOR REMOVIDO DO INICIO DA LISTA.\n");
					getch();
					system("cls");
				}
				else{
					if(aux->prox==inicio){
						aux->ant->prox=aux->prox;
						inicio->ant=aux->ant;
						aux->ant=(struct lista*)NULL;
						aux->prox=(struct lista*)NULL;
						free(aux);
						printf("ELEMENTO REMOVIDO DO FINAL DA LISTA.\n");
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

void inserir_elemento_ordenada(){
	struct lista *aux;
	int valor;
	printf("ENTRE COM O VALOR A SER INSERIDO NA LISTA ORDENADA.\n");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){ //LISTA VAZIA
		inicio=(struct lista*)malloc(sizeof(struct lista*));
		inicio->ant=inicio;
		inicio->valor=valor;
		inicio->prox=inicio;
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
			inicio->ant=aux->ant;
			inicio->ant->prox=inicio;
			inicio->prox=aux;
			aux->ant=inicio;
			aux=(struct lista*)NULL;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA");
			getch();
			system("cls");
		}
		else{ //no meio ou fim
			aux=inicio;
			while((valor>aux->valor)&&(aux->prox!=inicio)){
				aux=aux->prox;
			}
			if(valor>aux->valor){ //no fim
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=inicio;
				inicio->ant=aux;
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
		inicio=(struct lista*)malloc(sizeof(struct lista*));
		inicio->ant=inicio;
		inicio->valor=valor;
		inicio->prox=inicio;
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
			inicio->ant=aux->ant;
			inicio->ant->prox=inicio;
			inicio->prox=aux;
			aux->ant=inicio;
			aux=(struct lista*)NULL;
			printf("ELEMENTO INSERIDO NO INICIO DA LISTA");
			getch();
			system("cls");
		}
		else{ //no meio ou fim
			aux=inicio;
			while((valor>aux->valor)&&(aux->prox!=inicio)){
				aux=aux->prox;
			}
			if(valor>aux->valor){ //no fim
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux->prox->ant=aux;
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=inicio;
				inicio->ant=aux;
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
	printf("ENTRE COM OS VALORES PARA GERAR A LISTA EM ORDEM CRESCENTE. DIGITE UM VALOR MENOR QUE 0 PARA PARAR.\n");
	scanf("%d",&valor);
	if(valor<0){
		inicio=(struct lista*)NULL;
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		while(valor>=0){
			inserir_elemento_ordenada2(valor);
			scanf("%d",&valor);
		}
		printf("LISTA ORDENADA CRIADA COM SUCESSO.\n");
		getch();
		system("cls");
	}
}

void apagar_lista(){
	struct lista *aux;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio->ant;
		aux->prox=(struct lista*)NULL;
		aux=inicio;
		aux->ant=(struct lista*)NULL;
		while(aux!=(struct lista*)NULL){
			inicio=inicio->prox;
			aux->prox=(struct lista*)NULL;
			aux->ant=(struct lista*)NULL;
			free(aux);
			aux=inicio;
		}
		printf("LISTA ESVAZIADA COM SUCESSO.\n");
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
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->ant=(struct lista*)NULL;
		inicio->valor=valor;
		inicio->prox=(struct lista*)NULL;
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
		aux=inicio;
		while(aux->prox!=(struct lista*)NULL){
			aux=aux->prox;
		}
		aux->prox=inicio;
		inicio->ant=aux;
		aux=(struct lista*)NULL;
		printf("\nLISTA NA ORDEM DIGITADA CRIADA COM SUCESSO");
		getch();
		system("cls");
}	
}

void ordenar_duas_listas(){
	struct lista *aux;
	struct lista *aux2;
	int valor;
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
	while(aux->prox!=inicio){
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
	aux=inicio;
	while(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
	}
	aux->prox=inicio;
	inicio->ant=aux;
	aux=(struct lista*)NULL;
	aux2=(struct lista*)NULL;
}
