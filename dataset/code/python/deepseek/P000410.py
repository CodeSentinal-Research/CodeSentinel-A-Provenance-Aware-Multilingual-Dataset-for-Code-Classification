Sure, here is the Python code for the problem:

def search_products_by_suffix(product_records, suffix):
    return [product for product in product_records if product.endswith(suffix)]

class Product:
    def __init__(self, name):
        self.name = name

def main():
    product_records = [Product('product1'), Product('product2'), Product('product3'), Product('product4'), Product('product5')]
    suffix = '2'
    result = search_products_by_suffix(product_records, suffix)
    print(result)

if __name__ == "__main__":
    main()

In this code, we define a class `Product` to represent each product with a name. Then we define a function `search_products_by_suffix` that takes a list of `Product` objects and a suffix, and returns a list of all products whose names end with the suffix.

In the `main` function, we create a list of `Product` objects and a suffix, and call `search_products_by_suffix` with these parameters to get the result. Finally, we print the result.

The `main` function is the entry point of the program, and it runs when the script is executed directly. The `if __name__ == "__main__"` part ensures that `main` is only called when the script is run directly, not when it's imported as a module.

Please note that this is a very basic solution and might not work for complex cases. For example, it assumes that product names are unique, and it does not handle potential errors such as `product_records` not being a list or `suffix` not being a string. You may need to modify this code to fit your specific needs.