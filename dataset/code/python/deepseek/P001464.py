def move_zeroes(arr):
    start = 0
    end = len(arr) - 1

    while start < end:
        if arr[start] != 0:
            start += 1
        elif arr[end] == 0:
            end -= 1
        elif arr[end] != 0:
            end -= 1

        if start == end:
            start += 1

    return arr


def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    result = move_zeroes(arr)
    print(' '.join(map(str, result)))


if __name__ == '__main__':
    main()