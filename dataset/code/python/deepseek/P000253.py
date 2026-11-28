Here is the Python code to count the vowels in a string:

def count_vowels(s):
    vowels = "aeiou"
    count = 0
    for char in s.lower():
        if char in vowels:
            count += 1
    return count

def main():
    s = input("Enter a string: ")
    print(count_vowels(s))

if __name__ == "__main__":
    main()

In this code, the function `count_vowels` takes a string `s` as input and returns the number of vowels in the string. It does this by iterating over each character in the string (after converting it to lowercase). If the character is a vowel, it increments a counter. The `main` function is the entry point of the program, it reads a string from the user, and calls `count_vowels` with this string.