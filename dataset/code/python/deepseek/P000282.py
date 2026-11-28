Here is the Python code to solve the problem:

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
    s1 = input("Enter first string: ")
    s2 = input("Enter second string: ")
    print("Longest common substring: ", longest_common_substring(s1, s2))


if __name__ == "__main__":
    main()
This code uses the concept of dynamic programming to find the longest common substring of two strings. The main function first gets the input strings, then calls the `longest_common_substring` function with these strings as arguments, and finally prints the result.