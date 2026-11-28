Here is the Python code for the problem:

def findDuplicate(nums):
    nums_set = set()
    for num in nums:
        if num in nums_set:
            return num
        nums_set.add(num)
    return -1

def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(findDuplicate(nums))

if __name__ == "__main__":
    main()
This code defines a function called `findDuplicate` that takes an array of integers as input and returns the first duplicate value if one exists. The main function reads the input and calls the `findDuplicate` function.