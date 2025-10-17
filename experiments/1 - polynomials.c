// find the sum of 2 polynomials using an array!!

#include <stdio.h>

struct Term {
    int coefficient;
    int exponent;
};

typedef struct Term Term;


void inputPolynomial(Term poly[], int *n) {
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &poly[i].coefficient, &poly[i].exponent);
    }
}


void displayPolynomial(Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (poly[i].coefficient != 0) {
            if (i != 0 && poly[i].coefficient > 0) {
                printf(" + ");
            }
            if (poly[i].exponent == 0) {
                printf("%d", poly[i].coefficient);
            } else if (poly[i].exponent == 1) {
                printf("%dx", poly[i].coefficient);
            } else {
                printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
            }
        }
    }
    printf("\n");
}

int main() {
    Term poly1[100];
    int n1, n2;
    printf("Enter the first polynomial:\n");
    inputPolynomial(poly1, &n1);
    printf("Enter the second polynomial:\n");
    printf("\nPolynomial 1: ");
    displayPolynomial(poly1, n1);
    printf("Polynomial 2: ");

    return 0;
}
