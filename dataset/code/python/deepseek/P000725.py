Here's the Python code:

def split_descending(s):
    if len(s) % 2 == 1:
        return False

    for i in range(len(s) - 1):
        if s[i] < s[i + 1]:
            return False

    return True


def main():
    s = input()
    if split_descending(s):
        print('true')
    else:
        print('false')


if __name__ == "__main__":
    main()

In this code, the `split_descending` function first checks if the length of the string is odd. If it is, the string cannot be split into two or more substrings, so the function returns `False`.

If the length is even, the function then checks each character in the string against its following character. If any character is larger than its following character, the function returns `False`.

The `main` function reads the input string and calls the `split_descending` function. It then prints the result.

You can run this code with an example input. For example, if you input `123412`, the output will be `false` because `1` is not greater than `2` and `2` is not greater than `3`.