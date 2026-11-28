#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {
    string name;
};

vector<Product> searchProductsByNameSuffix(const vector<Product>& products, const string& suffix) {
    vector<Product> matchingProducts;

    for (const Product& product : products) {
        if (product.name.substr(product.name.size() - suffix.size()) == suffix) {
            matchingProducts.push_back(product);
        }
    }

    return matchingProducts;
}

int main() {
    vector<Product> products = {
        {"apple"},
        {"banana"},
        {"cherry"},
        {"date"},
        {"elderberry"},
        {"fig"},
        {"grape"},
        {"honeydew"},
        {"iceberg"},
        {"jambolan"},
        {"kiwi"},
        {"lemon"},
        {"mango"},
        {"nectarine"},
        {"orange"},
        {"pineapple"},
        {"quince"},
        {"raspberry"},
        {"strawberry"},
        {"tomato"},
        {"ugli"}
    };

    string suffix = "berry";

    vector<Product> matchingProducts = searchProductsByNameSuffix(products, suffix);

    for (const Product& product : matchingProducts) {
        cout << product.name << endl;
    }

    return 0;
}

This C++ code defines a struct for a Product and a function to search for Products with a given name suffix. The main function demonstrates this by setting up a list of products and a suffix, then calling the search function to find and print out all products whose names end with the suffix.