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
			inserir_final(inicio);
		}
		if(controle==6){
			media(inicio,0,0);
		}
		if(controle==7){
			remover_elemento(inicio,inicio,0,0);
		}
		if(controle==8){
			inserir_elemento_ordenada(inicio, inicio, 0,0,0);
		}
		if(controle==9){
			gerar_lista_crescente(0);
		}
		if(controle==10){
			apagar_lista(inicio,0);
		}
		if(controle==11){
			lista_ordem_correta(inicio,0);
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
	if(cont==0){
	inicio=(struct lista*)NULL;
	cont++;
	printf("Digite valores para a lista encadeada circular. Digite um valor menor que 0 para parar.\n");
}
	if(cont==1){
		scanf("%d",&valor);
	}
	if(valor>=0&&cont==1){
		aux=(struct lista*)malloc(sizeof(struct lista));
		aux->valor=valor;
		aux->prox=inicio;
		inicio=aux;
		criar_lista(cont,aux);
	}
	else{
	cont++;
	if(cont==2){
	aux=inicio;
	cont++;
}
	if(aux!=(struct lista*)NULL){
	if(aux->prox!=(struct lista*)NULL){
		aux=aux->prox;
		criar_lista(cont,aux);
	}
	if(aux->prox==(struct lista*)NULL){
	aux->prox=inicio;
}
}
	aux=(struct lista*)NULL;
}
}

void mostrar_lista(struct lista *aux){
	if(inicio==(struct lista*)NULL){
		printf("\nLISTA VAZIA");
		getch();
		system("cls");
	}
	else{
			printf("%d\t",aux->valor);
			aux=aux->prox;
			if(aux!=inicio){
				mostrar_lista(aux);
			}
	aux=(struct lista*)NULL;
	getch();
	system("cls");
}
}

void menor(struct lista *aux, int m){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(aux==inicio){
			m=inicio->valor;
		}
			aux=aux->prox;
			if(aux->valor<m){
				m=aux->valor;
			}
			if(aux->prox!=inicio){
				menor(aux,m);
			}
		else{
	aux=(struct lista*)NULL;
	printf("O menor valor da lista e: %d.\n",m);
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
			m=inicio->valor;
		}
			aux=aux->prox;
			if(aux->valor>m){
				m=aux->valor;
			}
			if(aux->prox!=inicio){
				maior(aux,m);
			}
		else{
	aux=(struct lista*)NULL;
	printf("O maior valor da lista e: %d.\n",m);
	getch();
	system("cls");
}
}
}

void elementos(struct lista *aux, int cont){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
			cont++;
			aux=aux->prox;
			if(aux!=inicio){
				elementos(aux,cont);
			}
			else{

	aux=(struct lista*)NULL;
	printf("A LISTA POSSUI: %d ELEMENTOS",cont);
	getch();
	system("cls");
}
}
}

void inserir_final(struct lista *aux, int valor){
	if(aux==inicio){
	printf("Digite um valor para a lista encadeada circular.\n");
	scanf("%d",&valor);
}	
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
			aux=aux->prox;
		if(aux->prox!=inicio){
			inserir_final(aux,valor);
		}
		else{
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
}

void media(struct lista *aux, int m, int cont){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		m+=aux->valor;
		cont++;
			if(aux->prox!=inicio){
				media(aux->prox,m,cont);
			}
			else{
	printf("A MEDIA DOS ELEMENTOS E: %d\n",m/cont);
	getch();
	system("cls");
}	
}
}

void remover_elemento(struct lista *aux, struct lista *aux2, int valor, int cont){
	if(cont==0){
	printf("Digite o elemento a ser removido da lista encadeada circular");
	scanf("%d",&valor);
	cont++;
}
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
			if(aux->valor!=valor&&aux->prox!=inicio&&cont==1){
				aux2=aux;
				aux=aux->prox;
				remover_elemento(aux,aux2,valor,cont);
			}
            if(cont==1){
            	cont++;
			}
			if(aux->valor!=valor&&cont==2){ //elemento nao existe 
				printf("ELEMENTO NAO EXISTE NA LISTA DE MAIS DE 1 ELEMENTO.\n");
				aux=(struct lista*)NULL;
				getch();
				system("cls");
			}
			else{   
			if(cont==2){
			cont++;
			}
			 //existe
				if(inicio->valor==valor){ //elemento no inicio da lista de + de 1 elemento
					if(cont==3){
						aux=inicio;
						cont++;
					}
					if(aux->prox!=inicio){
						aux=aux->prox;
						remover_elemento(aux,aux2,valor,cont);
					}
					else{
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

void inserir_elemento_ordenada(struct lista *aux, struct lista *aux2, int valor, int cont, int cont2){
	if(cont==0){
	printf("Escreva o elemento a ser inserido na lista ordenada.");
	scanf("%d",&valor);
	cont++;
}
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
		if(aux->valor>valor&&cont2==0){ //inicio da lista
			if(cont==1){
			inicio=(struct lista*)malloc(sizeof(struct lista));
			inicio->valor=valor;
			inicio->prox=aux;
			aux2=aux;
		    cont++;
		}
			if(aux2->prox!=aux){
				aux2=aux2->prox;
				inserir_elemento_ordenada(aux,aux2,valor,cont,cont2);
			}
			else{
			aux2->prox=inicio;
			aux=(struct lista*)NULL;
			aux2=aux;
			printf("INSERIDO NO INICIO DA LISTA.");
			getch();
			system("cls");
		}
		}
		else{ //no meio ou no fim
			if(valor>aux->valor&&aux->prox!=inicio){ 
				aux2=aux;
				aux=aux->prox;
				cont2++;
				inserir_elemento_ordenada(aux,aux2,valor,cont,cont2);
			}
			else{
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
	}
	aux=(struct lista*)NULL;
	aux2=aux;
}

void gerar_lista_crescente(int valor){
	void inserir_elemento_ordenada2(struct lista *aux, struct lista *aux2, int valor, int cont, int cont2){
	if(cont==0){
	cont++;
}
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
		if(aux->valor>valor&&cont2==0){ //inicio da lista
			if(cont==1){
			inicio=(struct lista*)malloc(sizeof(struct lista));
			inicio->valor=valor;
			inicio->prox=aux;
			aux2=aux;
		    cont++;
		}
			if(aux2->prox!=aux){
				aux2=aux2->prox;
				inserir_elemento_ordenada2(aux,aux2,valor,cont,cont2);
			}
			else{
			aux2->prox=inicio;
			aux=(struct lista*)NULL;
			aux2=aux;
			printf("INSERIDO NO INICIO DA LISTA.");
			getch();
			system("cls");
		}
		}
		else{ //no meio ou no fim
			if(valor>aux->valor&&aux->prox!=inicio){ 
				aux2=aux;
				aux=aux->prox;
				cont2++;
				inserir_elemento_ordenada2(aux,aux2,valor,cont,cont2);
			}
			else{
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
	}
	aux=(struct lista*)NULL;
	aux2=aux;
}
	printf("ENTRE COM OS ELEMENTOS PARA GERAR A LISTA NA ORDEM CRESCENTE. DIGITE UM VALOR MENOR QUE 0 PARA ENCERRAR.");
	scanf("%d",&valor);
	if(valor>=0){
		inserir_elemento_ordenada2(inicio,inicio,valor,0,0);
	    gerar_lista_crescente(valor);
	}

}

void apagar_lista(struct lista *aux, int cont){
	if(inicio==(struct lista*)NULL){
		printf("LISTA VAZIA.\n");
		getch();
		system("cls");
	}
	else{
		if(aux->prox!=inicio&&cont==0){
			aux=aux->prox;
			apagar_lista(aux,0);
		}
		else{
		if(cont==0){
		aux->prox=(struct lista*)NULL;
		cont++;
	}
	    aux=inicio;
		if(inicio!=(struct lista*)NULL){
			inicio=aux->prox;
			aux->prox=(struct lista*)NULL;
			free(aux);
			aux=inicio;
			apagar_lista(aux,cont);
		}
		else{
		inicio=(struct lista*)NULL;
		aux=inicio;
		printf("LISTA APAGADA.\n");
		getch();
		system("cls");
	}
	}
	}
}

void lista_ordem_correta(struct lista *aux, int cont){
    if(cont==0){
	apagar_lista(inicio,0);
}
	int valor;
	if(cont==0){
	printf("ENTRE COM OS VALORES PARA CRIAR A LISTA NA ORDEM CORRETA. DIGITE UM VALOR MENOR QUE 0 PARA ENCERRAR.\n");
	scanf("%d",&valor);
	if(valor<0){
		inicio=(struct lista*)NULL;
		aux=inicio;
		printf("LISTA VAZIA CRIADA.\n");
		getch();
		system("cls");
		cont++;
	}
	else{
		inicio=(struct lista*)malloc(sizeof(struct lista));
		inicio->valor=valor;
		inicio->prox=inicio;
		cont++;
		lista_ordem_correta(aux,cont);
	}
}
    else{
    	scanf("%d",&valor);
		if(cont==1){
		aux=inicio;
		cont++;
	}
		if(valor>=0){
			aux->prox=(struct lista*)malloc(sizeof(struct lista));
			aux=aux->prox;
			aux->valor=valor;
			aux->prox=inicio;
            lista_ordem_correta(aux,cont);
		}
		else{
			aux=(struct lista*)NULL;
	        printf("LISTA NA ORDEM CORRETA CRIADA COM SUCESSO.\n");
	        getch();
        	system("cls");
		}
	}
}

void ordenar_duas_listas(){
	struct lista *inicio2;
	struct lista *aux,*aux2;
	int valor,aux3;
	apagar_lista(inicio,0);
	criar_lista(0,inicio);
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

