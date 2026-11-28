Here is the Python code:

def valid_palindrome(s):
    s = ''.join(c for c in s if c.isalnum()).lower()
    return s == s[::-1]

def main():
    s = input()
    if valid_palindrome(s):
        print('YES')
    else:
        print('NO')

if __name__ == '__main__':
    main()

This code works by first removing all non-alphanumeric characters and converting the string to lower case. It then checks if the resulting string is the same as its reverse. If it is, then the original string is a palindrome, and it prints 'YES'. Otherwise, it prints 'NO'.