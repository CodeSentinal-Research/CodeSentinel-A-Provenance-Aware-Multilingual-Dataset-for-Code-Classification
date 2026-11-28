Here's the Python code for the problem:

def unique_morse_words():
    n = int(input())
    words = [input() for _ in range(n)]

    unique_words = set()

    for word in words:
        unique_words.add(word)

    print(len(unique_words))

if __name__ == "__main__":
    unique_morse_words()
In this code, we first take the number of words as input. Then, for each word, we add it to a set. This is because a set in Python automatically removes duplicates. The number of unique words is then printed out.