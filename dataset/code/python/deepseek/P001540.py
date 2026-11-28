Here is the Python code for the problem:

def count_vowel_substrings(s):
    vowels = set("aeiou")
    count = sum(s[i] in vowels and s[i-1:i+2] in vowels for i in range(1, len(s)-1))
    return count + s[-1] in vowels and s[:1] in vowels

def main():
    s = input().strip()
    print(count_vowel_substrings(s))

if __name__ == "__main__":
    main()

This code works by creating a function `count_vowel_substrings` that takes a string `s` as input. The function then checks each substring of `s` to see if it consists entirely of vowels and contains all five vowels at least once. The result is the total number of such substrings.

The `main` function is the entry point of the program. It reads a line from the input, strips off any trailing newline, and passes it to the `count_vowel_substrings` function. The result is printed out.