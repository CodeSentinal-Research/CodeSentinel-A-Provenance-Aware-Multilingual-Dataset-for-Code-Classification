Here is the Python code for the problem:

def solve():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    Q = int(input().strip())
    for _ in range(Q):
        L, R = map(int, input().strip().split())
        print(sum(nums[L:R+1]) / (R-L+1))

if __name__ == "__main__":
    solve()

This code first reads the array of integers and the number of queries. For each query, it reads the range L and R, and prints the average of the elements in that range.