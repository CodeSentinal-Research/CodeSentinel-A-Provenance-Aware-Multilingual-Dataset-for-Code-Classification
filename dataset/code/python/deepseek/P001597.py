def count_elements(A, L, R, X):
    count = 0
    for i in range(L, R+1):
        if A[i] == X:
            count += 1
    return count

def solve():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    Q = int(input().strip())
    for _ in range(Q):
        L, R, X = map(int, input().strip().split())
        print(count_elements(A, L, R, X))

if __name__ == "__main__":
    solve()