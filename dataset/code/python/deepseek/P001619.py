Here's a Python code for the given problem:

def solve():
    N = int(input().strip())
    A = list(map(int, input().strip().split()))
    Q = int(input().strip())

    prefix_xor = [A[0]]
    for i in range(1, N):
        prefix_xor.append(prefix_xor[-1] ^ A[i])

    for _ in range(Q):
        L, R = map(int, input().strip().split())
        if L == 0:
            print(prefix_xor[R])
        else:
            print(prefix_xor[R] ^ prefix_xor[L-1])

if __name__ == "__main__":
    solve()

In this code, we first read the number of elements N and the array A, and then the number of queries Q. We then calculate the prefix XOR of the array A and store it in a list. For each query, we read the range L and R, and print the XOR of the elements in this range.