Here is the Python code for the problem:

def maxLength(words):
    max_length = 0
    used = set()
    for word in words:
        if word in used:
            continue
        if len(word) == len(set(word)):
            max_length = max(max_length, len(word))
            used.update(word)
    return max_length

In this code, we use a set to keep track of the unique characters used in each word. If a word is already in the used set, it means that word contains duplicate characters and we skip it. Otherwise, we calculate the length of the word and check if it's the maximum length we have seen so far.

Input handling can be done in a main function, for example:

def main():
    words = input("Enter words separated by space: ").split()
    print("Maximum length: ", maxLength(words))

if __name__ == "__main__":
    main()

This will ask the user to input words separated by space and then print the maximum length of a concatenated string with unique characters.