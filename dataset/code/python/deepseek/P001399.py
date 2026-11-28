Here is a Python code that satisfies the problem's requirements:

def uncommon_words(sentence1, sentence2):
    word_count1 = {}
    for word in sentence1.split():
        word_count1[word] = word_count1.get(word, 0) + 1

    word_count2 = {}
    for word in sentence2.split():
        word_count2[word] = word_count2.get(word, 0) + 1

    for word in sorted(word_count1.keys() | word_count2.keys()):
        if (word in word_count1 and word_count1[word] == 1) or (word in word_count2 and word_count2[word] == 1):
            print(word)

def main():
    sentence1 = input().strip()
    sentence2 = input().strip()
    uncommon_words(sentence1, sentence2)

if __name__ == "__main__":
    main()
In this code, we first create a dictionary to count the occurrence of each word in the first sentence. Then, we do the same for the second sentence. The uncommon words are the words that appear in one dictionary but not in the other, sorted lexicographically.