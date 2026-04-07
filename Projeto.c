#include <stdio.h>
#include <stdlib.h>

void menu()
{
    int escolha = -1;

    do
    {
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
        scanf("%d", &escolha);


        switch(escolha)
        {
            case 1:
                printf("\n\t1. Exibindo mapa da sala");
                break;
            case 2:
                printf("\n\t2. Venda de ingresso manual");
                break;
            case 3:
                printf("\n\t3. Cancelando venda");
                break;
            case 4:
                printf("\n\t4. Sugerindo melhor assento disponivel");
                break;
            case 5:
                printf("\n\t5. Verificando fileiras criticas");
                break;
            case 6:
                printf("\n\t6. Mostrar estatisticas gerais");
                break;
            case 0:
                printf("\n\tSaindo...");
                break;
            default:
                printf("\n\tOpcao Invalida!");
                break;
        }
    } while (escolha != 0);
}
int main()
{
    menu();
    return 0;
}