Here's a Python solution. This program takes a list of words and returns words that can be typed on one row using only a single row of the keyboard.

def get_possible_words(words):
    row1 = set('qwertyuiopQWERTYUIOP')
    row2 = set('asdfghjklASDFGHJKL')
    row3 = set('zxcvbnmZXCVBNM')

    row1_words = [word for word in words if set(word).issubset(row1)]
    row2_words = [word for word in words if set(word).issubset(row2)]
    row3_words = [word for word in words if set(word).issubset(row3)]

    return row1_words + row2_words + row3_words


def main():
    words = input().split()
    possible_words = get_possible_words(words)
    for word in possible_words:
        print(word)


if __name__ == "__main__":
    main()

This program reads a list of words from the input and then outputs the words that can be typed on one row. The input is a list of words, and the output is a list of words that can be typed on one row.

The `get_possible_words` function finds words that can be typed on one row by iterating over the list of words and checking each word's set of characters against a set of characters in a row. If a word's set is a subset of the characters in a row, it's added to the corresponding row's list of words.

The `main` function is the entry point of the program. It reads a list of words from the input and then calls `get_possible_words` to find the words that can be typed on one row. It then outputs the possible words.

The `if __name__ == "__main__":` line makes the `main` function call itself if the script is run directly. This is a common approach for command-line scripts.