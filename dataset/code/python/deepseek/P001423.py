def find_and_replace_pattern(words, pattern):
    mapping = {}

    for i in range(len(pattern)):
        for j in range(i + 1, len(pattern) + 1):
            if pattern[i:j] not in mapping:
                mapping[pattern[i:j]] = chr(97 + i)
            else:
                mapping[pattern[i:j]] = chr(97 + i + 1)

    transformed_words = []
    for word in words:
        transformed_word = ''
        for char in word:
            if char in mapping:
                transformed_word += mapping[char]
            else:
                transformed_word += char
        transformed_words.append(transformed_word)

    transformed_words.sort()

    for word in transformed_words:
        print(word)


def main():
    N = int(input().strip())

    words = [input().strip() for _ in range(N)]

    pattern = input().strip()

    find_and_replace_pattern(words, pattern)


if __name__ == "__main__":
    main()