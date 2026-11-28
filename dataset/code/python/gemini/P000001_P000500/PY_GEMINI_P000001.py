import sys

def main():
    """
    Reads two integers from standard input and prints their sum.
    Handles inputs on the same line or separate lines.
    """
    try:
        input_data = sys.stdin.read().split()
        if len(input_data) >= 2:
            num1 = int(input_data[0])
            num2 = int(input_data[1])
            print(num1 + num2)
    except (ValueError, IndexError):
        # Handle potential parsing errors gracefully
        pass

if __name__ == '__main__':
    main()