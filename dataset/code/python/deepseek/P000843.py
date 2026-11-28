Here's the Python code for the problem:

def min_max_pair_diff(nums, p):
    nums.sort()
    return min(nums[i+1]-nums[i] for i in range(p-1))

def main():
    n = int(input("Enter the size of the array: "))
    nums = list(map(int, input("Enter the elements of the array: ").split()))
    p = n//2
    print(min_max_pair_diff(nums, p))

if __name__ == "__main__":
    main()

This program first sorts the array in ascending order. Then, it calculates the difference between the adjacent elements in the array and finds the minimum of these differences. 

The input for this program is a line of input containing two integers: the size of the array (`n`) and the number of pairs to be formed (`p`). This is followed by a line of input containing `n` space-separated integers, representing the elements of the array.

The main function calls this method to find the minimum possible maximum difference, and then prints the result.

The use of the `map` function to convert user input into a list of integers, and the `input` function to read user input in a string, is done in the `main` function.

Note: This program assumes that the input will be given in the correct format, i.e., a number followed by a space for each number, and the last number is the last input. Also, the array size is always an even number for this problem.