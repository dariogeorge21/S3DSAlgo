#include <stdio.h> 
struct polyTerm { 
    int coeff; 
    int exp; 
}; 
int main() { 
    int t1, t2, i = 0, j = 0, k = 0; 
    printf("Enter number of terms in first polynomial: "); 
    scanf("%d", &t1); 
    struct polyTerm poly1[t1]; 
    printf("Enter coefficients and exponents for first polynomial:\n"); 
    for (i = 0; i < t1; i++) { 
        printf("Term %d coeff and exp: ", i + 1); 
        scanf("%d %d", &poly1[i].coeff, &poly1[i].exp); 
    } 
    printf("Enter number of terms in second polynomial: "); 
    scanf("%d", &t2); 
    struct polyTerm poly2[t2]; 
    printf("Enter coefficients and exponents for second polynomial:\n"); 
    for (j = 0; j < t2; j++) { 
        printf("Term %d coeff and exp: ", j + 1); 
        scanf("%d %d", &poly2[j].coeff, &poly2[j].exp); 
    } 
    struct polyTerm poly3[t1 + t2];   
      i = 0; j = 0; k = 0; 
     while (i < t1 && j < t2) { 
        if (poly1[i].exp == poly2[j].exp) { 
            poly3[k].coeff = poly1[i].coeff + poly2[j].coeff; 
            poly3[k].exp = poly1[i].exp; 
            i++; j++; k++; 
        } else if (poly1[i].exp > poly2[j].exp) { 
            poly3[k] = poly1[i]; 
            i++; k++;                                         
        } else { 
            poly3[k] = poly2[j]; 
            j++; k++; 
        } 
    } 
    while (i < t1) { 
        poly3[k] = poly1[i]; 
        i++; k++; 
    }   
    while (j < t2) { 
        poly3[k] = poly2[j]; 
        j++; k++; 
    }   
    printf("Sum of polynomials: "); 
    for (int x = 0; x < k; x++) { 
if (x != 0 && poly3[x].coeff >= 0) { 
printf("+"); 
} 
printf("%d(x)^%d ", poly3[x].coeff, poly3[x].exp); 
} 
printf("\n"); 
return 0; 
} 
