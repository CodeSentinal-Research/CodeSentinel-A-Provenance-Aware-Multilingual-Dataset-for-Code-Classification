def product_of_digits(n):
    if n < 10:
        return n
    else:
        return n % 10 * product_of_digits(n // 10)

def main():
    n = int(input())
    print(product_of_digits(n))

if __name__ == "__main__":
    main()