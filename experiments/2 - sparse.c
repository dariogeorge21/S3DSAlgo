#include <stdio.h>

struct Term {
    int row;
    int col;
    int val;
};

void readSparse(struct Term mat[]) {
    int n;

    printf("Enter number of rows: ");
    scanf("%d", &mat[0].row);

    printf("Enter number of columns: ");
    scanf("%d", &mat[0].col);

    printf("Enter number of non-zero elements: ");
    scanf("%d", &mat[0].val);

    n = mat[0].val;

    for (int i = 1; i <= n; i++) {
        printf("Enter row, column, value for element %d: ", i);
        scanf("%d %d %d", &mat[i].row, &mat[i].col, &mat[i].val);
    }
}

void displaySparse(struct Term mat[]) {
    int n = mat[0].val;
    int rows = mat[0].row;
    int cols = mat[0].col;

    printf("\nRow\tCol\tVal\n");
    printf("%d\t%d\t%d\n", rows, cols, n);

    for (int i = 1; i <= n; i++) {
        printf("%d\t%d\t%d\n", mat[i].row, mat[i].col, mat[i].val);
    }
}

void addSparse(struct Term A[], struct Term B[], struct Term C[]) {
    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        printf("\nAddition not possible! Dimensions mismatch.\n");
        C[0].val = 0;
        return;
    }

    int i = 1, j = 1, k = 1;

    while (i <= A[0].val && j <= B[0].val) {
        if ((A[i].row < B[j].row) ||
            (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        else if ((B[j].row < A[i].row) ||
                 (B[j].row == A[i].row && B[j].col < A[i].col)) {
            C[k++] = B[j++];
        }
        else {
            C[k].row = A[i].row;
            C[k].col = A[i].col;
            C[k].val = A[i].val + B[j].val;
            i++;
            j++;
            k++;
        }
    }

    while (i <= A[0].val) {
        C[k++] = A[i++];
    }

    while (j <= B[0].val) {
        C[k++] = B[j++];
    }

    C[0].row = A[0].row;
    C[0].col = A[0].col;
    C[0].val = k - 1;
}

void transposeSparse(struct Term M[], struct Term T[]) {
    int n = M[0].val;

    T[0].row = M[0].col;
    T[0].col = M[0].row;
    T[0].val = n;

    int k = 1;

    for (int i = 1; i <= M[0].col; i++) {
        for (int j = 1; j <= n; j++) {
            if (M[j].col == i) {
                T[k].row = M[j].col;
                T[k].col = M[j].row;
                T[k].val = M[j].val;
                k++;
            }
        }
    }
}

int main() {
    struct Term A[50], B[50], C[100], T[50];
    int choice;

    printf("Enter first sparse matrix (A):\n");
    readSparse(A);

    printf("\nEnter second sparse matrix (B):\n");
    readSparse(B);

    addSparse(A, B, C);

    printf("\nMatrix A:");
    displaySparse(A);

    printf("\nMatrix B:");
    displaySparse(B);

    printf("\nMatrix C (A + B):");
    displaySparse(C);

    do {
        printf("\n--- Transpose Menu ---\n");
        printf("1. Transpose A\n");
        printf("2. Transpose B\n");
        printf("3. Transpose C\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            if (choice == 1) transposeSparse(A, T);
            else if (choice == 2) transposeSparse(B, T);
            else transposeSparse(C, T);

            printf("\nTranspose Result:");
            displaySparse(T);
        }
    } while (choice != 4);

    return 0;
}
