Here's the Python code for the problem.

def find_products_in_price_range(products, min_price, max_price):
    return [product for product in products if min_price <= product['price'] <= max_price]

def main():
    products = [
        {'name': 'Product1', 'price': 20},
        {'name': 'Product2', 'price': 40},
        {'name': 'Product3', 'price': 10},
        {'name': 'Product4', 'price': 50},
        {'name': 'Product5', 'price': 30},
    ]
    min_price = 10
    max_price = 50

    matching_products = find_products_in_price_range(products, min_price, max_price)
    for product in matching_products:
        print(product['name'])

if __name__ == "__main__":
    main()

In this code, we define a function `find_products_in_price_range` that takes a list of products and a minimum and maximum price as arguments, and returns a list of products that meet the condition.

In the main function, we first define a list of products and a range of prices. We then call the function `find_products_in_price_range` with these arguments, and print the names of the products that meet the condition.

Please note that the input to this code is hard-coded, as the purpose of this code is to illustrate the process in a simple manner. In a real-world scenario, you might want to take user inputs, or handle exceptions.