def solve(N, arr):
    squares = []
    for num in arr:
        squares.append(num ** 2)
    squares.sort()
    return squares


def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(solve(N, arr))


if __name__ == "__main__":
    main()