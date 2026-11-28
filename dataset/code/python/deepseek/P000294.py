Sure, here is a simple Python solution for the problem. The main function takes a string and a number of rows as inputs, and returns the zigzag pattern of the string.

def zigzag(s, rows):
    if rows == 1:
        return s

    result = ''
    cycle = 2 * rows - 2
    for i in range(rows):
        for j in range(i+1):
            index = (i - j) % cycle
            if index < len(s):
                result += s[index]
        if i % 2 == 1:
            result += '\n'

    return result


def main():
    s = input("Enter a string: ")
    rows = int(input("Enter the number of rows: "))
    print(zigzag(s, rows))


if __name__ == "__main__":
    main()

This code firstly handles the edge cases where the number of rows is 1. Then it creates a string in a zigzag pattern. It goes through each row from top to bottom, and for each row, it goes through each character in that row. It calculates the index of each character in the string according to the cycle of the zigzag pattern. If the index is within the length of the string, it adds the character to the result string. If the row number is odd, it adds a newline character to the result string.