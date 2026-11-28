def find_max_product(nums):
    max1, max2 = [None, None]
    min1, min2 = [None, None]

    for num in nums:
        if num > max1:
            max1, max2 = num, max1
        elif num > max2:
            max2 = num

        if num < min1:
            min1, min2 = num, min1
        elif num < min2:
            min2 = num

    return max(max1 * max2, max1 * min1, max2 * min2)

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(find_max_product(nums))

if __name__ == "__main__":
    main()