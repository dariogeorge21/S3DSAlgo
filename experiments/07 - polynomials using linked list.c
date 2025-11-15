#include <stdio.h> 
struct Node { 
    int coeff; 
    int exp; 
    struct Node* link; 
}; 
int main() { 
    struct Node poly1[10], poly2[10], poly3[20]; 
    struct Node *pptr, *qptr; 
    struct Node *head = NULL, *tail = NULL; 
    int t1, t2, i, j, k = 0; 
    printf("Enter the number of terms in the first polynomial: "); 
    scanf("%d", &t1); 
    for (i = 0; i < t1; i++) { 
        printf("Enter the coefficient for term %d: ", i + 1); 
        scanf("%d", &poly1[i].coeff); 
        printf("Enter the exponent for term %d: ", i + 1); 
        scanf("%d", &poly1[i].exp); 
        if (i < t1 - 1) 
            poly1[i].link = &poly1[i + 1]; 
        else 
            poly1[i].link = NULL;} 
    printf("Enter the number of terms in the second polynomial: "); 
    scanf("%d", &t2); 
    for (j = 0; j < t2; j++) { 
        printf("Enter the coefficient for term %d: ", j + 1); 
        scanf("%d", &poly2[j].coeff); 
        printf("Enter the exponent for term %d: ", j + 1); 
        scanf("%d", &poly2[j].exp); 
        if (j < t2 - 1) 
            poly2[j].link = &poly2[j + 1]; 
        else 
            poly2[j].link = NULL;} 
    pptr = poly1; 
    qptr = poly2; 
    while (pptr != NULL && qptr != NULL) { 
        if (pptr->exp == qptr->exp) { 
            int sum = pptr->coeff + qptr->coeff; 
            if (sum != 0) { 
                poly3[k].coeff = sum; 
                poly3[k].exp = pptr->exp; 
                poly3[k].link = NULL; 
                if (head == NULL) { 
                    head = &poly3[k]; 
                    tail = head; 
                } else { 
                    tail->link = &poly3[k]; 
                    tail = tail->link; 
                } 
                k++; 
            } 
            pptr = pptr->link; 
            qptr = qptr->link; 
        } else if (pptr->exp > qptr->exp) { 
            poly3[k] = *pptr; 
            poly3[k].link = NULL; 
            if (head == NULL) { 
                head = &poly3[k]; 
                tail = head; 
            } else { 
                tail->link = &poly3[k]; 
                tail = tail->link; 
            } 
            k++; 
            pptr = pptr->link; 
        } else { 
            poly3[k] = *qptr; 
            poly3[k].link = NULL; 
            
            if (head == NULL) { 
                head = &poly3[k]; 
                tail = head; 
            } else { 
                tail->link = &poly3[k]; 
                tail = tail->link; 
            } 
            k++; 
            qptr = qptr->link; 
        }} 
    while (pptr != NULL) { 
        poly3[k] = *pptr; 
        poly3[k].link = NULL; 
 
        if (head == NULL) { 
            head = &poly3[k]; 
            tail = head; 
        } else { 
            tail->link = &poly3[k]; 
            tail = tail->link; 
        } 
        k++; 
        pptr = pptr->link; 
    } 
    while (qptr != NULL) { 
        poly3[k] = *qptr; 
        poly3[k].link = NULL; 
 
        if (head == NULL) { 
            head = &poly3[k]; 
            tail = head; 
        } else { 
            tail->link = &poly3[k]; 
            tail = tail->link; 
        } 
        k++; 
        qptr = qptr->link; 
    } 
    struct Node* temp = head; 
    printf("Resultant Polynomial: "); 
    while (temp != NULL) { 
        printf("%dx^%d", temp->coeff, temp->exp); 
        if (temp->link != NULL) 
            printf(" + "); 
        temp = temp->link; 
    } 
    printf("\n"); 
    return 0; 
} 
