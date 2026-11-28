def product_of_digits(n: int) -> int:
    n = abs(n)
    if n == 0:
        return 0
    prod = 1
    for d in str(n):
        prod *= int(d)
    return prod

if __name__ == '__main__':
    n = int(input())
    print(product_of_digits(n))