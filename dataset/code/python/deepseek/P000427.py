Here is a Python solution using a dictionary for input handling and list for product selection.

def search_products(product_records, min_price):
    product_records = dict(product_records)
    eligible_products = [product for product, price in product_records.items() if price >= min_price]
    return eligible_products

def main():
    product_records = [('product1', 10), ('product2', 20), ('product3', 15)]
    min_price = 20
    print(search_products(product_records, min_price))

if __name__ == "__main__":
    main()

In this solution, we first define the `search_products` function that takes in a product records list and a minimum price. We then create a dictionary from the input list, and use list comprehension to create a list of products that have a price equal to or greater than the minimum price. Finally, we print out the list of eligible products.

The `main` function is just an example of how to use the `search_products` function. It creates a list of product records, a minimum price, and then calls `search_products` with these parameters.