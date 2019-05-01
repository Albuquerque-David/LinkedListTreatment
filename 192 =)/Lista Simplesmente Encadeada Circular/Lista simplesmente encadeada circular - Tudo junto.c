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
	printf("[LISTA SIMPLESMENTE ENCADEADA CIRCULAR]\n\n CRIANDO A LISTA.\n\n");
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
	printf("Digite valores para a lista encadeada circular. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	if(valor>=0){
	while(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		scanf("%d",&valor);
	}
	aux=inicio;
	while(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
	}
	aux->prox=inicio;
}
	aux=(struct lista*)NULL;
}

void mostrar_lista(){
	struct lista *aux;
	aux=inicio;
	if(aux==(struct lista*)NULL){
		printf("\nLISTA VAZIA");
	}
	else{
		do{
			printf("%d\t",aux->valor);
			aux=aux->prox;
		}while(aux!=inicio);
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
		do{
			aux=aux->prox;
			if(aux->valor<menor){
				menor=aux->valor;
			}
		}while(aux->prox!=inicio);
	aux=(struct lista*)NULL;
	printf("O menor valor da lista e: %d.\n",menor);
	getch();
	system("cls");
}
}

void maior(){
	struct lista *aux;
	int maior;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		maior=aux->valor;
		do{
			aux=aux->prox;
			if(aux->valor>maior){
				maior=aux->valor;
			}
		}while(aux->prox!=inicio);	
	aux=(struct lista*)NULL;
	printf("O maior valor da lista e: %d.\n",maior);
	getch();
	system("cls");
}
}

void elementos(){
	struct lista *aux;
	aux=inicio;
	int cont=0;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		do{
			cont++;
			aux=aux->prox;
		}while(aux!=inicio);
	aux=(struct lista*)NULL;
	printf("A LISTA POSSUI: %d ELEMENTOS",cont);
	getch();
	system("cls");
}
}

void inserir_final(){
	struct lista *aux;
	int valor;
	aux=inicio;
	printf("Digite um valor para a lista encadeada circular.\n");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		inicio=aux;
		aux->prox=aux;
		aux=(struct lista*)NULL;
		printf("ELEMENTO INSERIDO NO FINAL DA LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		do{
			aux=aux->prox;
		}while(aux->prox!=inicio);
		aux->prox=(struct lista*)malloc(sizeof(struct lista));
		aux=aux->prox;
		aux->valor=valor;
		aux->prox=inicio;
		aux=(struct lista*)NULL;
		printf("ELEMENTO INSERIDO NO FINAL DA LISTA.\n");
		getch();
		system("cls");
	}
}

void media(){
	struct lista *aux;
	int valor;
	int media=0;
	int cont=0;
	aux=inicio;
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		media+=aux->valor;
		cont++;
		do{
			aux=aux->prox;
			cont++;
			media+=aux->valor;
		}while(aux->prox!=inicio);
	printf("A MEDIA DOS ELEMENTOS E: %d\n",media/cont);
	getch();
	system("cls");
}
}

void remover_elemento(){
	struct lista *aux2,*aux;
	int valor;
	aux=inicio;
	printf("Digite o elemento a ser removido da lista encadeada circular");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){ //lista vazia
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(inicio->prox==inicio){ //lista de 1 elemento
			if(inicio->valor==valor){ //existe
				inicio->prox=(struct lista*)NULL;
				free(inicio);
				inicio=(struct lista*)NULL;
				aux=(struct lista*)NULL;
				printf("VALOR REMOVIDO DA LISTA DE 1 ELEMENTO.");
				getch();
				system("cls");
			}
			else{
				if(inicio->valor!=valor){ //nao existe
					printf("VALOR NAO EXISTE NA LISTA DE 1 ELEMENTO.");
					getch();
					system("cls");
					aux=(struct lista*)NULL;
				}
			}			
		}
		else{  //lista de +1 elemento
			aux=inicio; 
			while(aux->valor!=valor&&aux->prox!=inicio){
				aux2=aux;
				aux=aux->prox;
			}
			if(aux->valor!=valor){ //elemento nao existe 
				printf("ELEMENTO NAO EXISTE NA LISTA DE MAIS DE 1 ELEMENTO.\n");
				aux=(struct lista*)NULL;
				getch();
				system("cls");
			}
			else{ //existe
				if(inicio->valor==valor){ //elemento no inicio da lista de + de 1 elemento
					aux=inicio;
					do{
						aux=aux->prox;
					}while(aux->prox!=inicio);
					aux->prox=inicio->prox;
					aux=inicio;
					inicio=aux->prox;
					aux->prox=(struct lista*)NULL;
					free(aux);
					aux=(struct lista*)NULL;
					printf("ELEMENTO REMOVIDO DO INICIO DA LISTA DE MAIS DE 1 ELEMENTO.\n");
					getch();
					system("cls");
					
				}
				else{  //no meio ou fim
					if(aux->prox==inicio){ //no fim
						aux->prox=(struct lista*)NULL;
						free(aux);
						aux2->prox=inicio;
						aux=(struct lista*)NULL;
						aux2=aux;
						printf("ELEMENTO REMOVIDO DO FINAL DA LISTA DE MAIS DE 1 ELEMENTO.\n");
						getch();
						system("cls");
					}
					else{ //no meio da lista
						aux2->prox=aux->prox;
						aux->prox=(struct lista*)NULL;
						free(aux);
						aux=(struct lista*)NULL;
						aux2=aux;
						printf("ELEMENTO REMOVIDO DO MEIO DA LISTA DE MAIS DE 1 ELEMENTO.\n");
						getch();
						system("cls");
					}
				}
		}
	}
	}
	aux=(struct lista*)NULL;
	aux2=aux;
	
}

void inserir_elemento_ordenada(){
	struct lista *aux,*aux2;
	int valor;
	printf("Escreva o elemento a ser inserido na lista ordenada.");
	scanf("%d",&valor);
	if(inicio==(struct lista*)NULL){
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=inicio;
		printf("LISTA VAZIA. VALOR INSERIDO\n");
		aux=(struct lista*)NULL;
		aux2=aux;
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		if(aux->valor>valor){ //inicio da lista
			inicio=(struct lista*)malloc(sizeof(struct lista));
			inicio->valor=valor;
			inicio->prox=aux;
			aux2=aux;
			while(aux2->prox!=aux){
				aux2=aux2->prox;
			}
			aux2->prox=inicio;
			aux=(struct lista*)NULL;
			aux2=aux;
			printf("INSERIDO NO INICIO DA LISTA.");
			getch();
			system("cls");
		}
		else{ //no meio ou no fim
			while(valor>aux->valor&&aux->prox!=inicio){ 
				aux2=aux;
				aux=aux->prox;
			}
			if(valor>aux->valor){ //fim da lista
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=inicio;
				aux=(struct lista*)NULL;
				aux2=aux;
				printf("ELEMENTO INSERIDO NO FINAL DA LISTA ORDENADA.");
				getch();
				system("cls");
			}
			else{
				aux2->prox=(struct lista*)malloc(sizeof(struct lista));
				aux2=aux2->prox;
				aux2->valor=valor;
				aux2->prox=aux;
				aux2=(struct lista*)NULL;
				aux=aux2;
				printf("ELEMENTO INSERIDO NO MEIO DA LISTA ORDENADA.");
				getch();
				system("cls");
			}
		}
	}
	aux=(struct lista*)NULL;
	aux2=aux;
}

void gerar_lista_crescente(){
	int valor;
	apagar_lista();
	void inserir_elemento_ordenada2(int valor){
	struct lista *aux,*aux2;
	if(inicio==(struct lista*)NULL){
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=inicio;
		printf("LISTA VAZIA. VALOR INSERIDO\n");
		aux=(struct lista*)NULL;
		aux2=aux;
		getch();
		system("cls");
	}
	else{
		aux=inicio;
		if(aux->valor>valor){ //inicio da lista
			inicio=(struct lista*)malloc(sizeof(struct lista));
			inicio->valor=valor;
			inicio->prox=aux;
			aux2=aux;
			while(aux2->prox!=aux){
				aux2=aux2->prox;
			}
			aux2->prox=inicio;
			aux=(struct lista*)NULL;
			aux2=aux;
			printf("INSERIDO NO INICIO DA LISTA.");
			getch();
			system("cls");
		}
		else{ //no meio ou no fim
			while(valor>aux->valor&&aux->prox!=inicio){ 
				aux2=aux;
				aux=aux->prox;
			}
			if(valor>aux->valor){ //fim da lista
				aux->prox=(struct lista*)malloc(sizeof(struct lista));
				aux=aux->prox;
				aux->valor=valor;
				aux->prox=inicio;
				aux=(struct lista*)NULL;
				aux2=aux;
				printf("ELEMENTO INSERIDO NO FINAL DA LISTA ORDENADA.");
				getch();
				system("cls");
			}
			else{
				aux2->prox=(struct lista*)malloc(sizeof(struct lista));
				aux2=aux2->prox;
				aux2->valor=valor;
				aux2->prox=aux;
				aux2=(struct lista*)NULL;
				aux=aux2;
				printf("ELEMENTO INSERIDO NO MEIO DA LISTA ORDENADA.");
				getch();
				system("cls");
			}
		}
	}
	aux=(struct lista*)NULL;
	aux2=aux;
}
	printf("ENTRE COM OS ELEMENTOS PARA GERAR A LISTA NA ORDEM CRESCENTE. DIGITE UM VALOR MENOR QUE 0 PARA ENCERRAR.");
	scanf("%d",&valor);
	if(valor<0){
		printf("LISTA VAZIA CRIADA.");
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
		aux->prox=(struct lista*)NULL;
		aux=inicio;
		while(inicio!=(struct lista*)NULL){
			inicio=aux->prox;
			aux->prox=(struct lista*)NULL;
			free(aux);
			aux=inicio;
		}
		inicio=(struct lista*)NULL;
		aux=inicio;
		printf("LISTA APAGADA.\n");
		getch();
		system("cls");
	}
}

void lista_ordem_correta(){
	struct lista *aux;
	apagar_lista();
	int valor;
	printf("ENTRE COM OS VALORES PARA CRIAR A LISTA NA ORDEM CORRETA. DIGITE UM VALOR MENOR QUE 0 PARA ENCERRAR.\n");
	scanf("%d",&valor);
	if(valor<0){
		inicio=(struct lista*)NULL;
		aux=inicio;
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
	}
	else{
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=inicio;
		scanf("%d",&valor);
		aux=inicio;
		while(valor>=0){
			aux->prox=(struct lista*)malloc(sizeof(struct lista));
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=inicio;
			scanf("%d",&valor);
		}
	}
	aux=(struct lista*)NULL;
	printf("LISTA NA ORDEM CORRETA CRIADA COM SUCESSO.\n");
	getch();
	system("cls");
}

void ordenar_duas_listas(){
	struct lista *inicio2;
	struct lista *aux,*aux2;
	int valor,aux3;
	apagar_lista();
	criar_lista();
	inicio2=(struct lista*)NULL;
	aux=inicio2;
	printf("Digite valores para a lista encadeada circular. Digite um valor menor que 0 para parar.\n");
	scanf("%d",&valor);
	if(valor>=0){
	while(valor>=0){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio2;
		inicio2=aux;
		scanf("%d",&valor);
	}
	aux=inicio2;
	while(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
	}
	aux->prox=inicio;
}
	aux=(struct lista*)NULL;
	aux=inicio;
	while(aux->prox!=inicio){
		aux=aux->prox;
	}
	aux->prox=inicio2;
	inicio2=(struct lista*)NULL;
	 //listas já juntadas
	aux=inicio;
	while(aux->prox!=inicio){
		aux2=aux;
		aux2=aux2->prox;
		while(aux2->prox!=inicio){
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


