Sure, here is the Python code:

def is_palindrome(s):
    return s == s[::-1]

s = input()
print("Yes" if is_palindrome(s) else "No")

This program reads a line of input and checks if it is a palindrome. It does this by comparing the input string with its reverse. If they are equal, it means the string is a palindrome.