Here is a Python code that solves the problem:

def find_common_characters():
    N = int(input().strip())
    strings = [input().strip() for _ in range(N)]
    common_characters = []

    for char in strings[0]:
        if all(char in string for string in strings):
            common_characters.append(char)

    common_characters.sort()
    print(''.join(common_characters))

if __name__ == "__main__":
    find_common_characters()

This program first reads the number of strings from the first line of input. It then reads each of the strings from the subsequent lines of input. It then iterates over each character in the first string and checks if it exists in all the other strings. If it does, it appends it to a list of common characters. After all characters are checked, it sorts the list of common characters and prints them.

In the `if __name__ == "__main__":` block, this program is called when the script is run directly, but not when it is imported as a module.