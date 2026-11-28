def is_perfect(n):
    if n < 1 or n > 10000:
        return "Invalid input"

    sum = 1
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            if i * (n // i) == n:
                sum = sum + i + n//i
                i += 1
    if sum == n:
        return "Perfect"
    else:
        return "Not Perfect"

def main():
    n = int(input("Enter a positive integer: "))
    print(is_perfect(n))

if __name__ == "__main__":
    main()