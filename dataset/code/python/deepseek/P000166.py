Here is the Python code for the problem.

def min_product_subarray():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    
    min_product = float('inf')
    max_product = float('-inf')
    min_product_global = float('inf')
    max_product_global = float('-inf')
    last_min_product = 0
    last_max_product = 0
    
    for num in arr:
        last_max_product = max(last_max_product * num, num)
        last_min_product = min(last_min_product * num, num)
        
        max_product = max(max_product, last_max_product)
        min_product = min(min_product, last_min_product)
        
        min_product_global = min(min_product_global, min_product)
        max_product_global = max(max_product_global, max_product)
        
    print(min_product_global)

min_product_subarray()

This code first reads the size of the array and the elements of the array from the input. Then it initializes the minimum product, maximum product, global minimum product, and global maximum product. This is done for two different reasons: first, it ensures that if the maximum product is less than the minimum product, then the minimum product will be updated. Second, it ensures that the maximum product is always greater than the minimum product.

After this, the code iterates over each element of the array. For each element, it updates the maximum product and the minimum product. It also updates the global minimum and maximum product. Finally, it prints the global minimum product.