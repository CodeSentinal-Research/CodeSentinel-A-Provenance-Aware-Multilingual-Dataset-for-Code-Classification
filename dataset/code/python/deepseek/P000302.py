Here is the Python code:

def word_break(S, dictionary):
    dictionary = set(dictionary)
    break_point = [False] * (len(S) + 1)
    break_point[0] = True

    for i in range(1, len(S) + 1):
        for word in dictionary:
            if S[i-len(word):i] == word:
                break_point[i] = break_point[i-len(word)]
        if break_point[i]:
            break

    return 'Yes' if break_point[-1] else 'No'

def main():
    S = input().strip()
    dictionary_size = int(input().strip())
    dictionary = []
    for i in range(dictionary_size):
        dictionary.append(input().strip())
    print(word_break(S, dictionary))

if __name__ == "__main__":
    main()

This program takes as input a string `S` and a list of words `dictionary`. It checks each word in the dictionary against `S`, starting from the first word. If a match is found, it updates the `break_point` array accordingly. If at any point a word in `S` matches a word in the dictionary, the program checks if the next word in `S` matches a word in the dictionary. If no match is found, the program returns 'No'. If a match is found, the program updates the `break_point` array accordingly until the end of `S`. If the last element in `break_point` is `True`, the program returns 'Yes', otherwise 'No'.