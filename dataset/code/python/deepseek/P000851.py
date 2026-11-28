def set_kth_bit(N, K):
    return N | (1 << K)

def main():
    N = int(input("Enter an integer N: "))
    K = int(input("Enter an integer K: "))
    print("The modified integer is: ", set_kth_bit(N, K))

if __name__ == "__main__":
    main()