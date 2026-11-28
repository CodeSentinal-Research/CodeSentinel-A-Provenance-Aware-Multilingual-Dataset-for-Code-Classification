def clear_kth_bit(N, K):
    return N & ~(1 << K)

def main():
    N = int(input("Enter the number: "))
    K = int(input("Enter the position to clear the bit: "))
    print(clear_kth_bit(N, K))

if __name__ == "__main__":
    main()