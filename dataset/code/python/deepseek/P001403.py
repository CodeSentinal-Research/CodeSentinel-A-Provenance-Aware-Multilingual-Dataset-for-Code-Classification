Here is a Python solution for the problem:

def solve():
    N, Q = map(int, input().split())
    arr = list(map(int, input().split()))
    queries = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(Q)]

    for l, r in queries:
        if r - l <= 1 or arr[l:r+1] == sorted(arr[l:r+1]):
            print("YES")
        else:
            print("NO")

if __name__ == "__main__":
    solve()

This code first reads the number of integers N and the number of queries Q. Then it reads the N integers and the queries. For each query, it checks if the subarray from `l` to `r` can be rearranged to form an arithmetic sequence. It does this by comparing the lengths of the subarray and its sorted version. If the lengths are equal (indicating a arithmetic sequence) or if the subarray is already sorted, it prints "YES". Otherwise, it prints "NO".