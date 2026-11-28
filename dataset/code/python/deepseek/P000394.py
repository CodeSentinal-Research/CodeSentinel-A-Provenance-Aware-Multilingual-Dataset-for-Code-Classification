Sure, here's the Python code for the problem. This code uses dictionary to map brand names to their corresponding products, and then searches through this map to find products of a specific brand.

def search_products_by_brand(records, brand_name):
    brand_products = {}

    for record in records:
        product, brand = record
        brand_products[brand] = brand_products.get(brand, []) + [product]

    if brand_name in brand_products:
        return brand_products[brand_name]
    else:
        return []

records = [('product1', 'brand1'), ('product2', 'brand1'), ('product3', 'brand2'), ('product4', 'brand3')]
brand_name = 'brand1'
print(search_products_by_brand(records, brand_name))  

This code first separates the product records into brands using a dictionary. This allows us to quickly look up all products associated with a specific brand. If the brand does not exist in the dictionary, an empty list is returned.

Then, the function simply checks if the input brand name is in the dictionary. If it is, it returns the list of products for that brand.