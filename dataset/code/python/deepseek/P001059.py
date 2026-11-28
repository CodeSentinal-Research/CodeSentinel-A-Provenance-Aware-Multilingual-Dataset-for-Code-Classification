def solve(arr):
    n = len(arr)
    arr_min, arr_max = min(arr), max(arr)
    min_deviation = float('inf')

    for i in range(n):
        if arr[i] % 2 == 0:
            arr[i] /= 2
            min_deviation = min(min_deviation, max(arr) - min(arr))
            arr[i] *= 2

    for i in range(n):
        if arr[i] % 2 != 0:
            arr[i] *= 2
            min_deviation = min(min_deviation, max(arr) - min(arr))
            arr[i] /= 2

    return min_deviation


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(solve(arr))


if __name__ == "__main__":
    main()

This code first calculates the minimum possible deviation by first considering halving all the even numbers and then doubling all the odd numbers. It then returns the minimum of these two options.