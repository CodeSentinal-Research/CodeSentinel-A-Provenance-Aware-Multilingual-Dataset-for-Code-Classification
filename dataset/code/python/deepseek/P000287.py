def reverse_vowels(s: str) -> str:
    vowels = 'aeiouAEIOU'
    s = list(s)
    i, j = 0, len(s) - 1
    while i < j:
        if s[i] not in vowels:
            i += 1
        elif s[j] not in vowels:
            j -= 1
        else:
            s[i], s[j] = s[j], s[i]
            i, j = i + 1, j - 1
    return ''.join(s)

def main():
    s = input("Enter a string: ")
    print(reverse_vowels(s))

if __name__ == '__main__':
    main()
This Python code reads a string from the user, calls the function `reverse_vowels` with this string as an argument and prints the result. The function `reverse_vowels` first converts the string into a list of characters. It then uses two pointers (i and j) to traverse the list from both ends, and if both characters at the current position are vowels, it swaps them and moves both pointers. If any character is not a vowel, it simply moves the respective pointer.