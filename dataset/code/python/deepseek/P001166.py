def max_subarray_sum(arr):
    current_sum = max_sum = arr[0]
    for num in arr[1:]:
        current_sum = max(num, current_sum + num)
        max_sum = max(max_sum, current_sum)
    return max_sum

def main():
    n = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(max_subarray_sum(arr))

if __name__ == "__main__":
    main()