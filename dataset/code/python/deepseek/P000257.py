Here's a Python solution for the problem:

def check_anagram(s1, s2):
    return sorted(s1) == sorted(s2)

def main():
    s1 = input()
    s2 = input()
    if check_anagram(s1, s2):
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()

In this code, the function `check_anagram` sorts the characters in both strings and compares them. If they are the same, it means the strings are anagrams of each other.

The `main` function reads two strings from the user, calls the `check_anagram` function with these strings as arguments, and prints the result.

The `if __name__ == "__main__"` line makes sure the `main` function is only called when this script is run directly, not when it is imported as a module.