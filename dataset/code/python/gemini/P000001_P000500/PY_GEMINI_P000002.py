import sys

def main():
    # Read all inputs from standard input
    input_data = sys.stdin.read().split()
    if len(input_data) >= 2:
        try:
            a = int(input_data[0])
            b = int(input_data[1])
            print(a - b)
        except ValueError:
            # Handle cases where inputs are not valid integers
            pass

if __name__ == '__main__':
    main()