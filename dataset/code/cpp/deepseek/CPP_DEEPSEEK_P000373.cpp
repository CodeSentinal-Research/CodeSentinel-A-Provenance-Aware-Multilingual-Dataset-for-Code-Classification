#include <iostream>
#include <unordered_map>

using namespace std;

struct Product {
    int productCode;
    string name;
    double price;
};

int main() {
    int numProducts;
    cin >> numProducts;

    unordered_map<int, Product> productMap;

    for (int i = 0; i < numProducts; i++) {
        Product product;
        cin >> product.productCode >> product.name >> product.price;
        productMap[product.productCode] = product;
    }

    int productCodeToFind;
    cin >> productCodeToFind;

    if (productMap.find(productCodeToFind) != productMap.end()) {
        cout << productMap[productCodeToFind].productCode << " "
             << productMap[productCodeToFind].name << " "
             << productMap[productCodeToFind].price << endl;
    } else {
        cout << "Product Not Found" << endl;
    }

    return 0;
}