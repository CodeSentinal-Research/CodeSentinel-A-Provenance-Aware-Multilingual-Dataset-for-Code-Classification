Here is the Python code for the given problem:

def letterCombinations(digits):
    if not digits:
        return []
    
    phone = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }
    
    def dfs(index, path):
        if index == len(digits):
            result.append(''.join(path))
            return
        for letter in phone[digits[index]]:
            path.append(letter)
            dfs(index + 1, path)
            path.pop()
    
    result = []
    dfs(0, [])
    return result


def main():
    digits = input()
    print(letterCombinations(digits))


if __name__ == "__main__":
    main()

This code will prompt the user to input the digits, which will then be passed to the `letterCombinations` function. The function then uses a depth-first search (dfs) to find all possible combinations of the given digits. The dfs function will recursively add each letter in the phone key to the current path, and then recursively call itself with the next index. When the path is backtracking (i.e., when the path is empty), it will remove the last added letter. The result will be printed after the dfs has finished.