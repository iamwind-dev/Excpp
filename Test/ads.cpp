#include <iostream>

using namespace std;

// �?nh nghia m?t c?u tr�c cho m?t h?ng t? da th?c
struct Term {
    int coefficient;
    int exponent;
    Term *next;
};

// H�m d? ch�n m?t h?ng t? m?i v�o da th?c
void insertTerm(Term *&head, int coef, int exp) {
    Term *newTerm = new Term;
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    
    if (head == NULL) {
        // Tru?ng h?p 1: da th?c tr?ng
        head = newTerm;
    } else if (exp > head->exponent) {
        // Tru?ng h?p 2: h?ng t? m?i c� s? mu cao nh?t
        newTerm->next = head;
        head = newTerm;
    } else {
        // Tru?ng h?p 3: h?ng t? m?i c� s? mu <= h?ng t? d?u ti�n
        Term *current = head;
        while (current->next != NULL && current->next->exponent >= exp) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

// H�m d? hi?n th? da th?c
void displayPolynomial(Term *head) {
    Term *current = head;
    while (current != NULL) {
        cout << current->coefficient << "x^" << current->exponent;
        if (current->next != NULL) {
            cout << " + ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    Term *poly = NULL;
    
    insertTerm(poly, 5, 2); // Th�m 5x^2
    insertTerm(poly, 3, 1); // Th�m 3x^1
    insertTerm(poly, 2, 0); // Th�m 2x^0
    insertTerm(poly, 4, 3); // Th�m 4x^3
    
    displayPolynomial(poly); // Hi?n th? da th?c
    
    return 0;
}

