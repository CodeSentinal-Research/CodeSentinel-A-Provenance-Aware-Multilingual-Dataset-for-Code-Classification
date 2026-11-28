Here is the Python solution:

def insertion_sort(nums):
    if len(nums) == 1:
        return nums
    else:
        first = nums[0]
        rest = insertion_sort(nums[1:])
        i = rest.index(max(rest))
        if first > rest[i]:
            return first + rest
        else:
            return first + insertion_sort(rest)

def main():
    n = int(input("Enter the number of elements in the array: "))
    nums = list(map(int, input("Enter the elements of the array: ").split()))
    sorted_nums = insertion_sort(nums)
    print("The sorted array is: ", sorted_nums)

if __name__ == "__main__":
    main()

In this code, the function `insertion_sort` is a recursive implementation of the Insertion Sort algorithm. It takes as input a list of integers and returns a sorted version of it. The base case for the recursion is when the list has one or zero elements, in which case the list is already sorted. For the recursive case, we take the first element of the list, insert it in the sorted part of the rest of the list (obtained by calling `insertion_sort` on the rest of the list), and concatenate the two parts.

The `main` function reads the number of elements to sort and the elements to sort from the standard input, sorts them using `insertion_sort`, and prints the sorted array.