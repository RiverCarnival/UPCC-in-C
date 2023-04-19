#include <stdio.h>

int main() {
    int n, i, j, k;
    n = 1;

    int matriz[n][n][8];

    printf("Digite os valores binários da matriz:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < 8; k++) {
                scanf("%d", &matriz[i][j][k]);
            }
        }
    }
    
    int saida[n][n][1];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            int decimal = 0;
            for (k = 0; k < 8; k++) {
                decimal += matriz[i][j][k] << (7 - k);
            }
            saida[i][j][0] = decimal;
        }
    }

    printf("Matriz de saida:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", saida[i][j][0]);
        }
        printf("\n");
    }

    return 0;
}
