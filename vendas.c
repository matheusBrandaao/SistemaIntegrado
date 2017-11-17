#include <stdio.h>
#include <stdlib.h>

int quantidade;
int preco;
int total;
int margem;
int icms;
int venda;
char nome[20];
void valorTotal()
{
total = (quantidade*preco);
}

void margemContribuicao()
{
margem = total*0.5;
}

void calculaicms()
{
icms = total*0.17;
icms = icms + margem;
}

void valorVenda()
{
venda = total + margem + icms;
}
int main()
{
printf("Qual o nome do produto?\n");
scanf("%s", nome);
printf("Informe a quantidade do produto:\n");
scanf("%d", &quantidade);
printf("Agora qual é o preço do produto?(Unitario)\n");
scanf("%d", &preco);
void valorTotal();
void margemContribuicao();
void calculaicms();
void valorVenda();
printf("O valor do custo total do %s é de %d reais\n", nome, total);
printf("O valor da margem de contribuição do %s é de %d reais\n", nome, margem);
printf("O valor do ICMS para o produto %s é %d reais\n", nome, icms);
printf("O valor da venda do produto %s é %d reais\n", nome, venda);

}
