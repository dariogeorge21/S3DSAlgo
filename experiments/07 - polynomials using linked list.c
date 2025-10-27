// Polynomials using linked list

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in polynomial
struct Term {
    int coeff;           // coefficient
    int exp;             // exponent
    struct Term* next;   // pointer to next term
};

// Function to create a new term
struct Term* createTerm(int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = coeff;
    newTerm->exp = exp;
    newTerm->next = NULL;
    return newTerm;
}

// Function to insert a term in descending order of exponents
void insertTerm(struct Term** head, int coeff, int exp) {
    struct Term* newTerm = createTerm(coeff, exp);
    
    // If list is empty or new term has highest exponent
    if (*head == NULL || (*head)->exp < exp) {
        newTerm->next = *head;
        *head = newTerm;
        return;
    }
    
    // Find correct position to insert
    struct Term* current = *head;
    while (current->next != NULL && current->next->exp > exp) {
        current = current->next;
    }
    
    // If same exponent exists, add coefficients
    if (current->next != NULL && current->next->exp == exp) {
        current->next->coeff += coeff;
        free(newTerm);
    } else {
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

// Function to display polynomial
void displayPolynomial(struct Term* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    
    struct Term* current = head;
    int first = 1;
    
    while (current != NULL) {
        if (current->coeff != 0) {
            // Print sign
            if (!first && current->coeff > 0) {
                printf(" + ");
            } else if (current->coeff < 0) {
                printf(" - ");
            }
            
            // Print coefficient
            int absCoeff = (current->coeff < 0) ? -current->coeff : current->coeff;
            if (current->exp == 0 || absCoeff != 1) {
                printf("%d", absCoeff);
            }
            
            // Print variable and exponent
            if (current->exp > 0) {
                printf("x");
                if (current->exp > 1) {
                    printf("^%d", current->exp);
                }
            }
            
            first = 0;
        }
        current = current->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* p1 = poly1;
    struct Term* p2 = poly2;
    
    // Process all terms from both polynomials
    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL && (p2 == NULL || p1->exp > p2->exp)) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2 != NULL && (p1 == NULL || p2->exp > p1->exp)) {
            insertTerm(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            // Same exponent - add coefficients
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) {
                insertTerm(&result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    return result;
}

// Function to subtract two polynomials
struct Term* subtractPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;
    struct Term* p1 = poly1;
    struct Term* p2 = poly2;
    
    // Process all terms from both polynomials
    while (p1 != NULL || p2 != NULL) {
        if (p1 != NULL && (p2 == NULL || p1->exp > p2->exp)) {
            insertTerm(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } else if (p2 != NULL && (p1 == NULL || p2->exp > p1->exp)) {
            insertTerm(&result, -p2->coeff, p2->exp);
            p2 = p2->next;
        } else {
            // Same exponent - subtract coefficients
            int diffCoeff = p1->coeff - p2->coeff;
            if (diffCoeff != 0) {
                insertTerm(&result, diffCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    
    return result;
}

// Function to create polynomial by user input
struct Term* createPolynomial() {
    struct Term* poly = NULL;
    int numTerms, coeff, exp;
    
    printf("Enter number of terms: ");
    scanf("%d", &numTerms);
    
    for (int i = 0; i < numTerms; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
    
    return poly;
}

int main() {
    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;
    struct Term* result = NULL;
    int choice;
    
    printf("=== Polynomial Operations ===\n");
    printf("1. Create first polynomial\n");
    printf("2. Create second polynomial\n");
    printf("3. Display first polynomial\n");
    printf("4. Display second polynomial\n");
    printf("5. Add polynomials\n");
    printf("6. Subtract polynomials\n");
    printf("7. Exit\n");
    
    while (1) {
        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Creating first polynomial:\n");
                poly1 = createPolynomial();
                break;
                
            case 2:
                printf("Creating second polynomial:\n");
                poly2 = createPolynomial();
                break;
                
            case 3:
                printf("First polynomial: ");
                displayPolynomial(poly1);
                break;
                
            case 4:
                printf("Second polynomial: ");
                displayPolynomial(poly2);
                break;
                
            case 5:
                if (poly1 && poly2) {
                    result = addPolynomials(poly1, poly2);
                    printf("Sum: ");
                    displayPolynomial(result);
                } else {
                    printf("Please create both polynomials first!\n");
                }
                break;
                
            case 6:
                if (poly1 && poly2) {
                    result = subtractPolynomials(poly1, poly2);
                    printf("Difference: ");
                    displayPolynomial(result);
                } else {
                    printf("Please create both polynomials first!\n");
                }
                break;
                
            case 7:
                printf("Thank you for using Polynomial Calculator!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter 1-7.\n");
        }
    }
    
    return 0;
}
