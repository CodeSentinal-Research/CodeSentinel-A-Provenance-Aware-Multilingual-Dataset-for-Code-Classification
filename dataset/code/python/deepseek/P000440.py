Here is the Python code with input handling and a main function:

def find_min(nums):
    return min(nums)

def main():
    nums = list(map(int, input().split()))
    print(find_min(nums))

if __name__ == "__main__":
    main()

This program takes an input string of space-separated integers from the user, converts it to a list of integers, and then uses the `min` function to find and print the minimum element in the list.