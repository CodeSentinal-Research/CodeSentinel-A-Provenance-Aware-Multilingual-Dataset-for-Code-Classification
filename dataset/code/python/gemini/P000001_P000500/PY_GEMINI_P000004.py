import sys

def main():
    # Read all inputs from standard input
    input_data = sys.stdin.read().split()
    if len(input_data) >= 2:
        try:
            a = int(input_data[0])
            b = int(input_data[1])
            # Perform integer division
            print(a // b)
        except ValueError:
            pass
        except ZeroDivisionError:
            # Handle division by zero gracefully if it occurs
            print("Division by zero error", file=sys.stderr)

if __name__ == '__main__':
    main()