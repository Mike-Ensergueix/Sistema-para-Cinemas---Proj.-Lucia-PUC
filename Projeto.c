//importacao das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//valores atribuidos por diretivas de pré-processador para facilitar substituicoes (por mais que ja sejam definidas no inicio desse projeto)
#define FILEIRAS 10
#define ASSENTOS 8
#define TOTALASSENTOS (FILEIRAS*ASSENTOS)

void exibirMapa(int sala[FILEIRAS][ASSENTOS])   //imprime o MAPA recebendo paramentros da matriz sala
{
    printf("\n\t       ");                   //formatacao

    for (int j = 0; j < ASSENTOS; j++)       //loop imprime numeracao dos assentos
    {
        printf("%d   ", j + 1);              //cabecalho das colunas
    }

    printf("\n");                            //formatacao

    for (int i = 0; i < FILEIRAS; i++)       //impressao da matriz por linha
    {
        int ocupados = 0;                        //inicializa contador de assentos ocupados

        for (int j = 0; j < ASSENTOS; j++)       //percorrecao da linha
        {
            if (sala[i][j] == 1)             //soma de assentos ocupados por *linha*
            {
                ocupados++;                  //incremento
            }
        }

        if (i != FILEIRAS - 1)  //verifica ultima linha apenas para formataçao
        {
            if (ocupados >= ASSENTOS * 0.75)   //verifica fileiras criticas (75% ocupado) e imprime numeracao das fileira (antes da matriz)
            {
                printf("\t F%d*  ", i + 1);   //indica N* fileiras críticas
            }
            else
            {
                printf("\t F%d   ", i + 1);   //indica N  fileiras
            }
        }
        else                                 //mesmo processo de cima com -1 " ".
        {
            if (ocupados >= ASSENTOS * 0.75)  //verifica a ultima fileira e imprime sua numeracao (antes da linha da matriz)
            {
                printf("\t F%d* ", i + 1);   //indica N* fileira crítica
            }
            else
            {
                printf("\t F%d  ", i + 1);   //indica N  fileira
            }
        }

        for (int j = 0; j < ASSENTOS; j++)  //percorrecao da linha
        {
            if (sala[i][j] == 0)  //verifica disponibilidade
            {
                printf("[ ] ");   //imprime disponivel
            }
            else
            {
                printf("[X] ");   //imprime ocupado
            }
        }
        printf("(%d/%d)\n", ocupados, ASSENTOS);  //(ocupados/8) contagem por fileira (depois da linha da matriz)
    }      //fim loop matriz
    printf("\n\t       ____________TELA_____________\n");               //imprime distancia da tela
    printf("\n\t [ ] Disponivel   [X] Ocupado   * Fileira critica\n");  //imprime significados
    printf("\n\tDigite enter para continuar");
}

void verificarFileiras(int sala[FILEIRAS][ASSENTOS])
{
    int fileirac = 0, ocp = 0;      //inicia contador fileiras criticas e assentos ocupados total

    for (int i = 0; i < FILEIRAS; i++)       //linha atual
    {
        int ocupados = 0;                        //inicia contador de assentos ocupados por linha


        for (int j = 0; j < ASSENTOS; j++)       //percorre a linha
        {
            if (sala[i][j] == 1)             //soma de assentos ocupados por *linha*
            {
                ocupados++;                  //incremento ocupados por linha
                ocp++;                       //incremento ocupados total
            }
        }

        if (ocupados >= ASSENTOS * 0.75)   //verifica fileiras criticas (75% ocupado) e imprime numeracao das fileiras
            {
                fileirac++;                   //incremento fileira critica
                printf("\t F%d*\n", i + 1);   //indica N* fileira crítica
            }
    }
    printf("\n\tFileiras Criticas Existentes = %d\n", fileirac);            //print fileira criticas total
    printf("\n\tAssentos Disponiveis = %d\n", (TOTALASSENTOS-ocp));   //print fileiras disponiveis
}

void estatisticas(int sala[FILEIRAS][ASSENTOS])
{
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
            menor = i - 1;
        }
    }
    percentual = ((float)ocupados / TOTALASSENTOS) * 100;
    printf("\n\tTotal de assentos:          %d",TOTALASSENTOS);
    printf("\n\tAssentos ocupados:          %d",ocupados);
    printf("\n\tAssentos livres:            %d",livres);
    printf("\n\tPercentual de ocupacao:     %.2f%%",percentual);
    printf("\n\tFileira com maior ocupacao: %d",maior);
    printf("\n\tFileira com menor ocupacao: %d",menor);
    printf("\n\n\tPressione enter para continuar");

}

void insereVenda (int sala[FILEIRAS][ASSENTOS])
{
    int a, b;
    printf("\n\tDigite a fileira (1 a 10):\t");
    scanf("%d",&a);
    printf("\n\tDigite o assento(1 a 8):\t");
    scanf("%d",&b);
    if(sala[a-1][b-1] == 0)
    {
        sala[a-1][b-1] = 1;
        printf("\n\tVenda inserida com sucesso, digite enter para continuar.");
    }
    else
    {
        printf("\n\tAssento ocupado, digite enter para continuar.");
    }
}

void cancelaVenda(int sala[FILEIRAS][ASSENTOS])
{
    int a, b;
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
}

void menu(int sala[FILEIRAS][ASSENTOS])           //Criacao do menu recebendo paramentros da matriz sala
{
    int escolha = -1; //variavel para escolha

    do
    {
    /*                   impressao do menu                         */
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

        escolha = -1;               //reset para evitar erros de opcao invalida
        scanf("%d", &escolha);      //escolha da opcao
        system("cls");
        while (getchar() != '\n');  //limpeza de characteres invalidos (evita loop infinito)

        switch(escolha)            //opcoes
        {
            case 1:
                printf("\n\t1. Exibindo mapa da sala:\n");
                exibirMapa(sala); //chama funcao exibirMapa passando os paramentros da matriz sala
                getchar();
                system("cls");
                break;
            case 2:
                printf("\n\t2. Compra de ingresso manual\n");
                insereVenda(sala);//funcao venda manual
                getchar();
                getchar();
                system("cls");
                break;
            case 3:
                printf("\n\t3. Cancelando Compra\n");
                cancelaVenda(sala);
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
                verificarFileiras(sala);
                getchar();
                system("cls");
                break;
            case 6:
                printf("\n\t6. Mostrando estatisticas gerais\n");
                estatisticas(sala);//funcao mostrar estatisticas
                getchar();
                system("cls");
                break;
            case 0:
                printf("\n\tSaindo...\n");  //escolha = 0 sai do menu
                break;
            default:
                printf("\n\tOpcao Invalida!\n"); //escolha != 0 a 6 opcao invalida
                system("pause");  //pausa antes de voltar ao menu
                break;
        }
    } while (escolha != 0);    //sai da funcao
}

int main()
{
    int sala[FILEIRAS][ASSENTOS] = {0};  //cria a matriz da sala com todos os assentos disponiveis


    menu(sala);   //chama o menu passando os parametros da matriz sala
    return 0; //encerra o programa
}

