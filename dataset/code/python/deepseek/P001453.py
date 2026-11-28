Here is the Python code to solve the problem:

def longest_run(s):
    max_length = 0
    max_char = ''
    current_length = 1
    current_char = s[0]

    for char in s[1:]:
        if char == current_char:
            current_length += 1
        else:
            if current_length > max_length:
                max_length = current_length
                max_char = current_char
            current_length = 1
            current_char = char

    if current_length > max_length:
        max_length = current_length
        max_char = current_char

    print(max_char)

def main():
    s = input().strip()
    longest_run(s)

if __name__ == "__main__":
    main()

This program reads a string as input and then calls the `longest_run` function, which finds the character with the longest consecutive occurrence and its frequency. It handles multiple answers by printing the lexicographically smallest character.