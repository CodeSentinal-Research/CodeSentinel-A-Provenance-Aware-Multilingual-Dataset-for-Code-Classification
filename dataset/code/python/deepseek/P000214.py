Here is a Python solution:

def findDisappearedNumbers(nums):
    n = len(nums)
    missing_nums = set(range(1, n+1)) - set(nums)
    return list(missing_nums)

def main():
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(findDisappearedNumbers(nums))

if __name__ == "__main__":
    main()

In this code, we use a set operation to find all missing numbers. The set operation is a set of all the elements in the first set, minus the elements in the second set. The result is a set of all the elements that are in the first set, but not in the second.

In the `main` function, we first read the number of elements N from the first line of input. Then we read the list of integers from the second line. The `findDisappearedNumbers` function is then called with this list as argument. Finally, we print the result.

You can run this program with a test case like this:

5
4 3 2 7 8

This will print: `[1, 5]`, as these are the missing numbers in the array.