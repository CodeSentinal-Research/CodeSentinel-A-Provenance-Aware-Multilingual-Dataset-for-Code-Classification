def countBits(n):
    count = 0
    while n:
        n = n & (n - 1)
        count += 1
    return count

def main():
    n = int(input("Enter an integer: "))
    print(countBits(n))

if __name__ == "__main__":
    main()