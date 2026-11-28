Here is the Python code:

def majorityElement(nums):
    if not nums:
        return []
    count1, count2, candidate1, candidate2 = 0, 0, 0, 0
    for num in nums:
        if num == candidate1:
            count1 += 1
        elif num == candidate2:
            count2 += 1
        elif count1 == 0:
            candidate1, count1 = num, 1
        elif count2 == 0:
            candidate2, count2 = num, 1
        else:
            count1, count2 = count1-1, count2-1
    return [n for n in (candidate1, candidate2)
            if nums.count(n) > len(nums) // 3]

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(majorityElement(nums))

if __name__ == '__main__':
    main()

This code uses a variant of the Boyer-Moore voting algorithm to find the majority elements in the array. It counts the number of occurrences of each element and removes elements until only one element left.