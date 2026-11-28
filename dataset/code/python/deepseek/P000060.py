def count_even_digits(n):
    count = 0
    while n:
        if n % 2 == 0:
            count += 1
        n //= 2
    return count

def main():
    n = int(input())
    print(count_even_digits(n))

if __name__ == "__main__":
    main()