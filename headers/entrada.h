#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para abertura e verificação do arquivo de entrada
int open_file(char *file_name) {
    FILE *file = NULL;
    file = fopen(file_name, "r");
    if (file == NULL) {
        return 1;
    }
    return 0;
}

// Função para obter o tamanho (espaços/matriz) do arquivo de entrada
int get_size_arvore_natal(char *file_name) {
    FILE *file = NULL;
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Erro na abertura do arquivo\n");
    }

    char caractere_texto;
    int linha; linha = 1;

    do {
        caractere_texto = fgetc(file);
        switch (caractere_texto) {
            case EOF :
                break;
            case '\n' :
                linha++;
            default :
                break;
        }
    } while (caractere_texto != EOF);

    return linha;
}

// Função para iniciar a matriz de adjacências com base no arquivo de entrada
void iniciar_matriz_adj(char *file_name, int size, int matriz[size][size]) {
    FILE *file = NULL;
    file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Erro na abertura do arquivo\n");
    }

    int i, j;
    int cont; cont = 0;
    int tamanho;
    int vetor[100];
    char linha[100];
    char *num;

    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            matriz[i][j] = 0;
        }
    }              

    while(fgets(linha, 100, file) != NULL) {
        num = strtok(linha, " ");
        while(num) {
            tamanho = strlen(num);

            char aux_num[tamanho];

            if(num[tamanho - 1] == '\n') {
                for(i = 0; i < tamanho; i++) {
                    if(i != (tamanho - 1)) {
                        aux_num[i] = num[i]; 
                    }
                }
                strcpy(num, aux_num);
            }
            vetor[cont] = atoi(num);
            num = strtok(NULL, " "); 
            cont++;
        }
        cont--;
        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                if(i == j) {
                    matriz[i][j] = -1;
                }
                if(cont != 0) {
                    matriz[vetor[0]][vetor[cont]] = 1;
                    matriz[vetor[cont]][vetor[0]] = 1;
                    cont--;
                }
            }
        }
    }
}

// Função para imprimir a matriz de adjacências
void imprime_matriz_adj(int size, int matriz[size][size]) {
    int i, j;
    printf("\n\n");
    for (i = 0; i < size; i++) {
        if (i < 10) {
            printf(" %d | ", i);
        }
        else {
            printf("%d | ", i);
        }
        for (j = 0; j < size; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}
