#include <stdio.h>
#include <stdlib.h>

#define FILEIRAS 10
#define ASSENTOS 8
#define TOTALASSENTOS (FILEIRAS*ASSENTOS)

int main()
{
    int sala[FILEIRAS][ASSENTOS] = {0};

    int escolha = -1;

    do
    {
        printf("\n\t-----Sistema de Controle de Assentos------");
        printf("\n\t|  1. Exibir mapa da sala                |");
        printf("\n\t|  2. Comprar ingresso manualmente       |");
        printf("\n\t|  3. Cancelar compra                    |");
        printf("\n\t|  4. Sugerir melhor assento disponivel  |");
        printf("\n\t|  5. Verificar fileiras criticas        |");
        printf("\n\t|  6. Mostrar estatisticas gerais        |");
        printf("\n\t|  0. Sair                               |");
        printf("\n\t------------------------------------------");
        printf("\n\n\tDigite para Escolher: ");

        escolha = -1;
        scanf("%d", &escolha);
        system("cls");
        while (getchar() != '\n');

        switch(escolha)
        {
            case 1:
                printf("\n\t1. Exibindo mapa da sala:\n");
                printf("\n\t       ");

                    for (int j = 0; j < ASSENTOS; j++)
                        {
                            printf("%d   ", j + 1);
                        }

                        printf("\n");

                    for (int i = 0; i < FILEIRAS; i++)
                        {
                            int ocupados = 0;

                            for (int j = 0; j < ASSENTOS; j++)
                            {
                                if (sala[i][j] == 1)
                                {
                                    ocupados++;
                                }
                            }

                            if (i != FILEIRAS - 1)
                            {
                                if (ocupados >= ASSENTOS * 0.75)
                                {
                                    printf("\t F%d*  ", i + 1);
                                }
                                else
                                {
                                    printf("\t F%d   ", i + 1);
                                }
                            }
                            else
                            {
                                if (ocupados >= ASSENTOS * 0.75)
                                {
                                    printf("\t F%d* ", i + 1);
                                }
                                else
                                {
                                    printf("\t F%d  ", i + 1);
                                }
                            }

                            for (int j = 0; j < ASSENTOS; j++)
                            {
                                if (sala[i][j] == 0)
                                {
                                    printf("[ ] ");
                                }
                                else
                                {
                                    printf("[X] ");
                                }
                            }
                            printf("(%d/%d)\n", ocupados, ASSENTOS);
                        }      //fim loop matriz
                        printf("\n\t       ____________TELA_____________\n");
                        printf("\n\t [ ] Disponivel   [X] Ocupado   * Fileira critica\n");
                        printf("\n\tDigite enter para continuar");

                getchar();
                system("cls");
                break;
            case 2:
                printf("\n\t2. Compra de ingresso manual\n");

                int a, b;
                printf("\n\tDigite a fileira (1 a 10):\t");
                scanf("%d",&a);
                printf("\n\tDigite o assento(1 a 8):\t");
                scanf("%d",&b);
                while (getchar() != '\n');
                if(sala[a-1][b-1] == 0)
                {
                    sala[a-1][b-1] = 1;
                    printf("\n\tVenda inserida com sucesso, digite enter para continuar.");
                }
                else
                {
                    printf("\n\tAssento ocupado, digite enter para continuar.");
                }

                getchar();
                getchar();
                system("cls");
                break;
            case 3:
                printf("\n\t3. Cancelando Compra\n");

                printf("\n\tDigite a fileira (1 a 10):\t");
                scanf("%d",&a);
                printf("\n\tDigite o assento(1 a 8):\t");
                scanf("%d",&b);
                if(sala[a-1][b-1] == 1)
                {
                    sala[a-1][b-1] = 0;
                    printf("\n\tCompra cancelada com sucesso, digite enter para continuar.");
                }
                else
                {
                    printf("\n\tO assento nao esta ocupado, digite enter para continuar.");
                }

                getchar();
                getchar();
                system("cls");
                break;
            case 4:
                printf("\n\t4. Sugerindo melhor assento disponivel\n");
                getchar();
                system("cls");
                break;
            case 5:
                printf("\n\t5. Verificando fileiras criticas\n");
                int fileirac = 0, ocp = 0;

                for (int i = 0; i < FILEIRAS; i++)
                {
                    int ocupados = 0;


                    for (int j = 0; j < ASSENTOS; j++)
                    {
                        if (sala[i][j] == 1)
                        {
                            ocupados++;
                            ocp++;
                        }
                    }

                    if (ocupados >= ASSENTOS * 0.75)
                        {
                            fileirac++;
                            printf("\t F%d*\n", i + 1);
                        }
                }
                printf("\n\tFileiras Criticas Existentes = %d\n", fileirac);
                printf("\n\tAssentos Disponiveis = %d\n", (TOTALASSENTOS-ocp));
                getchar();
                system("cls");
                break;
            case 6:
                printf("\n\t6. Mostrando estatisticas gerais\n");
                    int ocupados = 0, livres = 0, cont = 0, maior = 0, menor = 0, max_ocup = 0, min_ocup = ASSENTOS;
                float percentual;


                for(int i = 0; i < FILEIRAS; i++)
                {
                    cont = 0;

                    for(int j = 0; j < ASSENTOS; j++)
                    {
                         if (sala[i][j] == 0)
                        {
                            livres++;
                        }
                        if(sala[i][j] == 1)
                        {
                            ocupados ++;
                            cont++;
                        }
                    }
                    if(cont > max_ocup)
                    {
                        max_ocup = cont;
                        maior = i + 1;
                    }
                    if(cont < min_ocup)
                    {
                        min_ocup = cont;
                        menor = i + 1;
                    }
                }
                percentual = ((float)ocupados / TOTALASSENTOS) * 100;
                printf("\n\tTotal de assentos:          %d",TOTALASSENTOS);
                printf("\n\tAssentos ocupados:          %d",ocupados);
                printf("\n\tAssentos livres:            %d",livres);
                printf("\n\tPercentual de ocupacao:     %.2f%%",percentual);
                printf("\n\tFileira com maior ocupacao: F%d",maior);
                printf("\n\tFileira com menor ocupacao: F%d",menor);
                printf("\n\n\tPressione enter para continuar");

                getchar();
                system("cls");
                break;
            case 0:
                printf("\n\tSaindo...\n");
                break;
            default:
                printf("\n\tOpcao Invalida!\n");
                system("pause");
                system("cls");
                break;
        }
    } while (escolha != 0);

    return 0;
}
