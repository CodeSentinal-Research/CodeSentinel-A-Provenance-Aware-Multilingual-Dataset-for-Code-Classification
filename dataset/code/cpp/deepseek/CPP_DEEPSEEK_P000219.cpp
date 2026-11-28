Here is the C++ code for the problem:

#include <iostream>
#include <deque>

using namespace std;

class ProductOfNumbers {
public:
    deque<int> d;

    void add(int num) {
        d.push_back(num);
    }

    int getProduct(int k) {
        long long prod = 1;
        for (int i = 0; i < k; i++) {
            prod *= d[i];
        }
        for (size_t i = d.size(); i < d.size() + k; i++) {
            prod /= d[i - k];
            prod *= d[i];
        }
        return prod;
    }
};

int main() {
    ProductOfNumbers prod;
    prod.add(1);
    prod.add(2);
    prod.add(3);
    cout << prod.getProduct(1) << endl; 
    prod.add(4);
    cout << prod.getProduct(1) << endl; 
    cout << prod.getProduct(2) << endl; 
    return 0;
}

This code defines a class `ProductOfNumbers` that uses a `deque` to store the last K numbers. The `add` function adds a number to the end of the `deque`. The `getProduct` function calculates the product of the last K numbers.

In the `main` function, a `ProductOfNumbers` instance is created and queries are made using the instance.