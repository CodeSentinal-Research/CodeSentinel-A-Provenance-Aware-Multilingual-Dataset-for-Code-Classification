Here is the Python code:

def count_unique_digits(n):
    if n == 0:
        return 1
    if n == 1:
        return 10
    if n == 2:
        return 9 * 10 + 10
    if n == 3:
        return 9 * 9 * 10 + 10 * 9 + 1
    total = 10 * (10 ** (n - 1)) + (10 ** n) - 1
    unique_digits = 9 * (10 ** (n - 1)) + (10 ** n) - (10 ** (n - 1))
    return total - unique_digits

def main():
    n = int(input("Enter the value of N: "))
    print(count_unique_digits(n))

if __name__ == "__main__":
    main()

This code calculates the count of integers in the range [0, 10^N) for a given N. The count includes all unique digits. For example, if N = 2, the range is [0, 10^2) = [0, 100), and the count includes all unique digits (0-9).