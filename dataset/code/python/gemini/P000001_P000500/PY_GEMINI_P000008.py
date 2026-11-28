import sys


def check_number(n: int) -> str:
    """Determines whether a given integer is positive, negative, or zero.

    Args:
        n (int): The integer to check.

    Returns:
        str: "Positive" if n > 0, "Negative" if n < 0, "Zero" if n == 0.
    """
    if n > 0:
        return "Positive"
    elif n < 0:
        return "Negative"
    else:
        return "Zero"


def main() -> None:
    """Main function to handle stdin input and stdout output."""
    input_data = sys.stdin.read().split()
    if input_data:
        for item in input_data:
            try:
                num = int(item)
                print(check_number(num))
            except ValueError:
                continue


if __name__ == "__main__":
    main()