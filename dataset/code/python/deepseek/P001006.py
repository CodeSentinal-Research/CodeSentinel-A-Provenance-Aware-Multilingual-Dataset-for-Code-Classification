def verify_min_heap(array):
    for i in range(len(array)):
        parent = i
        left = 2 * i + 1
        right = 2 * i + 2

        if left < len(array) and array[left] < array[parent]:
            parent = left

        if right < len(array) and array[right] < array[parent]:
            parent = right

        if i != 0 and array[i] < array[parent]:
            return 'NO'

    return 'YES'


def main():
    n = int(input().strip())
    array = list(map(int, input().strip().split()))
    print(verify_min_heap(array))


if __name__ == "__main__":
    main()