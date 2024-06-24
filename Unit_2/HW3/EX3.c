#include <stdlib.h>
#include <stdio.h>

int main() {
    int a[10][10];
    int t[10][10];
    int r, c;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe entered matrix is:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Transpose the matrix
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }

    printf("\nThe transposed matrix is:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}