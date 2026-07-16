#include <stdio.h>

int menu(){
    // menu de opção
    int opcao;
    printf("1 - calcular taxa de variação\n2 - Classificar consumo atual\n3 - Sair\n");
    scanf("%d", &opcao);

    return opcao;
    }
// classificando consumo
    int classifica_consumo(float consumo){
        int alerta_consumo;

        if(consumo <= 100){
            alerta_consumo = 1;
        } else if(consumo > 100 && consumo <= 250){
            alerta_consumo = 2;
        } else if(consumo > 250 && consumo <= 400){
            alerta_consumo = 3;
        } else {
            alerta_consumo = 4;
        }

        return alerta_consumo;

    }

    float calcula_valor_conta(float consumo, int alerta_consumo){
        float preco;
        switch (alerta_consumo) {
                case 1:
                printf("Consumo baixo.\n");
                preco = 0.60;
                break;
                case 2:
                printf("Consumo médio.\n");
                preco = 0.75;
                break;
                case 3:
                printf("Consumo alto.\n");
                preco = 0.90;
                break;
                case 4:
                printf("Consumo muito alto.\n");
                preco = 1.05;
                break;
        }

        return preco;
    }
 // calcula taxa de variacao
    float calcula_taxa_variacao(float anterior, float atual){
        float taxa;

        taxa =  100 * ((atual - anterior) / anterior);
        if (taxa < 0){
            printf("houve diminuição no consumo.\n");
        } else if (taxa > 0) {
            printf("Houve aumento no consumo.\n");
        } else {
            printf("Não houve variação");
        }

        return taxa;


    }


int main() {
    float preco, consumo, atual, anterior;
    int opcao, alerta_consumo;
    int flag = 0;
// verificando antes da condicao
    do{
        opcao = menu();
        //switch case para escolher a opção.
        switch(opcao){
            case 3:
                // flag para sair do loop
                flag = 1;
                printf("encerrando");
                break;
            case 2:
                printf("Digite o consumo: \n");
                scanf("%f", &consumo);
                alerta_consumo = classifica_consumo(consumo);
                preco = calcula_valor_conta(consumo, alerta_consumo);
                printf("Valor aproximado da conta: R$%.2f\n", consumo * preco);
                break;
            case 1:
                printf("Digite o consumo: \n");
                scanf("%f", &atual);

                printf("Digite o consumo do mes anterior: \n");
                scanf("%f", &anterior);

                printf("taxa de variação: %.2f\n", calcula_taxa_variacao(anterior, atual));

        }




    } while(flag == 0);



    return 0;
}
