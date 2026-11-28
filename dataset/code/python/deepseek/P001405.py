Here is the Python code for the given problem:

def count_nice_pairs(nums):
    count = 0
    for i in range(len(nums)):
        num = nums[i]
        rev_num = int(str(num)[::-1])
        for j in range(i + 1, len(nums)):
            if num + rev_num == nums[j] + rev_num:
                count += 1
    return count

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(count_nice_pairs(nums))

if __name__ == "__main__":
    main()

In this code, the `count_nice_pairs` function iterates through each number in the input list `nums`, reverses it, and then checks for pairs in the remaining list that sum up to the reversed number plus the original number. If a pair is found, it increments a counter. The main function reads the number of elements N and the elements themselves, calls the `count_nice_pairs` function with these inputs, and prints the result.