def decode(encoded):
    n = len(encoded)
    original = [0] * n
    xor = 0
    for i in range(1, n+1):
        if i % 2 == 0:
            xor ^= i
        else:
            original[i//2 - 1] = xor
            xor ^= i
    original[-1] = xor
    return original

def main():
    n = int(input("Enter the number of integers: "))
    while n < 3 or n > 10**5 or n % 2 == 0:
        n = int(input("Invalid input. Enter a number between 3 and 10^5, and odd: "))
    encoded = list(map(int, input("Enter the XOR-encoded representation of the permutation: ").split()))
    original = decode(encoded)
    print("The original permutation is: ", original)

if __name__ == "__main__":
    main()