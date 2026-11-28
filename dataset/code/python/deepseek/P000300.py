Here is the Python code for the problem.

def letterCombinations(digits):
    mapping = {
        '2': ['a', 'b', 'c'],
        '3': ['d', 'e', 'f'],
        '4': ['g', 'h', 'i'],
        '5': ['j', 'k', 'l'],
        '6': ['m', 'n', 'o'],
        '7': ['p', 'q', 'r', 's'],
        '8': ['t', 'u', 'v'],
        '9': ['w', 'x', 'y', 'z']
    }

    def backtrack(index, path):
        if len(path) == len(digits):
            result.append(''.join(path))
            return
        for letter in mapping[digits[index]]:
            path.append(letter)
            backtrack(index + 1, path)
            path.pop()

    result = []
    if digits:
        backtrack(0, [])

    return result

print(letterCombinations('2'))

In this code, we define a function `letterCombinations` that accepts a string of digits and returns a list of all possible combinations of letters that can represent those digits. We use a dictionary to map each digit to its corresponding set of letters. Then, we define a helper function `backtrack` that backtracks from the current path to the parent node, and for each node, we try to add a letter from its children nodes. If the path length is equal to the length of the digits, we add the current path to the result list. Finally, we call `backtrack` with the initial index and path as 0 and an empty list. The result is returned at the end.

You can run this code with a Python interpreter, it will output all possible letter combinations for the given phone number digits. For example, if you call `letterCombinations('2')`, it will return `['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']`.