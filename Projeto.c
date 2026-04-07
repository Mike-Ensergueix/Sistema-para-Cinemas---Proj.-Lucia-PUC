#include <stdio.h>
#include <stdlib.h>

void menu()           //Criacao do menu
{
    int escolha = -1; //variavel para escolha

    do
    {
    /*                impressao do menu                        */
        printf("\n\t-----Sistema de Controle de Assentos------");
        printf("\n\t|  1. Exibir mapa da sala                |");
        printf("\n\t|  2. Vender ingresso manualmente        |");
        printf("\n\t|  3. Cancelar venda                     |");
        printf("\n\t|  4. Sugerir melhor assento disponivel  |");
        printf("\n\t|  5. Verificar fileiras criticas        |");
        printf("\n\t|  6. Mostrar estatisticas gerais        |");
        printf("\n\t|  0. Sair                               |");
        printf("\n\t------------------------------------------");
        printf("\n\n\tDigite para Escolher: ");

        escolha = -1;               //reset para evitar erros de opcao invalida
        scanf("%d", &escolha);      //escolha da opcao
        while (getchar() != '\n');  //limpeza de characteres invalidos (evita loop infinito)

        switch(escolha)
        {
            case 1:
                printf("\n\t1. Exibindo mapa da sala");
                //funcao mostrar mapa
                break;
            case 2:
                printf("\n\t2. Venda de ingresso manual");
                //funcao venda manaul
                break;
            case 3:
                printf("\n\t3. Cancelando venda");
                //funcao cancelar venda
                break;
            case 4:
                printf("\n\t4. Sugerindo melhor assento disponivel");
                //funcao sugerur melhor assento
                break;
            case 5:
                printf("\n\t5. Verificando fileiras criticas");
                //funcao verificar fileiras
                break;
            case 6:
                printf("\n\t6. Mostrando estatisticas gerais");
                //funcao mostrar estatisticas
                break;
            case 0:
                printf("\n\tSaindo...");  //escolha = 0 encerra o programa
                break;
            default:
                printf("\n\tOpcao Invalida!"); //escolha != 0 a 6 opcao invalida
                break;
        }
    } while (escolha != 0);
}
int main()
{
    menu();   //chama o menu
    return 0;
}
