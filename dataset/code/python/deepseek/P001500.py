Here is the Python code for the problem:

def is_palindrome(s):
    return s == s[::-1]

def solve_problem(s):
    left, right = 0, len(s) - 1
    while left < right:
        if s[left] != s[right]:
            if is_palindrome(s[left+1:right+1]):
                return 'YES'
            if is_palindrome(s[left:right-1]):
                return 'YES'
        left += 1
        right -= 1
    return 'YES'

def main():
    s = input().strip()
    print(solve_problem(s))

if __name__ == '__main__':
    main()

In this code, we use two pointers, left and right, to traverse from both ends of the string. If the characters at the left and right pointers are not the same, we check if the string from left+1 to right+1 is a palindrome or from left to right-1 is a palindrome. We increment the left pointer and decrement the right pointer until we find a match. If we find a match, we return 'YES'. If we finish the traversal without finding a match, we return 'YES'.