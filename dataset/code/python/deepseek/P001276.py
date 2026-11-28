Here is a Python solution for the problem.

def maxDistToClosest(seats):
    N = len(seats)
    dists = [0]*N
    empty, wall = -1, 0
    left, right = [0]*N, [0]*N
    for i in range(N):
        if seats[i] == 0:
            dists[i] = 0
        else:
            dists[i] = float('inf')
    for i in range(N):
        if seats[i] == 0:
            left[i] = 0
        else:
            left[i] = left[i-1] + 1 if i > 0 else 0
    for i in range(N-1, -1, -1):
        if seats[i] == 0:
            right[i] = 0
        else:
            right[i] = right[i+1] + 1 if i < N-1 else 0
    for i in range(N):
        if seats[i] == 0:
            dists[i] = min(dists[i], left[i] + right[i])
    return max(dists)

def main():
    N = int(input().strip())
    seats = [int(s) for s in input().strip().split()]
    print(maxDistToClosest(seats))

if __name__ == "__main__":
    main()

This Python solution first computes the distances from the closest seats to the left and right of each empty seat. Then it finds the maximum distance among all empty seats.

The time complexity of this solution is O(N), and the space complexity is O(N).