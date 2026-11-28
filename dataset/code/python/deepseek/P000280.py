Here is the Python code for the problem:

def valid_anagram(s1, s2):
    if len(s1) != len(s2):
        return "No"

    count1 = [0] * 26
    count2 = [0] * 26

    for i in range(len(s1)):
        count1[ord(s1[i]) - ord('a')] += 1
        count2[ord(s2[i]) - ord('a')] += 1

    diff_count = 0
    for i in range(26):
        diff_count += abs(count1[i] - count2[i])

    if diff_count > 1:
        return "No"
    else:
        return "Yes"

def main():
    s1 = input()
    s2 = input()
    print(valid_anagram(s1, s2))

if __name__ == "__main__":
    main()

This program first checks if the lengths of the two strings are different, and if so, it returns "No". Then it initializes two count arrays, one for each string, to count the number of each character in the string. It iterates through the characters in each string, and increments the count for the corresponding character in the corresponding count array. After that, it iterates through the count arrays and adds the absolute difference of the counts to a total difference count. If the total difference count is greater than 1, it returns "No", as it is not possible to make the two strings anagrams by removing at most one character. Otherwise, it returns "Yes".