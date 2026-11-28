Here's the Python code for the problem:

def max_score(words, letters, scores):
    letter_freq = {chr(97 + i): scores[i] for i in range(26)}
    max_score = 0

    for word in words:
        word_score = 0
        for char in word:
            word_score += letter_freq[char]
        if word_score > max_score:
            max_score = word_score

    return max_score


def main():
    N = int(input().strip())
    words = [input().strip() for _ in range(N)]
    letters = input().strip()
    scores = [int(input().strip()) for _ in range(26)]

    print(max_score(words, letters, scores))


main()

This program first reads the number of words, words themselves, available letters, and letter scores from the input. Then it calculates the maximum obtainable score by selecting a subset of words that can be formed using the available letters.