def check_neon_number(n):
    sum_of_squares = sum([int(digit) for digit in str(n)])
    if n == sum_of_squares:
        print("Neon")
    else:
        print("Not Neon")

def main():
    n = int(input("Enter a positive integer: "))
    if not (1 <= n <= 1000):
        print("Input should be between 1 and 1000")
        return
    check_neon_number(n)

if __name__ == "__main__":
    main()