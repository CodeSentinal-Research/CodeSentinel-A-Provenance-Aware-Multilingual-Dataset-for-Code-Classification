import sys


def check_even_or_odd(n: int) -> str:
    """Checks whether a given integer is even or odd.

    Args:
        n (int): The integer to check.

    Returns:
        str: "Even" if the integer is even, "Odd" if it is odd.
    """
    return "Even" if n % 2 == 0 else "Odd"


def main() -> None:
    """Main function to handle standard input and output."""
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    for token in input_data:
        try:
            n = int(token)
            print(check_even_or_odd(n))
        except ValueError:
            continue


if __name__ == "__main__":
    main()