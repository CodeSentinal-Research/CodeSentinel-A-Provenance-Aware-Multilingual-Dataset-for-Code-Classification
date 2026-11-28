def dec_to_bin(n):
    if n == 0:
        return 0
    else:
        return (n % 2 + 10 * dec_to_bin(int(n / 2)))

def main():
    N = int(input("Enter a non-negative integer N: "))
    print(dec_to_bin(N))

if __name__ == "__main__":
    main()