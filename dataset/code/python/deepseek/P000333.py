Here is the Python code for the problem:

def numMatchingSubseq(S, words):
    res = 0
    for word in words:
        i = 0
        j = 0
        while i < len(word) and j < len(S):
            if word[i] == S[j]:
                j += 1
            i += 1
        if j == len(S):
            res += 1
    return res

def main():
    S = input()
    n = int(input())
    words = [input() for _ in range(n)]
    print(numMatchingSubseq(S, words))

if __name__ == "__main__":
    main()
This program reads the string S and the list of words from the input, and then it prints the number of words that are subsequences of the given string.