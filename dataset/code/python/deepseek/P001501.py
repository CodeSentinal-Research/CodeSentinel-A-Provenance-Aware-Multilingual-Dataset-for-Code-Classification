def maxDistToClosest(seats):
    N = len(seats)
    left, right = [0]*N, [0]*N
    min_distance = float('inf')
    max_distance = 0

    for i in range(N):
        if seats[i] == 1:
            min_distance = 0
        else:
            min_distance += 1
        left[i] = min_distance

    min_distance = float('inf')
    for i in range(N-1, -1, -1):
        if seats[i] == 1:
            min_distance = 0
        else:
            min_distance += 1
        right[i] = min_distance

    for i in range(N):
        max_distance = max(max_distance, left[i] + right[i])

    return max_distance

def main():
    N = int(input().strip())
    seats = list(map(int, input().strip().split()))
    print(maxDistToClosest(seats))

if __name__ == "__main__":
    main()