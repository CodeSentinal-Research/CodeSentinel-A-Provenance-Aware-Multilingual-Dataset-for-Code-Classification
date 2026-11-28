def can_split(arr):
    n = len(arr)

    starts = [0] * n
    ends = [0] * n

    ends[0] = arr[0]

    for i in range(1, n):
        if arr[i] < ends[i-1]:
            starts[i] = arr[i]
            ends[i] = ends[i-1] + arr[i]
        else:
            starts[i] = arr[i]
            ends[i] = ends[i-1] + arr[i]

    for i in range(n):
        if i > 0 and starts[i] - ends[i-1] < arr[i-1] - arr[i]:
            return "NO"

    return "YES"


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(can_split(arr))


if __name__ == "__main__":
    main()