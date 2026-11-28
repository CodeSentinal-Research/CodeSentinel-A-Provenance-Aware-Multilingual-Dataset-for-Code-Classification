Here is the Python code:

def find_arithmetic_slices(nums):
    count = 0
    for i in range(len(nums)):
        for j in range(i+2, len(nums)+1):
            diff = nums[j] - nums[i]
            if nums[j] - nums[j-1] == diff:
                count += 1
    return count

def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(find_arithmetic_slices(nums))

main()

In this code, we first read the number of elements (`n`) and the elements themselves (`nums`). We then call the function `find_arithmetic_slices` with `nums` as argument and print the result.

The `find_arithmetic_slices` function iterates through the array and for each element, it finds all possible arithmetic slices starting from that element and ending at the end of the array. It then checks if the difference between the current element and the previous element is the same as the difference between the current element and the next element. If they are the same, it means we have found an arithmetic slice, so it increments the count. Finally, it returns the count.