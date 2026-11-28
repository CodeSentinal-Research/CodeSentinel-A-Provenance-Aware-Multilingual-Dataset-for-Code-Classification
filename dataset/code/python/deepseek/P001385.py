def find_missing_numbers(N, arr):
    expected_set = set(range(1, N+1))
    given_set = set(arr)
    missing_numbers = expected_set - given_set
    return sorted(list(missing_numbers))


def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    missing_numbers = find_missing_numbers(N, arr)
    print(missing_numbers)


if __name__ == "__main__":
    main()