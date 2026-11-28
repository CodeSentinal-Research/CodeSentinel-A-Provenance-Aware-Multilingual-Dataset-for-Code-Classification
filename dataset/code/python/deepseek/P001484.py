def find_longest_mountain(array):
    max_length = 0
    for i in range(1, len(array) - 1):
        if array[i] > array[i - 1] and array[i] > array[i + 1]:
            left = i
            while left > 0 and array[left - 1] < array[left]:
                left -= 1
            right = i
            while right < len(array) - 1 and array[right + 1] < array[right]:
                right += 1
            length = right - left + 1
            if length > max_length:
                max_length = length
    return max_length


def main():
    n = int(input().strip())
    array = list(map(int, input().strip().split()))
    print(find_longest_mountain(array))


if __name__ == "__main__":
    main()