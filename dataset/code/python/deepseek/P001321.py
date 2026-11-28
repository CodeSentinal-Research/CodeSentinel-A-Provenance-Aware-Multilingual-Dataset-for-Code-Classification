Here is the Python code for the given problem:

def letterCombinations(digits):
    mapping = {
        "2": "abc",
        "3": "def",
        "4": "ghi",
        "5": "jkl",
        "6": "mno",
        "7": "pqrs",
        "8": "tuv",
        "9": "wxyz"
    }
    def dfs(index, path):
        if len(path) == len(digits):
            output.append(''.join(path))
            return
        for letter in mapping[digits[index]]:
            path.append(letter)
            dfs(index + 1, path)
            path.pop()
    output = []
    dfs(0, [])
    return output

print(letterCombinations("2"))

In this code, a dictionary `mapping` is used to map each digit to its corresponding letters. The `dfs` function is a depth-first search function that generates all possible combinations. It takes two arguments: an index and a path. The path is a list of characters that have been generated so far, and the index is the current digit we are working on.

The function first checks if the path has reached the length of the digits, if so, it means that we have generated a combination and we can print it. If not, it will generate all possible letters for the current digit, add the letter to the path, and recursively call `dfs` on the next index and the updated path. After the recursive calls, it will remove the last letter from the path and continue to the next iteration.

The output of this function will be all possible letter combinations for the given digits.