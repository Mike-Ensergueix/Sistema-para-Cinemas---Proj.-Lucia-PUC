//importacao das bibliotecas
#include <stdio.h>
#include <stdlib.h>

//valores atribuidos por diretivas de pré-processador para facilitar substituicoes (por mais que ja sejam definidas no inicio desse projeto)
#define FILEIRAS 10
#define ASSENTOS 8

void exibirMapa(int sala[FILEIRAS][ASSENTOS])   //imprime o MAPA recebendo paramentros da matriz sala
{
    //simulacao de alguns assentos ocupados para teste
    sala[0][0] = sala[0][1] = sala[0][2] = sala[0][3] = sala[0][4] = 1;
    sala[2][0] = sala[2][3] = 1;

    int ocupados;        //contador de assentos ocupados

    printf("\n\t       ");                   //formataçao
    for (int j = 0; j < ASSENTOS; j++)       //loop imprime numeracao dos assentos
        printf("%d   ", j + 1);              //cabecalho das colunas
    printf("\n");                            //formataçao

    for (int i = 0; i < FILEIRAS; i++)       //impressao da matriz por linha
    {
        int ocupados = 0;                        //(re)inicializa contador de assentos ocupados
        for (int j = 0; j < ASSENTOS; j++)       //percorrecao da linha
            if (sala[i][j] == 1) ocupados++;     //faz a soma de assentos ocupados por *linha*


        if (i != 9)  //verifica ultima linha apenas para formataçao
        {
            if (ocupados > ASSENTOS / 2)      //verifica fileiras criticas e imprime numeracao das fileira (antes da matriz) 
                printf("\t F%d*  ", i + 1);   //indica N* fileira crítica
            else
                printf("\t F%d   ", i + 1);   //indica N  fileira}
        } 
        else                                 //mesmo processo de cima com -1 " ".
        {
            if (ocupados > ASSENTOS / 2)     //verifica a ultima fileira e imprime sua numeracao (antes da linha da matriz) 
                printf("\t F%d* ", i + 1);   //indica N* fileira crítica
            else
                printf("\t F%d  ", i + 1);   //indica N  fileira}
        }

        for (int j = 0; j < ASSENTOS; j++)  //percorrecao da linha
        {
            if (sala[i][j] == 0)  //verifica disponibilidade
                printf("[ ] ");   //imprime disponivel
            else
                printf("[X] ");   //imprime ocupado
        }
        printf("(%d/%d)\n", ocupados, ASSENTOS);  //(ocupados/8) contagem por fileira (depois da linha da matriz)
    }      //fim loop matriz

    printf("\n\t [ ] Disponivel   [X] Ocupado   * Fileira critica\n");  //imprime significados
}

void menu(int sala[FILEIRAS][ASSENTOS])           //Criacao do menu recebendo paramentros da matriz sala
{
    int escolha = -1; //variavel para escolha

    do
    {
    /*                   impressao do menu                         */
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

        switch(escolha)            //opcoes
        {
            case 1:
                printf("\n\t1. Exibindo mapa da sala:\n");
                exibirMapa(sala); //chama funcao exibirMapa passando o paramentro da matriz sala
                system("pause");  //pausa antes de voltar ao menu
                break;
            case 2:
                printf("\n\t2. Venda de ingresso manual\n");
                //funcao venda manual
                system("pause");  //pausa antes de voltar ao menu
                break;
            case 3:
                printf("\n\t3. Cancelando venda\n");
                //funcao cancelar venda
                system("pause");  //pausa antes de voltar ao menu
                break;
            case 4:
                printf("\n\t4. Sugerindo melhor assento disponivel\n");
                //funcao sugerur melhor assento
                system("pause");  //pausa antes de voltar ao menu
                break;
            case 5:
                printf("\n\t5. Verificando fileiras criticas\n");
                //funcao verificar fileiras
                system("pause");  //pausa antes de voltar ao menu
                break;
            case 6:
                printf("\n\t6. Mostrando estatisticas gerais\n");
                //funcao mostrar estatisticas
                system("pause");  //pausa antes de voltar ao menu
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

    menu(sala);   //chama o menu passando o parametro da matriz sala
    return 0; //encerra o programa
}
