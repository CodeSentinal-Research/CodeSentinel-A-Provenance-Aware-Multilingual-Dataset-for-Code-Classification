def find_product(product_codes, product_code_to_find):
    for product_code in product_codes:
        if product_code == product_code_to_find:
            return product_code
    return "Product Not Found"

product_codes = ['P123', 'P456', 'P789']
product_code_to_find = 'P123'
print(find_product(product_codes, product_code_to_find))