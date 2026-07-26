/*//43. Escreva um programa de ajuda para vendedores. A partir de um valor total lido, mostre: 
    * o total a pagar com desconto de 10%; 
    * o valor de cada parcela, no parcelamento de 3 sem juros; 
    * a comissão do vendedor, no caso da venda ser a vista (5% sobre o valor com desconto)
    * a comissão do vendedor, no caso da venda ser parcelada (5% sobre o valor total)*/

#include <stdio.h>

void valida(float n);

int main(){
    float valor, desconto, qtde_parcelas;
    int parcela; 

    printf("Valor do produto: ");
    scanf("%f", &valor);

    valida(valor);

    printf("Forma de parcelamento \n1. À vista \t2.Parcelado\n");
    scanf("%d", &parcela);

    switch (parcela){
    case 1:
        desconto = valor - (valor * 0.10);
        printf("Valor com desconto: R$%.2f\n", desconto);
        printf("Comissão do vendedor: R$%.2f\n", desconto * 0.05);
        break;

    case 2:
        printf("Quantidade de parcelas: ");
        scanf("%f", &qtde_parcelas);

        valida(qtde_parcelas);

        if (qtde_parcelas <= 3){
            printf("Valor da parcela: %.0f vezes de R$%.2f\n", qtde_parcelas, valor / qtde_parcelas);
            printf("Comissão do vendedor: R$%.2f\n", valor * 0.05);
        }
            
        else{
            desconto = valor + (valor * 0.10); //inventei 
            printf("Valor da parcela: %.0f vezes de R$%.2f\n", qtde_parcelas, desconto / qtde_parcelas);
            printf("Comissão do vendedor: R$%.2f\n", desconto * 0.05);
        }
       break;     

    default:
    printf("Opção inválida\n");
        break;
    }

    return 0;
}

void valida(float n){
    if (n <= 0){
        printf("ERRO: Digite novamente: ");
        scanf("%f", &n);

    }
    
}