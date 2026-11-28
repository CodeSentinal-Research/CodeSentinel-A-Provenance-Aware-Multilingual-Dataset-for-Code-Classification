def count_leading_zeros(n):
    binary = bin(n)[2:]
    return binary.count('0')

def main():
    n = int(input("Enter a 32-bit unsigned integer: "))
    while not (0 <= n <= 2**32 - 1):
        print("Invalid input. Please enter a 32-bit unsigned integer between 0 and 2^32 - 1.")
        n = int(input("Enter a 32-bit unsigned integer: "))
    print("Number of leading zeros: ", count_leading_zeros(n))

if __name__ == "__main__":
    main()