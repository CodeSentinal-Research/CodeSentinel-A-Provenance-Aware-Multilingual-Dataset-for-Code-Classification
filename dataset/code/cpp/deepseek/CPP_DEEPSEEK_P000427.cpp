#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Product {
    string name;
    float price;
};

bool isEligibleForFreeShipping(Product product, float minPrice) {
    return product.price >= minPrice;
}

void findProducts(vector<Product>& products, float minPrice) {
    for (Product product : products) {
        if (isEligibleForFreeShipping(product, minPrice)) {
            cout << "Product name: " << product.name << ", Minimum Price: " << product.price << endl;
        }
    }
}

int main() {
    int n;
    float minPrice;
    cout << "Enter the number of products: ";
    cin >> n;
    cout << "Enter the minimum price: ";
    cin >> minPrice;

    vector<Product> products(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter product " << i + 1 << "'s name: ";
        cin >> products[i].name;
        cout << "Enter product " << i + 1 << "'s price: ";
        cin >> products[i].price;
    }

    findProducts(products, minPrice);

    return 0;
}
This code first takes the number of products and the minimum price as input. Then it takes the name and price of each product as input. It then checks if each product is eligible for free shipping by comparing the product price with the minimum price. If the product meets the minimum price requirement, it is printed out.