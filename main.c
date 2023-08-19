#include <stdio.h>
#include <stdlib.h>

int colunas = 13;
int linhas = 0;

void printarMatriz(int **matriz, int linhas, int colunas)
{
    system("cls");
    for (int i = 0; i <= linhas; i++)
    {
        for (int j = 0; j <= colunas; j++)
        {
            if (i == 0 && j == 0)
            {
                printf("| 0 \t||");
            }
            else if (j == 0)
            {
                printf("| %d \t||", matriz[i][j]);
            }
            else if (j == colunas && i == 0)
            {
                printf(" Total |");
            }
            else
            {
                printf(" %d \t|", matriz[i][j]);
            }
        }
        printf("\n");
    }
    printf("Precione qualquer tecla para continuar... ");
    getchar();
}

int **criarMatriz()
{
    printf("Informe o numero de linhas: ");
    scanf("%d", &linhas);
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    int soma[linhas];
    for (int i = 0; i <= linhas; i++)
    {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        system("cls");
        for (int j = 0; j <= colunas; j++)
        {
            if (i == 0)
            {
                matriz[i][j] = j;
                soma[i] = 0;
            }
            else if (j == 0)
            {
                matriz[i][j] = i;
                soma[i] = 0;
            }
            else if (j == colunas)
            {
                matriz[i][j] = soma[i];
            }
            else
            {
                printf("Linha: %d e Coluna: %d \n", i, j);
                printf("Informe o valor para a posicao: ");
                scanf("%d", &matriz[i][j]);
                soma[i] += matriz[i][j];
            }
        }
    }
    return matriz;
}

void liberarMatriz(int **matriz, int linhas)
{
    for (int i = 0; i <= linhas; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void menu(int **matrizInicial)
{
    int **matriz = matrizInicial;
    int selecao = 99;
    do
    {
        system("cls");
        printf("1 - Refazer matriz \n");
        printf("2 - Ver matriz \n");
        printf("0 - Sair \n");
        printf("Informe a opcao que deseja: ");
        scanf("%d", &selecao);
        getchar();
        switch (selecao)
        {
        case 1:
            liberarMatriz(matriz, linhas);
            matriz = criarMatriz();
            break;
        case 2:
            printarMatriz(matriz, linhas, colunas);
            break;
        case 0:
            break;
        default:
            system("cls");
            printf("Valor invalido! \n");
            printf("Precione qualquer tecla para continuar... ");
            getchar();
            break;
        }
    } while (selecao != 0);

    liberarMatriz(matriz, linhas);
}

int main()
{
    int **matriz = criarMatriz();
    menu(matriz);
    return 0;
}