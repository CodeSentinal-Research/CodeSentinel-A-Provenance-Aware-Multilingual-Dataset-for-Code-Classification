Here is the Python code:

def singleNumber(nums):
    return [num for num in set(nums) if nums.count(num) == 1][0]

This code works by first converting the input list `nums` into a set, which automatically removes any duplicates because sets can only contain unique elements. Then it creates a list of elements from the set that appear only once in the original list. The final result is the first element of this list, which is the unique element.

The main function to handle the input:

def main():
    nums = [int(x) for x in input().split()]
    print(singleNumber(nums))

if __name__ == "__main__":
    main()

In this code, the main function reads a line of numbers from standard input, splits this line into a list of numbers, and then calls the `singleNumber` function with this list as an argument. The `singleNumber` function then prints the result.