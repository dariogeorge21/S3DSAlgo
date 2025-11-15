#include <stdio.h> 
int main() { 
    int a[10][10], b[10][10]; 
    int A[100][3], B[100][3], C[100][3], R[100][3]; 
    int r, c, i, j, k; 
    printf("Enter number of rows and columns: "); 
    scanf("%d%d", &r, &c); 
    printf("Enter the elements of matrix A:\n"); 
    for(i = 0; i < r; i++) { 
        for(j = 0; j < c; j++) { 
            scanf("%d", &a[i][j]); 
        }}   
    printf("Enter the elements of matrix B:\n"); 
    for(i = 0; i < r; i++) { 
        for(j = 0; j < c; j++) { 
            scanf("%d", &b[i][j]); 
        }} 
    k = 1; 
    A[0][0] = r; 
    A[0][1] = c; 
    for(i = 0; i < r; i++) { 
        for(j = 0; j < c; j++) { 
            if(a[i][j] != 0) { 
                A[k][0] = i; 
                A[k][1] = j; 
                A[k][2] = a[i][j]; 
                k++; 
           }}} 
    A[0][2] = k - 1;   
    int m = 1; 
    B[0][0] = r; 
    B[0][1] = c; 
    for(i = 0; i < r; i++) { 
        for(j = 0; j < c; j++) { 
            if(b[i][j] != 0) { 
                B[m][0] = i; 
                B[m][1] = j; 
                B[m][2] = b[i][j]; 
                m++; 
            }}} 
    B[0][2] = m - 1;   
     printf("Sparse matrix A (row, column, value):\n"); 
       for(i = 0; i <= A[0][2]; i++) { 
          printf("%d %d %d\n", A[i][0], A[i][1], A[i][2]);} 
     printf("Sparse matrix B (row, column, value):\n"); 
       for(i = 0; i <= B[0][2]; i++) { 
          printf("%d %d %d\n", B[i][0], B[i][1], B[i][2]);} 
    i = 1; 
    j = 1; 
    k = 1;     
    while(i <= A[0][2] && j <= B[0][2]) { 
        if(A[i][0] == B[j][0] && A[i][1] == B[j][1]) { 
            C[k][0] = A[i][0]; 
            C[k][1] = A[i][1]; 
            C[k][2] = A[i][2] + B[j][2];   
            i++; 
            j++; 
            k++; 
        } 
        else if(A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) { 
            C[k][0] = A[i][0]; 
            C[k][1] = A[i][1]; 
            C[k][2] = A[i][2]; 
            i++; 
            k++; 
        } 
        else { 
            C[k][0] = B[j][0]; 
            C[k][1] = B[j][1]; 
            C[k][2] = B[j][2]; 
            j++; 
            k++; 
        }} 
    while(i <= A[0][2]) { 
        C[k][0] = A[i][0]; 
        C[k][1] = A[i][1]; 
        C[k][2] = A[i][2]; 
        i++; 
        k++;}   
    while(j <= B[0][2]) { 
        C[k][0] = B[j][0]; 
        C[k][1] = B[j][1]; 
        C[k][2] = B[j][2]; 
        j++; 
        k++;} 
    C[0][0] = r; 
    C[0][1] = c; 
    C[0][2] = k - 1;   
         printf("Sum of matrices A and B:\n"); 
    for(i = 0; i <= C[0][2]; i++) { 
        printf("%d %d %d\n", C[i][0], C[i][1], C[i][2]); 
    } 
    R[0][0] = C[0][1];   
    R[0][1] = C[0][0];   
    R[0][2] = C[0][2]; 
    
    k = 1; 
    for(i = 1; i <= C[0][2]; i++) { 
        R[k][0] = C[i][1]; 
        R[k][1] = C[i][0]; 
        R[k][2] = C[i][2]; 
        k++;} 
    printf("Transpose of the sum of matrices A and B:\n"); 
    for(i = 0; i <= R[0][2]; i++) { 
        printf("%d %d %d\n", R[i][0], R[i][1], R[i][2]); 
    } 
    return 0; 
} 
