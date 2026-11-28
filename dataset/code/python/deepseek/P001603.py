Here's the Python code:

def solve():
    N, X = map(int, input().split())
    arr = list(map(int, input().split()))

    prefix_sums = [arr[0]]
    for i in range(1, N):
        prefix_sums.append(prefix_sums[-1] + arr[i])

    l, r = 0, 10**9
    while l < r:
        mid = (l + r + 1) // 2
        if any(x >= mid for x in prefix_sums):
            r = mid - 1
        else:
            l = mid

    if l == 10**9:
        print(-1)
    else:
        print(l)

if __name__ == "__main__":
    solve()

This code first takes the size of the array and the target sum X as input. Then it takes the actual array as input.

The prefix sums are calculated and stored in a list.

Then a binary search is performed on the range from 0 to 10^9 (inclusive). In each iteration, if there exists a prefix sum greater than or equal to the mid point, we know that mid point cannot be the smallest prefix length, so we adjust the right bound to mid-1. If not, then mid point is the smallest prefix length we can find.

If no such prefix sum exists, we print -1. Otherwise, we print the smallest prefix length.