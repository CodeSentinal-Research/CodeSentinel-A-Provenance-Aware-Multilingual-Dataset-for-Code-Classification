Here is the Python code for the problem:

def longest_palindrome(s):
    def helper(s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1
            r += 1
        return s[l+1:r]

    longest = ''
    for i in range(len(s)):
        palindrome = helper(s, i, i)
        if len(palindrome) > len(longest):
            longest = palindrome
        palindrome = helper(s, i, i+1)
        if len(palindrome) > len(longest):
            longest = palindrome
    return longest

def main():
    s = input()
    print(longest_palindrome(s))

if __name__ == "__main__":
    main()

In this code, `longest_palindrome` function is the main function that takes a string as input, calls `helper` function for every character in the string, and returns the longest palindrome found.

`helper` function is a helper function that is used to find the longest palindrome within a substring. It does this by decrementing and incrementing the left and right indices until the characters at the left and right indices are not the same. Then it returns the longest palindrome found.

In the main function, it takes the string from the input and prints the longest palindrome found by calling `longest_palindrome` function.