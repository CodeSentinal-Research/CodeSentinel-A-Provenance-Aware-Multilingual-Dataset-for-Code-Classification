def find_max_repeating(n, k, arr):
    count_arr = [0]*k

    for i in range(n):
        count_arr[arr[i]] += 1

    max_repeating = max(count_arr)

    return max_repeating


def main():
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))

    print(find_max_repeating(n, k, arr))


if __name__ == "__main__":
    main()