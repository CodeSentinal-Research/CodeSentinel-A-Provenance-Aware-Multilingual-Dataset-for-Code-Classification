def count_substrings():
    s = input()
    count = 0
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            for k in range(j+1, len(s)+1):
                if s[i] == s[j] and s[j] == s[k]:
                    count += 1
    print(count)

if __name__ == "__main__":
    count_substrings()
This code will take input in the form of a string and count the number of substrings that contain at least one occurrence of each character. It iterates through each character in the string and for each character, it iterates through the rest of the string to form substrings. If a substring contains at least one occurrence of each character, it increments the count. The final count is then printed.