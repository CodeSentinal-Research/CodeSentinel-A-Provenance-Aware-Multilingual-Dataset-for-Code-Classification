Here is a Python solution using dynamic programming. The idea is to iterate through the input strings and find the longest common substring for each pair of characters.

def longest_common_substring(s1, s2):
    m = [[0] * (1 + len(s2)) for i in range(1 + len(s1))]
    longest, x_longest = 0, 0
    for x in range(1, 1 + len(s1)):
        for y in range(1, 1 + len(s2)):
            if s1[x - 1] == s2[y - 1]:
                m[x][y] = m[x - 1][y - 1] + 1
                if m[x][y] > longest:
                    longest = m[x][y]
                    x_longest = x
            else:
                m[x][y] = 0
    return s1[x_longest - longest: x_longest]


def main():
    s1 = input()
    s2 = input()
    print(longest_common_substring(s1, s2))


if __name__ == "__main__":
    main()

This code first reads two strings from the standard input, then it prints the longest common substring of the two input strings.