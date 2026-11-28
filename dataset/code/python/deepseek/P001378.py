Here's the Python code:

def word_pattern(pattern, sentence):
    words = sentence.split()
    if len(words) != len(pattern):
        return 'NO'
    mapping = {}
    for i in range(len(words)):
        if words[i] not in mapping:
            if pattern[i] in mapping.values():
                return 'NO'
            mapping[words[i]] = pattern[i]
        elif mapping[words[i]] != pattern[i]:
            return 'NO'
    return 'YES'

def main():
    pattern = input()
    sentence = input()
    print(word_pattern(pattern, sentence))

if __name__ == "__main__":
    main()

In this code, we first split the sentence into words. If the lengths of the words and the pattern are not the same, we return 'NO'. Then, we create a dictionary to store the mapping of each word to its corresponding pattern character. We iterate over the words and the pattern. If a word is not in the dictionary, we check if the pattern character is already used in the mapping values. If it is, we return 'NO'. If not, we add the word and pattern character to the dictionary. If a word is already in the dictionary, we check if the corresponding pattern character in the sentence is the same as the pattern character in the dictionary. If it is not, we return 'NO'. If all words and corresponding pattern characters are correctly mapped, we return 'YES'.