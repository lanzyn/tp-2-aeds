#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "./headers/arranjo.h"
#include "./headers/entrada.h"
#include "./headers/pbn.h"

// ./entradas/entrada_I.txt
// ./entradas/entrada_II.txt
// ./entradas/entrada_teste.txt

int main() {
    char file_name[100]; // Variável que recebe o nome do arquivo para ser lido
    char in_color[100]; // Variável que recebe as iniciais das cores das bolinhas para gerar os arranjos
    int size; // Variável que recebe o valor do tamanho/espaços da matriz/árvore de natal

    int loop; loop = 1; // Variável de loop para o menu
    int option; // Variável que recebe a opção do menu

    // Implementação do menu
    while (loop) {
        // Operações disponíveis no menu
        printf("\n-------------------- PROBLEMA DAS BOLINHAS DE NATAL --------------------\n");
        printf("\n     -------------------- COLORAÇÃO DE GRAFOS --------------------\n");
        printf("Escolha um modo:\n");
        printf("1. Gerar arranjos separadamente\n"); // Gera arranjos de N cores, tomados P a P
        printf("2. Gerar tabela de adjacências\n"); // Gera a tabela/matriz de adjacências
        printf("3. Verificar PBN\n"); // Verifica arranjos válidos e inválidos para o PBN a partir da matriz de adjacências
        printf("4. Instruções\n");
        printf("5. Sair do programa\n"); // Encerra o programa
        printf("-----------------------------------------------------------------------\n");
        printf("Opção desejada: "); scanf("%d", &option);
        system("cls || clear");

        switch (option) {
        case 1 :
            {
            printf("Modo arranjos escolhido!\n\n");

            printf("Letra inicial de cada cor (sem espaços): "); scanf("%s", in_color);
            printf("Espaços: "), scanf("%d", &size);
            printf("\n");

            // Declaração de variáveis para cálculo do tempo de execução
            clock_t start, end;
            time_t t_start, t_end;
            double cpu_time_used;
            double time_used;

            // Início do cálculo do tempo de execução
            start = clock();
            t_start = time(NULL);

            gerar_arranjo(in_color, size);
            
            // Fim do cálculo do tempo de execução
            end = clock();
            t_end = time(NULL);
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            time_used = difftime(t_end, t_start);

            printf("Tempo (método clock_t): %lf\n", cpu_time_used);
            printf("Tempo (método time_t): %lf\n", time_used);

            break;
            }
        case 2 :
            {
            printf("Modo tabela de adjacências escolhido!\n\n");

            do {
                printf("Nome do arquivo: "); scanf("%s", file_name);
                if (open_file(file_name) == 1) {
                    printf("Erro na abertura do arquivo!\nTente novamente!\n");
                }
                printf("\n");
            } while (open_file(file_name) == 1);

            size = get_size_arvore_natal(file_name);
            int matriz[size][size]; // Declaração de uma matriz de inteiros de tamanho SIZE x SIZE

            iniciar_matriz_adj(file_name, size, matriz);
            imprime_matriz_adj(size, matriz);

            break;
            }
        case 3 :
            {
            printf("Modo PBN escolhido!\n\n");

            size = get_size_arvore_natal(file_name);
            int matriz[size][size]; // Declaração de uma matriz de inteiros de tamanho SIZE x SIZE

            printf("Matriz de adjacências:\n");


            iniciar_matriz_adj(file_name, size, matriz);
            imprime_matriz_adj(size, matriz);

            // Declaração de variáveis para cálculo do tempo de execução
            clock_t start, end;
            time_t t_start, t_end;
            double cpu_time_used;
            double time_used;

            // Início do cálculo do tempo de execução
            start = clock();
            t_start = time(NULL);

            valida_pbn(size, matriz);

            // Fim do cálculo do tempo de execução
            end = clock();
            t_end = time(NULL);
            cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
            time_used = difftime(t_end, t_start);

            printf("\n");

            printf("Tempo (método clock_t): %lf\n", cpu_time_used);
            printf("Tempo (método time_t): %lf\n", time_used);
            
            break;
            }
        case 4 :
            {
            printf("Modo instruções escolhido!\n\n");

            printf("Instruções:\n");
            printf("Passo 1 - Inserir o destino do arquivo de entrada para gerar a matriz de adjacências (2)\n");
            printf("Passo 2 - Verificar possíveis soluções para o PBN com base na matriz de adjacências (3)\n");
            
            break;
            }
        case 5 :
            {
            loop = 0;

            break;
            }
        default:
            {
            printf("Opção inválida! Tente novamente!\n");
            }
        }
    }

    return 0;
}