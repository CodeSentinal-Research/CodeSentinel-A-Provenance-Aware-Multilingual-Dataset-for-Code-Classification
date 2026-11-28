Here is the Python code for the problem:

def min_deletions(s):
    count = [0] * 256
    for char in s:
        count[ord(char)] += 1

    deletions = 0
    freqs = set()
    for char in s:
        count[ord(char)] -= 1
        if count[ord(char)] == 0:
            if char in freqs:
                deletions += 1
            else:
                freqs.add(char)

    return deletions


def main():
    s = input()
    print(min_deletions(s))


if __name__ == "__main__":
    main()

In this code, we first count the frequency of each character in the string and then for each character in the string, we decrement the frequency and add the character to a set. If the frequency becomes zero and the character is not in the set, we increment the deletions count.

The main function reads the string input and prints the minimum number of deletions.