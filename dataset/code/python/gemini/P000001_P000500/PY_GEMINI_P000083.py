import sys


def find_largest(a: float, b: float, c: float) -> float:
    """Finds the largest among three numbers using nested if statements."""
    if a >= b:
        if a >= c:
            return a
        else:
            return c
    else:
        if b >= c:
            return b
        else:
            return c


def main():
    try:
        # Read all inputs from standard input
        input_data = sys.stdin.read().split()
        if len(input_data) < 3:
            print(
                "Error: Please provide at least three numbers.", file=sys.stderr
            )
            sys.exit(1)

        # Parse the first three inputs as floats
        try:
            num1 = float(input_data[0])
            num2 = float(input_data[1])
            num3 = float(input_data[2])
        except ValueError:
            print(
                "Error: Inputs must be valid numbers.", file=sys.stderr
            )
            sys.exit(1)

        # Find the largest number
        largest = find_largest(num1, num2, num3)

        # Print the result. If it's a whole number, print as integer.
        if largest.is_integer():
            print(int(largest))
        else:
            print(largest)

    except Exception as e:
        print(f"An unexpected error occurred: {e}", file=sys.stderr)
        sys.exit(1)


if __name__ == "__main__":
    main()