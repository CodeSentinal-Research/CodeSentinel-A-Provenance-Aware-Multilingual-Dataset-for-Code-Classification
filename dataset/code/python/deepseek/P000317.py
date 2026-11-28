Here is the Python code:

def match_pattern(pattern, string):
    pattern_dict = {}
    words = string.split(' ')
    if len(pattern) != len(words):
        return "No"
    for i in range(len(pattern)):
        if pattern[i] not in pattern_dict:
            pattern_dict[pattern[i]] = words[i]
        elif pattern_dict[pattern[i]] != words[i]:
            return "No"
    return "Yes"

def main():
    pattern = input()
    string = input()
    print(match_pattern(pattern, string))

if __name__ == "__main__":
    main()

In this code, we first split the string into words. Then we iterate over each character in the pattern. If the character is not in the dictionary yet, we add it and its corresponding word. If it is already in the dictionary, we check if the word for this character matches with the word in the dictionary. If it doesn't match, we return "No". If it matches all characters in the pattern in the string, we return "Yes".