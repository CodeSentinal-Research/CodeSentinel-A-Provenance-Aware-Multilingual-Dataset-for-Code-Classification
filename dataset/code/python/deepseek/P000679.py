def print_numbers(n):
    if n > 0:
        print(n, end=' ')
        print_numbers(n - 1)

def main():
    n = int(input("Enter a number: "))
    print_numbers(n)

if __name__ == "__main__":
    main()