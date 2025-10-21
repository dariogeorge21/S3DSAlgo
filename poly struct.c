#include <stdio.h>

struct term {
    int coeff;
    int exp;
};

int main() {
    struct term poly1[20], poly2[20], result[40];
    int n1, n2, i, j, k = 0;

    // First polynomial
    printf("Enter the no of terms of 1st poly : ");
    scanf("%d", &n1);
    for (i = 0; i < n1; i++) {
        printf("Enter the coefficient : ");
        scanf("%d", &poly1[i].coeff);
        printf("Enter the exponent : ");
        scanf("%d", &poly1[i].exp);
    }

    // Second polynomial
    printf("Enter the no of terms of 2nd poly : ");
    scanf("%d", &n2);
    for (i = 0; i < n2; i++) {
        printf("Enter the coefficient : ");
        scanf("%d", &poly2[i].coeff);
        printf("Enter the exponent : ");
        scanf("%d", &poly2[i].exp);
    }

    // Add polynomials
    i = 0; j = 0;
    while (i < n1 && j < n2) {
        if (poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exp < poly2[j].exp) {
            result[k++] = poly2[j++];
        } else {
            result[k].coeff = poly1[i].coeff + poly2[j].coeff;
            result[k].exp = poly1[i].exp;
            k++; i++; j++;
        }
    }

    // Copy remaining terms
    while (i < n1) result[k++] = poly1[i++];
    while (j < n2) result[k++] = poly2[j++];

    // Output result
    printf("Resultant polynomial : ");
    for (i = 0; i < k; i++) {
        printf("%d x^%d", result[i].coeff, result[i].exp);
        if (i < k - 1) printf(" + ");
    }
    printf("\n");

    return 0;
}