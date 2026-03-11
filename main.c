#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int tipoVeiculo, tipoSeguro, idade, eixos;
    float valorBase = 0, adicionalCat = 0, valorFinal;
    float adicionalIdade = 0;
    float  custoCobertura = 0, valorTotal;

    printf("--- SISTEMA DE CALCULO DE SEGURO ---\n");
    //1. Escolha do Veiculo
    do{
        printf("Selecione o tipo do veiculo:\n");
        printf("1. Passeio\n2. Carga Pesada\n3. Caminhonete\n4. Motocicleta (<1000cc)\n5. Motocicleta (1000cc+)\n");
        printf("Opcao: ");
        if(scanf("%d",&tipoVeiculo)!=1){
            while(getchar()!= '\n');//limpar o erro se o usuario digitar letra
        }
        if(tipoVeiculo < 1 || tipoVeiculo > 5){
            printf("[ERRO] Opcao invalida! Tente novamente.\n");
        }
    }while(tipoVeiculo < 1 || tipoVeiculo > 5);


    //Definir valor base e adicional categoria
    if(tipoVeiculo >=4){
        valorBase = 1200.00; //motos
        if (tipoVeiculo ==4) adicionalCat = valorBase * 0.80; //80%
        else adicionalCat = valorBase * 0.90;//90%
    }else{
        valorBase = 1000.00; //Demais
        if(tipoVeiculo == 1) adicionalCat = valorBase * 0.10; //10%
        else if (tipoVeiculo == 2) adicionalCat = valorBase * 0.20; //20%
        else  adicionalCat = valorBase * 0.33; //33%

    }
    printf("Digite a idade do condutor:");
    scanf("%d", &idade);
    if (idade <=25) adicionalIdade = valorBase * 0.15;
    else if (idade <=30) adicionalIdade = valorBase * 0.10;
    else  adicionalIdade = valorBase * 0.05;

    printf("Selecione o seguro:\n1. Basico\n2. Parcial\n3. Completo\n");
    scanf("%d", &tipoSeguro);

   if (tipoVeiculo == 2 || tipoVeiculo == 3){
     printf("Quantidade de eixos:");
    scanf("%d", &eixos);
    if (tipoSeguro == 1) custoCobertura = (valorBase*0.03)*eixos;
    else if (tipoSeguro == 2) custoCobertura = (valorBase*0.05)*eixos;
    else custoCobertura = (valorBase* 0.10)*eixos;
   }else{
   if (tipoVeiculo == 1){
    if(tipoSeguro == 1 || tipoSeguro == 2) custoCobertura= 2.00;
    else custoCobertura = 10.00;
}





valorFinal = valorBase + adicionalCat + adicionalIdade;

    printf("Valor final do seguro: R$ %.2f\n", valorFinal);





}
}
