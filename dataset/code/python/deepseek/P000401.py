Here's a simple Python solution using list comprehension.

def search_products_with_low_stock(product_records, stock_threshold):
    return [product for product in product_records if product['stock'] < stock_threshold]

def main():
    product_records = [{'product_id': 1, 'product_name': 'product1', 'stock': 10}, 
                       {'product_id': 2, 'product_name': 'product2', 'stock': 5}, 
                       {'product_id': 3, 'product_name': 'product3', 'stock': 6},
                       {'product_id': 4, 'product_name': 'product4', 'stock': 7},
                       {'product_id': 5, 'product_name': 'product5', 'stock': 20}]
    stock_threshold = 5
    products_with_low_stock = search_products_with_low_stock(product_records, stock_threshold)
    for product in products_with_low_stock:
        print(f'Product ID: {product["product_id"]}, Product Name: {product["product_name"]}, Stock: {product["stock"]}')

if __name__ == "__main__":
    main()

In this solution, the `search_products_with_low_stock` function takes a list of product records and a stock threshold as inputs. It then returns a list of products whose stock is less than the threshold. The `main` function demonstrates this by creating a list of product records, setting the stock threshold to 5, and calling the `search_products_with_low_stock` function with the product records and stock threshold. It then prints the product IDs, product names, and stock quantities of the products in the list of products with low stock.

Please note that this is a basic solution and might not be the most efficient one depending on the use case. For example, if you need to perform more complex operations on the product records such as adding or removing products, this solution would not be sufficient.