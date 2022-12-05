#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função que gera os arranjos de acordo com as cores e o tamanho
// Crédito:
// Marcos Paulo Ferreira (Daemonio)
// https://daemoniolabs.wordpress.com
// OBS.: detalhes do funcionamento do código 
// podem ser encontrados na documnetação
int gerar_arranjo(char *in_color, int size) {
    // Nosso número na base n. Ele é um vetor
    // de n+1 posições representando um número
    // na base n.
    int *num; 

    // O in_color é a string de entrada, e string
    // receberá cada permutação.
    char string[100];
    int n, r, i, j, k;

    // O código começa recebendo o conjunto de entrada (in_color) e do r (size). 
    // O conjunto pode ser uma string qualquer e o r deve ser um inteiro 
    // maior ou igual a 1.
    r = size;

    // Essa parte elimina os caracteres repetidos da string. 
    // Devemos ter esse tipo de código, pois a entrada deve conter elementos distintos.
    n = strlen(in_color);
    j = 0;
    string[0] = 0;
    for (i = 0; i < n; i++) {
        if (strchr(string, in_color[i]) == NULL) {
            string[j] = in_color[i];
            j++;
            string[j] = 0;
        }
    }
    strcpy(in_color, string);
    n = strlen(in_color);

    // Cria o nosso número. Ele é um vetor de
    // r+1 posições, sendo que a última é
    // reservada para indicar quando todos os
    // números de tamanho r foram gerados.
    num = (int *) calloc((r + 1), sizeof(int));
    if (num == NULL) {
        perror("calloc");
        return -1;
    }

    // Termina quando a última posição do vetor for 1.
    while (num[r] == 0) {
        for (i = 0; i < n; i++) {
            // Processo de mapeamento.
            for (j = 0, k = r - 1; j < r; j++) {
                string[k] = in_color[num[j]];
                k--;
            }

            // Mostra o resultado.
            string[r] = 0;
            printf("%s\n\n", string);

            // Incrementa o algarismo menos significativo.
            num[0]++;
        }

        // Muda de "casa" e lança os vai uns. 
        for (i = 0; i < r; i++) {
            if (num[i] == n) {
                num[i] = 0;
                num[i + 1]++;
            }
        }
    }

    return 0;
}
