Here is the C++ code for your problem:

#include <iostream>
#include <vector>
#include <algorithm>

struct Product {
    int id;
    float price;
};

void searchProducts(const std::vector<Product>& products, float minPrice, float maxPrice) {
    std::vector<Product> matchingProducts;
    for (const auto& product : products) {
        if (product.price >= minPrice && product.price <= maxPrice) {
            matchingProducts.push_back(product);
        }
    }

    if (matchingProducts.empty()) {
        std::cout << "No products found in the price range." << std::endl;
    } else {
        std::cout << "Matching products:" << std::endl;
        for (const auto& product : matchingProducts) {
            std::cout << "Product ID: " << product.id << ", Price: " << product.price << std::endl;
        }
    }
}

int main() {
    std::vector<Product> products = {
        {1, 1.5},
        {2, 2.5},
        {3, 2.9},
        {4, 4.5},
        {5, 5.0},
        {6, 4.8},
        {7, 4.2}
    };

    float minPrice, maxPrice;
    std::cout << "Enter minimum price: ";
    std::cin >> minPrice;
    std::cout << "Enter maximum price: ";
    std::cin >> maxPrice;

    searchProducts(products, minPrice, maxPrice);

    return 0;
}

In this code, we define a struct `Product` to represent the product records. In the `searchProducts` function, we iterate over the product records and check if each product's price falls within the given range. If a product matches the range, we add it to the `matchingProducts` vector. In the `main` function, we take user input for the minimum and maximum price, and call the `searchProducts` function with these values.