#include <iostream>
#include <vector>

using namespace std;

struct Product {
    int id;
    int stock;
};

int main() {
    int n, threshold;
    cin >> n >> threshold;

    vector<Product> products(n);

    for (int i = 0; i < n; i++) {
        cin >> products[i].id >> products[i].stock;
    }

    cout << "Products with stock less than threshold:" << endl;
    for (int i = 0; i < n; i++) {
        if (products[i].stock < threshold) {
            cout << products[i].id << endl;
        }
    }

    return 0;
}