def solve():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    Q = int(input())
    for _ in range(Q):
        L, R = map(int, input().split())
        count = sum(1 for i in range(L, R+1) if A[i] % K == 0)
        print(count)

if __name__ == "__main__":
    solve()