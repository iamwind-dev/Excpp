#include <iostream>

using namespace std;

// Ð?nh nghia m?t c?u trúc cho m?t h?ng t? da th?c
struct Term {
    int coefficient;
    int exponent;
    Term *next;
};

// Hàm d? chèn m?t h?ng t? m?i vào da th?c
void insertTerm(Term *&head, int coef, int exp) {
    Term *newTerm = new Term;
    newTerm->coefficient = coef;
    newTerm->exponent = exp;
    newTerm->next = NULL;
    
    if (head == NULL) {
        // Tru?ng h?p 1: da th?c tr?ng
        head = newTerm;
    } else if (exp > head->exponent) {
        // Tru?ng h?p 2: h?ng t? m?i có s? mu cao nh?t
        newTerm->next = head;
        head = newTerm;
    } else {
        // Tru?ng h?p 3: h?ng t? m?i có s? mu <= h?ng t? d?u tiên
        Term *current = head;
        while (current->next != NULL && current->next->exponent >= exp) {
            current = current->next;
        }
        newTerm->next = current->next;
        current->next = newTerm;
    }
}

// Hàm d? hi?n th? da th?c
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
    
    insertTerm(poly, 5, 2); // Thêm 5x^2
    insertTerm(poly, 3, 1); // Thêm 3x^1
    insertTerm(poly, 2, 0); // Thêm 2x^0
    insertTerm(poly, 4, 3); // Thêm 4x^3
    
    displayPolynomial(poly); // Hi?n th? da th?c
    
    return 0;
}

