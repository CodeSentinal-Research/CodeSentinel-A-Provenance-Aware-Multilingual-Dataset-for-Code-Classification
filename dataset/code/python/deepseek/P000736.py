def findKthGrammar(N, K):
    if N == 1:
        return 0
    else:
        if K % 2 == 0:
            return findKthGrammar(N - 1, K // 2) ^ 1
        else:
            return findKthGrammar(N - 1, (K + 1) // 2) ^ 0

def main():
    N = int(input("Enter the value of N: "))
    K = int(input("Enter the value of K: "))
    print(findKthGrammar(N, K))

if __name__ == "__main__":
    main()