def maxDistance(n, positions, m):
    positions.sort()
    min_dist = positions[1] - positions[0]
    for i in range(2, m):
        min_dist = min(min_dist, positions[i] - positions[i-1])
    return min_dist

def main():
    n = int(input())
    positions = list(map(int, input().split()))
    m = int(input())
    print(maxDistance(n, positions, m))

if __name__ == "__main__":
    main()