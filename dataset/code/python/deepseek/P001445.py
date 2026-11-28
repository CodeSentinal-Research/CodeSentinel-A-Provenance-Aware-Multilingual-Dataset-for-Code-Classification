Here is the Python code for the problem:

def main():
    s = input()
    n = int(input())
    words = [input() for _ in range(n)]

    count = 0
    for word in words:
        if is_subsequence(s, word):
            count += 1

    print(count)

def is_subsequence(s, t):
    t_index = 0
    for s_index in range(len(s)):
        if s[s_index] == t[t_index]:
            t_index += 1
            if t_index == len(t):
                return True
    return False

if __name__ == "__main__":
    main()

In this code, we read the string and the number of words from the input. We then loop through the list of words and for each word, we check if it is a subsequence of the given string. If yes, we increment the count. At the end, we print the count.