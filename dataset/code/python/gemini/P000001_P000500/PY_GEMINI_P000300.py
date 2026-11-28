import sys

def letter_combinations(digits: str):
    if not digits:
        return []
    mapping = {
        '2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl',
        '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'
    }
    res = []
    def backtrack(idx, path):
        if idx == len(digits):
            res.append(''.join(path))
            return
        for char in mapping.get(digits[idx], ''):
            path.append(char)
            backtrack(idx + 1, path)
            path.pop()
    backtrack(0, [])
    return res

def main():
    input_data = sys.stdin.read().split()
    if input_data:
        digits = input_data[0]
        combos = letter_combinations(digits)
        for c in combos:
            print(c)

if __name__ == '__main__':
    main()