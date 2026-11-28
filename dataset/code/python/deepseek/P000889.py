def is_prime(N):
    if N <= 1:
        return False
    if N == 2:
        return True
    if N % 2 == 0:
        return False

    max_divisor = int(N**0.5) + 1
    for d in range(3, max_divisor, 2):
        if N % d == 0:
            return False
    return True

def main():
    N = int(input("Enter a number: "))
    if is_prime(N):
        print("True")
    else:
        print("False")

if __name__ == "__main__":
    main()