Here is the Python code to solve the problem:

def sort_string(s):
    return ''.join(sorted(s))

s = input("Enter a string: ")
print(sort_string(s))

In this code, the `sort_string` function uses the built-in `sorted` function to sort the characters in the string. The `join` method is used to combine the sorted characters back into a string. The input string is taken as an input in the `input` function, which then gets passed to the `sort_string` function and the result is printed.