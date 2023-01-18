#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#define  MAX  10

//struct de produtos
typedef struct Produto{
    int id;
    char nome[20];
    float valor;

}produto;

//struct de chocolates
typedef struct Chocolate{
    int id;
    char sabor[20];
}chocolate;

//struct de pedido
typedef struct Pedido{
    produto produtos[5];
    float valor_acumulado;
    chocolate chocolate;

}pedido;
//struct das pessoas no restaurante
typedef struct Pessoa{
    char nome[20];
    pedido p;
}pessoa;

typedef struct Cardapio{
   produto produtos[10];
}cardapio;

//criar cardapio para uso
cardapio *criacardapio(){

  cardapio *a = malloc(sizeof(cardapio));

  for(int i=0; i<10; i++){
    a->produtos[i].id = i;

    }


  strcpy(a->produtos[0].nome, "Suco");
  a->produtos[0].valor = 5.00;

  strcpy(a->produtos[1].nome, "Cafe");
  a->produtos[1].valor = 2.00;

  strcpy(a->produtos[2].nome, "Vitamina");
  a->produtos[2].valor = 8.00;

  strcpy(a->produtos[3].nome, "Refrigerante");
  a->produtos[3].valor = 4.00;

  strcpy(a->produtos[4].nome, "Agua");
  a->produtos[4].valor = 2.00;

  strcpy(a->produtos[5].nome, "Batata Frita");
  a->produtos[5].valor= 16.00;

  strcpy(a->produtos[6].nome, "Jantinha");
  a->produtos[6].valor= 18.00;

  strcpy(a->produtos[7].nome, "Hamburguer");
  a->produtos[7].valor= 23;

 strcpy(a->produtos[8].nome, "Parmegiana");
  a->produtos[8].valor= 32.00;

 strcpy(a->produtos[9].nome, "File Mignon");
  a->produtos[9].valor= 45.00;


  return a;

}

chocolate *criachocolate(){

   chocolate *a = malloc(sizeof(chocolate)*10);

  for(int i=0; i<10; i++){
     a[i].id= i;

    }

  strcpy(a[0].sabor, "Bubble");
  strcpy(a[1].sabor, "Suflair");
  strcpy(a[2].sabor, "Serenata");
  strcpy(a[3].sabor, "Ouro Branco");
  strcpy(a[4].sabor, "Sonho de Valsa");
  strcpy(a[5].sabor, "KitKat");
  strcpy(a[6].sabor, "Bis");
  strcpy(a[7].sabor, "Snickers");
  strcpy(a[8].sabor, "Diamante Negro");
  strcpy(a[9].sabor, "Laka Oreo");

  return a;
}





void adicionapedido(cardapio a, pessoa *pessoa, int *idproduto){//adiciona todos items pedidos para pessoa ja calculando seu valor total
    pessoa->p.valor_acumulado = 0;
     for(int i=0; i<5; i++){
        for(int j=0; j<10; j++){
            if(a.produtos[j].id == idproduto[i]){
                pessoa->p.produtos[i].id = a.produtos[j].id;
                strcpy(pessoa->p.produtos[i].nome, a.produtos[j].nome);
                pessoa->p.produtos[i].valor = a.produtos[j].valor;
                float conta = (a.produtos[j].valor);
                strcpy(pessoa->p.chocolate.sabor,"Nenhum");
                pessoa->p.valor_acumulado += conta;
            }
        }
    }
}
void mostracardapio(cardapio a){//printa todos itens cadastrados no cardapio
    for(int i=0; i<10; i++){
    printf("%d.%s - R$%.2f \n", a.produtos[i].id, a.produtos[i].nome, a.produtos[i].valor);
    }


}

void mostrapedido(pessoa a){//mostra todos pedidos feitos pelo cliente alem de mostrar o valor total a ser pago

 if(a.nome != NULL){
    printf("COMANDA - %s\n",a.nome);
 }
 printf("---------------------------------\n");
    for(int i=0; i<5; i++){
        printf("%s............%.2f\n",a.p.produtos[i].nome, a.p.produtos[i].valor);
    }

    printf("valor total: %.2f\n", a.p.valor_acumulado);
    printf("chocolate: %s\n", a.p.chocolate.sabor);
    printf("---------------------------------\n");
}

// TAD PILHA ----------------------------------------------------------------------------------------------------------------------------
struct pilha {
    chocolate elementos[MAX];
    int topo;   // posicao onde esta o topo da pilha
};


typedef struct pilha Pilha;

Pilha *criarP(){
    Pilha *p;

    p = (Pilha *) malloc(sizeof(Pilha));
	if (p != NULL) { // alocou corretamente
		 p->topo = -1;
	}

    return p;

}

void destruiP(Pilha *p){
    if (p != NULL) free(p);
}

bool Pvazia(Pilha p){
    if (p.topo == -1) return true;
    else return false;

//    return ((p.topo == -1) ? true : false);
//    return (p.topo == -1);
}

bool Pcheia(Pilha p){
    if (p.topo == (MAX - 1)) return true;
    else return false;

    // MAX eh o total de elementos (no caso, 10)
    // o Topo vai de -1 (vazia) a 9 (cheia)
    // entao, eh cheia se Topo == MAX - 1
}

bool empilharP(Pilha *p, chocolate a){
    bool deuCerto;

    if (Pcheia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        p->topo = p->topo + 1;
        p->elementos[ p->topo ] = a;
        deuCerto = true;
        return deuCerto;
    }
}

bool desempilharP(Pilha *p, chocolate *a){
    bool deuCerto;

    if (Pvazia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        *a = p->elementos[ p->topo ];
        p->topo = p->topo - 1;
        deuCerto = true;
        return deuCerto;
    }

}

// TAD FILA ----------------------------------------------------------------------------------------------------------------------------
struct fila {
    pessoa clientes[MAX]; // conjunto de elementos
    int n_elem;		 // numero de elementos
    int primeiro;	 // posicao do primeiro elem
    int final;		 // primeira posicao livre
};

typedef struct fila Fila;

Fila *criarF(){
	Fila *F;

	F = (Fila *) malloc(sizeof(Fila));
	if (F != NULL) { // alocou corretamente
		F->n_elem = 0;
		F->primeiro = 0;
		F->final = 0;
	}

	return F;
}

void destruirF(Fila *F){
    if (F != NULL) free(F);
}

bool Fvazia(Fila *F){
    if (F->n_elem == 0) return true;
    else return false;
}

bool Fcheia(Fila *F){
    if (F->n_elem == MAX) return true;
    else return false;
}

bool insereF(Fila *F, pessoa a){
	bool deuCerto;

	if (Fcheia(F) == true) {
		deuCerto = false;
		return deuCerto;
	}

	// senao:
	deuCerto = true;
	F->clientes[F->final] = a;

	F->n_elem = F->n_elem + 1;

	if (F->final == (MAX-1)) F->final = 0;
	else F->final = F->final + 1;

	return deuCerto;
}

bool retiraF(Fila *F, pessoa *a){
	bool deuCerto;

	if (Fvazia(F) == true) {
		deuCerto = false;
		return deuCerto;
	}

	// senao:
	deuCerto = true;
	*a = F->clientes[F->primeiro];
	F->n_elem = F->n_elem - 1;

	if (F->primeiro == (MAX - 1)) F->primeiro = 0;
	else F->primeiro = F->primeiro + 1;

	return deuCerto;
}



int main(){
    cardapio *p = criacardapio();
    mostracardapio(*p);
    chocolate *choco = criachocolate();
    Pilha *pilha = criarP();

    for(int i = 0; i<10;i++){
        empilharP(pilha,choco[i]);
    }
    pessoa carlos;
    pessoa ana;
    pessoa a;
    strcpy(carlos.nome,"Carlos");
    strcpy(ana.nome,"Ana");


    int g[5] ={2,9,8,7,6};
     adicionapedido(*p,&carlos,g);
     int f[5] ={0,4,3,7,5};
     adicionapedido(*p,&ana,f);
     Fila *fila = criarF();
     insereF(fila,carlos);
     insereF(fila,ana);
     mostrapedido(fila->clientes[0]);

    while(!Fvazia(fila)){
       retiraF(fila,&a);
       desempilharP(pilha,&(a.p.chocolate));
       mostrapedido(a);
    }



    return 0;
}
