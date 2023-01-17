#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    for(int i=0; i<5; i++){
        printf("%s............%.2f\n",a.p.produtos[i].nome, a.p.produtos[i].valor);
    }

    printf("valor total: %.2f", a.p.valor_acumulado);
}



int main(){
    cardapio *p = criacardapio();
    mostracardapio(*p);
    pessoa a;

    int f[5] = {1,2,3,4,5};
    adicionapedido(*p,&a,f);
    mostrapedido(a);



    return 0;
}
