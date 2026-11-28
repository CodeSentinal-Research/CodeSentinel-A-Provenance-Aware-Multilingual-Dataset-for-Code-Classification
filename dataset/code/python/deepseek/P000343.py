def solve(word1, word2):
    freq1 = [0] * 26
    freq2 = [0] * 26

    for char in word1:
        freq1[ord(char) - ord('a')] += 1

    for char in word2:
        freq2[ord(char) - ord('a')] += 1

    diff_count = 0
    for i in range(26):
        diff_count += abs(freq1[i] - freq2[i])

    if diff_count <= 3:
        print('Yes')
    else:
        print('No')


def main():
    word1 = input()
    word2 = input()
    solve(word1, word2)


if __name__ == "__main__":
    main()