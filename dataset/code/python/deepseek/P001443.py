Here is the Python code for the given problem.

def canBeConstructed(s1, s2):
    counter1 = [0] * 26
    counter2 = [0] * 26
    for c in s1:
        counter1[ord(c) - ord('a')] += 1
    for c in s2:
        counter2[ord(c) - ord('a')] += 1
    for i in range(26):
        if counter1[i] > counter2[i]:
            return False
    return True

def countWordsObtained(N, first, second):
    count = 0
    for s1 in first:
        for s2 in second:
            if canBeConstructed(s1, s2):
                count += 1
    return count

def main():
    N, M = map(int, input().split())
    first = [input() for _ in range(N)]
    second = [input() for _ in range(M)]
    print(countWordsObtained(N, first, second))

if __name__ == '__main__':
    main()
This code first declares a function `canBeConstructed(s1, s2)` that checks if all characters in the first word can be reconstructed from the second word. The counter arrays `counter1` and `counter2` are used to count the occurrences of each character in the two words.

Then, in the `countWordsObtained(N, first, second)` function, we iterate over all words in the first list and for each word, we iterate over all words in the second list. If a word from the first list can be reconstructed from a word from the second list, we increment our count.

Finally, in the `main()` function, we read the number of words N and the words, and print the count of words that can be obtained after adding a letter.