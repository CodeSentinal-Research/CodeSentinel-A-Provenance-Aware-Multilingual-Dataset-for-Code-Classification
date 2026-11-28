Sure, here is the Python code with the main function and input handling.

def first_non_repeating(stream):
    count = {}

    for char in stream:
        count[char] = count.get(char, 0) + 1

    for char in stream:
        if count[char] == 1:
            return char
    return '#'


def main():
    stream = input()

    first_non_repeat = first_non_repeating(stream)

    print(first_non_repeat)


if __name__ == '__main__':
    main()

The main function reads the stream, processes it, and then prints the result. The `first_non_repeating` function is a helper function that processes the stream and returns the first non-repeating character. The dictionary `count` is used to keep track of the count of each character in the stream.