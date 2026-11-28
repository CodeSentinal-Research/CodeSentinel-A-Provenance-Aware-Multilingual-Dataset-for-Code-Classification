def check_kth_bit(N, K):
    if (N >> K) & 1 == 1:
        return True
    else:
        return False

def main():
    N = int(input("Enter a positive integer: "))
    K = int(input("Enter the position of the bit to check: "))
    if check_kth_bit(N, K):
        print("Bit is set")
    else:
        print("Bit is not set")

if __name__ == "__main__":
    main()