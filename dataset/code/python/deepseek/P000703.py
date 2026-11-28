def is_palindrome(nums):
    if len(nums) <= 1:
        return True
    elif nums[0] != nums[-1]:
        return False
    else:
        return is_palindrome(nums[1:-1])

def main():
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    print(is_palindrome(nums))

if __name__ == "__main__":
    main()
This Python code firstly defines a function `is_palindrome` that checks if a list of integers is a palindrome. This function uses recursion to compare the first and last elements of the list, and if they are equal, it calls itself with the rest of the list. If they are not equal, it returns False.

In the main function, it first reads the number of elements n and the array of integers from the input. It then prints the result of calling `is_palindrome` with the given array.

Please note that this code only works for a list with integers, not for other data types. If you need to handle lists of different data types (like strings or custom objects), you will need to modify the code to handle these cases appropriately.