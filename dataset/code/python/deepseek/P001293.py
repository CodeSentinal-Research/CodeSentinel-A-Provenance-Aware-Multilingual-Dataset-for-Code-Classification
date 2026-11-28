def max_product_after_k_increments(N, K, arr):
    arr.sort()
    
    max_product = 1
    
    for i in range(N):
        product = arr[i] * arr[N-i-1]
        max_product = max(max_product, product)
    
    return max_product

N, K = map(int, input().split())
arr = list(map(int, input().split()))

print(max_product_after_k_increments(N, K, arr))