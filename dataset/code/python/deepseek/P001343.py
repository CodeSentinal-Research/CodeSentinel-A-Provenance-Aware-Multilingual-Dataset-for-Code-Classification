def generate_gray(n):
    for x in range(0, 2**n):
        y = x ^ (2**n - 1)
        print(bin(y)[2:].zfill(n))

def main():
    N = int(input())
    generate_gray(N)

if __name__ == "__main__":
    main()