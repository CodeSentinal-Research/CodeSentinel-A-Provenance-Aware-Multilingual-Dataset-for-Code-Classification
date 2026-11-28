def factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial(n-1)

def main():
    n = int(input("Enter a non-negative integer: "))
    while not (0 <= n <= 20):
        n = int(input("Input must be a non-negative integer between 0 and 20. Enter again: "))
    print(f"The factorial of {n} is {factorial(n)}")

if __name__ == "__main__":
    main()