Here is a Python solution for the problem:

def validWordAbbreviation(word, abbr):
    i, n, j = 0, len(word), 0
    while i < n and j < len(abbr):
        if word[i] == abbr[j]:
            i += 1
            j += 1
        elif abbr[j].isdigit():
            if abbr[j] == '0':
                return False
            k = j
            while k < len(abbr) and abbr[k].isdigit():
                k += 1
            l = int(abbr[j:k])
            i += l
            j = k
        else:
            return False
    return i == n and j == len(abbr)

def main():
    word = input()
    abbr = input()
    result = "Yes" if validWordAbbreviation(word, abbr) else "No"
    print(result)

if __name__ == "__main__":
    main()

In this solution, the `validWordAbbreviation` function takes a word and an abbreviation as input, and checks if the word matches the abbreviation. It iterates through the word and abbreviation, comparing the corresponding characters. If the abbreviation is a digit, it checks if the next characters are also digits. If so, it extracts the number and moves the pointer by the extracted number. If the abbreviation is a letter, it checks if the letter in the word matches the abbreviation, and if so, moves the pointers to the next characters. If any character doesn't match, the function returns False. The `main` function handles the input and output.