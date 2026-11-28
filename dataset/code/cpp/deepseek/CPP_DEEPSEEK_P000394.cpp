#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {
    string brand;
};

int main() {
    int n;
    cin >> n;

    vector<Product> products(n);

    for(int i = 0; i < n; ++i) {
        cin >> products[i].brand;
    }

    string brandToSearch;
    cin >> brandToSearch;

    for(const Product& product : products) {
        if(product.brand == brandToSearch) {
            cout << product.brand << '\n';
        }
    }

    return 0;
}