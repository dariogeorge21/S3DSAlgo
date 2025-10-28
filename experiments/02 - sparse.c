// Sparse Matrix Representation and Operations - Addition and Transpose

#include <stdio.h>

struct element{
    int row;
    int col;
    int value;
};

int main(){
    int n1, n2;
    printf("Enter the number of non-zero elements in the first sparse matrix: ");
    scanf("%d", &n1);
    struct element mat1[n1];
    printf("Enter the row, column and value of non-zero elements of the first sparse matrix:\n");
    for(int i=0; i<n1; i++){
        printf("Element %d:\n", i+1);
        printf("Row: ");
        scanf("%d", &mat1[i].row);
        printf("Column: ");
        scanf("%d", &mat1[i].col);
        printf("Value: ");
        scanf("%d", &mat1[i].value);
    }
    printf("Enter the number of non-zero elements in the second sparse matrix: ");
    scanf("%d", &n2);
    struct element mat2[n2];
    printf("Enter the row, column and value of non-zero elements of the second sparse matrix:\n");
    for(int i=0; i<n2; i++){
        printf("Element %d:\n", i+1);
        printf("Row: ");
        scanf("%d", &mat2[i].row);
        printf("Column: ");
        scanf("%d", &mat2[i].col);
        printf("Value: ");
        scanf("%d", &mat2[i].value);
    }
    // Addition of two sparse matrices
    struct element sum[n1 + n2];
    for (int i = 0; i < n1+n2; i++){
        if (mat1[i].row == mat2[i].row && mat1[i].col == mat2[i].col) {
            sum[i].row = mat1[i].row;
            sum[i].col = mat1[i].col;
            sum[i].value = mat1[i].value + mat2[i].value;
        } else {
            sum[i].row = mat1[i].row;
            sum[i].col = mat1[i].col;
            sum[i].value = mat1[i].value;
            sum[i].row = mat2[i].row;
            sum[i].col = mat2[i].col;
            sum[i].value = mat2[i].value;
        }
    }
    printf("The sum of the two sparse matrices is:\n");
    for (int i = 0; i < n1+n2; i++){
        printf("%d %d %d\n", sum[i].row, sum[i].col, sum[i].value);
    }
    return 0;
}