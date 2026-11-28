Here is the Python code for the problem:

def longest_uncommon(A, B):
    if A == B:
        return -1
    else:
        return max(len(A), len(B))

def main():
    A = input("Enter string A: ")
    B = input("Enter string B: ")
    print(longest_uncommon(A, B))

if __name__ == "__main__":
    main()

In this code, we first define a function `longest_uncommon` that takes two strings as input. If both strings are the same, it returns -1, otherwise it returns the maximum length of the two strings.

Then, we define a `main` function that takes user input for the two strings and prints the length of the longest uncommon subsequence.

Finally, we run our program if it's being run as a script, and call the `main` function.

Note: In Python, we should avoid using 'if __name__ == "__main__":' because it can cause unexpected behavior when the script is imported as a module. We should use 'if __name__ == "__main__"'.