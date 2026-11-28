def find_pivot(arr):
    left_sum = 0
    total_sum = sum(arr)

    for i, num in enumerate(arr):
        total_sum -= num
        if left_sum == total_sum:
            return i
        left_sum += num

    return -1

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))

    print(find_pivot(arr))

if __name__ == "__main__":
    main()