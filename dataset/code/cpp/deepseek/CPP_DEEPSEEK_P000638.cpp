Here is a simple implementation of the problem in C++. The code uses a linked list to represent the polynomial. Each node in the list contains a coefficient and an exponent. The operations include insert, delete, and evaluate.

#include <iostream>
#include <list>

using namespace std;

class Node {
public:
    int coefficient;
    int exponent;
    Node(int c, int e) : coefficient(c), exponent(e) {}
};

class Polynomial {
private:
    list<Node> terms;
public:
    void insert(int coefficient, int exponent) {
        bool inserted = false;
        for(auto it = terms.begin(); it != terms.end(); ++it) {
            if(it->exponent > exponent) {
                terms.insert(it, Node(coefficient, exponent));
                inserted = true;
                break;
            }
        }
        if(!inserted) {
            terms.push_back(Node(coefficient, exponent));
        }
    }

    void deleteTerm(int exponent) {
        for(auto it = terms.begin(); it != terms.end(); ++it) {
            if(it->exponent == exponent) {
                terms.erase(it);
                break;
            }
        }
    }

    int evaluate(int x) {
        int result = 0;
        for(auto &term : terms) {
            result += term.coefficient * pow(x, term.exponent);
        }
        return result;
    }

    void display() {
        bool first = true;
        for(auto &term : terms) {
            if(!first) {
                cout << " + ";
            }
            cout << term.coefficient << "x^" << term.exponent;
            first = false;
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly;
    int n, q, coefficient, exponent;
    char operation;
    cin >> n >> q;
    for(int i = 0; i < n; ++i) {
        cin >> coefficient >> exponent;
        poly.insert(coefficient, exponent);
    }
    for(int i = 0; i < q; ++i) {
        cin >> operation >> coefficient >> exponent;
        switch(operation) {
            case 'I':
                poly.insert(coefficient, exponent);
                break;
            case 'D':
                poly.deleteTerm(exponent);
                break;
            case 'E':
                cout << "Result: " << poly.evaluate(coefficient) << endl;
                break;
            case 'P':
                poly.display();
                break;
        }
    }
    return 0;
}

Please note that this code assumes that you are using a C++ compiler that supports C++11 or later. Also, the `pow` function from the `cmath` library is used to raise `x` to the power of `exponent`.