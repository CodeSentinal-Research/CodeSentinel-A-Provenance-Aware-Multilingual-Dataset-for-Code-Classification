def find_max_length(arr):
    n = len(arr)

    positive_product = 1
    length = 0

    count_positive = 0
    max_length = 0

    for i in range(n):
        if arr[i] > 0:
            count_positive += 1
            positive_product *= arr[i]
        else:
            count_positive = 0
            positive_product = 1

        if count_positive > length:
            length = count_positive

    return length


def main():
    n = int(input())
    arr = list(map(int, input().split()))
    print(find_max_length(arr))


if __name__ == "__main__":
    main()