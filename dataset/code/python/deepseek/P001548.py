Here is the Python code for the problem:

def max_product(arr, k):
    n = len(arr)
    if k > n:
        return "Invalid window size"
    w_product = 1
    for i in range(k):
        w_product *= arr[i]
    max_product = w_product
    for i in range(k, n):
        w_product /= arr[i - k]
        w_product *= arr[i]
        max_product = max(max_product, w_product)
    return max_product

def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(max_product(arr, k))

if __name__ == "__main__":
    main()

In this code, the `max_product` function calculates the product of the first `k` elements, and the `w_product` variable stores this product. Then it initializes `max_product` to be equal to `w_product` and multiplies `w_product` by each element in the remaining part of the array (from the `k`-th to the end). In each iteration, it divides `w_product` by the left-out element to re-calculate it for the next window. If the new product is higher than `max_product`, it replaces `max_product` with this new product.

The `main` function reads the input, calls `max_product` and prints the result.