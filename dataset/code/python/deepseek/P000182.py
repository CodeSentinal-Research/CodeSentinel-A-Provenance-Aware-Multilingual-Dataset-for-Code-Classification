Here is the Python code for the given problem:

def find_most_frequent(nums):
    count = {}
    max_count = 0
    result = None

    for num in nums:
        if num in count:
            count[num] += 1
        else:
            count[num] = 1
        if count[num] > max_count:
            max_count = count[num]
            result = num

    return result

if __name__ == "__main__":
    N = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(find_most_frequent(nums))

This program reads the number of elements N and the elements of the array from the standard input. It then calls the `find_most_frequent` function with the array as the argument, and prints the result.

The `find_most_frequent` function works by iterating over the array and maintaining a count of each number in a dictionary. It then updates the count and result whenever a number is encountered that is more frequent than the current maximum count. After the iteration, the function returns the number with the highest count.

The `if __name__ == "__main__":` block at the end ensures that the code is run when the script is executed directly (not imported as a module). It first reads the number of elements N, then the array elements, and finally prints the result of `find_most_frequent`.