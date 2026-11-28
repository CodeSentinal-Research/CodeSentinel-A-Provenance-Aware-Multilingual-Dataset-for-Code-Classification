Here is the Python code for the problem:

def reverse_string(input_string):
    reversed_string = input_string[::-1]
    return reversed_string

input_string = input()
print(reverse_string(input_string))

The input string is received from the user in the main function. The `reverse_string` function is defined to reverse the string in-place. The slicing operation `[::-1]` is used to reverse the string.