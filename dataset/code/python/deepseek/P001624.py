def reconstruct_array(difference_array):
    size = len(difference_array)
    original_array = []

    sum_difference = sum(difference_array)

    if sum_difference != 0:
        return "The array cannot be reconstructed because the sum of the differences is not zero."

    difference_array.sort()

    for i in range(size - 1):
        if difference_array[i] < 0:
            if -difference_array[i] > difference_array[i + 1]:
                return "The array cannot be reconstructed."

    for i in range(size - 1):
        if difference_array[i] > 0:
            if difference_array[i] > difference_array[i + 1]:
                return "The array cannot be reconstructed."

    for i in range(size):
        original_array.append(difference_array[i])

    return original_array


def main():
    N = int(input().strip())
    difference_array = list(map(int, input().strip().split()))
    reconstructed_array = reconstruct_array(difference_array)

    if type(reconstructed_array) is str:
        print(reconstructed_array)
    else:
        print(" ".join(map(str, reconstructed_array)))


if __name__ == "__main__":
    main()