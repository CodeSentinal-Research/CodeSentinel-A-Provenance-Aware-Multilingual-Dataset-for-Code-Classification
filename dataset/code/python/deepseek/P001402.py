def check_divisibility(N, K):
    if N % K == 0:
        return 'YES'
    else:
        return 'NO'

def main():
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    print(check_divisibility(N, K))

if __name__ == "__main__":
    main()