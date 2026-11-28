Here is a Python solution that uses recursion to count the occurrences of a target value in a list.

def count_occurrences(nums, target):
    if len(nums) == 0:
        return 0
    elif nums[0] == target:
        return 1 + count_occurrences(nums[1:], target)
    else:
        return count_occurrences(nums[1:], target)

def main():
    nums = list(map(int, input("Enter numbers separated by space: ").strip().split()))
    target = int(input("Enter target: "))

    occurrences = count_occurrences(nums, target)

    print("Number of occurrences of {} is {}".format(target, occurrences))

if __name__ == "__main__":
    main()

In this code, the `count_occurrences` function uses recursion to count the occurrences of the target value in the list. It first checks if the list is empty, in which case it returns 0. If the first element of the list is the target, it returns 1 plus the count of the rest of the list (nums[1:]), otherwise, it returns the count of the rest of the list.

The `main` function first reads the input values, counts the occurrences of the target using `count_occurrences`, and then prints the result.