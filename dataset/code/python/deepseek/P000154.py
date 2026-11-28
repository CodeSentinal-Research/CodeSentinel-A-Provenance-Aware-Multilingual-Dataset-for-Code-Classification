Here is the Python code for the problem:

def find_missing_repeating(arr):
    n = len(arr)
    total_sum = n + 1
    arr_sum = sum(arr)
    missing = total_sum - arr_sum
    repeating = (n*(n+1))/2 - arr_sum
    return (missing, int(repeating))

def main():
    arr = list(map(int, input().split()))[1:]
    missing, repeating = find_missing_repeating(arr)
    print(f'Missing number: {missing}, Repeating number: {repeating}')

if __name__ == "__main__":
    main()

In the above code, we first calculate the sum of all numbers from 1 to N using the formula `n*(n+1)/2 - arr_sum`. Then we subtract this sum from the sum of all numbers in the array to find the missing number. The repeating number is the sum of all numbers from 1 to N, which we can find using the formula `(n*(n+1))/2`.

In the `main` function, we read the input from the standard input, split it by spaces, and ignore the first item (the number of elements N). We then call `find_missing_repeating` with the array of integers, and print the missing and repeating numbers.