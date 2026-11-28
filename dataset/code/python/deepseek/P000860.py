def find_complement(N):
    return 2 ** (len(bin(N)) - 2) - N - 1

def main():
    N = int(input('Enter a non-negative integer: '))
    print(find_complement(N))

if __name__ == "__main__":
    main()