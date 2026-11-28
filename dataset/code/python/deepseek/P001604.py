def countSubarrays(A, K):
    count = 0
    for i in range(len(A)):
        total = 0
        for j in range(i, len(A)):
            total += A[j]
            if total == K:
                count += 1
    return count

def main():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    print(countSubarrays(A, K))

if __name__ == "__main__":
    main()