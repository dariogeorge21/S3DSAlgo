// find the sum of 2 polynomials using an structure!!

#include<stdio.h>

struct poly{
    int coeff;
    int exp;
};

int main(){
    int n1, n2;
    printf("Enter the number of terms in the first polynomial: ");
    scanf("%d", &n1);
    struct poly p1[n1];
    printf("Enter the coefficients and exponents of the first polynomial: ");
    for(int i=0; i<n1; i++){
        printf("Coefficient %d: ", i+1);
        scanf("%d", &p1[i].coeff);
        printf("Exponent %d: ", i+1);
        scanf("%d", &p1[i].exp);
    }
    printf("Enter the number of terms in the second polynomial: ");
    scanf("%d", &n2);
    struct poly p2[n2];
    printf("Enter the coefficients and exponents of the second polynomial: ");
    for(int i=0; i<n2; i++){
        printf("Coefficient %d: ", i+1);
        scanf("%d", &p2[i].coeff);
        printf("Exponent %d: ", i+1);
        scanf("%d", &p2[i].exp);
    }
    int max_exp;
    for (int i =0,j=0;i<n1 && j<n2;i++,j++){
        max_exp = (p1[i].exp > p2[j].exp) ? p1[i].exp : p2[j].exp;
    }
    struct poly sum[max_exp+1];
    for (int i = 0; i <= max_exp; i++) {
        sum[i].coeff = 0;
        sum[i].exp = i;
    }
    for (int i = 0; i < max_exp; i++) {
        if (p1[i].exp == p2[i].exp) {
            sum[i].coeff = p1[i].coeff + p2[i].coeff;
            sum[i].exp = p1[i].exp;
        } else if (p1[i].exp > p2[i].exp) {
            sum[i].coeff = p1[i].coeff;
            sum[i].exp = p1[i].exp;
        } else if (p1[i].exp < p2[i].exp) {
            sum[i].coeff = p2[i].coeff;
            sum[i].exp = p2[i].exp;
        } else {
            sum[i].coeff = 0;
            sum[i].exp = 0;
        }
    }
    printf("The sum of the polynomials is: ");
    for(int i=0; i<max_exp; i++){
        if(sum[i].coeff != 0){
            printf("%dx^%d ", sum[i].coeff, sum[i].exp);
            if(i<max_exp-1){
                printf("+ ");
            }
        }
    }
    printf("\n");
    
    return 0;
}