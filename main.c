#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#define  MAX  5

//struct de produtos
typedef struct Produto{
    int id;
    char nome[20];
    float valor;

}produto;


//struct de pedido
typedef struct Pedido{
    produto produtos[5];
    float valor_acumulado;
    char chocolate[20];

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

void adicionapedido(cardapio a, pessoa *pessoa, int *idproduto){
    pessoa->p.valor_acumulado = 0;
     for(int i=0; i<5; i++){
        for(int j=0; j<10; j++){
            if(a.produtos[j].id == idproduto[i]){
                pessoa->p.produtos[i].id = a.produtos[j].id;
                strcpy(pessoa->p.produtos[i].nome, a.produtos[j].nome);
                pessoa->p.produtos[i].valor = a.produtos[j].valor;
                float conta = (a.produtos[j].valor);
                pessoa->p.valor_acumulado += conta;
            }
        }
    }
}
void mostracardapio(cardapio a){
    for(int i=0; i<10; i++){
    printf("%d.%s - R$%.2f \n", a.produtos[i].id, a.produtos[i].nome, a.produtos[i].valor);
    }


}

void mostrapedido(pessoa a){

 printf("---------------------------------\n");
    for(int i=0; i<5; i++){
        printf("%s............%.2f\n",a.p.produtos[i].nome, a.p.produtos[i].valor);
    }

    printf("valor total: %.2f\n", a.p.valor_acumulado);
    printf("---------------------------------\n");
}


struct pilha {
    char elementos[MAX];
    int topo;   // posicao onde estah o topo da pilha
};

typedef struct pilha Pilha;

void criarP(Pilha *p){
    //(*p).topo = -1
    p->topo = -1;
}

void destruirP(Pilha *p){
    //(*p).topo = -1
    p->topo = -1;
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

bool empilharP(Pilha *p, char X){
    bool deuCerto;

    if (Pcheia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        p->topo = p->topo + 1;
        p->elementos[ p->topo ] = X;
        deuCerto = true;
        return deuCerto;
    }
}
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
		// *deuCerto = true;
		F->n_elem = 0;
		F->primeiro = 0;
		F->final = 0;
	} // else *deuCerto = false;

	return F;
}

void destruirF(Fila *F){
    if (F != NULL) free(F);
}

bool Fvazia(Fila *F)
{
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
	*a = F->clientes[F->primeiro ];
	F->n_elem = F->n_elem - 1;

	if (F->primeiro == (MAX - 1)) F->primeiro = 0;
	else F->primeiro = F->primeiro + 1;

	return deuCerto;
}

bool desempilharF(Pilha *p, char *X)
{
    bool deuCerto;

    if (Pvazia(*p) == true) {
        deuCerto = false;
        return deuCerto;
    } else {
        *X = p->elementos[ p->topo ];
        p->topo = p->topo - 1;
        deuCerto = true;
        return deuCerto;
    }

}



int main(){
    cardapio *p = criacardapio();
    mostracardapio(*p);
    pessoa a;

    int f[5] = {1,2,3,4,5};
    adicionapedido(*p,&a,f);
    mostrapedido(a);
    Fila *fila = criarF();
    insereF(fila,a);
    mostrapedido(fila->clientes[0]);





    return 0;
}
