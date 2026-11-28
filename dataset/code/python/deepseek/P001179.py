Here is a Python solution for the problem:

def max_merit_points():
    N = int(input().strip())
    points = []
    for _ in range(N):
        a, b, c = map(int, input().strip().split())
        points.append((a+b+c, a, b, c))
    points.sort()
    dp = [0] * N
    dp[0] = points[0][1]
    dp[1] = max(points[0][1], points[1][2])
    for i in range(2, N):
        dp[i] = max(dp[i-1], dp[i-2] + points[i][1], points[i][2] + points[i-1][1])
    print(dp[-1])

if __name__ == "__main__":
    max_merit_points()

The function `max_merit_points` first reads the number of training days (N) and for each day, it reads three integers and appends a tuple of these integers and their sum to a list `points`.

Then, it sorts this list in descending order.

Finally, it uses dynamic programming to calculate the maximum merit points. It initializes a list `dp` with the first two elements of `points` and the maximum of the first two activities as the third element in `points`. It then iterates over the rest of the list, updating `dp` to be the maximum of the previous element, the previous element plus the merit points of the current element, and the current element's merit points plus the merit points of the previous element.

The maximum merit points are stored in the last element of `dp`, and this is printed as the output.