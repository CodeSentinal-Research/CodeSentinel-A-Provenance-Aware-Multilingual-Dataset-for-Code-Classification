Here is the Python code:

def solve():
    N, K = map(int, input().split())
    A = list(map(int, input().split()))

    for i in range(N - K + 1):
        window = A[i : i + K]
        print(sum(abs(a - b) for a, b in zip(window, window[1:])))

if __name__ == "__main__":
    solve()

In this code, the `solve` function first takes the number of elements and the window size as input, then it takes the array of integers as input. Then for every starting point `i` in the range from 0 to `N - K + 1`, it calculates a window of size `K` starting from position `i` and computes the sum of absolute differences between consecutive elements in this window. The `zip` function is used to pair each element in the window with the next element in the window.