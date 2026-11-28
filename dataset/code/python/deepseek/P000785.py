def pivotIndex(nums):
    left_sum = 0
    total_sum = sum(nums)
    for i, num in enumerate(nums):
        total_sum -= num
        if left_sum == total_sum:
            return i
        left_sum += num
    return -1

def main():
    n = int(input("Enter the number of elements: "))
    nums = list(map(int, input("Enter the elements: ").split()))
    print(pivotIndex(nums))

if __name__ == "__main__":
    main()