#include <stdio.h>
#include <stdlib.h>

// Structure to represent a term in the polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

// Function to insert a new term at the end of a linked list
void insertTerm(struct Term** head, int coeff, int exp) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coefficient = coeff;
    newTerm->exponent = exp;
    newTerm->next = NULL;

    if (*head == NULL) {
        *head = newTerm;
        return;
    }

    struct Term* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newTerm;
}

// Function to add two polynomials represented as linked lists
struct Term* addPolynomials(struct Term* poly1, struct Term* poly2) {
    struct Term* result = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            insertTerm(&result, poly1->coefficient + poly2->coefficient, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

// Function to print a polynomial represented as a linked list
void printPolynomial(struct Term* poly) {
    while (poly != NULL) {
        printf("%d ", poly->coefficient);
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Term* poly1 = NULL;
    struct Term* poly2 = NULL;

    for (int i = 0; i < n + m; ++i) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp);
        if (i < n) {
            insertTerm(&poly1, coeff, exp);
        } else {
            insertTerm(&poly2, coeff, exp);
        }
    }

    struct Term* result = addPolynomials(poly1, poly2);
    printPolynomial(result);

    return 0;
}