Here's a Python solution using recursion:

def generateAbbreviations(word):
    def dfs(word, index, curr, count, abbreviation):
        if index == len(word):
            if count > 0:
                abbreviation.append(curr + str(count))
            else:
                abbreviation.append(curr)
            return
        else:
            dfs(word, index + 1, curr, count + 1, abbreviation)
            if count > 0:
                dfs(word, index + 1, curr + str(count), 1, abbreviation)

    abbreviation = []
    dfs(word, 0, "", 1, abbreviation)
    return sorted(abbreviation)

word = input("Enter a word: ")
print("All valid abbreviations:", generateAbbreviations(word))

This program uses depth-first search (DFS) to generate all abbreviations. The `dfs` function recursively generates abbreviations by replacing consecutive characters. It takes the word, the current index, the current abbreviation, the current count of consecutive characters and a list to store the abbreviations.

The function starts with the first character of the word. If the index equals the length of the word, it adds the current abbreviation to the list and returns. Otherwise, it continues with the next character.

If the count is greater than 0, it adds the count to the current abbreviation and recursively calls the function with the next character. If the count is 0, it simply appends the current abbreviation to the list.

Finally, the program sorts and returns the list of abbreviations in lexicographical order.

Please note that this program only handles input words with length less than or equal to 15. If you need to handle longer words, you may need to consider using a different method for generating abbreviations.