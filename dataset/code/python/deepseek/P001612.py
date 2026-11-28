def ways_to_split_array(arr):
    total = sum(arr)
    if total % 3 != 0:
        return 0
    target_sum = total // 3
    count = 0
    left = 0
    total_sum = 0
    for i, num in enumerate(arr):
        total_sum += num
        if total_sum == target_sum:
            count += (left == 0)
            left += 1
        elif total_sum > target_sum:
            total_sum -= arr[i - (left - 1)]
            left -= 1
    return count

def main():
    N = int(input().strip())
    arr = list(map(int, input().strip().split()))
    print(ways_to_split_array(arr))

if __name__ == "__main__":
    main()