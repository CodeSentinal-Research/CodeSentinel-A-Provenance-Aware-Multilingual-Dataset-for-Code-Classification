def max_difference(N, array):
    min_val = array[0]
    max_diff = 0

    for i in range(1, N):
        if array[i] < min_val:
            min_val = array[i]
        elif array[i] - min_val > max_diff:
            max_diff = array[i] - min_val

    return max_diff

def main():
    N = int(input().strip())
    array = list(map(int, input().strip().split()))
    print(max_difference(N, array))

if __name__ == "__main__":
    main()