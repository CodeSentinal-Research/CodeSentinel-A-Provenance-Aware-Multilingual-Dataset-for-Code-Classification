def is_neon_number(n):
    sum_of_squares = sum(int(digit) for digit in str(n))
    return sum_of_squares == n

def main():
    n = int(input("Enter a number: "))
    print(is_neon_number(n))

if __name__ == "__main__":
    main()