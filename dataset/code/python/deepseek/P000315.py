def titleToNumber(columnTitle):
    result = 0
    for i, char in enumerate(reversed(columnTitle)):
        result += (ord(char) - ord('A') + 1) * (26 ** i)
    return result

def main():
    columnTitle = input("Enter the column title: ")
    print(titleToNumber(columnTitle))

if __name__ == "__main__":
    main()

This Python script is a simple conversion program that converts an Excel column title to its corresponding column number. 

The script uses a straightforward method where we iterate the reversed column title string, and for each character in the string, we calculate the corresponding number (from 'A' to 'Z'). The exponentiation (26 raised to the power of the current position) is used because we're dealing with a base 26 (26 letters in the English alphabet) number system. The `ord` function is used to get the ASCII value of a character, and then we subtract the ASCII value of 'A' to get the corresponding number from 1 to 26.

The main function of the script is handling input for the column title, and then printing the column number.