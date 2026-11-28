import sys


def is_special_symbol(ch: str) -> bool:
    """Check whether a given single character is a special symbol.

    A special symbol is defined as a character that is not an alphanumeric
    character (alphabet letter or digit) and not a whitespace character.

    Args:
        ch: A string containing a single character.

    Returns:
        bool: True if the character is a special symbol, False otherwise.

    Raises:
        ValueError: If the input is not a single character.
    """
    if len(ch) != 1:
        raise ValueError("Input must be exactly one character.")
    return not ch.isalnum() and not ch.isspace()


def main() -> None:
    input_data = sys.stdin.read()
    if not input_data:
        return

    # Process each character or the first non-newline character
    # Commonly, input is given as a single character or line
    char = input_data.strip("\r\n")
    if len(char) == 1:
        if is_special_symbol(char):
            print(f"'{char}' is a special symbol.")
        else:
            print(f"'{char}' is not a special symbol.")
    elif len(char) > 1:
        # If input has multiple characters on the line, evaluate the first character
        target = char[0]
        if is_special_symbol(target):
            print(f"'{target}' is a special symbol.")
        else:
            print(f"'{target}' is not a special symbol.")


if __name__ == "__main__":
    main()